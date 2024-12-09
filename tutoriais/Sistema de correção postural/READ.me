#  Sistema de Monitoramento de Postura com Feedback utilizando o MPU6050X' 
## Descrição:
  - O objetivo deste projeto é detectar a postura do usuário em tempo real e alertá-lo se ele estiver em uma postura incorreta. Para isso, o sistema será capaz de medir os ângulos de inclinação do corpo e fornecer feedback através de um LED ou buzzer caso a postura seja inadequada.
#:


## Índice 
1-  [Introdução](#introdução)

2-  [Requisitos](#requisitos)

3- [Configuração do ambiente](#configuração-do-ambiente)
  - [Parte de software](#parte-de-software)
  - [Montagem do circuito](#montagem-do-circuito)

4- [Programação](#programação)

5- [Teste e Validação](#teste-e-validação)

6- [Informações Adicionais](#informações-adicionais)

7-[Expansão e melhorias](#Expansão-e-melhorias)

8-[Referências](#Referências)

  
 
# Introdução
- Manter uma boa postura é essencial para a saúde e o bem-estar geral, pois impacta diretamente a funcionalidade do corpo. Uma postura inadequada pode sobrecarregar músculos e articulações, causando desconfortos, dores crônicas, fadiga e até condições mais graves, como escoliose, hipercifose ou hérnias de disco. 
Para enfrentar esses desafios, sistemas de correção postural, como o circuito aqui apresentado , desempenham um papel fundamental. Utilizando sensores como o MPU6050, esse dispositivo monitora a inclinação do corpo em tempo real e emite alertas visuais e sonoros (via LED e buzzer) quando detecta desvios inadequados. Isso incentiva o usuário a corrigir sua postura imediatamente, promovendo hábitos saudáveis e prevenindo problemas futuros. Dessa forma, um corretor postural não apenas auxilia na prevenção de complicações musculoesqueléticas, mas também contribui para a reeducação postural e para uma melhor qualidade de vida.


# Requisitos 
- **1x ESP32**
- **1x Sensor MPU6050**
- **1x LED**
- **1x Buzzer**
- **1x Protoboard**
- **1x Resistor de 220Ω**
- **Fios jumper para conexões**



## Software
- C/C++ 
- Arduíno IDE

# Configuração-do-ambiente 

## Software
- **Linguagem de Programação**: C/C++
- **Ambiente de Desenvolvimento**: Arduino IDE

## Configuração do Ambiente

### Parte de Software

### Passo 1: Fazer o Download da Arduino IDE

1. Acesse o site oficial da **[Arduino](https://www.arduino.cc/en/software)**.
2. Selecione a versão do Arduino IDE para o seu sistema operacional (Windows, macOS ou Linux).
3. Faça o download e instale o **Arduino IDE** no seu computador.

### Passo 2: Instalar as Bibliotecas Necessárias

Após abrir o Arduino IDE, siga os passos abaixo:

#### 1. Biblioteca **Wire.h** (Comunicação I2C):
- A biblioteca **Wire** já está incluída no Arduino IDE, então não há necessidade de fazer o download manual. Ela é utilizada para a comunicação I2C entre o **ESP32** e o **sensor MPU6050**.

#### 2. Biblioteca **MPU6050.h** (Sensor MPU6050):
- A biblioteca **MPU6050** pode ser instalada diretamente pelo Arduino IDE.
  - Vá em **Sketch** → **Incluir Biblioteca** → **Gerenciar Bibliotecas**.
  - Na janela de **Gerenciador de Bibliotecas**, pesquise por **MPU6050**.
  - Selecione a biblioteca **MPU6050** e clique em **Instalar**.

#### 3. Biblioteca do **ESP32**:
- Para programar o **ESP32**, você precisa instalar a placa no Arduino IDE.
  1. Vá em **Arquivo** → **Preferências**.
  2. Na seção **URLs Adicionais de Gerenciadores de Placas**, adicione o seguinte link:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
  3. Em seguida, vá em **Ferramentas** → **Placa** → **Gerenciador de Placas**.
  4. Pesquise por **ESP32** e instale a versão mais recente da plataforma **ESP32**.

### Passo 3: Digite o Código

Agora, no Arduino IDE, digite ou cole o código que será utilizado para o **monitoramento de postura** com o sensor **MPU6050**, **LED** e **buzzer**.

### Passo 4 : Compile e Execute o Código
- Verifique o código e faça o upload para a placa ESP-32 após verificar se a conexão das portas USB e a placa escolhida estão corretas.
- Após o upload, o **ESP32** irá iniciar a execução do código.

## Montagem do circuito
### Passo 1: Componentes 
- Faça a separação dos componentes que serão necessários para a montagem desse circuito  
### Passo 2: Conectar o ESP32 à Protoboard

- Conecte o **GND** do **ESP32** ao **GND** da **protoboard**.
- Conecte o **5V** do **ESP32** ao **polo positivo** da **protoboard**.

### Passo 3: Conectar o Sensor MPU6050 ao ESP32

Conecte os pinos do sensor **MPU6050** ao **ESP32** da seguinte forma:

- **VCC** do **MPU6050** -> **3.3V** do **ESP32**
- **GND** do **MPU6050** -> **GND** da **protoboard**
- **SCL** do **MPU6050** -> **GPIO 23** do **ESP32**
- **SDA** do **MPU6050** -> **GPIO 22** do **ESP32**

### Passo 4: Conectar o LED à Protoboard

1. Insira o **LED** na **protoboard**.
2. Conecte o **anodo** (pino longo) do **LED** à **porta GPIO 13** do **ESP32**.
3. Conecte o **catodo** (pino curto) do **LED** a um **resistor de 220Ω**.
4. Conecte o outro lado do resistor ao **polo negativo da protoboard** (GND).

### Passo 5: Conectar o Buzzer à Protoboard

1. Conecte o **pino negativo** (fio preto) do **buzzer** ao **polo negativo da protoboard** (GND).
2. Conecte o **pino positivo** do **buzzer** à **porta GPIO 34** do **ESP32**.

### Passo 6: Iniciar o Código

Agora, com todas as conexões feitas, inicie o código no ambiente de desenvolvimento (como o Arduino IDE ou o Wokwi) para testar o monitoramento da postura com feedback visual (LED) e sonoro (buzzer).
- Idealmente deve estar assim após os passos anteriormente ditos:

![Circuito](https://github.com/ArthurRamos26/Tutorial_Maloca_2/blob/b93d4d0eb7de3551f537ff43469fd40d67a6202d/Circuito%20.png)


# Programação 
## O Código utilizado foi : 
```` cpp 
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;


const int ledPin = 13;   // Pino do LED
const int buzzerPin = 34; // Pino do Buzzer

// Definindo o limite de inclinação (em graus)
const float angleThreshold = 10.0;

void setup() {
  Serial.begin(115200);
  
  // Inicializa a comunicação I2C
  Wire.begin(22, 23);  // Pinos SDA e SCL definidos

  // Inicializa o sensor MPU6050
  mpu.initialize();
  
  // Configura os pinos do LED e buzzer
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Testa a conexão do MPU6050
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 não está conectado!");
    while (1);
  }

  Serial.println("MPU6050 Conectado!");
}

void loop() {
  // Variáveis para armazenar os dados de aceleração
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  // Lê os dados do sensor MPU6050
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Calcular o ângulo de inclinação com base na aceleração
  float angleX = atan2(ay, az) * 180.0 / PI;  // Inclinação no eixo X
  float angleY = atan2(ax, az) * 180.0 / PI;  // Inclinação no eixo Y

  // Exibir os valores de ângulo no monitor serial
  Serial.print("Angle X: ");
  Serial.print(angleX);
  Serial.print("  Angle Y: ");
  Serial.println(angleY);

  // Lógica para verificar postura
  if (abs(angleX) > angleThreshold || abs(angleY) > angleThreshold) {
    // Postura incorreta
    digitalWrite(ledPin, HIGH); // Ativa o LED
    digitalWrite(buzzerPin, HIGH); // Ativa o Buzzer
    Serial.println("Postura incorreta! Corrija sua postura.");
  } else {
    // Postura correta
    digitalWrite(ledPin, LOW);  // Desativa o LED
    digitalWrite(buzzerPin, LOW);  // Desativa o Buzzer
    Serial.println("Postura correta!");
  }
  
  delay(500); // Atraso de 500ms antes da próxima leitura
}

`````


### Explicação do código 
-  No início do código, são importadas as bibliotecas responsáveis pelo funcionamento do sensor MPU-6050 e pela comunicação I2C. Em seguida, são declarados os pinos utilizados para o LED e o buzzer, além da definição do limite máximo de inclinação permitida, considerado saudável. Esse limite foi estabelecido com base em estudos que indicam que angulações superiores a 10° podem ser um indicativo de escoliose ou aumentar a predisposição a danos na postura.

- Após a declaração dos pinos e variáveis, ocorre a inicialização do sensor MPU-6050, garantindo sua conexão correta com o sistema. Os pinos do LED e do buzzer são configurados como saídas (OUTPUT), permitindo que esses dispositivos sejam controlados pelo microcontrolador para emitir alertas visuais e sonoros quando necessário.

- O cálculo da inclinação é realizado com base nos dados de aceleração coletados pelo sensor. Utiliza-se a função atan2 para calcular os ângulos nos eixos X e Y. Esses valores inicialmente estão em radianos, e para convertê-los em graus, multiplica-se pelo fator de conversão 180/𝜋. Essa conversão é necessária, pois os graus são uma unidade mais intuitiva para interpretar a inclinação em comparação com radianos, facilitando a análise e definição de limites como o ângulo de 10° estabelecido no código.   

# Teste-e-Validação 
## Testes
- Foi realizado o teste no simulador wokwi onde funcionou perfeitamente 
## Resultados : 
- 
###  O que foi implementado:
- Um cicuito que avisa quado há necessidade de correção postural 
### Ajudar No Tratamento:
- Esse sistema pode ajudar tanto na prevenção de lesôes na região da coluna quanto no tratamento de doenças relativas a essa região como: Escoliose, Hipercifose,Lombalgia,Hérnia De Disco.

# Experimentos:

### Teste No Simulador :
- Segue a foto Do circuito no simulador funcionando perfeitamente

### Resultados dos Testes:


- Em caso de postura correta : 

![Correta](https://github.com/ArthurRamos26/Tutorial_Maloca_2/blob/b93d4d0eb7de3551f537ff43469fd40d67a6202d/Posturacorreta.png)
- Em caso de Postura incorreta:

![Postura Incorreta](https://github.com/ArthurRamos26/Tutorial_Maloca_2/blob/b93d4d0eb7de3551f537ff43469fd40d67a6202d/Postura%20incorreta.png)
# Expansão-e-melhorias
- Uma melhoria seria tentar reduzir o tamanho do circuito para tornar mais fácil o seu uso 

# Referências
  O link do projeto no simulador : https://wokwi.com/projects/305569599398609473
