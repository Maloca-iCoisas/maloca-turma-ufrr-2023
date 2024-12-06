# Sistema de Monitoramento de IMC com Sensores de Peso e Altura

**Descrição:** Neste projeto, vamos criar um sistema de monitoramento de saúde utilizando um sensor de força para medir o peso de um indivíduo e um sensor de distância para calcular sua altura, ambos conectados a um microcontrolador. O sistema também calculará o Índice de Massa Corporal (IMC) com base nos valores de peso e altura, e exibirá as informações no display LCD. Além disso, o sistema indicará a faixa do IMC através de LEDs, ajudando na avaliação de condições como baixo peso, sobrepeso e obesidade. Esse projeto pode ser útil em clínicas, academias ou até mesmo para uso pessoal, promovendo o acompanhamento da saúde de forma prática e visual.

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

Este projeto visa desenvolver um sistema para calcular e monitorar o Índice de Massa Corporal (IMC) utilizando sensores de peso e altura. O sistema exibe os resultados em um display LCD e utiliza LEDs para indicar diferentes faixas de IMC, como baixo peso, peso normal e obesidade. A proposta é fornecer uma ferramenta prática e acessível para o acompanhamento da saúde física.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno.
- **Sensores**: Sensor de força (para medir o peso) e sensor de distância (ultrassônico) para medir a altura.
- **Atuadores**: 5 LEDs de cores diferentes (para indicar diferentes faixas de IMC).
- **Display**: LCD 16x2 com interface I2C.
- **Outros componentes**: Protoboard, 6 resistores de 220 Ω, jumpers.

### Software

- **Linguagens**: C/C++ para programação do Arduino..
- **IDE**: Arduino IDE e Tinkercad.
- **Bibliotecas**: Wire.h e Adafruit_LiquidCrystal.h para controle do LCD e comunicação com os sensores.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software
 
- **Arduino IDE:** Faça o download e instale o Arduino IDE acessando o site https://www.arduino.cc/en/software.

![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/Tutorial-2/tutoriais/Sistema%20de%20Monitoramento%20de%20IMC%20com%20Sensores%20de%20Peso%20e%20Altura/download%20arduino.png?raw=true)

### Passo 2: Configuração das Placas
- **Configuração no Arduino:**
1. Conecte a placa Arduino ao computador utilizando o cabo USB;
2. Na IDE do Arduino, clique em "Select other board and port" (Selecionar outra placa e porta);
3. Escolha a opção "Arduino Mega or Mega 2560";
4. Por último, selecione a porta correta na IDE do Arduino.
     
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/Tutorial-2/tutoriais/Sistema%20de%20Monitoramento%20de%20IMC%20com%20Sensores%20de%20Peso%20e%20Altura/arduino.png?raw=true)
---

## Montagem do Circuito

- **Junte a Placa Arduino Uno à protoboard para facilitar as conexões.**
- **Sensor de Força**
1. Um terminal do sensor de força está conectado ao pino A1 do Arduino.
2. No mesmo ponto de conexão do sensor de força na protoboard, há um resistor de 220 Ω que vai para o barramento positivo (+), que por sua vez é conectado ao pino de 5V do Arduino.
3. O outro terminal do sensor de força está conectado ao barramento negativo (-) da protoboard usando dois jumpers, e esse barramento negativo está conectado ao GND do Arduino.
- **Sensor de Distância (Ultrassônico)**
1. Conecte o pino VCC do sensor de distância ao pino de 5V do Arduino.
2. Conecte o pino GND do sensor ao GND do Arduino.
3. Conecte o pino Trig a um pino digital, por exemplo, o pino 3.
4. Conecte o pino Echo a um pino digital, por exemplo, o pino 2.
- **Display LCD 16x2 (I2C)** 
1. Conecte o pino VCC do módulo I2C ao pino de 5V do Arduino.
2. Conecte o pino GND ao GND do Arduino.
3. Conecte o pino SDA ao pino A4 do Arduino.
4. Conecte o pino SCL ao pino A5 do Arduino.
- **LEDs de Cores Diferentes**
1. Conecte o ânodo de cada LED a pinos digitais diferentes no Arduino (por exemplo, 8, 9, 10, 11, e 12).
2. Conecte o cátodo de cada LED a um resistor de 220 Ω, e então conecte o outro terminal do resistor ao GND.
- **Jumpers**:
1. Use jumpers para conectar o barramento GND da protoboard ao GND do Arduino e garantir todas as conexões corretamente.
## Circuito
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/Tutorial-2/tutoriais/Sistema%20de%20Monitoramento%20de%20IMC%20com%20Sensores%20de%20Peso%20e%20Altura/circuito1.png?raw=true)

---

## Programação

### Passo 1: Configuração do Sistema

Inicialize o display LCD com o endereço correto e defina os pinos de entrada e saída no Arduino. Isso inclui configurar o sensor de força, o sensor de distância e os LEDs. Certifique-se de que a comunicação serial esteja pronta para a exibição de dados no monitor serial.



```cpp
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

long duracao;
double sensorDeForca = A1;
double altura1;
double altura2;
double pesoNewton = 0; // O sensor de força mede em Newtons
double pesoKG = 0;
double IMC1;
double IMC2;

// Inicializa o LCD com o endereço 0x20
Adafruit_LiquidCrystal lcd_1(0x20);

void setup() {
  lcd_1.begin(16, 2);  // Configura o LCD para 16 colunas e 2 linhas
  lcd_1.setBacklight(1);  // Liga a luz de fundo do LCD

  pinMode(sensorDeForca, INPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}


```

### Passo 2: Processamento e Lógica de Cálculos e Exibição

No loop principal, colete dados do sensor de distância para calcular a altura em metros e do sensor de força para estimar o peso em quilogramas. Em seguida, calcule o IMC usando os valores de altura e peso. Os resultados são exibidos no monitor serial e no display LCD.

```cpp
void loop() {
  // Fórmulas de Distância
  digitalWrite(3, LOW);
  delayMicroseconds(2);

  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  duracao = pulseIn(2, HIGH);

  altura1 = duracao * 0.034 / 2;
  altura2 = altura1 / 100;  // Converte de CM para M

  // Fórmulas de Peso
  pesoNewton = analogRead(sensorDeForca);
  pesoKG = pesoNewton * pesoNewton * pesoNewton * pesoNewton * pesoNewton * pesoNewton / 10000000000000000;

  // Imprimir os valores no Monitor Serial
  Serial.print("Altura: ");
  Serial.print(altura2);
  Serial.println(" m");

  Serial.print("Peso: ");
  Serial.print(pesoKG);
  Serial.println(" kg");

  IMC1 = altura2 * altura2;
  IMC2 = pesoKG / IMC1;

  Serial.print("IMC: ");
  Serial.println(IMC2);

  // Imprimir os valores no LCD
  lcd_1.clear();  // Limpa o LCD antes de imprimir as novas informações
  lcd_1.setCursor(0, 0);  // Posiciona o cursor na primeira linha, primeira coluna
  lcd_1.print("Altura: ");
  lcd_1.print(altura2);
  lcd_1.print(" m");

  lcd_1.setCursor(0, 1);  // Posiciona o cursor na segunda linha, primeira coluna
  lcd_1.print("Peso: ");
  lcd_1.print(pesoKG);
  lcd_1.print(" kg");

  delay(2000);  // Aguarda 2 segundos antes de atualizar a tela

  // Categorizar o IMC e acionar os LEDs correspondentes
  if (IMC2 < 18.5) {
    Serial.println("ABAIXO DO PESO");
    digitalWrite(12, HIGH);
    delay(200);
    digitalWrite(12, LOW);
  } else if (IMC2 > 18.5 && IMC2 < 25) {
    Serial.println("PESO NORMAL");
    digitalWrite(11, HIGH);
    delay(200);
    digitalWrite(11, LOW);
  } else if (IMC2 >= 25 && IMC2 < 30) {
    Serial.println("SOBREPESO");
    digitalWrite(10, HIGH);
    delay(200);
    digitalWrite(10, LOW);
  } else if (IMC2 >= 30 && IMC2 < 35) {
    Serial.println("OBESIDADE MODERADA");
    digitalWrite(9, HIGH);
    delay(200);
    digitalWrite(9, LOW);
  } else if (IMC2 >= 35) {
    Serial.println("OBESIDADE SEVERA");
    digitalWrite(8, HIGH);
    delay(200);
    digitalWrite(8, LOW);
  }
}

}
```
---

## Teste e Validação



- **Testar o Sensor de Distância:** Verifique se o sensor de distância está medindo corretamente a altura. Utilize um objeto de referência com altura conhecida e confirme se o valor calculado corresponde ao esperado, tanto no monitor serial quanto no LCD.

- **Testar o Sensor de Força:** Aplique diferentes pesos conhecidos ao sensor de força e verifique se os valores de peso em quilogramas são calculados corretamente. Compare as leituras no monitor serial com os valores reais para validar a precisão.

- **Cálculo de IMC:** Valide o cálculo do IMC com exemplos de altura e peso conhecidos. Certifique-se de que o valor exibido esteja correto e dentro do intervalo esperado.

- **Funcionamento dos LEDs:** Teste cada LED individualmente para garantir que eles acendem corretamente com base na categoria de IMC. Simule diferentes IMCs e observe se o LED correspondente é ativado.

- **Display LCD:** Verifique se as informações de altura, peso e IMC são exibidas corretamente no LCD. Garanta que o LCD limpa as informações antigas e atualiza os dados em tempo real.

- **Monitor Serial:** Confirme que todos os dados coletados e os cálculos do IMC estão sendo impressos corretamente no monitor serial para facilitar o monitoramento e a depuração.

![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/Tutorial-2/tutoriais/Sistema%20de%20Monitoramento%20de%20IMC%20com%20Sensores%20de%20Peso%20e%20Altura/T2_Circuito.png?raw=true)
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/Tutorial-2/tutoriais/Sistema%20de%20Monitoramento%20de%20IMC%20com%20Sensores%20de%20Peso%20e%20Altura/T2_Terminal%20(2).png?raw=true)

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- **Comunicação com a Nuvem**: Integrar o projeto com uma plataforma para armazenar as métricas captadas pelos sensores em tempo real. Isso permite o acesso remoto aos dados, a análise de históricos de IMC, e o monitoramento contínuo das condições do usuário.
- **Implementar Alarmes Sonoros:** Adicionar um buzzer que emita sons de alerta para casos de IMC fora da faixa saudável, aumentando a usabilidade em ambientes com menos visibilidade.
---

## Referências

- Link simulação: https://www.tinkercad.com/things/hezlOPXRZWe-sistema-de-monitoramento-de-imc-com-sensores-de-peso-e-altura?sharecode=aCFzLU7Zibd8mRkQ5pw7I1kYj_9DKlnJC2mFIFggUw4
- ArduinoIDE: https://www.arduino.cc/
- Tinkercad: https://www.tinkercad.com/

---
Este sistema oferece uma solução simples e eficaz para monitoramento da saúde física, e pode ser expandido para incluir recursos como armazenamento de dados, alarmes e integração com outros sistemas de saúde
