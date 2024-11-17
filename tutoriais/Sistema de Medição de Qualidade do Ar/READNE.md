# Sistema de Monitoramento de Qualidade do Ar com Arduino

**Descrição:** Criação de um circuito utilizando Arduino UNO e o sensor MQ-135 para monitorar a qualidade do ar e indicar níveis críticos por meio de um alerta visual e sonoro.

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
Este projeto utiliza o sensor MQ-135 para medir a qualidade do ar, exibindo os dados em um display LCD 16x2 e acionando alertas visuais e sonoros para níveis críticos de poluição. O sistema é voltado para aplicações em **saúde pública**, auxiliando na prevenção de doenças respiratórias e na identificação de ambientes potencialmente perigosos.

---

## Requisitos

### Hardware

- **Placa:** Arduino UNO;
- **Sensores:** MQ-135 (sensor de gás);
- **Atuadores:**
  - Buzzer (alarme sonoro);
- **Display:** LCD 16x2 (com ou sem módulo I2C);
- **Outros componentes:**
  - Protoboard;
  - Resistores de 220 ohms e 4k ohm;
  - Cabo USB;
  - Cabos jumpers.

### Software

- **Linguagens**: C para Arduino via Arduino IDE;
- **IDE**: Arduino IDE, Tinkercad (Opcional);
- **Bibliotecas**: LiquidCrystal (LCD).

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

1. Faça o download e instale a [Arduino IDE](https://www.arduino.cc/en/software);
   
2. Após instalar o Arduino IDE, certifique-se de que a biblioteca **LiquidCrystal** está instalada:
   - Na Arduino IDE, abra o **Library Manager**;
<img src="Caminho-Biblioteca.png" alt="caminho-biblioteca-manager" />
   - Pesquise por `LiquidCrystal` e clique em **Instalar**.

### Passo 2: Configuração da Placa

1. Conecte o Arduino UNO ao computador via cabo USB;
2. Na Arduino IDE:
   - Acesse **Tools > Board > Arduino UNO**;
   - Acesse **Tools > Port** e selecione a porta correta.

---

## Montagem do Circuito

Monte o circuito conforme as conexões abaixo. Utilize uma protoboard para organizar os componentes.

### **Conexões**
#### Sensor MQ-135
- **AOUT** → Pino A0 do Arduino;
- **VCC** → 5V;
- **GND** → GND.

#### Display LCD
- **RS** → Pino 2;
- **E** → Pino 3;
- **D4, D5, D6, D7** → Pinos 4, 5, 6, 7;
- **VSS e RW** → GND;
- **VDD** → 5V;
- **VO** → Potenciômetro para ajuste do contraste.

#### LED
- **Pino Positivo (LED)** → Pino A1;
- **GND (LED)** → GND.

#### Buzzer
- **Pino Positivo (Buzzer)** → Pino 8;
- **GND (Buzzer)** → GND.

---

## Programação

### Passo 1: Configuração do LCD

Adicione a biblioteca e configure os pinos do LCD no código:

```cpp
#include <LiquidCrystal.h>
#define D7 7
#define D6 6
#define D5 5
#define D4 4
#define E 3
#define RS 2
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
