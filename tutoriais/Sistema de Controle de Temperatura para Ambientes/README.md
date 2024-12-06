# Sistema de Controle de Temperatura para Ambientes

**Descrição:** Neste tutorial, vamos desenvolver um sistema de monitoramento para quartos de pacientes usando uma ESP32 com sensores de temperatura. O sistema mantém a temperatura dos quartos dentro de um intervalo seguro, alertando os profissionais de saúde caso a temperatura fique muito alta (LED vermelho) ou muito baixa (LED verde). Este projeto é particularmente útil para pacientes vulneráveis, como recém-nascidos, idosos ou pessoas com condições de saúde sensíveis à temperatura.

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

Este projeto visa monitorar a temperatura de quartos de pacientes, garantindo um ambiente seguro e confortável, essencial para pacientes vulneráveis como recém-nascidos e idosos. Utilizando a ESP32 com sensores de temperatura, o sistema envia alertas visuais para desvio de temperatura (LEDs), integrando-se ao ambiente IoT para permitir o monitoramento remoto e em tempo real por profissionais de saúde. Esta integração facilita intervenções rápidas e eficazes, melhorando o cuidado e a segurança dos pacientes..

---

## Requisitos

### Hardware

- **Placa**: ESP32
- **Sensores**: Substituto usamos o potenciômetro.
- **Atuadores**: LEDs (Verde, Laranja e Vermelho).
- **Outros componentes**: Jumpers, resistores e Protoboard.

### Software

- **Linguagens**: C/C++ para ESP32.
- **IDE**: Wokwi.
- **Bibliotecas**: Biblioteca padrão Arduino.h.

---

## Configuração do Ambiente

### Passo 1: Acessando e Configurando

- **Wokwi**: 
  1. Acesse o Wokwi no seu navegador https://wokwi.com/
  2. Crie um novo projeto e selecione a placa ESP32.
     
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/main/tutoriais/Sistema%20de%20Controle%20de%20Temperatura%20para%20Ambientes/wokwi.png?raw=true)

### Passo 2: Configuração das Placas

- **Arduino/ESP32**: Como vamos fazer a simulação online, não será necessário realizar configurações específicas na placa.

---

## Montagem do Circuito

### **LEDs e Resistores**:
- Conecte um resistor de 330 ohms a cada LED (verde, laranja e vermelho).
- Conecte um jumper do GND da ESP32 a cada LED através do resistor.
- Conecte os LEDs aos pinos da ESP32: 
   - LED Verde: Conecte ao pino 12 da ESP32. 
   - LED Laranja: Conecte ao pino 14 da ESP32. 
   - LED Vermelho: Conecte ao pino 27 da ESP32.
### **Potenciômetro**:
  - Conecte a porta VCC do potenciômetro ao pino de 5V da ESP32.
  - Conecte a porta GND do potenciômetro ao GND da ESP32.
  - Conecte a porta SIG do potenciômetro ao pino VP (36) da ESP32.
    
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/main/tutoriais/Sistema%20de%20Controle%20de%20Temperatura%20para%20Ambientes/circuito.png?raw=true).

---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Nesta parte do código, os pinos utilizados para os LEDs e o sensor de temperatura são definidos. Em seguida, os pinos dos LEDs são configurados como saídas e a comunicação serial é iniciada para permitir a depuração e monitoramento dos dados.



```cpp
#include <Arduino.h>

// Definindo os pinos
const int tempPin = 36; // Pino analógico VP conectado ao sensor de temperatura (GPI36, ADC1_CH0)
const int ledVerde = 12; // LED verde no pino 12
const int ledAmarelo = 14; // LED amarelo no pino 14
const int ledVermelho = 27; // LED vermelho no pino 27

void setup() {
  // Configuração dos pinos como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  // Inicializando a comunicação serial
  Serial.begin(9600);
}

```
- Definição de Pinos: Os pinos do sensor de temperatura e dos LEDs são definidos.
- Configuração Inicial: Os pinos dos LEDs são configurados como saída e a comunicação serial é iniciada para depuração.


### Passo 2: Processamento e Lógica de Alerta

Nesta seção, o código lê o valor do sensor de temperatura e o converte para uma leitura em Celsius. A voltagem e a temperatura são exibidas no monitor serial para depuração. Dependendo da temperatura medida, os LEDs são acionados para indicar se a temperatura está baixa, média ou alta. Um atraso de 1 segundo é adicionado para controlar a frequência das leituras e evitar sobrecarga.

```cpp
void loop() {
  // Lendo o valor do sensor de temperatura
  int valorSensor = analogRead(tempPin);
  
  // Convertendo o valor lido para a temperatura em Celsius
  float voltagem = (valorSensor / 4095.0) * 3.3; // ESP32 tem resolução de 12 bits e tensão de referência de 3.3V
  
  // Incluindo uma verificação da voltagem para depuração
  Serial.print("Voltagem lida: ");
  Serial.print(voltagem);
  Serial.println(" V");

  // Convertendo a voltagem para temperatura
  float temperatura = voltagem * 100.0; // Assumindo sensor LM35 (10mV por grau Celsius)

  // Exibindo a temperatura no monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");

  // Acendendo os LEDs com base na temperatura
  if (temperatura <= 20) {
    // Temperatura baixa, acende o LED verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (temperatura > 20 e temperatura <= 25) {
    // Temperatura média, acende o LED amarelo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else {
    // Temperatura alta, acende o LED vermelho
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  // Atraso de 1 segundo
  delay(1000);
}
```
- Leitura do Sensor: O valor do sensor de temperatura é lido e convertido para uma medida utilizável em Celsius.
- Depuração: A voltagem e a temperatura são impressas no monitor serial para verificação.
- Lógica de Alerta: Os LEDs são acionados com base na faixa de temperatura medida.
- Atraso: Um atraso de 1 segundo é adicionado para controlar a frequência das leituras.

---

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

- **Testando Sensores**: Gire o potenciômetro e observe as leituras de voltagem e temperatura no monitor serial. As leituras devem variar de 0V a 3.3V e refletir a temperatura correta.
-  **Validação dos Atuadores**: Ajuste o potenciômetro para simular diferentes temperaturas e observe os LEDs.
-  **Monitoramento em Tempo Real**: Simule temperaturas girando o potenciômetro e monitore os LEDs e o monitor serial. O sistema deve responder rapidamente às mudanças de temperatura e os LEDs devem refletir corretamente as faixas de temperatura.
    - Exemplo:
      
      ![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/main/tutoriais/Sistema%20de%20Controle%20de%20Temperatura%20para%20Ambientes/terminal.png?raw=true)
---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Integração de um Display LCD: Use um display para mostrar a temperatura e outras informações em tempo real.
- Buzzer para Alerta Sonoro: Adicione um buzzer para emitir alertas sonoros em casos de temperatura alta ou baixa, complementando os sinais visuais dos LEDs.
  - Display + Buzzer:
    
  ![imagm alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/main/tutoriais/Sistema%20de%20Controle%20de%20Temperatura%20para%20Ambientes/melhorias.png?raw=true)
---

## Referências

- Link simulação: https://wokwi.com/projects/414635274333556737
- Documentação: https://docs.wokwi.com/pt-BR/
- Conhecendo o simulador: https://www.youtube.com/watch?v=ZHz9nBDnFhU&t=87s

---

Caso os LEDs não acendam, é importante revisar as conexões e garantir que os LEDs estão corretamente polarizados. Se a temperatura exibida estiver incorreta, verifique a conexão do potenciômetro ao pino VP (36). Caso os LEDs não respondam às mudanças de temperatura, ajuste as faixas no código e o tempo de delay para otimizar a leitura e resposta do sistema.
