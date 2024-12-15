# Sistema de Alerta para Longos Períodos Sedentários

**Descrição:** O tutorial ensina como simular um sistema de alerta para longos períodos sedentários usando o Tinkercad. A simulação usa um botão para representar a presença de uma pessoa sentada e um temporizador no código Arduino para monitorar quanto tempo essa pessoa permanece sentada. Quando o tempo pré-definido (tempo sedentário) é atingido, um alerta (representado por um LED e um buzzer) é ativado.

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

O propósito de um projeto de "Sistema de Alerta para Longos Períodos Sedentários" no contexto da saúde é combater os efeitos negativos do sedentarismo, promovendo a conscientização e incentivando a adoção de hábitos mais ativos. O sedentarismo é um fator de risco significativo para diversas doenças crônicas não transmissíveis.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno
- **Sensores**: Como o Tinkercad não oferece simulação realista de sensores de pressão ou movimento, usamos um botão como um substituto simplificado. Pressionar o botão simula a detecção da presença (pessoa sentada), e soltá-lo simula a ausência. Para uma implementação realista, podemos usar o sensor PIR
- **Atuadores**: LED e buzzer
- **Outros componentes**: Jumpers, resistores e placa de ensaio pequena.

### Software

- **Linguagens**: C/C++ para Arduino
- **IDE**: Arduino IDE
- **Bibliotecas**: Não é necessário.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Acesse o site oficial do Arduino: www.arduino.cc/en/software
  - Selecione o sistema operacional do seu computador (Windows, macOS ou Linux).
  - Escolha a opção de download que preferir:
    - Instalador: Recomendado para a maioria dos usuários. Faz o download de um arquivo executável que instala o IDE automaticamente.
    - Arquivo ZIP: Para quem prefere instalar manualmente ou não tem permissão de administrador.
    - Windows App: Disponível na Microsoft Store.
  - 2.Instalação:
    - Execute o arquivo executável baixado (.exe).
    - Siga as instruções do instalador, aceitando os termos de licença e escolhendo o local de instalação.
    - Marque as opções para instalar drivers USB durante a instalação.
  - 3.Verificação da instalação
    - Abra o Arduino IDE.
    - Conecte sua placa Arduino ao computador com um cabo USB.
    - Vá em "Ferramentas" > "Placa" e selecione o modelo da sua placa.
    - Vá em "Ferramentas" > "Porta" e selecione a porta serial à qual sua placa está conectada.
    - Se tudo estiver correto, você verá a mensagem "Placa Arduino/Genuino Uno na porta COMX" (onde X é o número da porta) na barra de status do Arduino IDE.


### Passo 2: Configuração das Placas

- **Arduino**:
1. Conecte a placa:
  - Conecte sua placa Arduino ao computador usando um cabo USB.
  - Importante: Certifique-se de que o cabo USB esteja em boas condições e seja adequado para transferência de dados (alguns cabos só servem para carregar).
2. Abra o Arduino IDE:

  - Inicie o software Arduino IDE no seu computador.
3. Selecione a placa:

  - Vá no menu "Ferramentas" > "Placa".
  - Encontre o modelo da sua placa na lista e selecione-o.
    - Exemplo: Se você estiver usando um Arduino Uno, selecione "Arduino Uno".
    - Dica: Se você não encontrar sua placa na lista, pode ser necessário instalar o suporte para ela. Vá em "Ferramentas" > "Placa" >        "Gerenciador de Placas..." e procure pelo nome da sua placa.
4. Selecione a porta:

  - Vá no menu "Ferramentas" > "Porta".
  - Selecione a porta serial à qual sua placa Arduino está conectada.
    - Dica: A porta geralmente tem um nome como "COMX" (Windows) ou "/dev/ttyACMX" (Linux) ou "/dev/cu.usbmodemXXXX" (macOS), onde X é        um número.
    - Dica 2: Se você não tiver certeza de qual porta é a correta, desconecte a placa do computador e veja qual porta desaparece da 
      lista. Conecte a placa novamente e veja qual porta reaparece.
5. Verifique a conexão:

  - Na barra de status do Arduino IDE (parte inferior da janela), você deverá ver uma mensagem indicando a placa e a porta selecionada.
    - Exemplo: "Placa Arduino/Genuino Uno na porta COM3".
   ![IDE](https://github.com/user-attachments/assets/0b7b64c0-0a1e-40f0-836f-44f03c1cb586)



---

## Montagem do Circuito

1. Componentes Necessários no Tinkercad:

- Arduino Uno R3: A placa controladora.
- Protoboard (opcional, mas recomendado): Para facilitar as conexões.
- Botão (Pushbutton): Para simular a detecção de presença (quando pressionado, simula a pessoa sentada).
- Resistor de 10kΩ: Para o botão (resistor pull-down).
- LED (opcional): Para feedback visual do alerta.
- Buzzer (opcional): Para um alerta sonoro.
2. Montagem do Circuito:
- **Botão:**
  - Conecte um terminal do botão a um pino digital do Arduino (ex: Pino 2).
  - Conecte o outro terminal do botão a um resistor de 10kΩ.
  - Conecte a outra extremidade do resistor ao GND do Arduino.
  - Conecte um fio do mesmo terminal do botão que está conectado ao resistor para o GND do Arduino. Esta configuração é um "pull-down resistor".
- **LED:**
  - Conecte o terminal positivo (ânodo) do LED a um pino digital do Arduino (Pino 13) através de um resistor de 220Ω (para limitar a corrente e proteger o LED).
  - Conecte o terminal negativo (cátodo) do LED ao GND do Arduino.
- **Buzzer:**
  - Conecte o terminal positivo do buzzer a um pino digital do Arduino (Pino 8).
  - Conecte o terminal negativo do buzzer ao GND do Arduino.
  ![imagem2](https://github.com/user-attachments/assets/3ede1b72-8d7a-4914-b202-97051a7241e4)


**Com sensor PIR**
Para um teste realista, você pode remover o botão e adicionar o sensor PIR, lembrando que no TinkerCad apresenta falhas.
- Conexão do sensor PIR:

  - VCC: Conecte ao 5V do Arduino.
  - GND: Conecte ao GND do Arduino.
  - OUT (Sinal): Conecte ao pino digital 2 (no nosso exemplo) do Arduino.
    ![imagem1](https://github.com/user-attachments/assets/8d36b933-6f50-4844-b43c-4421de6c2304)


---

## Programação

### Passo 1: Configuração do botão e Atuadores


**C++ para Arduino UNO utilizando o botão:**

```c++
const int buttonPin = 2;    // Pino conectado ao botão
const int ledPin = 13;     // Pino conectado ao LED (opcional)
const int buzzerPin = 8;  // Pino conectado ao buzzer (opcional)

unsigned long startTime = 0; // Variável para armazenar o tempo inicial
const unsigned long sedentaryTime = 5000; // Tempo sedentário em milissegundos (ex: 5000ms = 5 segundos para teste. Ajuste para minutos no seu projeto real. Ex: 60000ms = 1 minuto, 300000ms= 5 minutos, etc).
bool isSedentary = false;    // Variável para controlar o estado sedentário

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); // Define o pino do botão como entrada com pull-up interno
  pinMode(ledPin, OUTPUT);       // Define o pino do LED como saída
  pinMode(buzzerPin, OUTPUT);    // Define o pino do buzzer como saída
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) { // Botão pressionado (simula a pessoa sentada)
    if (!isSedentary) {    // Verifica se o estado sedentário já não foi iniciado
      startTime = millis(); // Registra o tempo atual
      isSedentary = true;  // Marca como estado sedentário
      Serial.println("Iniciou tempo sedentário.");
    }
  } else {               // Botão não pressionado (pessoa se levantou)
    if (isSedentary) {      // Verifica se estava em estado sedentário
      isSedentary = false;   // Reseta o estado sedentário
      Serial.println("Tempo sedentário interrompido.");
    }
  }

  if (isSedentary && (millis() - startTime >= sedentaryTime)) {
    // Tempo sedentário atingido
    Serial.println("ALERTA: Longo período sedentário!");
    digitalWrite(ledPin, HIGH);  // Liga o LED (opcional)
    tone(buzzerPin, 1000, 500); // Toca o buzzer por 500ms (opcional)
    delay(5000); // Pequena pausa antes de checar novamente. Evita que o alerta se repita muito rapidamente.
    digitalWrite(ledPin, LOW); // Desliga o LED após o alerta.
  }
}
```

**C++ para Arduino UNO utilizando o sensor PIR:**

```c++
#define PIR_PIN 2      // Pino do sensor PIR
#define LED_PIN 13      // Pino do LED
#define BUZZER_PIN 8   // Pino do Buzzer

unsigned long previousMillis = 0;    // Armazena o tempo anterior
const long alertInterval = 10000;    // Tempo limite: 10 segundos para testes

void setup() {
  pinMode(PIR_PIN, INPUT);          // Configura o sensor PIR como entrada
  pinMode(LED_PIN, OUTPUT);         // Configura o LED como saída
  pinMode(BUZZER_PIN, OUTPUT);      // Configura o buzzer como saída
  Serial.begin(9600);               // Inicializa a comunicação serial
}

void loop() {
  int pirState = digitalRead(PIR_PIN);  // Lê o estado do sensor PIR

  if (pirState == HIGH) {   // Movimento detectado
    Serial.println("Movimento detectado! Resetando timer...");
    previousMillis = millis();       // Reseta o tempo
    digitalWrite(LED_PIN, LOW);      // Desliga o LED
    digitalWrite(BUZZER_PIN, LOW);   // Desliga o buzzer
  } else {
    // Verifica o tempo sem movimento
    if (millis() - previousMillis >= alertInterval) {
      Serial.println("Tempo limite excedido! ALERTA!");
      digitalWrite(LED_PIN, HIGH);   // Liga o LED
      digitalWrite(BUZZER_PIN, HIGH);// Liga o buzzer
    }
  }
}

```

### Passo 2: Processamento e Lógica de Alerta

- Monitoramento de Tempo Sedentário: O código rastreia quanto tempo o usuário permanece sentado (botão pressionado) e emite um alerta se o tempo exceder um determinado limite.
- Atuadores Simples: O código usa um LED e um buzzer para indicar o alerta, mas a ativação destes ocorre com base no tempo, e não em dados de um sensor externo.

---

## Teste e Validação


1. **Testando Sensores**: Verifique se ao manter pressionado o botão inicia a contagem do sedentárismo.
2. **Validação dos Atuadores**: Verifique se o Piezo Buzzer e o Led estão corretamente conectados aos pinos designados e com a polaridade adequada e se emitem sinal após 5s pressionado o botão.
3. **Monitoramento em Tempo Real**: Solte o botão e veja se a mensagem de alerta no monitor serial some.

---

## Expansões e Melhorias

1. Registro de Dados:
   - Coletar dados para análise posterior, como o tempo total sedentário por dia ou a frequência de curtas pausas.
2. Alertas Personalizados:
   - Utilizar múltiplos LEDs ou buzzers para criar padrões de alerta diferentes.
4. Comunicação Sem Fio:
   - Utilizar módulos como ESP8266 ou ESP32 para conectar o Arduino a uma rede Wi-Fi.
---

## Referências
**Circuito no TinkerCad:** https://www.tinkercad.com/things/8FClpFf9EWv-sistema-de-alerta-para-longos-periodos-sedentarios?sharecode=Zpl3WqcMFhq8bdAn2_clb2JxbfDfw27Iq9NZaWDxd3A

**Arduino IDE:** www.arduino.cc/en/software


