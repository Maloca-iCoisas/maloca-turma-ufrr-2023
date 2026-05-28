# Alarme de Segurança para Portas e Janelas

**Descrição:** O seguinte tutorial tem o intuito de desenvolver um protótipo de sistema simples capaz de detectar quando portas e janelas são abertas em situações que é necessário constante vigilância de um paciente.

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

Existem muitas situações que podem colocar um paciente em risco, principalmente aqueles que necessitam de constante monitoramento, por exemplo em casos de transtornos psíquicos severos, como depressão e esquizofrenia. Essas doenças psiquiátricas são conhecidas por trazer pensamentos intrusivos para seus portadores, como saltar de uma janela por exemplo. O sistema criado neste tutorial funciona como um mecanismo a mais de segurança, além das já desenvolvidas (como travas, fechaduras, alarmes) para evitar que situações não desejadas sejam evitadas.

---

## Requisitos

### Hardware

- **Placa**: Arduino UNO
- **Sensores**: Sensor de distância ultrassônico
- **Atuadores**: Buzzer
- **Outros componentes**: Jumpers, 1 resistor de 1kOhm, protoboard e fonte de alimentação para a placa.

### Software

- **Linguagens**: C/C++ para Arduino
- **IDE**: Arduino IDE
- **Bibliotecas**: Não é necessário bibliotecas externas

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

**Arduino IDE**:
  1. Através do site de download do Arduino (https://www.arduino.cc/en/software), selcione o arquivo de acordo com seu sistema operacional.
  2. Instale normalmente e abra-o para as configurações do projeto.


### Passo 2: Configuração das Placas
  
  1. Na tela inicial do Arduino IDE, selecione “Select Board” e depois “Select other board and port” para selecionar a placa a ser utilizada.

  ![1](https://github.com/user-attachments/assets/8d8eba8e-d730-41ac-840c-23d00e4788ed)


  2. No campo “Boards”, digite a placa a ser utilizada, no nosso caso será o Arduino UNO. Em "Ports", selecione a porta USB na qual a placa está conectada. Depois de selecionar, clique em “OK” no canto inferior direito.
     
  ![config_ide2](https://github.com/user-attachments/assets/724aae51-bf4c-4fa0-b66e-1becae8ee43f)


---

## Montagem do Circuito

**• Alimentação e aterramento do circuito**
  1. Conecte o pino GND do Arduino na linha de alimentação negativa (linha preta) do protoboard.
  2. Faça o mesmo com o pino 5V do Arduino e conecte na linha de alimentação positiva (linha vermelha).
  *O pino GND funciona como terra para todo o circuito, enquanto o pino de 5V serve como fonte de energia.*

**• Conectando o sensor de distância**
  1. Conecte o pino GND do sensor na linha de alimentação negativa
  2. Conecte o pino SIG do sensor no pino digital 7, ou outro de sua preferência
  3. Conecte o pino 5V na linha de alimentação positiva da protoboard
     
**• Conectando o buzzer**
  1. Ligue o terminal negativo do buzzer na linha negativa de alimentação
  2. Ligue o terminal positivo do buzzer em um resistor de 1kOhm e depois no pino digital 13, ou se sua preferência.
  *O resistor irá limitar a energia que passa pelo buzzer, evitando a queima.*

  ![Captura de tela 2024-11-19 010546](https://github.com/user-attachments/assets/ea7563e5-5006-4b4e-8fc7-6aa07d53be76)

---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Aqui definiremos os pinos dos sensores no Arduino e suas saídas:

```C
//declaração dos pinos e tipos de dados
int sensor = 7; 
int buzzer = 13;
long duracao, cm;

void setup()
{
  pinMode(7, OUTPUT); //sensor como saída
  pinMode(13, OUTPUT); //buzzer como saída
  Serial.begin(9600);
}

//função para converter microssegundos captados pelo sensor em centímetros
/*A velocidade do som é 340 m/s ou 29 microssegundos por centímetro.
  O ping viaja para fora e para trás, para encontrar a distância do objeto que
  pega metade da distância percorrida.*/
long microsegs_para_cm (long microsegundos){
  return microsegundos / 29 / 2;
}
```

### Passo 2: Processamento e Lógica de Alerta

Lógica para o sensor detectar movimento e duração para posteriormente ser convertido em cm, podendo acionar o buzzer

```C
void loop()
{
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, OUTPUT); //declaração do sensor como saída de dados

  /*configuração para o sensor emitir o sinal e tentar detectar o objeto,
  enviando sinais baixos e altos*/
  digitalWrite(sensor, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensor, LOW);
  
  pinMode(sensor, INPUT); //declaração do sensor como entrada de dados
  duracao = pulseIn(sensor, HIGH); //captura a duração de um pulso, caso exista, e armeza na variável duracao
  
  cm = microsegs_para_cm(duracao);
  
  //condição para acionar o buzzer caso a distância entre sensor e objeto seja maior que 250cm
  //ou maior que 366cm (o máximo que o sensor detecta)
  if (cm > 250 || cm = 366){
    tone(buzzer, 500, 200);
    delay(200);
  }
  
  //imprime os centimetros lidos atualmente pelo sensor
  Serial.print(cm);
  Serial.print(" cm, \n");
               
  delay(100);
}
```

---

## Teste e Validação

  **1. Placa ligada o computador:** Certifique-se que a placa esteja devidamente ligada no computador pela porta USB e sendo reconhecida na IDE em "PORTS".

  **2. Ligações entre os sensores e a placa:** Certifique-se que todas ligações entre os sensores, o resistor e a placa estejam devidamente no lugares corretos para evitar transtornos. A plataforma Tinkercad (https://www.tinkercad.com/) pode ser utilizada para uma primeira modelagem do sistema.
     
  **3. Distância que aciona o alarme:** verifique se o acionamento pela distância estabelecida é atendido e se o alarme é tocado.
    
  **4. Teste em ambientes:** Faça o teste em lugares que o sistema possa ficar de maneira estratégica e que consiga executar sua função. Teste em diferentes posições de portas e janelas, e em situações onde a abertura dessas é variada, como hospitais e domicílio.
     
  ![Captura de tela 2024-11-19 145830](https://github.com/user-attachments/assets/ddff2b32-2e27-44d1-a723-cffb21254666)


---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Ajuste a tolerância de distância que ativa o alarme, conforme necessário.
- Uso de módulos de comunicação Wi-Fi ou Bluetooth para enviar alertas de maneira mais conveniente.
- Uso de LEDs coloridos para gerar atenção visual.

---

## Referências

- Funcionamento do sensor de distância ultrassônico: https://rascunhos.pt/article/Medir-a-velocidade-do-som
- Como usar sensor de distância no Tinkercad: https://www.youtube.com/watch?v=4m0rv3p4Os8
- Especificações do sensor: https://www.parallax.com/product/ping-ultrasonic-distance-sensor/
- Documentação Arduino: https://docs.arduino.cc/

---
