# Sistema de Controle de Fluxo de Pessoas para Prevenção de Aglomerações com Controle Manual

**Descrição:**  Neste tutorial, vamos construir um sistema de semáforo simples com Arduino e LEDs, ideal para controlar o fluxo de entrada e saída de pessoas em áreas restritas ou de alto risco. Este projeto adiciona a funcionalidade de um botão para controle manual, permitindo que operadores ajustem o fluxo conforme necessário. Essa abordagem aumenta a flexibilidade e segurança em ambientes hospitalares, prevenindo aglomerações de forma eficaz.

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

Controlar o fluxo de pessoas é essencial em áreas críticas de hospitais. Este projeto de semáforo com LEDs fornece uma sinalização visual para entrada (LED verde) e parada (LED vermelho). Agora, com a adição de um botão para controle manual, o sistema pode ser ajustado em tempo real, garantindo ainda mais eficiência e segurança.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno ou compatível;
- **Atuadores**: LEDs (1 verde e 1 vermelho);
- **Outros componentes**: Resistores de 220Ω (um para cada LED), botão, jumpers e uma protoboard;

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

5. Conexão da Linha Positiva da Protoboard:

- Conecte a linha positiva (linha vermelha) da protoboard ao pino 5V do Arduino para fornecer alimentação estável aos componentes do circuito.

6. Conexão do Botão:

- Conecte um terminal do botão ao pino digital 8 do Arduino.
- O outro terminal deve ser conectado ao GND por meio de um resistor de 10kΩ (pull-down).

<img src="modelo thinker card.png" alt="modelo thinker card" />
---

## Programação

### Passo 1: Configuração dos LEDs e do Botão

Definiremos os pinos dos LEDs e do botão, configurando-os como saídas e entrada, respectivamente:

```cpp
// Definição dos pinos dos LEDs
const int ledVerde = 2;
const int ledVermelho = 4;

// Definição do pino do botão
const int botao = 8;

// Variável para armazenar o estado atual do semáforo
bool estadoSemaforo = false;

void setup() {
  // Configuração dos pinos como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Configuração do pino do botão como entrada com pull-up interno
  pinMode(botao, INPUT_PULLUP);
}
```

### Passo 2: Lógica de Controle do Semáforo

O código abaixo permite alternar entre os LEDs (verde e vermelho) com o botão:

```cpp
void loop() {
   // Verifica se o botão foi pressionado
  if (digitalRead(botao) == LOW) { 
    estadoSemaforo = !estadoSemaforo; // Alterna o estado do semáforo
    delay(200); // Debounce do botão
  }
  
  // Controle dos LEDs com base no estado do semáforo
  if (estadoSemaforo) {
    digitalWrite(ledVerde, HIGH);   // Liga o LED verde
    digitalWrite(ledVermelho, LOW); // Desliga o LED vermelho
  } else {
    digitalWrite(ledVerde, LOW);    // Desliga o LED verde
    digitalWrite(ledVermelho, HIGH); // Liga o LED vermelho
  }
}
```

---

## Teste e Validação

Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Verificação da Conexão dos LEDs**: Certifique-se de que os LEDs estão conectados nos pinos corretos e orientados com os terminais certos.
2. **Teste do Botão**: Pressione o botão e observe a troca entre os LEDs verde e vermelho.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adicionar um buzzer para alertar durante a troca de estado.
- Integrar sensores para automação completa do fluxo.
- Adicionar um display para exibir mensagens como "Acesso Permitido" ou "Acesso Negado".

---

## Referências

- Documentação do Arduino: https://www.arduino.cc/.
- Tutoriais de circuitos com LEDs: https://www.blogdarobotica.com/2020/09/23/pisca-led-com-arduino-blink/.
- https://docs.arduino.cc/built-in-examples/digital/Button/.

---

Este tutorial apresenta um sistema básico de controle de semáforo com botão, para controle do fluxo de pessoas em ambientes sensíveis.