# Regulador de Cortinas e Persianas para Hospitais

**Descrição** Neste tutorial iremos construir um circuito para regular o quanto uma cortina pode ser aberta; Mais tarde, em aplicações futuras, queremos utilizar sensores de luminosidade para automatizar a utilização e facilitar a vida dos profissionais da saúde e dos internos do hospital.

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

A utilização de luz natural em enfermarias e UTIs promove bem-estar, acelera a recuperação, melhora o humor dos pacientes e reduz o uso de luz artificial, contribuindo para a saúde e sustentabilidade, por isso iremos montar um circuito que regula a abertura de persianas ou cortinas dessas alas.

---

## Requisitos

## Hardware
- **Placa**: Arduino Uno ou compátivel;
- **Atuadores**: Servo Motor;
- **Outros componentes**: potenciômetro, se necessário, protoboard;

## Software
- **Linguagens**: C++ para Arduino
- **IDE**: Arduino IDE

---

## Configuração do Ambiente

## Passo 1: Instalação do Software

- **Arduino IDE**: Baixe e instale o arduino IDE a partir do https://www.arduino.cc/en/software.

## Passo 2: Configuração da Placa

1. Com o software Arduino IDE aberto, conecte a placa Arduino ao computador via USB.
2. Clique no quadro “Select Board” e em seguida “Select other board and port” como mostram nas imagens abaixo:

<img src="Tutorial 1.png" alt="tela do arduino" />

<img src="Tutorial 2.png" alt="tela do arduino" />

3. Digite no quadro ou pesquise pela placa “Arduino Mega” or “Mega 2560”.
 
 <img src="Tutorial 3.png" alt="tela do arduino" />

4. Escolha o port onde a placa Arduino está conectada.

---

## Montagem do Circuito 

Para montar o circuito, siga as instruções abaixo e se preciso analise o circuito modelo da imagem:

1. Conectar o Servo Motor:
- Conecte o pino **GND** do Arduino ao pino/entrada da direita do Servo Motor, esse é o terra.
- Conecte o pino digital **~9** do Arduino ao pino/entrada da esquerda do Servo Motor, esse será o pino que envia informações ao servo motor para como e quando ele atuar
- Conecte o pino **5V** do Arduino ao pino do meio do Servo Motor, esse alimentará com energia o Servo. A fim de mais segurança ligue primeiramente no pino **3v3** do Arduino, caso o Servo não funcione, teste com resistores antes de conectar os 5V ao Servo Motor.

2. Conectar o potenciometro:
- Conecte o pino **GND** do Arduino ao pino da direita do potenciometro, esse é o terra, comum aos dois atuadores.
- Conecte o pino analógico **AO** do Arduino ao pino do meio do potenciometro.
- Conecte o pino **5V** do Arduino ao pino da esquerda do potenciometro.


<img src="Circuito 1.png" alt="circuito simulado" />

<img src="Circuito 2.png" alt="circuito simulado" />
circuito sem o protoboard

---

## Programação

## Passo 1: Configuração dos Atuadores

Definiremos a ligação dos pinos aos terminais dos atuadores
```cpp
#include <Servo.h> // Biblioteca para controle do servo motor

Servo servoMotor;  // Cria um objeto do tipo Servo

// Configuração dos pinos
const int potPin = A0;  // Pino analógico conectado ao potenciômetro
const int servoPin = 9; // Pino digital conectado ao servo motor
```
## Passo 2: Execução do código

```cpp
void setup() {
  servoMotor.attach(servoPin);  // Conecta o servo ao pino especificado
}

void loop() {
  int potValue = analogRead(potPin);        // Lê o valor do potenciômetro (0 a 1023)
  int angle = map(potValue, 0, 1023, 0, 180); // Mapeia o valor do potenciômetro para ângulos de 0 a 180
  servoMotor.write(angle);                  // Define o ângulo do servo
  delay(15);                                // Pequeno atraso para suavizar o movimento
}
```

## Teste e validação

Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Verificação da Conexão dos atuadores**: Certifique-se de que o potenciometro e o Servo Motor estão conectados nos pinos corretos e orientados com os terminais certos.
2. **Teste da Sequência**: Carregue o código para o Arduino e observe a ocorrência de algum erro de digitação, sintaxe ou lógica.
3. **Ajuste de Tempo**: Se necessário, ajuste o tempo de delay para modificar o tempo de resposta entre potenciometro e Servo Motor

---

## Expansão e Melhoria

Sugestões para melhoria do projeto, como: 
- Substituir o uso de um potenciometro por sensor de luminosidade, para automatizar os horários de abertura e o quanto se pode abrir das cortinas e persianas
- Introdução a rede IoT para uso remoto

---

# Referências
1. Link da simulação: https://www.tinkercad.com/things/7UjP70b0sNC-servo-motor-e-potenciometro

2. Documentação do Arduino: https://docs.arduino.cc/

3. Artigo sobre Iluminação em ambientes hospitalares: http://www.biolab.eletrica.ufu.br/simposios/viseb/ArtigoSEB-IluminacaoHospitalar.pdf

---

Esse tutorial fornece introdução à sensores para arduino, e modulo Servo Motor com utilização de potenciometro.