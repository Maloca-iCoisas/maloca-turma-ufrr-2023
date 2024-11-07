# Sistema de Controle de Fluxo de Pessoas para Prevenção de Aglomerações

**Descrição:**  Neste tutorial, vamos construir um sistema de semáforo simples com Arduino e LEDs, aplicável para ambientes de saúde, com o objetivo de controlar o fluxo de entrada e saída de pessoas em áreas restritas ou de alto risco. Esse projeto oferece uma maneira visual de indicar quando é seguro entrar (LED verde) ou parar (LED vermelho), contribuindo para um ambiente hospitalar mais organizado e seguro.

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

Controlar o fluxo de pessoas é essencial em áreas críticas de hospitais. Este projeto de semáforo com LEDs fornece uma sinalização visual para entrada (LED verde) e parada (LED vermelho). Isso ajuda a manter o controle, evitando aglomerações em espaços sensíveis. Este projeto é também uma ótima introdução ao uso de Arduino e componentes básicos em ambientes IoT voltados para a saúde.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno ou compatível;
- **Atuadores**: LEDs (1 verde e 1 vermelho);
- **Outros componentes**: Resistores de 220Ω (um para cada LED), jumpers e uma protoboard;

### Software

- **Linguagens**: C/C++ para Arduino
- **IDE**: Arduino IDE

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Baixe e instale o Arduino IDE a partir do https://www.arduino.cc/en/software.

### Passo 2: Configuração da Placa

- **Arduino**: Conecte a placa ao computador via USB e selecione a porta correta na IDE do Arduino.

---

## Montagem do Circuito

Para montar o circuito, siga as instruções abaixo:

1. Preparação da Protoboard e Conexão do GND:
- Conecte o pino GND do Arduino à linha de alimentação negativa (linha preta) da protoboard. Esta linha servirá como terra para todo o circuito.

2. Conexão dos LEDs na Protoboard:

- Coloque os dois LEDs na protoboard, deixando espaço suficiente entre eles para as conexões.

3. Conexão dos Resistores:

- Conecte um resistor de 220Ω ao ânodo de cada LED. Isso limitará a corrente que passa pelos LEDs, protegendo-os de queima.

4. Conexão dos LEDs aos Pinos do Arduino:

- LED Verde: Conecte o terminal do resistor do LED verde ao pino digital 2 do Arduino.
- LED Vermelho: Conecte o terminal do resistor do LED vermelho ao pino digital 4 do Arduino.

3. Conexão da Linha Positiva da Protoboard:

- Conecte a linha positiva (linha vermelha) da protoboard ao pino 5V do Arduino para fornecer alimentação estável aos componentes do circuito.

<img src="modelo thinker card.png" alt="modelo thinker card" />
---

## Programação

### Passo 1: Configuração dos LEDs

Definiremos os pinos dos LEDs e os configuraremos como saídas para controlar o estado de cada LED:

```cpp
// Definição dos pinos dos LEDs
const int ledVerde = 2;
const int ledVermelho = 4;

void setup() {
  // Configuração dos pinos como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}
```

### Passo 2: Lógica de Sequência do Sinal

Abaixo está o código que controla a sequência de um semáforo simples, alternando entre os LEDs verde e vermelho com uma duração específica para cada um:

```cpp
void loop() {
  // LED verde
  digitalWrite(ledVerde, HIGH);   // Acende o LED verde
  delay(5000);                    // Mantém o LED verde aceso por 5000 milissegundos (5 segundos)
  digitalWrite(ledVerde, LOW);    // Apaga o LED verde
  
  // LED vermelho
  digitalWrite(ledVermelho, HIGH); // Acende o LED vermelho
  delay(5000);                     // Mantém o LED vermelho aceso por 5000 milissegundos (5 segundos)
  digitalWrite(ledVermelho, LOW);  // Apaga o LED vermelho
}
```

---

## Teste e Validação

Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Verificação da Conexão dos LEDs:** Certifique-se de que os LEDs estão conectados nos pinos corretos e orientados com os terminais certos.
2. **Teste da Sequência:** Carregue o código para o Arduino e observe a sequência de acendimento dos LEDs.
3. **Ajuste de Tempo:** Se necessário, ajuste o tempo de delay para modificar a duração de cada fase do semáforo.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adicionar um botão para controle manual do semáforo.
- Utilizar um display para mostrar o tempo restante para cada fase.
- Integrar o sistema a uma rede IoT para monitoramento remoto e controle do fluxo em tempo real.

---

## Referências

1. Link da simulação: https://www.tinkercad.com/things/7hZtcHNeM26-sinal-com-2-leds.
2. Documentação do Arduino: https://www.arduino.cc/.
3. Tutoriais de circuitos com LEDs: https://www.blogdarobotica.com/2020/09/23/pisca-led-com-arduino-blink/.

---

Este tutorial fornece uma introdução básica ao controle de LEDs com Arduino, simulando um sistema de semáforo para ambientes de saúde.

