# Sinal de Controle de fluxo de Pessoas

**Descrição:**  Neste tutorial, vamos construir um sistema de semáforo simples com Arduino e LEDs, aplicável para ambientes de saúde, com o objetivo de controlar o fluxo de entrada e saída de pessoas em áreas restritas ou de alto risco. Esse projeto oferece uma maneira visual de indicar quando é seguro entrar (LED verde) ou parar (LED vermelho), contribuindo para um ambiente hospitalar mais organizado e seguro.
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

Controlar o fluxo de pessoas é essencial em áreas críticas de hospitais. Este projeto de semáforo com LEDs fornece uma sinalização visual para entrada (LED verde) e parada (LED vermelho). Isso ajuda a manter o controle, evitando aglomerações em espaços sensíveis. Este projeto é também uma ótima introdução ao uso de Arduino e componentes básicos em ambientes IoT voltados para a saúde.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno ou compatível;
- **Atuadores**: LEDs (1 verde e 1 vermelho);
- **Outros componentes**: Resistores de 220Ω (um para cada LED), jumpers e uma protoboard;

### Software

- **Linguagens**: C/C++ para Arduino
- **IDE**: Arduino IDE

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Baixe e instale o Arduino IDE a partir do https://www.arduino.cc/en/software.

### Passo 2: Configuração da Placa

- **Arduino**: Conecte a placa ao computador via USB e selecione a porta correta na IDE do Arduino.

---

## Montagem do Circuito

Para montar o circuito, siga as instruções abaixo:

1. Preparação da Protoboard e Conexão do GND:
- Conecte o pino GND do Arduino à linha de alimentação negativa (linha preta) da protoboard. Esta linha servirá como terra para todo o circuito.

2. Conexão dos LEDs na Protoboard:

- Coloque os dois LEDs na protoboard, deixando espaço suficiente entre eles para as conexões.

3. Conexão dos Resistores:

- Conecte um resistor de 220Ω ao ânodo de cada LED. Isso limitará a corrente que passa pelos LEDs, protegendo-os de queima.

4. Conexão dos LEDs aos Pinos do Arduino:

- LED Verde: Conecte o terminal do resistor do LED verde ao pino digital 2 do Arduino.
- LED Vermelho: Conecte o terminal do resistor do LED vermelho ao pino digital 4 do Arduino.

3. Conexão da Linha Positiva da Protoboard:

- Conecte a linha positiva (linha vermelha) da protoboard ao pino 5V do Arduino para fornecer alimentação estável aos componentes do circuito.

> **Nota**: Use imagens ou diagramas para auxiliar a compreensão.

---

## Programação

### Passo 1: Configuração dos LEDs

Use o código a seguir para controlar os LEDs:

**Exemplo em C para ESP32:**


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

Espero que esse modelo ajude a organizar o conteúdo e fornecer uma estrutura clara e completa para tutoriais de IoT no contexto da saúde.
