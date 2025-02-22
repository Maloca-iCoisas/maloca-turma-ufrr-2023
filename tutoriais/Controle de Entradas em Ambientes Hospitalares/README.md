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
- Criar um banco de dados Firebase para armazenar os registros.
- Configurar APIs para envio de dados via HTTP.


### Passo 2: Configuração da Placa e Porta
Conecte o Arduino ao computador via USB.
No Arduino IDE, vá em Ferramentas > Placa e selecione Arduino Uno.
Em Ferramentas > Porta, escolha a porta correspondente ao Arduino conectado, como mostra a imagem abaixo: 



## Montagem do Circuito

Conecte o sensor de temperatura ao Arduino conforme o esquema abaixo:

VCC do RFID ao pino 5V do ESP32.  
GND do RFID ao GND do ESP32.  
SDA conectado ao pino 22 do ESP32.  
SCL conectado ao pino 21 do ESP32.  

---

## Programação
### Passo 1: Configuração dos Sensores e Atuadores

Código em C para Arduino:

```cpp
#include <Adafruit_PN532.h>

// Definição dos pinos do PN532
#define SDA_PIN 22
#define SCL_PIN 21

// Inicialização do módulo PN532 (I2C padrão)
Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

void setup() {
    Serial.begin(115200);
    nfc.begin();
    uint32_t versiondata = nfc.getFirmwareVersion();
    if (!versiondata) {
        Serial.println("Falha ao encontrar PN532");
        while (1);
    }
    nfc.SAMConfig();

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

- Link da simulação:  
- Documentação do Arduino: https://www.arduino.cc/.  
---
