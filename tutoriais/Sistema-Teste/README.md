# Sistema de Monitoramento de Batimentos Cardíacos com Alerta Sonoro

**Descrição:** O tutorial ensinará como desenvolver um sistema simples para monitorar os batimentos cardíacos com alerta sonoro usando o Arduino, ideal para iniciantes visualizarem aplicações do Arduino ou similares na área da saúde.

---

## Índice

- [Sistema de Monitoramento de Batimentos Cardíacos com Alerta Sonoro](#sistema-de-monitoramento-de-batimentos-cardíacos-com-alerta-sonoro)
  - [Índice](#índice)
  - [Introdução](#introdução)
  - [Requisitos](#requisitos)
    - [Hardware](#hardware)
    - [Software](#software)
  - [Configuração do Ambiente](#configuração-do-ambiente)
    - [Passo 1: Instalação do Software](#passo-1-instalação-do-software)
    - [Passo 2: Configuração das Placas](#passo-2-configuração-das-placas)
  - [Montagem do Circuito](#montagem-do-circuito)
  - [Programação](#programação)
    - [Passo 1: Configuração dos Sensores e Atuadores](#passo-1-configuração-dos-sensores-e-atuadores)
    - [Passo 2: Processamento e Lógica de Alerta](#passo-2-processamento-e-lógica-de-alerta)
  - [Teste e Validação](#teste-e-validação)
  - [Expansões e Melhorias](#expansões-e-melhorias)
  - [Referências](#referências)

---

## Introdução

Este circuito tem como finalidade simular uma situação recorrente hospitais que é a variação da frenquência cardíaca dos pacientes, onde se os valores dos batimentos por minuto (BPM) chegarem a determinados valores críticos enviasse informações como um alerta sono, isso pode ser facilmente escalável para o envio de notificações diretamente para os médicos e enfermeiros responsáveis, mas o intuito deste tutorial é a introdução de conhecimentos básicos a iniciantes e sua ambientação com as ferramentas, então será trabalhado um circuito mais simples.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno
- **Sensores**: Sensor de batimentos cardíacos
- **Atuadores**: Buzzer(emissão de alerta sonoro)
- **Outros componentes**: Protoboard, 1 resistor de 330Ω(depende do modelo do buzzer) e 5 jumpers

### Software

- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.
- **Bibliotecas**:`PulseSensorPlayground`

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Instruções para instalar e configurar a IDE do Arduino para ESP32/Arduino.
- **Thonny Python**: Configuração do Thonny para programar em Python no Raspberry Pi.
- **Bibliotecas**: Como instalar as bibliotecas necessárias. Exemplo:

```bash
# Instalar bibliotecas do Python
pip install Adafruit_DHT
```

### Passo 2: Configuração das Placas

- **Arduino/ESP32**: Passos para configurar a placa e selecionar a porta correta na IDE.
- **Raspberry Pi**: Configuração do GPIO para comunicação com os sensores.

---

## Montagem do Circuito

Insira um diagrama do circuito, ou descreva as conexões principais, incluindo onde cada sensor e atuador deve ser conectado. 

> **Nota**: Use imagens ou diagramas para auxiliar a compreensão.

---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Forneça o código para a configuração dos sensores. Por exemplo, para medir temperatura e batimentos cardíacos:

**Exemplo em C para ESP32:**

```cpp
#include <DHT.h>

#define DHTPIN 2     // Pino do sensor DHT
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  Serial.println(temp);
  delay(2000);
}
```

**Exemplo em Python para Raspberry Pi:**

```python
import Adafruit_DHT

sensor = Adafruit_DHT.DHT11
pin = 4  # Pino GPIO

humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)
print(f"Temperatura: {temperature}ºC")
```

### Passo 2: Processamento e Lógica de Alerta

Adicione a lógica para processar os dados e acionar atuadores, como LEDs ou buzzer, caso as leituras excedam um determinado limite.

---

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

1. **Testando Sensores**: Verifique se as leituras são consistentes e corretas.
2. **Validação dos Atuadores**: Confirme que os atuadores funcionam corretamente.
3. **Monitoramento em Tempo Real**: Teste o sistema completo em condições simuladas para garantir que funciona conforme o esperado.

---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Adicionar comunicação Wi-Fi (ESP32) para enviar dados para uma nuvem.
- Integrar um banco de dados para registro das leituras.
- Conectar-se a uma aplicação móvel para visualização remota.

---

## Referências

Liste todas as referências e links úteis para guias, bibliotecas, e materiais adicionais que ajudem a complementar o tutorial.

---