
# Sistema Com Arduíno Para manter a qualidade do ar para pacientes com doenças respiratórias 
## Descrição:
  - Este Tutorial irá instruir na construção de um sistema que utiliza de arduíno e sensores o qual demonstra o aviso em uma tela LCD de qualidade de ar que pode ser muito útil quando se tratando de pacientes com síndromes respiratórias agudas.Onde O mesmo indica a umidade baixa do ambiente
#:


## Índice 
1-  [Introdução](#introdução)

2-  [Requisitos](#requisitos)

3- [Configuração do ambiente](#configuração-do-ambiente)
  - [Parte de software](#parte-de-software)
  - [Montagem do circuito](#montagem-do-circuito)

4- [Programação](#programação)

5- [Teste e Validação](#teste-e-validação)

6- [Informações Adicionais](#informações-adicionais)

7-[Expansão e melhorias](#Expansão-e-melhorias)

8-[Referências](#Referências)

  
 
# Introdução
- A qualidade do ar é um fator crucial para a saúde, especialmente para indivíduos com condições respiratórias agudas, como asma, bronquite e outras doenças pulmonares. A manutenção de níveis adequados de umidade no ambiente é essencial para evitar complicações respiratórias, uma vez que o ar muito seco pode irritar as vias aéreas, dificultar a respiração e agravar os sintomas dessas doenças.

- Este tutorial tem como objetivo orientar a construção de um sistema utilizando Arduino e sensores, capaz de monitorar a umidade do ambiente e exibir alertas em uma tela LCD sempre que os níveis estiverem baixos. Essa ferramenta é de grande utilidade para a gestão da qualidade do ar em ambientes onde residem pacientes com síndromes respiratórias, contribuindo para um cuidado mais eficaz e para a prevenção de crises respiratórias.


# Requisitos 

## Hardware 
 - Arduíno uno (para mandar os comandos de print da tela e interpretar os sinais analógicos dos sensores)
-  Sensor DHT-22 (Utilizado para checar a umidade relativa do ambiente)
-  Protoboard (utilizado para faciltar as conexões entre os componentes)
-  Tela LCD 16X2 (utilizado para mandar um aviso caso haja alteração na umidade do ar )
-  Fios e cabos (para fazer as conexões entre os componentes)
-  Potenciômetro(Para regular a tela LCD)
 
## Software
- C/C++ Proprio para arduíno 
- Arduíno IDE

# Configuração-do-ambiente 
## Parte de software 
### 1° Passo 
- Fazer o download da IDE do arduíno 
### 2° Passo 
- Após a entrada no ambiente faça o download das bibliotecas: DHT sensor library by Adafuit  do sensor DHT-22 e da biblioteca Liquid Crystal  by Ada fruit que é responsável pela documentação da tela LCD
### 3° Passo  
- Digite o código que será utilizado
### 4° Passo 
- Verifique o código
### 5° Passo 
- Selecione a placa arduíno UNO e a porta correta e faça o upload do código para o arduíno
## Montagem do circuito
### 1° Passo 
- Separar os componentes necessários para a montagem do circuito nesse caso a tela LCD , o sensor DHT , o arduíno , a protoboard e um potenciômetro
### 2° Passo 
- Fazer a conexão do 5V do arduíno ao polo positivo da protoboard e o do GND do arduíno ao polo negativo da protoboard 
### 3° Passo 
- Fazer a conexão do sensor DHT-22 aos GND(GND) e ao 5V(VCC) e também a porta digital 7(SDA) do arduíno 
### 4° Passo 
- Fazer a conexão do potenciômetro o VCC no 5V , o GND no GND e o SIG no V0 da tela LCD 
### 5° Passo 
- Fazer a conexão da tela LCD onde da esquerda para direita: a porta VSS np GND , a VDD no 5V , a DV0 no SIG , RS na porta digital 12 , RW no GND , E na porta digital 11 então vai para a D4 na porta digital 5 , D5 NA PORTA DIGITAL 4 , D6 na porta digital 3 , D7 na porta digital 2 , A no 5V e K no GND 
- Idealmente Deve estar seguindo este modelo : 
![Circuito](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/sensor%20desligado%20.png)


# Programação 
## O Código utilizado foi : 
#include <DHT.h>
#include <LiquidCrystal.h> 
  
#define DHTPIN       

#define DHTTYPE DHT22   


 DHT dht(DHTPIN, DHTTYPE);




LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()  {

  // Inicializa o LCD

  lcd.begin(16, 2);

  lcd.print("Medindo...");

  // Inicializa o sensor DHT

  dht.begin();


  pinMode(A5, INPUT);
}

void loop() {

  // Lê a umidade do sensor DHT22

  float umidade = dht.readHumidity();

  // Verifica se a leitura foi bem-sucedida

  if (isnan(umidade)) {

    lcd.clear();

    lcd.print("Erro no DHT22");

    return;

  }

  // Exibe a umidade na primeira linha


  lcd.clear();

  lcd.setCursor(0, 0);

  lcd.print("Umidade: ");

  lcd.print(umidade);

  lcd.print("%");

  // Verifica se a umidade está abaixo de 50%

  if (umidade < 50) {

    lcd.setCursor(0, 1);

    lcd.print("Alerta! Umid. Baixa");

  }

  // Delay de 2 segundos antes de ler novamente

  delay(2000);
}

### Explicação do código 
-  Este código mede a umidade do ar com um sensor DHT22 e exibe os dados em um display LCD. Inicialmente, são importadas as bibliotecas necessárias para o funcionamento do sensor e do LCD. No setup, o LCD é configurado para operar no modo de 16 colunas por 2 linhas e exibe a mensagem inicial "Medindo...". O sensor DHT22 é então inicializado. No loop principal, o programa realiza a leitura da umidade através do sensor. Caso a leitura falhe, uma mensagem de erro é exibida no display. Caso contrário, a umidade medida é mostrada na primeira linha do LCD no formato "Umidade: XX%". Se o valor estiver abaixo de 50%, um alerta é exibido na segunda linha indicando "Alerta! Umid. Baixa". Após cada leitura, há um intervalo de 2 segundos antes da próxima medição.

# Teste-e-Validação 
## Testes
- Foi feito um teste antes para ver se a conexão da tela estava feita corretamente printando um "Ola Mundo"
- Também foi testado se o arduíno estava recebendo corretamente as informações do sensor printando as informações do mesmo no monitor serial
## Resultados : 
- Foi feito o teste junto do código na plataforma de simulação wokwi onde tanto com a umidade baixa quanto normal estava fazendo o print na tela LCD corretamente. 
- Para a umidade normal : 
- ![Umidade_normal](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/foto%20de%20trabalho%20de%20boa%20.png)
- Para a umidade baixa
-  ![Umidade_Baixa](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/sensor%20baixo%20%20132018.png)
-  O link do projeto no simulador : https://wokwi.com/projects/414730818955336705
###  O que foi implementado:
- Um circuito composto por sensores e arduíno que colabora para a manutenção da qualidade do ar  
### Ajudar No Tratamento:
- Voltado para a manutenção da qualidade do ar onde ajudará o tratamento de pacietes com doenças respiratórias. 
#
# Experimentos:

### Teste No Simulador :
- O teste foi feito no simulador wokwi onde foi feito um sistema em arduíno que utilizando do sensor exibe um aviso caso a umidade do ar esteja em nível alarmante. 


### Resultados dos Testes:

- A tela lcd exibe um aviso perfeitamente  
- No caso de umidade baixa : 
  ![Umidade_Baixa](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/sensor%20baixo%20%20132018.png)
- No caso de umidade normal : 
 ![Umidade_normal](https://github.com/ArthurRamos26/Tutorial_maloca/blob/06be1c565b82277954f840526d2dcec7d3d5c56e/foto%20de%20trabalho%20de%20boa%20.png)


# Expansão-e-melhorias
- Poderia ser feita a integração com o ESP-32 para comunicae-se via wi-fi em tempo real com os agentes de saúde 
- Outra melhoria seria a substituição da tela LCD por um display mais avançado 
- Para expansões poderia introduzir mais sensores para fazer a checagem não só da ummidade do ar 

# Referências
  O link do projeto no simulador : https://wokwi.com/projects/414730818955336705
  https://youtu.be/oz5OrfTWpNM?si=yB5czX8RAl4XniHK
