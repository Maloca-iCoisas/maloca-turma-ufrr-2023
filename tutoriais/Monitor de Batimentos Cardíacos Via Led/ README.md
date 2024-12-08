# Título do Tutorial

**Descrição:** Este tutorial ensina como simular um monitor cardíaco simples usando um LED no Tinkercad e, em seguida, como adaptar o projeto para usar um sensor real com o Arduino IDE.

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

O tutorial do monitor de batimentos cardíacos via LED tem como propósito educacional,  inspirando a  aprendizagem, a  criatividade e a  inovação na área da saúde. Ele busca  desmistificar o uso da tecnologia em saúde e  demonstrar como ela pode ser utilizada para  monitorar e melhorar a saúde das pessoas.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno
- **Sensores**: Pulse Sensor
- **Atuadores**: LED, gerador de funções
- **Outros componentes**: Jumpers, resistore, Cabo USB

### Software

- **Linguagens**: C/C++ para Arduino e ESP32
- **IDE**: Arduino IDE
- **Bibliotecas**: PulseSensor Playground

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Acesse o site oficial do Arduino: www.arduino.cc/en/software
  - Selecione o sistema operacional do seu computador (Windows, macOS ou Linux).
  - Escolha a opção de download que preferir:
    - Instalador: Recomendado para a maioria dos usuários. Faz o download de um arquivo executável que instala o IDE automaticamente.
    - Arquivo ZIP: Para quem prefere instalar manualmente ou não tem permissão de administrador.
    - Windows App: Disponível na Microsoft Store.
  - 2.Instalação:
    - Execute o arquivo executável baixado (.exe).
    - Siga as instruções do instalador, aceitando os termos de licença e escolhendo o local de instalação.
    - Marque as opções para instalar drivers USB durante a instalação.
  - 3.Verificação da instalação
    - Abra o Arduino IDE.
    - Conecte sua placa Arduino ao computador com um cabo USB.
    - Vá em "Ferramentas" > "Placa" e selecione o modelo da sua placa.
    - Vá em "Ferramentas" > "Porta" e selecione a porta serial à qual sua placa está conectada.
    - Se tudo estiver correto, você verá a mensagem "Placa Arduino/Genuino Uno na porta COMX" (onde X é o número da porta) na barra de status do Arduino IDE.

- **Bibliotecas**: Para instalar a biblioteca "PulseSensor Playground"
  1. Abra o Arduino IDE.
  2.Vá em "Sketch" > "Incluir Biblioteca" > "Gerenciar Bibliotecas...".
  3. Na caixa de pesquisa, digite "PulseSensor Playground".
  4. Selecione a biblioteca "PulseSensor Playground" by World Famous Electronics LLC.
  5. Clique em "Instalar".
Após a instalação, você poderá incluir a biblioteca em seu código com a seguinte linha:
```c
#include <PulseSensorPlayground.h>
```

### Passo 2: Configuração da Placa

- **Arduino**:
1. Conecte a placa:
  - Conecte sua placa Arduino ao computador usando um cabo USB.
  - Importante: Certifique-se de que o cabo USB esteja em boas condições e seja adequado para transferência de dados (alguns cabos só servem para carregar).
2. Abra o Arduino IDE:

  - Inicie o software Arduino IDE no seu computador.
3. Selecione a placa:

  - Vá no menu "Ferramentas" > "Placa".
  - Encontre o modelo da sua placa na lista e selecione-o.
    - Exemplo: Se você estiver usando um Arduino Uno, selecione "Arduino Uno".
    - Dica: Se você não encontrar sua placa na lista, pode ser necessário instalar o suporte para ela. Vá em "Ferramentas" > "Placa" >        "Gerenciador de Placas..." e procure pelo nome da sua placa.
4. Selecione a porta:

  - Vá no menu "Ferramentas" > "Porta".
  - Selecione a porta serial à qual sua placa Arduino está conectada.
    - Dica: A porta geralmente tem um nome como "COMX" (Windows) ou "/dev/ttyACMX" (Linux) ou "/dev/cu.usbmodemXXXX" (macOS), onde X é        um número.
    - Dica 2: Se você não tiver certeza de qual porta é a correta, desconecte a placa do computador e veja qual porta desaparece da 
      lista. Conecte a placa novamente e veja qual porta reaparece.
5. Verifique a conexão:

  - Na barra de status do Arduino IDE (parte inferior da janela), você deverá ver uma mensagem indicando a placa e a porta selecionada.
    - Exemplo: "Placa Arduino/Genuino Uno na porta COM3".
    - ![IDE](https://github.com/user-attachments/assets/60a6e594-af1a-46d9-a90b-86015561e477)



---

## Montagem do Circuito

Conexões no Tinkercad:

Arduino Uno:

  - Pino 13: Conecte ao anodo (perna mais longa) do LED.
  - GND: Conecte ao catodo (perna mais curta) do LED através do resistor de 220 ohms.
  - A0: Conecte à saída (positivo) do gerador de funções, (negativo) no GND.
  - Lembre-se:

    - Conecte o gerador de funções ao pino A0 do Arduino. Configure o gerador para onda quadrada, frequência de 1Hz (ou outra que simule batimentos cardíacos), amplitude de 5V e offset de 0V.
      ![Captura de tela 2024-12-08 183019](https://github.com/user-attachments/assets/0800a1ec-272a-4dcf-86ba-01d26862a761)

---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

**C++ para TinkeCard simulação:**

```c++
int sensorPin = A0;  // Pino analógico A0 conectado ao gerador de funções
int ledPin = 13;     // Pino digital 13 conectado ao LED

void setup() {
  pinMode(ledPin, OUTPUT); // Define o pino 13 como saída
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Lê o valor do sensor no pino A0

  // Simula a detecção de batimento cardíaco
  // Se o valor do sensor for maior que 512 (metade da faixa de valores), 
  // considera-se como um batimento detectado
  if (sensorValue > 512) { 
    digitalWrite(ledPin, HIGH);  // Liga o LED
  } else {
    digitalWrite(ledPin, LOW);   // Desliga o LED
  }
}
```

**Exemplo em C++ para Arduino IDE:**

```c++
#include <PulseSensorPlayground.h> // Inclui a biblioteca do Pulse Sensor

const int PulseWire = A0;       // Pino do sinal do Pulse Sensor
const int LED13 = 13;          // Pino do LED
int Threshold = 550;           // Valor limite para detecção de batimento (ajuste conforme necessário)

PulseSensorPlayground pulseSensor;  // Cria um objeto PulseSensor

void setup() {
  Serial.begin(9600);          // Inicia a comunicação serial (para debug)
  pulseSensor.analogInput(PulseWire);   // Define o pino do sensor
  pulseSensor.setThreshold(Threshold);   // Define o valor limite

  if (pulseSensor.begin()) {
    Serial.println("Sensor encontrado!");  // Mensagem de sucesso
  }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();  // Lê os batimentos por minuto

  if (pulseSensor.sawStartOfBeat()) {            // Verifica se um novo batimento foi detectado
    Serial.println("♥  Batimento!");          // Mensagem no monitor serial
    digitalWrite(LED13, HIGH);                // Liga o LED
  } else {
    digitalWrite(LED13, LOW);                 // Desliga o LED
  }

  delay(20);                    // Pequena pausa 
}
```

### Passo 2: Processamento e Lógica de Alerta

Explicação da lógica:

1. Leitura do sensor: O código lê o valor analógico do pino A0, que simula o sensor.
2. Condição: Se o valor lido for maior que 512, significa que um "batimento" foi detectado.
3. Acionamento dos atuadores:
  - digitalWrite(ledPin, HIGH); Liga o LED.
4. Desligamento dos atuadores:
  - digitalWrite(ledPin, LOW); Desliga o LED.
---

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

1. **Testando Sensores**: Verifique se as leituras são consistentes e corretas.
2. **Validação dos Atuadores**: Confirme que os atuadores funcionam corretamente.
3. **Monitoramento em Tempo Real**: Teste o sistema completo em condições simuladas para garantir que funciona conforme o esperado.

---

## Expansões e Melhorias

- Interface mais informativa.
- Mais Leds: Usar LEDs de diferentes cores para indicar diferentes faixas de frequência cardíaca (ex: verde para normal, amarelo para moderada, vermelho para alta).
- Alarmes: implementar alarmes sonoros (com buzzer) que disparam quando a frequência cardíaca ultrapassa limites definidos, ou quando detecta padrões anormais (arritmias).

---

## Referências

www.tinkercad.com

https://www.tinkercad.com/things/diNXBp7jY2n-monitor-de-batimentos-cardiacos-com-alerta-via-led?sharecode=Eh0NAm455gc2cGZ-tbGXkeiGWD5VI6SkQIKg53SIBV0

https://www.arduino.cc/en/software

---


