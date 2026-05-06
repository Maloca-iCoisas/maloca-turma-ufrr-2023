# Dispensador Automático de Medicamentos com Alerta e LCD  

**Descrição:**  
Neste tutorial, vamos criar um **Dispensador Automático de Medicamentos** utilizando um Arduino Uno, um **servo motor**, um botão, um **buzzer** e um LCD 16x2. O sistema abre o compartimento do medicamento em intervalos de tempo programados, alertando o usuário com um som (buzzer) e exibindo mensagens no LCD. Após o medicamento ser retirado, o compartimento é fechado ao pressionar o botão.

Este projeto é ideal para aplicações na área da saúde, facilitando a administração controlada de medicamentos para idosos, pacientes crônicos ou em recuperação.

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

O **Dispensador Automático de Medicamentos** utiliza um servo motor para abrir o compartimento onde os medicamentos são armazenados. Um alerta sonoro (buzzer) avisa o usuário que é hora de tomar o medicamento, e o display LCD exibe mensagens com instruções. O compartimento só é fechado quando o usuário pressiona um botão, indicando que o medicamento foi retirado.

Este projeto visa melhorar a aderência ao tratamento médico e proporcionar maior autonomia para pacientes em casa ou em hospitais.

---

## Requisitos  

### Hardware  
- **Placa**: Arduino Uno  
- **Atuadores**: Servo motor, buzzer (ativo)  
- **Sensores/Entradas**: Botão (com resistor pull-up interno)  
- **Saída de Dados**: LCD 16x2  
- **Outros componentes**: Protoboard, jumpers, resistor de 220 Ω, potenciômetro  

### Software  
- **Linguagens**: C/C++ para Arduino  
- **IDE**: Arduino IDE  
- **Bibliotecas**: LiquidCrystal, Servo  

---

## Configuração do Ambiente  

### Passo 1: Instalação do Software  
- **Arduino IDE**: Baixe e instale o [Arduino IDE](https://www.arduino.cc/en/software). Pesquise Arduino IDE download no navegador, abra o link no site oficial do Arduino e baixe a versão compativel com seu sistema.  
- **Simulador TinkerCad**: Acesse o [Tinkercad](https://www.tinkercad.com/things/8zfrWpxt90U-tuto2-maloca) para simular o circuito.  

### Passo 2: Configuração das Bibliotecas  
- **LiquidCrystal**: Já inclusa no Arduino IDE.
Mas caso não venha, siga os seguintes passos: Abra o Arduino IDE, vá em tools (Ferramentas), agora clique em "Manage Libraries", pesquise por LiquidCrystal by Arduino.
- **Servo**: Biblioteca padrão da IDE para controle de servo motores.
Caso não venha a servo também, repita o mesmo processo mas pesquise por Servo.h (ou só servo).
![biblioteca_arduinoIDE_print](https://github.com/user-attachments/assets/4883a200-ac12-4d0f-b903-7641fcc1473b)


### Passo 3: Configuração das Placas

- **Arduino Uno**: Vamos utilizar o Arduino Uno, que já vem por padrão instalado no Arduino IDE. Para selecionar a placa desejada vá em "Select Board" (selecionar placa)
selecione a entrada USB que vai usar, e por fim selecione o Arduino Uno.

---

## Montagem do Circuito  

### Componentes e Conexões  

#### **Servo Motor**  
- **Sinal** → Pino **9**  
- **VCC** → 5V  
- **GND** → GND  

#### **Botão**  
- **Pino** → Pino **7** (INPUT_PULLUP)  
- **GND** → GND  

#### **Buzzer**  
- **Positivo** → Pino **8**  
- **Negativo** → GND  

#### **LCD 16x2**  
- **RS** → Pino 12
  (Registro seletor, usado para escolher entre comandos ou dados que o LCD exibe)
- **E** → Pino 11
  (Habilita a comunicação entre o Arduino e o LCD, controla a transmissão de dados)
- **D4** → Pino 5
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D5** → Pino 4
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D6** → Pino 3
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D7** → Pino 2
  (Pino de dados, utilizado para enviar informações para o LCD)
- **VSS** → GND
  (Conecta o terra do LCD ao terra do Arduino)
- **VDD** → 5V
  (Conecta o terra do LCD ao terra do Arduino)
- **V0** → Potenciômetro (ajuste de contraste)  
  (Usado para ajustar o contraste do LCD)

  ### Alimentação
- O circuito deve ser alimentado através do Arduino (USB ou fonte externa compatível).

![image](https://github.com/user-attachments/assets/5b580eb9-e6d9-4bcc-b5b4-7d0904568052)
  ## Montagem no Simulador Tinkercad
- Você pode montar o circuito em um simulador como o [Tinkercad](https://www.tinkercad.com/) para testes virtuais antes da montagem física.
---

## Programação  

### Passo 1: Simulação

Antes de implementar o circuito fisicamente, você pode testar a simulação do projeto no Tinkercad. Abaixo está o link para a simulação, onde você pode verificar como o circuito e o código interagem.

**Simulação no Tinkercad:**  
[Simulação do Projeto no Tinkercad](https://www.tinkercad.com/things/8zfrWpxt90U-tuto2-maloca)

Clique no link para acessar a simulação e verificar o funcionamento do circuito e do código.

### Passo 2: Código para o Dispensador Automático  

Copie e cole o código abaixo na **Arduino IDE** e faça o upload para a placa.  

```cpp
#include <LiquidCrystal.h>
#include <Servo.h>

// Configuração do LCD (pinos RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pinos dos componentes
#define SERVO_PIN 9    // Pino do servo motor
#define BUTTON_PIN 7   // Pino do botão
#define LED_PIN 6      // Pino do LED verde
#define BUZZER_PIN 8   // Pino do buzzer (novo)

// Inicialização do servo motor
Servo servo;

// Variáveis de controle
bool medicationDispensed = false;  // Indica se o compartimento foi aberto
bool buttonPressed = false;       // Indica se o botão foi pressionado (transição detectada)
unsigned long lastDispenseTime = 0; // Armazena o tempo da última dispensação
const unsigned long dispenseInterval = 10000; // Intervalo de 10 segundos

// Estado atual e anterior do botão
int lastButtonState = HIGH;

void setup() {
  // Configuração dos pinos
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Botão com pull-up interno
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT); // Configura buzzer
  digitalWrite(LED_PIN, LOW); // LED começa apagado
  digitalWrite(BUZZER_PIN, LOW); // Buzzer começa desligado

  // Configuração do servo motor
  servo.attach(SERVO_PIN);
  servo.write(0); // Servo na posição inicial (fechado)

  // Inicialização do LCD
  lcd.begin(16, 2); // Configura LCD 16x2
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();
  lcd.print("Pronto!");

  // Inicialização do Serial (opcional para depuração)
  Serial.begin(9600);
  Serial.println("Sistema inicializado!");
}

void loop() {
  // Verifica se é hora de dispensar o medicamento (a cada 10 segundos)
  unsigned long currentMillis = millis();
  if ((currentMillis - lastDispenseTime >= dispenseInterval) && !medicationDispensed) {
    dispenseMedication();
    medicationDispensed = true;
    lastDispenseTime = currentMillis; // Atualiza o tempo da última dispensação
  }

  // Verifica o botão para fechar o compartimento
  if (medicationDispensed) {
    checkButton(); // Função que gerencia o estado do botão
  }

  delay(50); // Pequeno atraso para evitar polling excessivo
}

// Função para dispensar o medicamento
void dispenseMedication() {
  Serial.println("Dispensando medicamento...");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Medicamento");
  lcd.setCursor(0, 1);
  lcd.print("Disponivel!");
  
  servo.write(90); // Abre o compartimento
  Serial.println("Compartimento aberto.");

  // Alerta sonoro com buzzer
  for (int i = 0; i < 3; i++) { // 3 bipes
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200); // Bipe curto
    digitalWrite(BUZZER_PIN, LOW);
    delay(200);
  }
}

// Função para gerenciar o estado do botão
void checkButton() {
  int currentButtonState = digitalRead(BUTTON_PIN);

  // Detecta a transição do botão (HIGH -> LOW)
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    buttonPressed = true;
  }

  // Se o botão foi pressionado, execute a ação de fechamento
  if (buttonPressed) {
    handleButtonPress();
    buttonPressed = false; // Reseta o estado do botão
  }

  // Atualiza o estado anterior do botão
  lastButtonState = currentButtonState;
}

// Função para lidar com o botão
void handleButtonPress() {
  digitalWrite(LED_PIN, HIGH); // Acende o LED verde
  Serial.println("Medicamento retirado!");
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Compartimento");
  lcd.setCursor(0, 1);
  lcd.print("fechando...");
  
  delay(2000); // Mantém o LED aceso por 2 segundos
  
  servo.write(0); // Fecha o compartimento
  Serial.println("Compartimento fechado.");
  
  digitalWrite(LED_PIN, LOW); // Apaga o LED

  // Reseta o estado para o próximo ciclo
  medicationDispensed = false;
}
```
---

### Passo 3: Processamento e Lógica de Alerta  
- **Aquisição de Dados**:  
  O sistema utiliza a função `millis()` para contar o tempo decorrido desde o início do programa e determinar o intervalo para dispensar os medicamentos. Quando o tempo programado é atingido, o servo motor abre o compartimento e um alerta sonoro é acionado usando o buzzer. O LCD exibe mensagens informativas para o usuário.  

- **Lógica de Funcionamento**:  
  1. **Tempo de Dispensação**:  
     A cada **10 segundos** (valor definido pela variável `dispenseInterval`), o servo motor se move para **90°**, abrindo o compartimento do medicamento.  
  2. **Alerta Sonoro**:  
     O buzzer emite **3 bipes curtos** para notificar que o medicamento está disponível.  
  3. **Fechamento Manual**:  
     Após pressionar o botão, o servo retorna para **0°**, fechando o compartimento. O LED verde acende momentaneamente e o LCD exibe a mensagem **"Compartimento fechando..."**.  

---

## Teste e Validação  

Para garantir o bom funcionamento do **Dispensador Automático de Medicamentos**, é necessário realizar os seguintes testes:  

1. **Abertura Automática do Compartimento**:  
   - **Objetivo**: Verificar se o servo motor abre o compartimento no intervalo correto (10 segundos).  
   - **Procedimento**:  
     - Ligue o sistema.  
     - Aguarde **10 segundos** e observe se o servo motor se move para a posição **90°**, abrindo o compartimento.  
     - Verifique também se o buzzer emite **3 bipes** e o LCD exibe a mensagem **"Medicamento Disponível!"**.  

2. **Confirmação pelo Botão**:  
   - **Objetivo**: Validar o fechamento do compartimento ao pressionar o botão.  
   - **Procedimento**:  
     - Após o compartimento ser aberto, pressione o botão conectado ao pino **7**.  
     - O servo motor deve retornar para a posição **0°**, fechando o compartimento.  
     - O LED verde deve acender brevemente, e o LCD deve exibir **"Compartimento fechando..."**.  

3. **Monitor Serial**:  
   - **Objetivo**: Conferir as mensagens de status no **Monitor Serial**.  
   - **Procedimento**:  
     - Abra o **Monitor Serial** na IDE do Arduino com a taxa de **9600 bauds**.  
     - Verifique as mensagens exibidas:  
       - **"Dispensando medicamento..."** quando o compartimento abre.  
       - **"Medicamento retirado!"** e **"Compartimento fechado."** quando o botão é pressionado.  

---

## Expansões e Melhorias  

Sugestões para expandir e melhorar o **Dispensador Automático de Medicamentos**:

1. **Configuração de Horários Específicos**:  
   - **Objetivo**: Permitir que os medicamentos sejam dispensados em horários programados (ex.: manhã, tarde e noite).  
   - **Como**: Utilize um módulo **RTC (Real Time Clock)** para programar horários específicos para a dispensação dos medicamentos.  

2. **Notificação Remota via Wi-Fi**:  
   - **Objetivo**: Alertar o usuário ou cuidadores remotamente quando o medicamento estiver disponível.  
   - **Como**: Utilize um módulo **ESP8266** ou **ESP32** para enviar notificações para um aplicativo móvel ou dashboard na nuvem, como **Blynk** ou **ThingSpeak**.  

3. **Integração com Sensores de Presença**:  
   - **Objetivo**: Garantir que o medicamento foi retirado.  
   - **Como**: Adicione um sensor de presença (como um **LDR** ou **sensor infravermelho**) para detectar se o compartimento está vazio após a abertura.  

4. **Alerta Sonoro Personalizado**:  
   - **Objetivo**: Tornar o alerta sonoro mais específico.  
   - **Como**: Utilize tons diferenciados com um buzzer passivo para criar um padrão de som único e identificar facilmente o alerta do dispensador.  

5. **Tela Touch ou Botões para Configuração**:  
   - **Objetivo**: Facilitar a configuração dos horários e intervalos sem precisar alterar o código.  
   - **Como**: Adicione um **teclado matricial (Keypad)** ou uma tela touch para ajustar o intervalo diretamente no sistema.  

---

## Como o Tempo Impacta a Dispensação  

No **Dispensador Automático de Medicamentos**, a lógica baseada no tempo controla a abertura do compartimento no intervalo configurado. A função `millis()` é usada para medir o tempo em milissegundos desde que o Arduino iniciou, garantindo precisão sem bloquear outras operações no loop principal.  

- **Intervalo Definido**: O valor de **10 segundos** pode ser ajustado conforme a necessidade.  
- **Abertura Automática**: O servo abre o compartimento quando o tempo programado é atingido.  
- **Fechamento Manual**: O botão é utilizado para confirmar a retirada do medicamento, garantindo que o servo feche o compartimento apenas após a interação do usuário.  

Esse sistema garante uma administração controlada dos medicamentos e pode ser facilmente expandido para incluir funcionalidades mais avançadas, como monitoramento remoto e integração com sistemas de saúde.  

---

## Referências  

Lista de referências:

- **Servo Motor com Arduino**: [Documentação da Biblioteca Servo](https://www.arduino.cc/en/Reference/Servo)  
- **Buzzer com Arduino**: [Exemplo de Alerta Sonoro](https://www.youtube.com/watch?v=QEIl2Nxot5M)  
- **RTC (Real Time Clock)**: [Guia para Relógios RTC](https://www.youtube.com/watch?v=abc123rtc)
- **COMO PROGRAMAR O SERVO MOTOR NO ARDUINO?**: [Guia Servo motor com arduino](https://www.youtube.com/watch?v=Pw9rECny0Ss)
- **Como Programar Servomotores no seu Projeto**: [Video Servo motor](https://www.youtube.com/watch?v=cnMTA9PgGj8)

---

Com este circuito, garantimos que os medicamentos sejam dispensados de maneira **automática** e **controlada**, facilitando a vida de pacientes e cuidadores! 🚀  
