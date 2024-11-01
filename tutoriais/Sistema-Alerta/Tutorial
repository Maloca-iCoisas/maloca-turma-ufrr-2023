# Sistema de Alerta com Arduino Uno R3

**Descrição:** Criação de um circuito utilizando Arduino Uno R3 para indicar um estado de socorro de um paciente, por meio de uma botão.

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
Explique o propósito do projeto em um contexto de saúde. Por exemplo, o monitoramento de sinais vitais em tempo real para pacientes, ou um sistema de alarme para quedas. Inclua uma breve visão sobre como o projeto se integra ao ambiente IoT.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno R3;
- **Sensores**: Botão;
- **Atuadores**: Dois Led's (Verde: Estado Normal; Vermelho: Estado Emergência);
- **Outros componentes**: Protoboard(fins educacionais), 5 resistores ( 3 de 330ohms e 2 de 1kohms), jumpers, 1 Lcd.

### Software

- **Linguagens**: C para Arduino via Arduino IDE;
- **IDE**: Arduino IDE, Tinkercad(Opcional);
- **Bibliotecas**: LiquidCrystal(Lcd).

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Por meio do link (https://www.arduino.cc/en/software) faça o download software que usaremos para programar a placa.
- **Bibliotecas**: Como instalar as bibliotecas necessárias:
  1.Após instalar o Arduino IDE procure por:
  <img>  
```bash!

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

Espero que esse modelo ajude a organizar o conteúdo e fornecer uma estrutura clara e completa para tutoriais de IoT no contexto da saúde.
