# Controle de Entradas em Ambientes Hospitalares

**Descrição:** Neste tutorial, vamos desenvolver um sistema de controle de entradas em ambientes hospitalares usando ESP32 com sensor de cartão RFID, registrando as entradas em um banco de dados.  

—
## Índice

1. [Introdução](#introdução)
2. [Requisitos](#requisitos)
3. [Configuração do Ambiente](#configuração-do-ambiente)
4. [Montagem do Circuito](#montagem-do-circuito)
5. [Programação](#programação)
6. [Teste e Validação](#teste-e-validação)
7. [Expansões e Melhorias](#expansões-e-melhorias)
8. [Referências](#referências)

---
## Introdução
O controle de entradas em ambientes hospitalares tem a utilidade de garantir a segurança de locais de acesso restrito e guardar os acessos para consultas necessárias. O monitoramento das entradas deve ser registrado em um banco de dados.
O sistema de controle de acessos em hospitais para segurança de pacientes e funcionários deve integrar o  ESP32 e RFID para registrar acessos e armazená-los em um banco de dados.  

---
## Requisitos
### Hardware
Sensores: Capturam dados de proximidade e uso da estação. 
Microcontrolador (ESP32): Recebe os dados e os transmite via Wi-Fi. 

- **Placa**: ESP32 com Wi-fi.
- **Sensores**: Módulo RFID (NFC PN532).
- **Outros componentes**: Cartões ou tags RFID compatíveis, buzzer e LED para feedback de acesso, protoboard e jumpers.

### Software
Servidor Central: Armazena os dados e gera relatórios. 

- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.
- **Bibliotecas**: Adafruit_PN532, SPI, WiFi, HTTPClient.
- **Banco de dados**: Firebase.


---

## Configuração do Ambiente
### Passo 1: Instalação do Software

- Arduino IDE: Baixe e instale o Arduino IDE a partir do https://www.arduino.cc/en/software.
- Adicionar a ESP32 no Gerenciador de Placas do Arduino IDE.
- Instalar as bibliotecas necessárias.
- Criar um banco de dados Firebase para armazenar os registros:  
Acesse o Firebase Console e crie um novo projeto. 
Vá em Build > Realtime Database e clique em Criar Banco de Dados.  
Escolha um local (exemplo: us-central1) e selecione modo de teste para evitar problemas de permissão.  
Vá em Configurações do Projeto > Contas de Serviço e copie a Chave da API.  
- Configurar APIs para envio de dados via HTTP.  


### Passo 2: Configuração da Placa e Porta
Conecte o Arduino ao computador via USB.
No Arduino IDE, vá em Ferramentas > Placa e selecione Arduino Uno.
Em Ferramentas > Porta, escolha a porta correspondente ao Arduino conectado, como mostra a imagem abaixo: 

![image](https://github.com/user-attachments/assets/85910db9-eee0-470c-a68b-8070bf18dfce)


## Montagem do Circuito

Conecte o sensor de temperatura ao Arduino conforme o esquema abaixo:

VCC do RFID ao pino 3.3V do ESP32.  
GND do RFID ao GND do ESP32.   
SDA conectado ao pino 22 do ESP32.  
SCL conectado ao pino 21 do ESP32.  

![Simulacao_Sistema_Seguranca](https://github.com/user-attachments/assets/1010b039-9b66-41b5-8721-e0f27da28697)

---

## Programação
### Passo 1: Configuração dos Sensores e Atuadores

Código em C para Arduino:

```cpp
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Wire.h>
#include <Adafruit_PN532.h>
#include "time.h"

// Configurações do Wi-Fi
#define WIFI_SSID "SEU_WIFI"
#define WIFI_PASSWORD "SUA_SENHA"

// Configuração do Firebase
#define FIREBASE_HOST "SEU_FIREBASE.firebaseio.com"
#define FIREBASE_AUTH "SEU_FIREBASE_AUTH_KEY"

FirebaseData firebaseData;

// Configuração do sensor RFID PN532 via I2C
#define SDA_PIN 21
#define SCL_PIN 22
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

// Definição dos pinos do LED e Buzzer
#define BUZZER_PIN 23
#define LED_PIN 2

// Lista de cartões autorizados (substitua pelos UIDs reais)
const String IDsPermitidos[] = {"A1B2C3D4", "11223344"};

// Configuração do servidor NTP para obter horário
const char* ntpServer = "pool.ntp.org";
long gmtOffset_sec = -10800; // UTC-3 para Brasil
int daylightOffset_sec = 3600; 

void setup() {
    Serial.begin(115200);

    // Inicializa Wi-Fi
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Conectando ao Wi-Fi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("\nConectado ao Wi-Fi!");

    // Inicializa Firebase
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
    
    // Inicializa o sensor RFID
    Wire.begin(SDA_PIN, SCL_PIN);
    nfc.begin();
    if (!nfc.getFirmwareVersion()) {
        Serial.println("Erro: Não foi possível detectar o PN532!");
        while (1);
    }
    nfc.SAMConfig();

    // Configurações dos pinos do LED e Buzzer
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);

    // Sincroniza horário
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    Serial.println("Sistema pronto para leitura de cartões!");
}

void loop() {
    Serial.println("Aproxime um cartão...");

    // Aguarda um cartão RFID ser detectado
    if (!nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, NULL, 0)) {
        delay(500);
        return;
    }

    // Lê UID do cartão detectado
    uint8_t uid[7]; 
    uint8_t uidLength;
    
    if (!nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength)) {
        Serial.println("Erro na leitura do cartão!");
        return;
    }

    // Converte UID para String
    String cardID = "";
    for (uint8_t i = 0; i < uidLength; i++) {
        cardID += String(uid[i], HEX);
    }

    Serial.print("Cartão detectado: ");
    Serial.println(cardID);

    // Verifica se o cartão está autorizado
    bool autorizado = false;
    for (String id : IDsPermitidos) {
        if (cardID.equalsIgnoreCase(id)) {
            autorizado = true;
            break;
        }
    }

    if (autorizado) {
        Serial.println("Acesso autorizado!");
        digitalWrite(LED_PIN, HIGH);
        delay(1000);
        digitalWrite(LED_PIN, LOW);
    } else {
        Serial.println("Acesso negado!");
        digitalWrite(BUZZER_PIN, HIGH);
        delay(1000);
        digitalWrite(BUZZER_PIN, LOW);
    }

    // Obtém data e hora atual
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Erro ao obter horário!");
        return;
    }

    char timeString[30];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", &timeinfo);
    String dataHora = String(timeString);

    // Envia os dados para o Firebase
    String path = "/registros/" + cardID + "/" + dataHora;
    Firebase.setString(firebaseData, path, autorizado ? "Autorizado" : "Negado");

    Serial.println("Registro enviado ao Firebase!");

    delay(2000);
}

```
---
## Teste e Validação
Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Testando Sensores**: Verifique se as leituras são consistentes e corretas.
2. **Monitoramento em Tempo Real**: Teste o sistema completo em condições simuladas para garantir que funciona conforme o esperado.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adição de um display LCD para mostrar nome e status do acesso.
- Autenticação dupla com senha numérica.
- Integração com reconhecimento facial para maior segurança.
- Notificação via Telegram ou e-mail ao registrar acessos.


---

## Referências

- Link da simulação: https://wokwi.com/projects/423637992584440833  
- Documentação do Arduino: https://www.arduino.cc/.  
---
