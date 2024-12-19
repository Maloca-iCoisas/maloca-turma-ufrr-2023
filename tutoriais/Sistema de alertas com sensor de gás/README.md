# Sistema de alerta para gases nocivos em ambientes hospitalares
**Descrição:** O seguinte tutorial tem o intuito de desenvolver um protótipo de sistema simples capaz de emitir alertas sonoros e visuais, a partir da detecção de alguns gases nocivos à saúde humana no ambiente médico hospitalar.  

![sistema em funcionamento](https://github.com/user-attachments/assets/5f7ae597-bf7d-4882-8307-60f4adc48536)

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
</br>

# Introdução
<p align="justify">A manipulação de gases como oxigênio, dióxido de carbono e óxido nítrico é muito comum em ambientes hospitalares, pois são usados principalmente para finalidades médicas. Porém, outros tipos de gases podem ser encontrados nesses ambientes, como o gás de cozinha, que é inflamável. Muitos deles são incolores e inodoros, não sendo possível detectar num primeiro momento se estão dispersos em espaços indevidos, seja por vazamento ou administração incorreta.

Esse projeto utiliza o sensor MQ-6 para detectar a presença de gases no ar – especificamente de gás de cozinha, isobutano e propano – que são inflamáveis, e emitir alerta sonoro e visual, caso detectado.</p>

---

</br>

## Requisitos
### Hardware

- **Placa:** Arduino
- **Sensores:** Sensor de gás MQ-6
- **Atuadores:** Buzzer, LED vermelho
- **Outros componentes:** Jumpers, 1 resistor de 10 kOhm, 1 resistor de 100 Ohm, protoboard e fonte de alimentação

### Software
- **Linguagens:** C/C++ para Arduino
- **IDE:** Arduino IDE
- **Bibliotecas:** Não é necessário bibliotecas externas

---
</br>

## Configuração do Ambiente

### Passo 1: Instalação do Software

**No Arduino IDE:**
  1. Através do site de download do Arduino (https://www.arduino.cc/en/software), selecione o arquivo de acordo com seu sistema operacional.
  2. Instale normalmente e abra-o para as configurações do projeto.

  ![config_ide1](https://github.com/user-attachments/assets/8b686755-e429-45bc-90f6-f73c3100f95d)

</br>

### Passo 2: Configuração das Placas
  1. Na tela inicial do Arduino IDE, selecione “Select Board” e depois “Select other board and port” para selecionar a placa a ser utilizada.
  2. No campo “Boards”, digite a placa a ser utilizada, no nosso caso será o Arduino UNO. Depois de selecionar, clique em “OK” no canto inferior direito.

  ![config_ide2](https://github.com/user-attachments/assets/d0c578a6-28b9-4abc-ab08-983ecc372637)


---
</br>

## Montagem do Circuito

Para montar o circuito, podemos utilizar a plataforma Tinkercad, como modo de testar e adaptar conforme necessário.
Siga os passos seguintes:

**• Alimentação e aterramento do circuito**
  1. Conecte o pino GND do Arduino na linha de alimentação negativa (linha preta) do protoboard. O pino GND funciona como terra para todo o circuito, enquanto o pino de 5V serve como fonte de energia;
  2. Faça o mesmo com o pino 5V do Arduino e conecte na linha de alimentação positiva (linha vermelha).

**• Conectando o sensor de gás**
  1. O pino B2 deve ser conectados no GND;
  2. O pino H2 também deve ser conectado ao GND, porém com o resistor de 10kOhm;
  3. O pino B1 deve ser conectado a uma porta analógica de sua preferência do Arduino;
  4. Os pinos A1, H2, A3, devem ser conectados todos na linha de alimentação positiva, ou seja, no 5V.
  
**• Conectando o buzzer**
  1.  Ligue o terminal negativo do buzzer na linha negativa de alimentação;
  2.  Ligue o terminal positivo do buzzer em um resistor de 1kOhm e depois no pino digital 13, ou se sua preferência. O resistor irá limitar a energia que passa pelo buzzer, evitando a queima.
     
**• Conectando o LED**
  1. Conecte o catodo do LED (lado negativo) no GND da placa;
  2. O anodo (lado positivo) do LED deve ser conectado com o resistor de 100kOhm a uma porta digital de sua preferência do Arduino.

  ![esquema de conexão](https://github.com/user-attachments/assets/8a818023-04b7-4005-8bc4-cba9dc153ae8)


---
</br>

## Programação
### Passo 1: Configuração dos Sensores e Atuadores

***Definição do pinos a serem usados***

```c
int gasSensorPin = A1;  // Pino analógico conectado ao sensor de gás
int ledPin = 2;         // Pino do LED de aviso
int buzzerPin = 4;      // Pino do buzzer

// Limite de detecção de gás
const int limite_gas = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(gasSensorPin, INPUT);

  Serial.begin(9600);

  Serial.println("Sensor de Gas Iniciado");
}
```

### Passo 2: Processamento e Lógica de Alerta

**Lógica utilizada para deteccção, sendo cabível ajustes conforme necessidade**

```c
void loop() {
  // Leitura do sensor
  int nivel_gas = analogRead(gasSensorPin);

  // Exibe o valor do sensor no monitor serial
  Serial.print("Nivel de gas: ");
  Serial.println(nivel_gas);

  // Verifica se o valor excede o limite
  if (nivel_gas > limite_gas) {
    // Aciona o LED e o buzzer
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    tone(buzzerPin, 700, 500);
    Serial.println("Alerta: Vazamento detectado!");
  } else {
    // Desliga o LED e o buzzer
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  // Pequeno atraso para evitar leitura excessiva
  delay(500);
}
```

---
</br>

## Teste e Validação

 - **Ligações entre os sensores e a placa:** Certifique-se que todas ligações entre os sensores, o resistor e a placa estejam devidamente no lugares corretos para evitar transtornos. A plataforma Tinkercad pode ser utilizada para uma primeira modelagem do sistema.
  
 - **Verificação do buzzer:** Ajuste o buzzer conforme a sua necessidade. Utilize o campo *tone* no código para ajustar tonalidade e repetição do som emitido.

 - **Teste em ambientes:** Faça o teste em lugares que o sistema possa ficar de maneira estratégica e que consiga executar sua função. Faça o teste com o gás de cozinha, é mais comum de ser encontrado, e faça ajustes no campo *limite_gas* do código para se adequar ao limite na qual você esteja buscando, conforme seu objetivo.
Acionamento do sistema: Verifique se, quando exposto ao gás, o sensor é capaz de detectá-lo e se o sistema será capaz de acionar os gatilhos de ativação do LED e buzzer. Você pode verificar isso no Serial Monitor do Tinkercad ou no Arduino IDE.

---
</br>

## Expansões e Melhorias

- Uso de módulos de comunicação Wi-Fi ou Bluetooth para enviar alertas remotamente.
- Uso de mais LEDs para aumentar a atenção visual.
- Um display LCD pode ser usado para mostrar as informações de detecção.
- Adaptação do código para indicar acionamento em situações específicas, por exemplo: acionar o alarme somente caso o sensor detecte grande concentração do gás.

---
</br>

## Referências

Referências utilizadas para construção do projeto:

- [O papel dos gases medicinais em internações hospitalares | Air Liquide Healthcare Brasil](https://br.healthcare.airliquide.com/o-papel-dos-gases-medicinais-em-internacoes-hospitalares)
- [Exemplo de uso sensor AirQualityMQ13](https://wiring.org.co/learning/basics/airqualitymq135.html)
- [Sensor de Gás MQ-6 GLP Isobutano Propano - MakerHero](https://www.makerhero.com/produto/sensor-de-gas-mq-6-glp-isobutano-propano/)
- [Fazendo um Sensor de gás no Tinkercad](https://www.youtube.com/watch?v=Mk1mQ2V6FQg)
