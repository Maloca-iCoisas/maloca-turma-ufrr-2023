# Estação meteorológica com feedback ao smartphone

**Descrição:** Neste tutorial, iremos desenvolver uma estação metoerológica utilizando o arduino uno, para então enviar essas informações ao smartphone dos pacientes. 

---

## Índice

1. [Introdução](#introdução)
2. [Requisitos](#requisitos)
3. [Configuração do Ambiente](#configuração-do-ambiente)
4. [Montagem do Circuito](#montagem-do-circuito)
5. [Programação](#programação)
6. [Expansões e Melhorias](#expansões-e-melhorias)
7. [Referências](#referências)

---

## Introdução

Este projeto foi desenvolvido para auxiliar pacientes sensíveis a mudanças climáticas sutis, necessitando de um ambiente de clima mais controlado, visando isso os dados analisadas pela estação meteorológica são enviadas ao celular do usuário, facilitando o acesso a informação. 

---

## Requisitos

### Hardware

- 1 Sensor DHT22
- 1 Módulo Bluetooth HC-05
- 1 Arduino Uno
- 1 Protoboard
- 1 Resistor 1K Ohm
- 1 Resistor 2K Ohm
- 1 Resistor 10K Ohm
- 1 Potenciômetro 10K Ohm
- 1 Display LCD 16×2

### Software

- **Linguagens**: C para Arduino 
- **IDE**: Arduino IDE
- **Bibliotecas**: Necessário importar as bibliotecas do DHT (DHT sensor library) e LCD (LiquidCrystal)

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Acessar o Website www.arduino.cc/en/software e instalar o IDE do Arduino para o sistema operacional de seu computador, no caso deste exemplo, Windows 10.

## Montagem do Circuito
 
![circuito-completo-2-1](https://github.com/user-attachments/assets/24f00f22-fb4d-4b48-a387-01fa42a5d33f)



## Programação

### Passo 1: Código no Arduino IDE

Feita a instalação da IDE e das bibliotecas necessárias, compile e grave o código abaixo, lembrando de remover as conexões dos pinos TX e RX do Arduino:

**Código:**

```cpp
// Inclusão das bibliotecas do sensor DHT22 e Do display LCD
#include &lt;LiquidCrystal.h&gt;
#include &lt;DHT.h&gt;

// Define o pino 2 do arduino como o do sensor DHT22
#define DHT_PIN 2

// Define o modelo do sensor DHT
#define DHTTYPE DHT22

// Define os pinos a serem usados pelo display LCD
#define RS 12
#define EN 11
#define D4  4
#define D5  5
#define D6  6
#define D7  7

// Define um parâmetro com valor 5000
#define INTERVALO 5000

// Cria um objeto para o sensor DHT22 e para o DIsplay LCD
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);
DHT dht(DHT_PIN, DHTTYPE);

// Função executada apenas uma vez durante o funcionamento
void setup() {
  // Inicializa a serial do arduino e printa a mensagem
  Serial.begin(9600);
  Serial.println("INICIANDO SISTEMA");
  dht.begin();

  // Inicia o Display e limpa todos os caracteres
  lcd.begin(16, 2);
  lcd.clear();

  // Posiciona o ponteiro na segunda coluna, primeira linha do display
  lcd.setCursor(2, 0); 
  
  // Apresenta a mensagem no display LCD.
  lcd.print("INIT SYSTEM"); 
  // Espera por 3 segundos 
  delay(3000);
}

//Função que fica em loop durante a execução do programa
void loop() {

  // Cria variáveis que irão receber os dados do sensor
  float h = 0, t = 0, f = 0;

  // Recebe a umidade
  h = dht.readHumidity();
  // Recebe a temperatura em graus Celsius
  t = dht.readTemperature();
  // Fórmula para converter a temperatura para graus Farenheit
  f = dht.readTemperature(true);

  // Lógica para eliminar resultados indesejados
  if(isnan(h) || isnan(t) || t == 0 || h == 0){
    Serial.println(F("Falha na leitura do sensor"));
  }
  // Se estiver tudo ok com a leitura, transmite os dados via bluetooth
  else{
    // Temperatura
    Serial.print(t);
    Serial.print(",");

    // Umidade
    Serial.print(h);
    Serial.print(",");

    // Temperatura em Farenheit
    Serial.print(f);
    Serial.print(",");
    Serial.println();

    // Exibe as informações no display LCD
    lcd.clear();
    lcd.setCursor(2, 0); 
    lcd.print("MONITORANDO");  
    lcd.setCursor(0, 1); 
    lcd.print(t);
    lcd.print("C  ");
    lcd.print(h);
    lcd.print("%RH  ");
  }
  // Espera o intervalo definido para fazer a próxima leitura
  delay(INTERVALO);  
}
```

### Passo 2: Conectar ao smartphone

Neste projeto utilizaremos o aplicativo **DHT11 sensor data with bluetooth** encontrado na Google play store. Instalado o aplicativo, o usuário deve parear o bluetooth do celular com a estação meteorológica através do aplicativo. Feita a conexão o aplicativo será atualizado com novas informações do Arduino a cada 5 segundos, mostrando um relatório do ambiente.

![graficos-app-2-1](https://github.com/user-attachments/assets/dc8bfbac-86fc-4ba1-9491-043a139579d2)


---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Enviar dados pela nuvem.
- Integrar um sistema de notificações personalizadas, onde o paciente delimita um espaço onde o clima é favorável para ele, e caso contrário receba um alerta do sistema.

---

## Referências

https://flaviobabos.com.br/estacao-meteorologica-arduino/
https://play.google.com/store/apps
https://www.arduino.cc/en/software
