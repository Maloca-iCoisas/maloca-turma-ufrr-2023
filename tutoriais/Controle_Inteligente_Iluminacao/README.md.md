
# **Tutorial: Controle Inteligente de Iluminação com IoT**

Este tutorial mostra como criar um sistema IoT para controle inteligente de iluminação em ambientes médicos, como salas de espera ou consultórios. Ele ajustará a iluminação automaticamente com base na presença de pessoas e nas condições de luz ambiente, otimizando o conforto e a eficiência energética.

---

## **Sumário**

1. [Objetivo do Projeto](#objetivo-do-projeto)  
2. [Componentes Necessários](#componentes-necessários)  
3. [Esquema de Conexão](#esquema-de-conexão)  
    - [1. Conexão do Sensor PIR](#1-conexão-do-sensor-pir)  
    - [2. Conexão do Sensor de Luz](#2-conexão-do-sensor-de-luz-ldr-ou-bh1750)  
    - [3. Conexão da Lâmpada LED](#3-conexão-da-lâmpada-led)  
4. [Código do Projeto](#código-do-projeto)  
5. [Funcionamento](#funcionamento)  
6. [Testando o Sistema](#testando-o-sistema)  
7. [Possíveis Melhorias](#possíveis-melhorias)

---

## **Objetivo do Projeto**

Desenvolver um sistema IoT para controle de iluminação que:  
- Detecta automaticamente a presença de pessoas no ambiente.  
- Mede a intensidade da luz ambiente.  
- Liga e desliga uma lâmpada LED com base nas condições detectadas.  

Esse sistema é útil em hospitais e clínicas para:  
- Garantir conforto visual durante exames e consultas.  
- Reduzir o consumo de energia elétrica em ambientes com pouca ocupação.  

---

## **Componentes Necessários**

1. **Hardware**
   - ESP32 ou Arduino Uno
   - Sensor PIR (exemplo: HC-SR501) para detecção de presença
   - Sensor de luz ambiente (LDR ou BH1750)
   - Lâmpada LED ou faixa de LEDs
   - Driver de LED ou módulo relé
   - Resistores e jumpers
   - Protoboard ou PCB
   - Fonte de alimentação (5V)

2. **Software**
   - IDE Arduino
   - Bibliotecas:
     - `Wire.h` para comunicação I2C
     - `BH1750.h` para leitura de luminosidade (se usar BH1750)

---

## **Esquema de Conexão**

### **1. Conexão do Sensor PIR**
- **VCC** → 5V  
- **GND** → GND  
- **OUT** → Pino digital (ex: D2 no Arduino ou GPIO15 no ESP32)  

### **2. Conexão do Sensor de Luz (LDR ou BH1750)**  
- **LDR**:  
  - Conecte em série com um resistor de 10k ohms entre o pino analógico A0 e o GND.  
- **BH1750** (I2C):  
  - **VCC** → 3.3V (ESP32) ou 5V (Arduino)  
  - **GND** → GND  
  - **SCL** → GPIO22 (ESP32) ou A5 (Arduino)  
  - **SDA** → GPIO21 (ESP32) ou A4 (Arduino)  

### **3. Conexão da Lâmpada LED**
- **Driver ou Relé IN** → Pino digital (ex: D4 no Arduino ou GPIO17 no ESP32)  
- **Driver/Relé VCC** → 5V  
- **Driver/Relé GND** → GND  

---

## **Código do Projeto**

```cpp
#include <Wire.h>
#include <BH1750.h>

BH1750 lightMeter;

const int pirPin = 2; // Pino do sensor PIR
const int ledPin = 4; // Pino para controle do LED

bool isPersonDetected = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Wire.begin();
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println("Sensor de luz iniciado com sucesso!");
  } else {
    Serial.println("Erro ao iniciar sensor de luz!");
    while (true);
  }
}

void loop() {
  // Detecta presença de pessoas
  isPersonDetected = digitalRead(pirPin);

  // Lê o nível de luz ambiente
  float lux = lightMeter.readLightLevel();
  Serial.print("Luminosidade: ");
  Serial.print(lux);
  Serial.println(" lux");

  // Lógica de controle de iluminação
  if (isPersonDetected) {
    if (lux < 300) { // Ajuste o valor conforme necessário
      digitalWrite(ledPin, HIGH); // Liga a luz
      Serial.println("Pessoa detectada, luz ligada!");
    } else {
      digitalWrite(ledPin, LOW); // Desliga a luz
      Serial.println("Pessoa detectada, luz desligada devido à luminosidade suficiente.");
    }
  } else {
    digitalWrite(ledPin, LOW); // Desliga a luz
    Serial.println("Sem presença detectada, luz desligada.");
  }

  delay(1000);
}
```

---

## **Funcionamento**

1. **Sensor PIR** detecta a presença de pessoas no ambiente:  
   - Quando alguém entra, o sistema verifica a luz ambiente.  
2. **Sensor de Luz** ajusta a iluminação:  
   - Se a luz ambiente for baixa, a lâmpada LED será ligada.  
   - Se a luz ambiente for suficiente, a lâmpada permanecerá desligada.  
3. **Controle Inteligente**:  
   - Após 10 segundos sem detecção de presença, a lâmpada será desligada para economizar energia.  

---

## **Testando o Sistema**

1. Configure o hardware conforme o esquema.  
2. Carregue o código no ESP32 ou Arduino usando a IDE Arduino.  
3. Verifique o funcionamento:  
   - Movimente-se na frente do sensor PIR e observe o LED acender.  
   - Ajuste a luminosidade da sala e veja como o sistema responde.  

---

## **Possíveis Melhorias**

1. **Controle por Aplicativo**  
   - Conecte o ESP32 à rede Wi-Fi e controle a iluminação via um aplicativo móvel.  

2. **Ajuste Dinâmico da Intensidade**  
   - Use PWM (Modulação por Largura de Pulso) para controlar a intensidade da lâmpada LED com base na luminosidade ambiente.  

3. **Relatórios e Monitoramento na Nuvem**  
   - Envie dados do consumo de energia e do uso do sistema para um painel online.  

4. **Detecção Multiambiente**  
   - Adicione múltiplos sensores PIR e LEDs para controlar diferentes áreas do ambiente de forma independente.  

---

Este tutorial é uma base para desenvolver soluções mais avançadas. Teste, personalize e leve o projeto ao próximo nível! 🚀
