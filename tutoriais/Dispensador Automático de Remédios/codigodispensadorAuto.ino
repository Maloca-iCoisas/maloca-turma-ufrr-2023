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
