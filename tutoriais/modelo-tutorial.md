## Monitoramento de Temperatura com Arduino e Wi-fi

**Descrição:** Neste tutorial, vamos criar um sistema de monitoramento de temperatura corporal usando um Arduino, um sensor de temperatura, um display LCD para exibição local, e um módulo ESP8266 para enviar os dados para a plataforma ThingSpeak. Este projeto é útil para monitoramento de sinais vitais em ambiente doméstico ou hospitalar, permitindo o acompanhamento remoto e o envio de alertas. Este tutorial é destinado a estudantes, profissionais e curiosos na área de eletrônica e IoT que desejam aprender a criar sistemas de monitoramento remoto usando sensores, display LCD e comunicação Wi-Fi.

---

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

O monitoramento de temperatura corporal é uma aplicação essencial para a saúde, principalmente em casos de acompanhamento de condições médicas onde é importante observar febres ou outras variações de temperatura. Este sistema utiliza um sensor de temperatura conectado ao Arduino para capturar a temperatura corporal, que é exibida localmente em um display LCD e enviada para o ThingSpeak, onde é possível monitorar os dados em tempo real remotamente.

---

## Requisitos

### Hardware

- **Placa**: Arduino(UNO ou Mega);
- **Sensores**: Sensor de Temperatura (como TMP36 ou LM35);
- **Módulo Wi-fi**: ESP8266;
- **Display**: LCD 16x2 com interface I2C ou sem(conectado via pinos);
- **Outros componentes**: Jumpers, resistores, protoboard, potenciômetro;

### Software

- **Linguagens**: C/C++ para Arduino;
- **Plataforma Iot**: ThingSpeak.
- **IDE**: Arduino IDE;
- **Bibliotecas**: LiquidCrystal, math.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

1. Arduino IDE: Certifique-se de que a IDE do Arduino está instalada e configurada corretamente para compilar e enviar o código para a placa. Faça o download a partir do site https://www.arduino.cc/en/software.
2. Conexão do ESP8266: Configure o módulo ESP8266 para se conectar ao Wi-Fi virtual do simulador ou a uma rede Wi-Fi.

- **Bibliotecas**: Como instalar bibliotecas: 

1. No IDE arduino após instalado, clicar no ícone da biblioteca.

![biblioteca LiquidCrystal ](https://github.com/user-attachments/assets/59cc5b68-4a15-44b4-86df-e27ce9e226b7)

2. Pesquise por "LiquidCrystal" e "math", selecione e clique em Install.

**Configuração do ThingSpeak**:

1. Crie uma conta no ThingSpeak se ainda não tiver uma.
2. Crie um novo "Canal" e habilite o campo para temperatura.
3. Copie a API Key de escrita, pois ela será necessária para o código.

### Passo 2: Configuração das Placas

- **Arduino**: Passos para configurar a placa e selecionar a porta correta no IDE Arduino.

1. Conecte o Arduino via usb;
2. Selecione Select Board;

![selecionarBoard](https://github.com/user-attachments/assets/f65764af-3df0-4078-b18d-e64eb6825f2f)

3. Após selecionado, aparecerá as opções de portas e você clicará na opção: Select Other Board and port;
4. Você selecionará a opção de Arduino Mega ou Mega 2560;

![selecionarBoard](https://github.com/user-attachments/assets/3ea98c1a-c3c6-41c0-9d3d-d719ce89f738)

5. Por último selecionará a porta.

---

## Montagem do Circuito

Conecte os componentes conforme o diagrama abaixo: 

![print do circuito](https://github.com/user-attachments/assets/c28ad78a-9654-4264-a680-1ca164b99ba9)

Pinagem dos Componentes
  ## 1. Arduino UNO
    Pino A0: Conectado ao sensor de temperatura para leitura analógica.
    Pinos Digitais 12, 11, 5, 4, 3, 2: Conectados ao display LCD 16x2 para exibir a temperatura.
    Pinos 3.3V e GND: Conectados ao módulo ESP8266 (fornecendo alimentação).
    Pino 5V: Alimenta o display LCD e o sensor de temperatura.
  ## 2. Display LCD 16x2
    VSS: Conectado ao GND do Arduino.
    VDD: Conectado ao 5V do Arduino.
    V0: Conectado ao potenciômetro para ajustar o contraste.
    RS: Conectado ao pino digital 12 do Arduino.
    RW: Conectado ao GND do Arduino.
    E: Conectado ao pino digital 11 do Arduino.
    D4, D5, D6, D7: Conectados aos pinos digitais 5, 4, 3 e 2 do Arduino, respectivamente.
    A (Anodo): Conectado ao 5V através de um resistor para controlar o brilho do display.
    K (Cátodo): Conectado ao GND.
  ## 3. Módulo Wi-Fi ESP8266
    VCC: Conectado ao pino 3.3V do Arduino.
    GND: Conectado ao GND do Arduino.
    TX: Conectado ao RX do Arduino (pino digital 0).
    RX: Conectado ao TX do Arduino (pino digital 1).
  ## 4. Sensor de Temperatura (por exemplo, LM35 ou TMP36)
    VCC: Conectado ao 5V do Arduino.
    GND: Conectado ao GND do Arduino.
    OUT: Conectado ao pino A0 do Arduino para leitura da temperatura.
  ## 5. Potenciômetro
    Utilizado para ajustar o contraste do display LCD.
    Terminal 1: Conectado ao GND.
    Terminal 2 (Pino Central): Conectado ao pino V0 do LCD.
    Terminal 3: Conectado ao 5V.
---

## Programação

### Passo 1: Configuração do LCD e ThingSpeak

Neste projeto,vamos configurar O LCD e o thingSpeak no Arduino.

**Código em C++ para Arduino:**

#include <LiquidCrystal.h> // Inclui a biblioteca para controle do display LCD
#include <math.h>           // Inclui a biblioteca de funções matemáticas

// Define os pinos de conexão do display LCD ao Arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variáveis de configuração do ThingSpeak
String ssid = "Simulator Wifi";              // Nome da rede Wi-Fi
String password = "";                        // Senha da rede (neste caso, vazia)
String host = "https://api.thingspeak.com";  // Endereço do ThingSpeak
const int httpPort = 80;                     // Porta para conexão HTTP
String API_KEY = "KN0GF1ZWJ93CIGYS";         // Chave de API para escrita no ThingSpeak
String uri = "/update?api_key=" + API_KEY + "&field1=";

### Passo 2: Processamento e Lógica do Sistema

Após as configurações necessárias, vamos adicionar a lógica para o funcionamento do sistema

int temp; // Variável para armazenar a temperatura lida

void setup() {
  Serial.begin(9600);      // Inicializa a comunicação serial para monitoramento
  lcd.begin(16, 2);        // Inicializa o display LCD com 16 colunas e 2 linhas
  lcd.setCursor(0, 1);     // Define o cursor no início da segunda linha do display
  
  setupESP8266();          // Configura o módulo ESP8266 para conectar ao Wi-Fi
}

void loop() {
  // Lê a temperatura do sensor e converte a leitura para graus Celsius
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print("Temp: ");
  Serial.println(temp);
    
  // Exibe a temperatura no display LCD
  lcd.clear();
  lcd.print("Temp: ");
  lcd.setCursor(6, 0);  // Move o cursor para a posição correta
  lcd.print(temp);

  // Envia os dados de temperatura para o ThingSpeak
  enviaTemperatura();
    
  delay(1000);  // Espera 1 segundo antes de repetir a leitura e envio
}

int setupESP8266() {
  // Inicia a comunicação com o módulo ESP8266
  Serial.begin(115200);  // Configura a comunicação serial em 115200 bps
  Serial.println("AT");  // Envia o comando "AT" para verificar a resposta do módulo
  delay(10);             // Aguarda a resposta do ESP8266
  if (!Serial.find("OK")) return 1;

  // Conecta à rede Wi-Fi
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);  // Aguarda a resposta do módulo
  if (!Serial.find("OK")) return 2;

  // Abre uma conexão TCP com o servidor ThingSpeak
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);  // Aguarda a resposta do módulo
  if (!Serial.find("OK")) return 3;
  return 0;
}

void enviaTemperatura() {
  // Constrói o pacote HTTP para enviar a temperatura ao ThingSpeak
  String httpPacket = "GET " + uri + String(temp) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();

  // Envia o comprimento do pacote
  Serial.print("AT+CIPSEND=");
  Serial.println(length);
  delay(10);  // Aguarda a resposta do módulo
  
  // Envia o pacote HTTP
  Serial.print(httpPacket);
  delay(10);  // Aguarda a confirmação de envio
  if (!Serial.find("SEND OK\r\n")) return;
}

## Teste e Validação

1. Teste do Sensor de Temperatura: Verifique se a leitura do sensor de temperatura corporal é correta.
2. Teste do Display LCD: Assegure-se de que a temperatura está sendo exibida corretamente no LCD.
3. Envio ao ThingSpeak: Verifique no painel do ThingSpeak se os dados estão sendo atualizados corretamente.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adição de um Alerta: Adicione um LED ou buzzer para alertar se a temperatura corporal ultrapassar um limite (por exemplo, 38°C).
- Integração com Aplicativo Móvel: Conecte-se a um aplicativo para notificação em tempo real.
- Armazenamento Local: Adicione um cartão SD para salvar dados.

---

## Referências

- Link da simulação: https://www.tinkercad.com/things/ccyciIdf1FK-p5-sensor-de-temperatura-com-wi-fi-oficial?sharecode=pIV2mreEdajbvkVpup6dyhDSjJHkHJpOMCQ6i7WPiNM
- Plataforma do ThingSpeak: https://thingspeak.mathworks.com/
- Documentação do Arduino: https://www.arduino.cc/.

---
