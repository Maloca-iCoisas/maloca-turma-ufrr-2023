# Jogo "Memorize a sequência!" para estímulo mental em crianças e idosos
**Descrição:** O seguinte tutorial tem o intuito de desenvolver e propor um protótipo de jogo da memória para estimular áreas do cérebro de crianças e idosos, principalmente para aquelas com algum tipo de problema cognitivo, e retardar o declínio cognitivo.  

![circuito em funcionamento](https://github.com/user-attachments/assets/e17256e3-50fd-4887-aab7-3ab4d5735ee1)


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
</br>

# Introdução
<p align="justify">O declínio cognitivo em humanos é um processo natural e inevitável, podendo causar consequências irreparáveis. O esquecimento de coisas bobas, como escovar o dente, amarrar os cadarços, esquecer o rosto de alguém que ama. A cognição mental é responsável não somente pela memória, mas também pela atenção, concentração, raciocínio lógico e comunicação.  

  <p align="justify">Quanto ao ensino escolar, o estímulo cognitivo em crianças cria um processo de desenvolvimento de maior atenção, raciocínio, autorregulação, controle emocional e consequentemente influenciando suas habilidades intelectuais futuras.  
  
  <p align="justify">Por isso, a inserção de jogos como o desenvolvido neste tutorial, é essencial no cotidiano desses públicos, para que exercitem essas habilidades e garantem uma melhor qualidade de vida de modo geral e interação com o mundo.

---

</br>

## Requisitos
### Hardware

- **Placa:** Arduino
- **Sensores:** Não se aplica
- **Atuadores:** Botões, LEDs, potênciometro para brilho do LCD
- **Outros componentes:** Resistores de 220ohm, display LCD, protoboard, fios jumpers e fonte de alimentação
- A quantidade de botões, LEDs, resistores e tipo de LCD podem variar de acordo com a preferência.


### Software
- **Linguagens:** C/C++ para Arduino
- **IDE:** Arduino IDE
- **Bibliotecas:** <LiquidCrystal.h> para funcionamento do display LCD

---
</br>

## Configuração do Ambiente

### Passo 1: Instalação do Software

**No Arduino IDE:**
  1. Através do site de download do Arduino (https://www.arduino.cc/en/software), selecione o arquivo de acordo com seu sistema operacional.
  2. Instale normalmente e abra-o para as configurações do projeto.

  ![config_ide1](https://github.com/user-attachments/assets/8b686755-e429-45bc-90f6-f73c3100f95d)

</br>

### Passo 2: Configuração das Placas
  1. Na tela inicial do Arduino IDE, selecione “Select Board” e depois “Select other board and port” para selecionar a placa a ser utilizada.
  2. No campo “Boards”, digite a placa a ser utilizada, no nosso caso será o Arduino UNO. Depois de selecionar, clique em “OK” no canto inferior direito.

  ![config_ide2](https://github.com/user-attachments/assets/d0c578a6-28b9-4abc-ab08-983ecc372637)


---
</br>

## Montagem do Circuito

Para montar o circuito, podemos utilizar a plataforma Tinkercad, como modo de testar e adaptar conforme necessário.  
Para esse projeto, serão utilizados um display LCD 16x2 e 3 botões com 4 terminais para 3 LEDs correspondentes.   
Siga os passos seguintes:

**• Alimentação e aterramento do circuito**
  1. Conecte o pino GND do Arduino na linha de alimentação negativa (linha preta) do protoboard. O pino GND funciona como terra para todo o circuito, enquanto o pino de 5V serve como fonte de energia;
  2. Faça o mesmo com o pino 5V do Arduino e conecte na linha de alimentação positiva (linha vermelha).

**• Conectando os botões de interação**
  1. Conecte o terminal 1a de cada botão em uma porta digital do Arduino;
  2.  Conecte o terminal 2a de cada botão no GND da placa;
  3. No circuito realizado para o tutorial, os botões estão conectados nos pinos D11, D12 e D13, assim como no GND, respectivamente.
  
**• Conectando os LEDs**
  1. Conecte o catodo de cada LED (lado negativo) em um resistor de 220ohm e ligue ao GND da placa;
  2. Conecte o anodo (lado positivo) de cada LED em um porta digital da placa;
  3. No circuito montado para o tutorial, os LEDs estão, cada um, conectados aos pinos D8, D9 e D10, assim como no GND, respectivamente.
     
**• Conectando o LED**
  1. Conecte o catodo do LED (lado negativo) no GND da placa;
  2. O anodo (lado positivo) do LED deve ser conectado com o resistor de 100kOhm a uma porta digital de sua preferência do Arduino.

**• Conectando o display LCD 16x2 e o potenciômetro:**
  1. Conecte o terminal 1 do potenciômetro ao VCC da placa/protoboard e o terminal 2 ao GND.
  
*Em relação aos pinos do display:*
  1. Conecte o pino GND (solo) no GND da placa ou protoboard;
  2. O pino VCC (potência) servirá como alimentação e deve ser conectado ao pino de 3.3V da placa ou protoboard;
  3. O pino V0 (contraste) determina o contraste das informações a serem exibidas em relação ao fundo (backlight) do display. Ele deve ser conectado ao pino central do potenciômetro.
  4. Conecte o pino RS (seleção de registro) em uma portal digital da placa, como por exemplo a porta D7
  5. Assim como o pino RS, conecte o pino E (ativar) em um portal digital, como exemplo a porta D6
  6. Os pinos DB4, DB5, DB6 e DB7 devem ser conectados às portas digitais da placa. D5, D4, D3 e D2 são exemplos.
  7. Conecte o pino LED (anodo) em um resistor de 220ohm e ligue ao VCC da placa/protoboard
  8. O pino LED (catodo) pode ser conectado diretamente ao GND da placa

![esquema de conexão do circuito](https://github.com/user-attachments/assets/de5e2906-db92-477e-b25f-306a012f56a1)

---
</br>

## Programação
### Passo 1: Configuração dos sensores, atuadores e bibliotecas

***Definição do pinos a serem usados***

```c
#include <LiquidCrystal.h>  //Biblioteca usada para funcionamento do display LCD

#define NUM_LEDS 3
#define NUM_BUTTONS 3  //Definição da quantidade de atuadores a serem utilizados

int ledPins[NUM_LEDS] = {8, 9, 10};  // Pinos dos LEDs
int buttonPins[NUM_BUTTONS] = {11, 12, 13};  // Pinos dos botões
int sequence[100]; // Máximo de 100 passos na sequência
int userInput[100];
int sequenceLength = 1;
int step = 0;
bool playerTurn = false;

LiquidCrystal lcd(7, 6, 2, 3, 4, 5);  // Endereço dos pinos do display

void setup() {
    Serial.begin(115200);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Iniciando...");  //Mensagem de inicialização

    for (int i = 0; i < NUM_LEDS; i++) { //Define os botões e LEDs como saída
        pinMode(ledPins[i], OUTPUT);
    }
    for (int i = 0; i < NUM_BUTTONS; i++) {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }

    randomSeed(analogRead(0));
    generateSequence();
}
```

### Passo 2: Processamento e Lógica de Alerta

**Lógica utilizada para deteccção, sendo cabível ajustes conforme necessidade**

```c
void loop() {
    if (playerTurn) {
        checkPlayerInput();
    }
}

void generateSequence() {  //Função que gera sequências aleatórias de acionamento dos LEDs
    for (int i = 0; i < 100; i++) {
        sequence[i] = random(NUM_LEDS);
    }
}

void playSequence() {  //Função que exibe a sequência gerada pela função “generateSequence”
    playerTurn = false;
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Memorize");
  	lcd.setCursor(0, 1);
    lcd.print("a sequencia!");

    for (int i = 0; i < sequenceLength; i++) {
      	delay(3000);
        digitalWrite(ledPins[sequence[i]], HIGH);
        delay(500);
        digitalWrite(ledPins[sequence[i]], LOW);
        delay(250);
    }
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sua vez!");
    playerTurn = true;
    step = 0;
}

void checkPlayerInput() {  //Função que verifica se a sequência inserida pelo usuário corresponde a sequência previamente exibida.
    for (int i = 0; i < NUM_BUTTONS; i++) {
        if (digitalRead(buttonPins[i]) == LOW) {
            userInput[step] = i;
            digitalWrite(ledPins[i], HIGH);
            delay(300);
            digitalWrite(ledPins[i], LOW);

            if (userInput[step] != sequence[step]) { //Condição que reinicia o jogo caso o usuário erre a sequência estabelecida
                Serial.println("Você errou! Reiniciando...");
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Você errou!");
                lcd.setCursor(0, 1);
                lcd.print("Reiniciando...");
                delay(2000);
                sequenceLength = 1;
                generateSequence();
                playSequence();
                return;
            }

            step++; //Adiciona mais uma variável na sequência de LEDs, conforme o usuário acerta
            if (step == sequenceLength) {
                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Acertou!");
                delay(1000);
                sequenceLength++;
                playSequence();
            }
        }
    }
}
```

---
</br>

## Teste e Validação

**1. Ligações entre os atuadores e a placa:** Certifique-se que todas ligações entre os atuadores (LEDs, botões, resistores, display LCD) e a placa estejam devidamente no lugares corretos para evitar transtornos, como queimas ou mal funcionamento. As plataformas Tinkercad ou Wokwi podem ser utilizadas para uma primeira modelagem e simulação do sistema;
  
**2. Verificação dos botões e LEDs:** Certifique-se que na seção “void setup” do código, os atuadores estão configurados conforme as conexões na placa. Verifique se cada botão aciona cada LED associado, sem delay. Isso pode ser ajustado no código;
 
**3. Verificação do display LCD:** Atente-se sobre as conexões do display à placa Arduino e ao código configurado. Ajuste o contraste pelo potenciômetro para melhorar o conforto visual e leitura das informações;
 
**4. Funcionalidades do sistema:** Em um primeiro teste, verifique se:
- As mensagens estão sendo exibidas corretamente, sem erros ortográficos;
- A sequência gerada pelo sistema e a verificação estão sendo, de fato, correspondentes à etapa de interação com o usuário, nos cenários onde o jogo avança (o usuário acerta) e o jogo reinicia (o usuário erra);
- A interação entre os LEDs e os botões estão sendo realizados de maneira esperada.
  
**5. Testes iniciais:** Depois das etapas acima, faça os primeiros testes e verifique se o sistema está sendo executado conforme esperado. Observe possíveis erros e ajuste caso necessário.

---
</br>

## Expansões e Melhorias

- Uso de módulos de comunicação Wi-Fi para enviar a quantidade de vezes que o usuário errou ou avançou na sequência
- Uso de mais LEDs para aumentar a dificuldade e dinamismo
- Uso de buzzers para aumentar estímulos e dificuldade
- Condições específicas como idosos com Alzheimer e crianças com autismo, podem ajudar a melhorar o sistema a ser mais específico e inclusivo nessas situações.

---
</br>

## Referências

Referências utilizadas para construção do projeto:

- [O uso de jogos cognitivos no contexto escolar: contribuições às funções executivas](https://www.scielo.br/j/pee/a/FNqKBGyKTrFJDzFvH8mZTkG/)
- [Declínio cognitivo em idosos: Conheça os fatores de risco](https://priscilapisoligeriatra.com.br/declinio-cognitivo-em-idosos/)
- [Guia Completo do Display LCD - Arduino - Blog Eletrogate](https://blog.eletrogate.com/guia-completo-do-display-lcd-arduino/)
- [UNO R3 | Arduino Documentation](https://docs.arduino.cc/hardware/uno-rev3/)
