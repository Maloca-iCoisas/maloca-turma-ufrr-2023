# Projeto de Monitoramento de Nível de Líquido - Maloca das iCoisas

## Descrição
Neste tutorial, vamos desenvolver um sistema de monitoramento de nível de líquido utilizando um sensor de umidade, com acionamento de LEDs e buzzer, usando uma placa **Arduino**. O objetivo é criar um sistema que detecte o nível de líquido e forneça alertas visuais e sonoros em tempo real. Este projeto é ideal para iniciantes e tem foco em automação de ambientes e sistemas de monitoramento.

## Índice
1. [Introdução](#introdução)
2. [Requisitos](#requisitos)
   - [Hardware](#hardware)
   - [Software](#software)
3. [Configuração do Ambiente](#configuração-do-ambiente)
4. [Montagem do Circuito](#montagem-do-circuito)
5. [Programação](#programação)
   - [Configuração dos Sensores e Atuadores](#configuração-dos-sensores-e-atuadores)
   - [Processamento e Lógica de Alerta](#processamento-e-lógica-de-alerta)
6. [Teste e Validação](#teste-e-validação)
7. [Expansões e Melhorias](#expansões-e-melhorias)
8. [Referências](#referências)

---

## Introdução

Este projeto tem como objetivo a construção de um sistema de monitoramento de nível de líquido, como água ou soro, utilizando um sensor de umidade. O sistema utiliza LEDs para indicar os níveis de líquido e um buzzer para emitir alertas quando o nível atingir valores críticos. O projeto integra a automação no ambiente e pode ser expandido para outros sistemas de monitoramento, como controle de umidade e temperatura.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno (ou similar)
- **Sensor**: Sensor de umidade (moisture sensor)
- **Atuadores**: LEDs (para diferentes níveis de líquido) e Buzzer (para alerta sonoro)
- **Outros componentes**:
  - Jumpers
  - Resistores (para limitar a corrente dos LEDs)
  - Fonte de alimentação (se necessário)
  - Placa de prototipagem (breadboard)

### Software

- **Linguagens**:
  - C/C++ (Arduino)
- **IDE**:
  - Arduino IDE
- **Bibliotecas**:
  - Nenhuma biblioteca externa necessária para este projeto específico.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**:  
  Baixe e instale a IDE do Arduino [aqui](https://www.arduino.cc/en/software). Certifique-se de que a IDE está configurada para sua placa **Arduino Uno**.

### Passo 2: Configuração das Placas

- **Arduino**:  
  No Arduino IDE, selecione a placa correta (Arduino Uno) em **Ferramentas > Placa > Arduino Uno** e configure a porta de comunicação correta.

---

## Montagem do Circuito

A montagem do circuito é bem simples. Conecte o sensor de umidade aos pinos analógicos do Arduino e os LEDs e buzzer aos pinos digitais.

- **Sensor de umidade**:  
  Conecte o pino de leitura analógica do sensor ao pino A1 do Arduino.
  
- **LEDs**:  
  Conecte três LEDs aos pinos digitais 10, 11 e 12 do Arduino. Cada LED representará um nível de líquido (baixo, médio, alto).

- **Buzzer**:  
  Conecte o buzzer ao pino digital 8 para emitir um som quando o nível de líquido estiver baixo.

```plaintext
Pinos Arduino -> Componentes
A0    -> VCC do sensor de umidade
GND   -> GND do sensor de umidade
A1    -> Pino de leitura do sensor de umidade
D8    -> Buzzer
D10   -> LED alto
D11   -> LED médio
D12   -> LED baixo

