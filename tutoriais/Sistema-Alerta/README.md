# Sistema de Alerta com Arduino Mega

**Descrição:** Criação de um circuito utilizando Arduino Mega para indicar um estado de socorro de um paciente, por meio de uma botão.

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
O princípio deste circuito está na possibilidade de acionar uma equipe médica o mais rapido possível. Assim caso ocorra algum acidente como queda, piora repentina de algum sintoma e entre outros incidentes o paciente pode ligeiramente acionar o socorro. Dessa maneira, como se trata de um circuito simples pode ser facilmente instalado em casa de pessoas que necessitam de supervisionamento.

---

## Requisitos

### Hardware

- **Placa**: Arduino Mega;
- **Sensores**: Botão;
- **Atuadores**: Dois Led's (Verde: Estado Normal; Vermelho: Estado Emergência);
- **Outros componentes**: Protoboard(fins educacionais), 5 resistores(3 de 330ohms e 2 de 1kohms), jumpers, 1 Lcd, cabo usb.

### Software

- **Linguagens**: C para Arduino via Arduino IDE;
- **IDE**: Arduino IDE, Tinkercad(Opcional);
- **Bibliotecas**: LiquidCrystal(Lcd).

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Por meio do link (https://www.arduino.cc/en/software) faça o download software que usaremos para programar a placa;
- **Bibliotecas**: Como instalar a biblioteca necessária:
1. Após instalar o Arduino IDE procure por:
  
  <img src="Caminho-Biblioteca.png" alt="caminho-biblioteca-manager" />

2. Na área de texto digite "LiquidCrystal" e instale a que está escrito by Arduino;

### Passo 2: Configuração das Placas

- **Arduino**: Passos para configurar a placa e selecionar a porta correta na IDE:
1. Conecte o arduino no computador via cabo usb;
2. Clique em:

   <img src="Caminho-Selecionar-Port.png" alt="caminho-biblioteca-manager" />
3. Clique em Select other board and port;
4. Selecione a board Arduino Mega or Mega 2560;
5. Por fim seleciona a Port.

---

## Montagem do Circuito

- Para montar o circuito será necessário muita atenção ao manusear os cabos, se atente as portas e siga a imagem abaixo:

<img src="Caminho-Montagem-Circuito.png" alt="caminho-montagem-circuito" />

---

## Programação

### Passo 1: Configuração do Lcd
- Com o circuito montado, vamos configurar o Lcd no Arduino IDE:
```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
```

### Passo 2: Lógica do Sistema de Alerta
- Após configurar o Lcd, vamos adicionar a lógica para o funcionamento do sistema 
```cpp
#define LedVerm 2
#define LedVerd 3
#define BotAlert 10

int bot = 0;
int cont = 0;

void lerBot()
{
  bot = digitalRead(BotAlert);
}

void ligaVerd()
{
  digitalWrite(LedVerd, HIGH);
}

void desligaVerd()
{
  digitalWrite (LedVerd,LOW);
}

void PiscaVerm()
{
  digitalWrite(LedVerm, HIGH);
  delay(100);
  digitalWrite(LedVerm,LOW);
}

void Padrao()
{
  lcd.setCursor(3,0);
  lcd.print("Sistema em:");
  lcd.setCursor(2,1);
  lcd.print("Estado Normal");
  ligaVerd();
}

void Alerta()
{
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("ALERTA!!!!!!!");
  PiscaVerm();
  delay(200);
  lcd.clear();
}
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  delay(500);
  pinMode(LedVerm, OUTPUT);
  pinMode(LedVerd, OUTPUT);
  pinMode(BotAlert, INPUT);
}

void loop()
{
  cont = 0;
  lerBot();
  if (bot == HIGH)
  {
    desligaVerd();
    delay(400);
    for(cont;cont <= 5; cont++){
      Alerta();
      delay(400);
    }
  }else {
    Padrao();
  }
}
```
---

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

1. **Testando Atuadores**: Verifique o funcionamento dos led's, vermelho deve ligar apenas ao pressionar o botão e o verde deve ficar ligado até o botão ser pressionado.
2. **Validação dos Sensores**: Confirme que ao apertar o botão, ligue o led vermelho e mude a mensagem do lcd.
3. **Estado Normal**: Verifique se após um intervalo de tempo a mensagem do lcd volte ao estado normal e ligue o led verde. 

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Modulo ESP32 para comunicação WIFI com algum dispositivo.
- Ao invés do botão, optar por outros sensores como de temperatura(DHT11), de gás(MQ-2,MQ-7) ou até sensores de queda.
- .

---

## Referências

Liste todas as referências e links úteis para guias, bibliotecas, e materiais adicionais que ajudem a complementar o tutorial.
1. https://www.tinkercad.com/things/1unuX2OeU4X
2. https://docs.arduino.cc/libraries/liquidcrystal/
3. https://www.arduino.cc/en/software
   
---
