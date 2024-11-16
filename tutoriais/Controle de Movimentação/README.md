# Controle de leitos hospitalares

**Descrição:** Neste tutorial, vamos desenvolver um sistema de monitoramento que detecta a ocupação ou movimentação em leitos hospitalares para monitorar pacientes acamados utilizando um sensor de distância ultrassônico HC-SR04 no Arduino.

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

A detecção de ocupação ou movimentação em leitos hospitalares em contexto hospitalar tem a utilidade de averiguar e informar aos profissionais para monitorar pacientes acamados ou outras áreas restritas em caso de ausência ou movimentação inesperada de pacientes.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno.
- **Sensores**: Sensor HC-SR04.
- **Outros componentes**: Jumpers, protoboard (opcional), resistores (opcional).


### Software

- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Baixe e instale o Arduino IDE a partir do https://www.arduino.cc/en/software.

### Passo 2: Configuração da Placa e Porta

- **Arduino**: Passos para configurar a placa e selecionar a porta correta na IDE.
1. Conecte o Arduino ao computador via USB.
2. No Arduino IDE, vá em Ferramentas > Placa e selecione Arduino Uno.
3. Em Ferramentas > Porta, escolha a porta correspondente ao Arduino conectado, como mostra a imagem abaixo:

![Selecionar porta ARDUINO](https://github.com/user-attachments/assets/5467e2ef-ce78-4aa9-a95f-1b9b5cf4a59e)
---

## Montagem do Circuito

Conecte o sensor de HC-SR04 ao Arduino conforme o esquema abaixo:

- VCC do HC-SR04 ao 5V do Arduino.
- GND do HC-SR04 ao GND do Arduino.
- TRIG do HC-SR04 ao pino 9 do Arduino.
- ECHO do HC-SR04 ao pino 10 do Arduino.

Nota: Use resistores divisores de tensão no pino ECHO se necessário, para proteger a entrada digital do Arduino.

![SensorHC-SR04-ARDUINO](https://github.com/user-attachments/assets/f2ecd797-67da-4848-859d-8e7aff62babd)
---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Forneça o código para a configuração dos sensores. Por exemplo, para medir temperatura e batimentos cardíacos:

**Código para monitoramento com HC-SR04 em C para Arduino:**

```cpp
#define TRIG_PIN 9  // Pino TRIG do HC-SR04
#define ECHO_PIN 10 // Pino ECHO do HC-SR04

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration;
  float distance;

  // Envia pulso TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Calcula duração do sinal ECHO
  duration = pulseIn(ECHO_PIN, HIGH);

  // Converte duração para distância em centímetros
  distance = (duration * 0.034) / 2;

  // Exibe a distância no monitor serial
  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Verifica ocupação do leito
  if (distance < 50) { // Ajustar conforme necessário
    Serial.println("Leito ocupado!");
  } else {
    Serial.println("Leito vazio.");
  }

  delay(1000); // Aguarda 1 segundo entre leituras
}

```

## Teste e Validação

Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Verificação de Conexões:** Certifique-se de que o circuito está montado corretamente.
2. **Monitoramento em Tempo Real**: Teste o sensor simulando presença (mãos ou objetos próximos) e ausência para validar o funcionamento.
---

## Expansões e Melhorias

Sugestões para melhorar o projeto:

- Integrar um buzzer para alertas sonoros em caso de movimentação anormal.
- Adicionar comunicação Wi-Fi (ESP32) para enviar dados para uma nuvem.
- Integrar um banco de dados para registro das leituras.


---

## Referências

- Link da simulação: https://wokwi.com/projects/407047625786887169.
- Documentação do Arduino: https://www.arduino.cc/.
- Documentação do sensor HC-SR04: https://docs.arduino.cc/libraries/hcsr04-ultrasonic-sensor/

---
