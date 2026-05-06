# Detector de Proximidade com Alarme e LCD

**Descrição:** Neste tutorial, vamos criar um Detector de Proximidade utilizando um Arduino Uno, um sensor de ultrassom HC-SR04, um buzzer, um LED e um LCD 16x2 para exibir a distância medida. Este projeto pode ser aplicado na área da saúde para monitorar pacientes acamados, alertando cuidadores sobre movimentações ou quedas, sendo um sistema simples de aplicar."

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

O Detector de Proximidade com Alarme é um sistema simples que utiliza o HC-SR04 para medir a distância de objetos próximos. Quando a distância é inferior a um limite configurado (ex.: 50 cm), o sistema aciona um buzzer e um LED para alertar sobre a proximidade. O LCD exibe a distância em tempo real. Este projeto é ideal para aplicações na saúde, como o monitoramento de pacientes com mobilidade reduzida.

O objetivo do Detector de Proximidade com Alarme neste contexto é criar uma solução que ajude a monitorar o movimento do paciente e a alertar os profissionais de saúde ou cuidadores quando o paciente se aproxima da borda da cama, cadeira ou qualquer outra área potencialmente perigosa. O alarme ajuda a prevenir quedas, permitindo intervenções rápidas antes que o incidente aconteça.

Em hospitais ou clínicas, o sistema pode ser usado para monitorar se há algo ou alguém muito próximo a alguma máquina ou equipamento médico que não pode ter sua passagem obstruida.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno.
- **Sensores**: HC-SR04 (sensor de ultrassom) para medir o movimento do paciente.
- **Atuadores**: Buzzer ativo, LED (vermelho)
- **Outros componentes**: Protoboard, jumpers, resistor 220 Ω, e monitor LCD 16x2.

### Software

- **Linguagens**: C/C++ para Arduino.
- **IDE**: Arduino IDE.
- **Bibliotecas**: LiquidCrystal.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Arduino IDE**: Pesquise Arduino IDE download no navegador, abra o link no site oficial do Arduino e baixe a versão compativel com seu sistema.
- **Simulador TinkerCad**: Para melhores resultados, simule no site Tinkercad o circuito utilizado. Não precisa ser instalado, basta pesquisar tinkercad no navegador e entrar no site.
- **Bibliotecas**: LiquidCrystal: Normalmente já vem instalada com o Arduino IDE, mas caso não venha, siga os seguintes passos: Abra o Arduino IDE, vá em tools (Ferramentas),
agora clique em "Manage Libraries", pesquise por LiquidCrystal by Arduino.


### Passo 2: Configuração das Placas

- **Arduino Uno**: Vamos utilizar o Arduino Uno, que já vem por padrão instalado no Arduino IDE. Para selecionar a placa desejada vá em "Select Board" (selecionar placa)
selecione a entrada USB que vai usar, e por fim selecione o Arduino Uno.

---

## Montagem do Circuito

# Detector de Proximidade com Alarme

Este projeto consiste em um sistema simples que utiliza o sensor ultrassônico **HC-SR04** para medir a distância de objetos. Quando a distância detectada é inferior ao limite configurado, o sistema aciona um buzzer e um LED como alerta. Além disso, um display **LCD 16x2** exibe a distância em tempo real.

## Componentes Necessários

- 1 x Sensor Ultrassônico **HC-SR04**
- 1 x LED (vermelho ou outro de sua preferência)
- 1 x Resistor de **220 Ω**
- 1 x Buzzer (ativo ou passivo)
- 1 x Display **LCD 16x2**
- 1 x Potenciômetro (para ajustar o contraste do LCD)
- 1 x Placa Arduino (ex.: Arduino Uno ou similar)
- Jumpers e fios de conexão
- Protoboard

## Esquema de Conexão

### HC-SR04
- **VCC** → 5V  
  (Recebe energia da placa Arduino para alimentar o sensor)
- **GND** → GND  
  (Conecta o terra do sensor ao terra da placa Arduino)
- **TRIG** → D8  
  (Pino de gatilho para iniciar a medição da distância; é acionado pelo Arduino)
- **ECHO** → D9  
  (Pino de eco, retorna o sinal de ultrassom após ser refletido pelo objeto)

### LED
- **Ânodo** → Resistor (220 Ω) → D12  
  (O ânodo do LED é conectado ao pino digital 12 do Arduino, com um resistor limitando a corrente)
- **Cátodo** → GND  
  (O cátodo do LED é conectado ao terra da placa Arduino)

### Buzzer
- **Positivo** → D11  
  (Pino de controle do buzzer, acionado pelo Arduino para emitir o som)
- **Negativo** → GND  
  (Conecta o terminal negativo do buzzer ao terra da placa Arduino)

### LCD 16x2
- **RS** → D7  
  (Registro seletor, usado para escolher entre comandos ou dados que o LCD exibe)
- **E** → D6  
  (Habilita a comunicação entre o Arduino e o LCD, controla a transmissão de dados)
- **D4** → D5  
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D5** → D4  
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D6** → D3  
  (Pino de dados, utilizado para enviar informações para o LCD)
- **D7** → D2  
  (Pino de dados, utilizado para enviar informações para o LCD)
- **VSS** → GND  
  (Conecta o terra do LCD ao terra do Arduino)
- **VDD** → 5V  
  (Fornece 5V para alimentar o LCD)
- **V0** → Terminal central do potenciômetro  
  (Usado para ajustar o contraste do LCD)

> **Nota**: Ajuste o potenciômetro para configurar o contraste do LCD.

### Alimentação
- O circuito deve ser alimentado através do Arduino (USB ou fonte externa compatível).

## Montagem no Simulador Tinkercad

Você pode montar o circuito em um simulador como o [Tinkercad](https://www.tinkercad.com/) para testes virtuais antes da montagem física.

---

## Programação

### Passo 1: Simulação

Antes de implementar o circuito fisicamente, você pode testar a simulação do projeto no Tinkercad. Abaixo está o link para a simulação, onde você pode verificar como o circuito e o código interagem.

**Simulação no Tinkercad:**  
[Simulação do Projeto no Tinkercad](https://www.tinkercad.com/things/7cVZB5EvYWB-tuto-maloca-01-github)

Clique no link para acessar a simulação e verificar o funcionamento do circuito e do código.

---

### Passo 2: Configuração dos Sensores e Atuadores

Copie e cole o código abaixo na IDE do Arduino. Depois, faça o upload para a placa.

**Código em C/C++ para Arduino Uno:**

```cpp
#include <LiquidCrystal.h>

// Configuração do LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  
// A linha acima define a conexão dos pinos do LCD com a placa Arduino. 
// Aqui estão os detalhes das conexões:
// RS -> Pino 7: Pino de controle (registro de seleção) para LCD.
// E  -> Pino 6: Pino de controle (habilitação) para LCD.
// D4 -> Pino 5: Pino de dados de 4 bits para LCD.
// D5 -> Pino 4: Pino de dados de 4 bits para LCD.
// D6 -> Pino 3: Pino de dados de 4 bits para LCD.
// D7 -> Pino 2: Pino de dados de 4 bits para LCD.

// Definição dos pinos para o sensor e os atuadores
#define TRIG_PIN 8          // Pino de gatilho do HC-SR04: envia o pulso ultrassônico
#define ECHO_PIN 9          // Pino de eco do HC-SR04: recebe o pulso refletido
#define LED_PIN 12          // Pino para o LED: usado para alerta visual
#define BUZZER_PIN 11       // Pino para o buzzer: usado para alerta sonoro

void setup() {
  // Configuração dos pinos de entrada e saída
  pinMode(TRIG_PIN, OUTPUT);  // TRIG como saída, envia o pulso ultrassônico
  pinMode(ECHO_PIN, INPUT);   // ECHO como entrada, recebe o pulso refletido
  pinMode(LED_PIN, OUTPUT);   // LED como saída, usado para alerta visual
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer como saída, usado para alerta sonoro

  // Inicialização do LCD
  lcd.begin(16, 2);           // Inicializa o LCD 16x2 (16 colunas, 2 linhas)
  lcd.print("Distance:");     // Exibe uma mensagem fixa "Distance:" na linha 1
  Serial.begin(9600);         // Inicia a comunicação serial com a taxa de 9600 bauds
}

void loop() {
  long duration, distance;

  // Pulso para o TRIG
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);      // Espera 2 microssegundos para garantir a leitura correta
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);     // Pulso de 10 microssegundos que aciona a emissão de ultrassom
  digitalWrite(TRIG_PIN, LOW); 

  // Tempo do pulso no ECHO
  duration = pulseIn(ECHO_PIN, HIGH); // Calcula o tempo que o sinal leva para voltar

  // Calcula a distância com base no tempo de ida e volta do sinal
  // Fórmula para calcular a distância:
  distance = duration * 0.034 / 2;   // Fórmula: distância = (tempo de ida e volta * velocidade do som no ar) / 2

  // Explicação da fórmula:
  // A função pulseIn mede o tempo que o sinal ultrassônico leva para ir e voltar.
  // 0.034 cm/us é a velocidade do som no ar, onde cada microssegundo de viagem corresponde a 0.034 cm.
  // Dividimos o resultado por 2 porque o tempo medido corresponde à ida e volta do sinal, 
  // então devemos dividir por 2 para obter apenas a distância até o objeto.

  // Exibe a distância no LCD
  lcd.setCursor(0, 1);  // Posiciona o cursor na linha 2, coluna 0
  lcd.print("    ");     // Limpa a linha para evitar sobreposição de números
  lcd.setCursor(0, 1);  // Posiciona o cursor novamente
  lcd.print(distance);  // Exibe a distância calculada no LCD
  lcd.print(" cm");     // Adiciona "cm" ao final da distância exibida

  // Aciona o LED e buzzer se a distância for menor que 50 cm
  if (distance > 0 && distance < 50) {
    digitalWrite(LED_PIN, HIGH);   // Acende o LED
    digitalWrite(BUZZER_PIN, HIGH); // Aciona o Buzzer
  } else {
    digitalWrite(LED_PIN, LOW);    // Desliga o LED
    digitalWrite(BUZZER_PIN, LOW); // Desliga o Buzzer
  }

  delay(500); // Atualiza a cada 0.5 segundos
}

```
---

### Passo 3: Processamento e Lógica de Alerta
- Aquisição de Dados:
A distância é calculada com base no tempo de ida e volta do pulso ultrassônico medido pelo sensor HC-SR04. O sensor emite um sinal de ultrassom pelo pino TRIG, que viaja até um objeto e é refletido de volta para o sensor, sendo captado pelo pino ECHO.

- Fórmula de Distância:
A distância é calculada com a seguinte fórmula:
![image](https://github.com/user-attachments/assets/03ddbc55-c1e0-48b6-90f5-520ef8811517)

- Duração do pulso: Tempo total de ida e volta do sinal ultrassônico (medido em microssegundos).
0.034: Velocidade do som no ar (340 m/s) convertida para cm/μs.
- Divisão por 2: O sinal percorre ida e volta, então a distância deve ser dividida para considerar apenas o trajeto de ida.

## Teste e Validação

Para garantir o bom funcionamento do **Sistema de Prevenção de Quedas**, é necessário realizar os seguintes testes:

1. **Monitoramento de Distância no LCD**:
   - **Objetivo**: Verificar se o sistema exibe corretamente a distância entre o paciente e a borda da cama ou cadeira no LCD 16x2.
   - **Procedimento**: Posicione o sensor HC-SR04 a uma distância conhecida da borda da cama ou cadeira. A distância medida pelo sensor deve ser exibida em tempo real no LCD, com a leitura atualizada a cada 500 ms.

2. **Validação dos Atuadores (LED e Buzzer)**:
   - **Objetivo**: Validar se os alertas visuais e sonoros são acionados quando o paciente se aproxima da borda de forma crítica (distância inferior a 50 cm).
   - **Procedimento**: Simule a aproximação de um paciente à borda da cama ou cadeira, aproximando um objeto (como uma mão ou outro objeto) a menos de 50 cm do sensor. O LED deve acender, e o buzzer deve emitir um som contínuo, indicando o risco de queda.

3. **Monitor Serial**:
   - **Objetivo**: Conferir os valores medidos pelo sensor e garantir que o cálculo da distância esteja correto.
   - **Procedimento**: Abra o **Monitor Serial** na IDE do Arduino e verifique se os valores de distância (em centímetros) correspondem às leituras esperadas quando o sensor é posicionado a diferentes distâncias da borda da cama ou cadeira.
![image](https://github.com/user-attachments/assets/38ed40f3-2ae0-45b3-af4e-6244e130a6a0)


---

## Expansões e Melhorias

Sugestões para expandir e melhorar o **Sistema de Prevenção de Quedas**:

1. **Conexão Wi-Fi (Para Monitoramento Remoto)**:
   - **Objetivo**: Integrar um **ESP32** para enviar os dados de distância para um servidor na nuvem, permitindo que os cuidadores ou profissionais de saúde monitorem o paciente remotamente.
   - **Como**: Utilize um módulo Wi-Fi (ESP32 ou ESP8266) para enviar os dados de distância para uma plataforma como **Blynk** ou **ThingSpeak**, permitindo o monitoramento em tempo real por meio de um aplicativo ou dashboard.

2. **Adição de Sensores**:
   - **Objetivo**: Adicionar sensores complementares para tornar o sistema mais completo e seguro.
   - **Como**:
     - **Sensor de Temperatura**: Monitorar a temperatura corporal do paciente, permitindo detectar variações que possam indicar febre ou mal-estar.
     - **Sensor de Movimento**: Detectar movimentos do paciente para verificar se ele está tentando sair da cama ou cadeira, acionando alertas preventivos de queda.

3. **Alarme Remoto via Bluetooth**:
   - **Objetivo**: Configurar uma comunicação **Bluetooth** para enviar alertas diretamente para um aplicativo móvel, notificando os cuidadores sobre a proximidade do paciente à borda de uma superfície.
   - **Como**: Usando um módulo **HC-05 Bluetooth** ou **ESP32**, é possível criar um aplicativo simples para Android ou iOS que receberá notificações quando o paciente estiver em risco de queda.

4. **Integração com Sistemas de Monitoramento de Saúde**:
   - **Objetivo**: Integrar o sistema com plataformas de monitoramento de saúde mais amplas, como sistemas de monitoramento de sinais vitais ou sistemas hospitalares.
   - **Como**: Enviar dados do sistema de prevenção de quedas para sistemas já existentes em hospitais ou clínicas para uma resposta mais coordenada e eficaz.

---

## Como a Distância Impacta a Detecção de Queda:

No **Sistema de Prevenção de Quedas**, a **distância medida** entre o paciente e a borda da cama ou cadeira tem um impacto direto na detecção do risco de queda. O sensor HC-SR04 mede constantemente a distância do paciente em relação à borda da superfície. Quando a distância se aproxima de um valor crítico (por exemplo, **menos de 50 cm**), isso indica que o paciente está muito próximo da borda e pode cair. 

**O sistema gera um alerta visual (LED) e sonoro (buzzer)** para avisar os cuidadores ou profissionais de saúde, permitindo que eles intervenham rapidamente e prevenam a queda antes que ela aconteça. 

Este tipo de monitoramento contínuo é particularmente útil para pacientes com mobilidade reduzida, idosos ou pacientes em recuperação de cirurgias, onde a prevenção de quedas é uma prioridade para a segurança.

## Referências

Liste todas as referências e links úteis para guias, bibliotecas, e materiais adicionais que ajudem a complementar o tutorial.

**Video sobre o sensor HC-SR04**
https://www.youtube.com/watch?v=n-gJ00GTsNg

**Video sobre um circuito de alerta usando HC-SR04**
https://www.youtube.com/watch?v=QEIl2Nxot5M


---

Com este circuito podemos ter uma rápida atuação quando um paciente com mobilidade limitada cair, podendo evitar uma tragédia!
