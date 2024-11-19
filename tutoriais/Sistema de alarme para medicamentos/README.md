# Sistema de alarme para medicamentos

**Descrição:** Este tutorial ensina como criar um sistema de alarme para lembrar pacientes de tomar medicamentos em horários específicos utilizando um Arduino Uno, um LED e um buzzer.

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

O gerenciamento correto de horários para tomar medicamentos é essencial para garantir a eficácia de tratamentos, especialmente para pacientes que precisam de lembretes constantes. Este projeto oferece uma solução simples e prática: um sistema de alarme baseado em Arduino que combina indicadores sonoros (buzzer) e visuais (LED) para alertar o paciente. Além disso, ele permite desativar o alarme temporariamente por meio de um botão, reativando-o automaticamente após um minuto.

---

## Requisitos

### Hardware

- **Placa:** Arduino Uno  
- **Atuadores:** 1 buzzer, 1 LED  
- **Outros componentes:** 1 botão, 2x resistores (220Ω e 10kΩ), jumpers e uma protoboard.  

### Software

- **IDE:** Arduino IDE  
- **Bibliotecas:** Nenhuma biblioteca externa é necessária.  

---

## Configuração do Ambiente

### Passo 1: Instalação do Arduino IDE  
- Baixe a IDE no [site oficial do Arduino](https://www.arduino.cc/en/software) e instale no seu computador.  

### Passo 2: Configuração da Placa  
- Conecte a placa Arduino ao computador e selecione a porta serial correta na IDE (Menu: `Ferramentas > Porta`).  
- Escolha o modelo da sua placa em `Ferramentas > Placa > Arduino Uno`.  

---

## Montagem do Circuito

Você pode acessar o circuito pelo Tinkercad clicando [aqui](https://www.tinkercad.com/things/gED6XUVIJy0-tutorial-sistema-de-alarme-para-medicamentos?sharecode=6NWKQ3q4GM-DVPG1ZKIghCep1jBR7lyA8gxUiVn4sJc).

<img src="tutoriais\Sistema de alarme para medicamentos\diagrama-circuito.png" alt="Diagrama">

---

## Programação

### Código para Arduino

```cpp
// Definição dos pinos
const int ledPin = 9;
const int buzzerPin = 8;
const int buttonPin = 7;

// Variáveis
bool alarmActive = true; // O alarme começa ativo

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // Inicia com LED e buzzer ligados
  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, 1000); // Frequência do buzzer (1kHz)
  
  Serial.begin(9600);
  Serial.println("Sistema de Alarme para Medicamentos Iniciado");
  Serial.println("Alarme ativo! Hora de tomar o medicamento.");
}

void loop() {
  // Verifica se o botão foi pressionado
  if (digitalRead(buttonPin) == HIGH && alarmActive) {
    alarmActive = false; // Desativa o alarme
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    Serial.println("Alarme desligado. Ele será reativado em 1 minuto.");
    delay(60000); // Aguarda 1 minuto (60.000 ms)
    alarmActive = true; // Reativa o alarme automaticamente
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000); // Liga o buzzer novamente
    Serial.println("Alarme reativado! Hora de tomar o medicamento.");
  }
}
```

---

## Teste e Validação

1. **Teste Inicial:**  
   - Conecte o Arduino ao computador e carregue o código.  
   - O LED e o buzzer devem ligar automaticamente ao iniciar o sistema.  

2. **Desativação Temporária:**  
   - Pressione o botão para desligar o alarme.  
   - O LED e o buzzer devem desligar, e o alarme será reativado após 1 minuto.  

---

## Expansões e Melhorias

- **Cronômetro Personalizado:** Permitir ajustes no intervalo do alarme usando um potenciômetro.  
- **Integração IoT:** Adicionar um módulo Wi-Fi (como ESP8266) para notificações remotas.  
- **Interface Visual:** Conectar um display LCD para mostrar mensagens como "Hora do medicamento!".  

---

## Referências

1. [Documentação do Arduino](https://docs.arduino.cc/language-reference/pt/)

2. [TinkerCad](https://www.tinkercad.com)

---