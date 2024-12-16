# Sistema de Monitoramento de Umidade para Ambientes com Arduino

**Descrição:** Este tutorial ensina como criar um sistema básico de monitoramento de umidade utilizando um Arduino Uno e um sensor DHT22. Este projeto é útil para monitorar condições de umidade em ambientes internos, como quartos ou estufas.

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

Este sistema foi projetado para monitorar a umidade relativa do ar em ambientes internos. Utiliza o sensor DHT22 para captar os dados, que são exibidos no monitor serial. O projeto também inclui um LED para alertar quando a umidade ultrapassar limites predefinidos.

---

## Requisitos

### Hardware

- **Placa:** Arduino Uno
- **Sensor:** DHT22 (sensor de umidade e temperatura)
- **Atuadores:** LED
- **Outros componentes:** Resistores, jumpers, protoboard, cabos USB

### Software

- **IDE:** Arduino IDE
- **Bibliotecas:** `DHT` (disponível no Gerenciador de Bibliotecas do Arduino IDE)

### Imagens 
 ![ texto]()
---

## Configuração do Ambiente

### Passo 1: Instalação do Software

1. Faça o download e instale o Arduino IDE a partir do [site oficial](https://www.arduino.cc/en/software).
2. Instale a biblioteca do DHT no Arduino IDE:
   - Vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas...**.
   - Procure por "DHT" e instale a biblioteca "DHT sensor library" de Adafruit.

### Passo 2: Configuração do Arduino Uno

1. Conecte o Arduino ao computador usando um cabo USB.
2. No Arduino IDE, selecione a porta correta em **Ferramentas > Porta** e escolha "Arduino Uno" em **Placa**.

---

## Montagem do Circuito

### Diagrama de Conexão

#### Sensor:

- **DHT22:**
  - Pino VCC -> 5V (Arduino)
  - Pino GND -> GND (Arduino)
  - Pino DATA -> Pino 2 (Arduino)

#### Atuador:

- **LED:**
  - Anodo -> Pino 8 (Arduino) com resistor de 220 ohms
  - Catodo -> GND

> **Nota:** Use uma protoboard para organizar as conexões.

---

## Programação

### Passo 1: Código para Leitura do Sensor

```cpp
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22
#define LED_PIN 8

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    float umidade = dht.readHumidity();

    // Verifica se a leitura foi bem-sucedida
    if (isnan(umidade)) {
        Serial.println("Falha ao ler o sensor DHT!");
        return;
    }

    // Exibe o valor no monitor serial
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.println(" %");

    // Lógica de alerta
    if (umidade > 60.0) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }

    delay(2000);
}
```

### Passo 2: Upload do Código

1. Conecte o Arduino ao computador.
2. No Arduino IDE, clique em **Verificar** e, em seguida, **Fazer Upload**.

---

## Teste e Validação

1. **Testando o Sensor de Umidade:** Respire próximo ao sensor DHT22 e observe os valores no monitor serial.
2. **Verificação do LED:** Simule uma umidade elevada (acima de 60%) e observe o LED acender.

---

## Expansões e Melhorias

- Adicionar um display LCD para exibir os valores de umidade em tempo real.
- Conectar o sistema a um módulo Wi-Fi (como ESP8266) para enviar os dados para a nuvem.
- Expandir para monitorar também a temperatura com alertas adicionais.

---

## Referências

1. [Documentação do Arduino](https://www.arduino.cc/reference/en/)
2. [Datasheet do DHT22](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
3. [Biblioteca DHT](https://github.com/adafruit/DHT-sensor-library)
