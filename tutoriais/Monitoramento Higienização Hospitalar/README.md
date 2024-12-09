# Monitoramento de higienização das mãos  
**Descrição:** Neste tutorial, vamos desenvolver um sistema de monitoramento do uso de estações de higienização em ambiente hospitalar usando ESP32 com sensor de movimento HCSR04.

—
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
O monitoramento do uso de dispensers de sabão em um ambiente hospitalar ou clínico tem a utilidade de averiguar e informar aos profissionais as condições ambientais que em muitos tratamentos deve ser controlada. O monitoramento deve ser informado através de um dispositivo. 
O sistema de monitoramento utiliza um ESP32 e um sensor de presença HCSR04 para detectar quando alguém se aproxima do dispenser e o utiliza, fazendo a contagem do tempo e quantidade de usos caso o tempo seja suficiente para uma lavagem recomendada, cujo tempo mínimo é 20 segundos.

---
## Requisitos
### Hardware
Sensores: Capturam dados de proximidade e uso da estação. 
Microcontrolador (ESP32): Recebe os dados e os transmite via Wi-Fi. 

- **Placa**: Arduino.
- **Sensores**: Sensor PIR e Sensor HC-SR04.
- **Outros componentes**: Jumpers, resistores, buzzer e led, fonte de alimentação (bateria ou usb). 

### Software
Servidor Central: Armazena os dados e gera relatórios. 
Dashboard: Visualização em tempo real dos dados. 
- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.
- **Bibliotecas**: `DHT sensor library’.

---

## Configuração do Ambiente
### Passo 1: Instalação do Software

- Arduino IDE: Baixe e instale o Arduino IDE a partir do https://www.arduino.cc/en/software.

### Passo 2: Configuração da Placa e Porta
Conecte o Arduino ao computador via USB.
No Arduino IDE, vá em Ferramentas > Placa e selecione Arduino Uno.
Em Ferramentas > Porta, escolha a porta correspondente ao Arduino conectado, como mostra a imagem abaixo: 



## Montagem do Circuito

Conecte o sensor de temperatura ao Arduino conforme o esquema abaixo:

VCC do HC-SR04 ao pino 5V do Arduino.
GND do HC-SR04 ao GND do Arduino.
TRIG do HC-SR04 ao pino digital D5 do Arduino.
ECHO do HC-SR04 ao pino digital D18 do Arduino.

Use imagens ou diagramas para auxiliar a compreensão.

---

## Programação
### Passo 1: Configuração dos Sensores e Atuadores

Para medir distância e tempo:

Código em C para Arduino:

```cpp
#define TRIG_PIN 5       // Pino TRIG do HC-SR04
#define ECHO_PIN 18      // Pino ECHO do HC-SR04
#define BUZZER_PIN 2     // Pino do buzzer

const int DISTANCIA_LIMITE = 10;  // Distância em cm para considerar que há mãos próximas
const unsigned long TEMPO_MINIMO = 20000;  // Tempo mínimo em milissegundos (20 segundos)

unsigned long tempoInicio = 0;  // Armazena o tempo de início da detecção
bool detectou = false;          // Indica se a detecção começou

int contagemSucesso = 0;        // Contagem de usos que atingiram os 20 segundos
int contagemFalha = 0;          // Contagem de usos que não atingiram os 20 segundos

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);  // Monitor serial para depuração
}

void loop() {
  long duracao = medirDistancia();
  int distancia = duracao * 0.034 / 2;  // Conversão para cm

  if (distancia <= DISTANCIA_LIMITE) {
    if (!detectou) {
      // Inicia a contagem do tempo
      tempoInicio = millis();
      detectou = true;
      Serial.println("Mãos detectadas, iniciando contagem...");
    } else {
      // Verifica se o tempo mínimo foi atingido
      if (millis() - tempoInicio >= TEMPO_MINIMO) {
        Serial.println("Higienização completa!");
        digitalWrite(BUZZER_PIN, HIGH);  // Aciona o buzzer
        delay(2000);                    // Buzzer ligado por 2 segundos
        digitalWrite(BUZZER_PIN, LOW);  // Desliga o buzzer
        detectou = false;               // Reinicia o estado
        contagemSucesso++;              // Incrementa a contagem de sucesso
        Serial.print("Contagem de sucessos: ");
        Serial.println(contagemSucesso);
      }
    }
  } else {
    if (detectou) {
      // Mãos removidas antes do tempo mínimo
      Serial.println("Mãos removidas antes do tempo necessário.");
      detectou = false;             // Reinicia o estado
      contagemFalha++;              // Incrementa a contagem de falhas
      Serial.print("Contagem de falhas: ");
      Serial.println(contagemFalha);
    }
  }

  delay(100);  // Pequena pausa para estabilizar as leituras
}

// Função para medir a distância usando o HC-SR04
long medirDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  return pulseIn(ECHO_PIN, HIGH);
}
```
---
## Teste e Validação
Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Testando Sensores**: Verifique se as leituras são consistentes e corretas.
2. **Monitoramento em Tempo Real**: Teste o sistema completo em condições simuladas para garantir que funciona conforme o esperado.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adicionar comunicação Wi-Fi (ESP32) para enviar dados para uma nuvem.
- Integrar um banco de dados para registro das leituras.
- Conectar-se a uma aplicação móvel para visualização remota.

---

## Referências

- Link da simulação:  
- Documentação do Arduino: https://www.arduino.cc/.  
- Documentação do sensor HC-SR04: https://docs.arduino.cc/libraries/hcsr04-ultrasonic-sensor/  
---
