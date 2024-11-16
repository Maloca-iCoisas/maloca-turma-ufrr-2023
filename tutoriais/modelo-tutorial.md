# Detector de Proximidade com Alarme e LCD

**Descrição:** Neste tutorial, vamos criar um Detector de Proximidade utilizando um Arduino Uno, um sensor de ultrassom HC-SR04, um buzzer, um LED e um LCD 16x2 para exibir a distância medida. Este projeto pode ser aplicado na área da saúde para monitorar pacientes acamados, alertando cuidadores sobre movimentações ou quedas, sendo um sistema simples de aplicar."

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

O Detector de Proximidade com Alarme é um sistema simples que utiliza o HC-SR04 para medir a distância de objetos próximos. Quando a distância é inferior a um limite configurado (ex.: 50 cm), o sistema aciona um buzzer e um LED para alertar sobre a proximidade. O LCD exibe a distância em tempo real. Este projeto é ideal para aplicações na saúde, como monitoramento de pacientes com mobilidade reduzida.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno.
- **Sensores**: HC-SR04 (sensor de ultrassom) para medir o movimento do paciente.
- **Atuadores**: Buzzer ativo, LED (vermelho)
- **Outros componentes**: Protoboard, jumpers, resistor 220 Ω, e monitor LCD 16x2.

### Software

- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.
- **Bibliotecas**: LiquidCrystal.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Pesquise Arduino IDE download no navegador, abra o link no site oficial do Arduino e baixe a versão compativel com seu sistema.
- **Simulador TinkerCad**: Para melhores resultados, simule no site Tinkercad o circuito utilizado. Não precisa ser instalado, basta pesquisar tinkercad no navegador e entrar no site.
- **Bibliotecas**: LiquidCrystal: Normalmente já vem instalada com o Arduino IDE, mas caso não venha, siga os seguintes passos: Abra o Arduino IDE, vá em tools (Ferramentas),
agora clique em "Manage Libraries", pesquise por LiquidCrystal by Arduino.


### Passo 2: Configuração das Placas

- **Arduino Uno**: Vamos utilizar o Arduino Uno, que já vem por padrão instalado no Arduino IDE. Para selecionar a placa desejada vá em "Select Board" (selecionar placa)
selecione a entrada USB que vai usar, e por fim selecione o Arduino Uno.

---

## Montagem do Circuito

Monte o circuito conforme o diagrama abaixo:

HC-SR04:
VCC → 5V, GND → GND, TRIG → D8, ECHO → D9
LED:
Ânodo → Resistor (220 Ω) → D12, cátodo → GND
Buzzer:
Positivo → D11, Negativo → GND
LCD 16x2:
RS → D7, E → D6, D4 → D5, D5 → D4, D6 → D3, D7 → D2
VSS → GND, VDD → 5V, V0 → Terminal central do potenciômetro
Nota: Ajuste o potenciômetro para configurar o contraste do LCD.
> **Nota**: Imagem do circuito feito no simulador Tinkercad.
![imagem_2024-11-16_173940039](https://github.com/user-attachments/assets/48dbace3-54d9-4213-a72e-16ed0d12aeb5)

---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Copie e cole o código abaixo na IDE do Arduino. Depois, faça o upload para a placa.

**Código em C/C++ para Arduino Uno:**

```cpp
#include <LiquidCrystal.h>

// Configuração do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

#define TRIG_PIN 8
#define ECHO_PIN 9
#define LED_PIN 12
#define BUZZER_PIN 11

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin(16, 2); // Inicializa o LCD
  lcd.print("Distance:"); // Linha fixa
  Serial.begin(9600); // Monitor Serial
}

void loop() {
  long duration, distance;

  // Pulso para o TRIG
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Tempo do pulso no ECHO
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calcula distância (cm)
  distance = duration * 0.034 / 2;

  // Exibe no LCD
  lcd.setCursor(0, 1);
  lcd.print("    ");  // Limpa linha
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  // Aciona LED e buzzer se perto
  if (distance > 0 && distance < 50) {
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500); // Atualiza a cada 0.5s
}

```


### Passo 2: Processamento e Lógica de Alerta

**Aquisição de Dados:**
A distância é calculada com base no tempo de ida e volta do pulso ultrassônico medido pelo sensor HC-SR04.

**Condição de Alerta:**
Se a distância for menor que um limite pré-definido (ex.: 50 cm), o LED será aceso e o buzzer ativado. Caso contrário, ambos permanecem desligados.

**Saída no LCD:**
A distância é exibida em tempo real no LCD 16x2.

---

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

1. **Monitoramento de distância no LCD**: A distância medida pelo sensor deve ser exibida no LCD.
2. **Validação dos atuadores**: Aproximar um objeto a menos de 50 cm deve acionar o LED e o buzzer.
3. **Monitor Serial**: Utilize o Monitor Serial para conferir os valores medidos pelo sensor.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- **Conexão Wi-Fi**: Use um ESP32 para enviar os dados para um servidor na nuvem.
- **Adição de sensores**: Integre um sensor de temperatura ou de movimento para criar um sistema mais completo.
- **Alarme remoto**: Configure uma comunicação Bluetooth para notificar um aplicativo móvel.

---

## Referências

Liste todas as referências e links úteis para guias, bibliotecas, e materiais adicionais que ajudem a complementar o tutorial.

**Video sobre o sensor HC-SR04**
https://www.youtube.com/watch?v=n-gJ00GTsNg

**Video sobre um circuito de alerta usando HC-SR04**
https://www.youtube.com/watch?v=QEIl2Nxot5M


---

Com este circuito podemos ter uma rápida atuação quando um paciente com mobilidade limitada cair, podendo evitar uma tragédia!
