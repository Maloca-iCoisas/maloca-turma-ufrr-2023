# Sistema de controle de temperatura para áreas hospitalares sensiveis

**Descrição** Neste tutorial iremos construir um circuito para controle de temperatura para pontos onde não pode haver grande flutuação de temperatura.

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

Áreas sensíveis como, UTIs, salas de cirurgia e até mesmo farmácias, tem temperaturas parametrizadas para o controle higiênico e não proliferação de agentes infecciosos. Dessa forma podemos construir um sistema com sensor de temperatura e que também emite um sinal sonoro quando a temperatura ambiente aumentar a um nível estabelecido. Posteriormente o sistema pode substituir  o alerta sonoro e avisar apenas enfermeiros ou chefes de departamento para melhor visualização do caso.

---

## Requisitos

## Hardware
- **Placa**: Arduino Uno ou compátivel;
- **Atuadores**: sensor de temperatura LM35 e piezo buzzer;
- **Outros componentes**: resistor de 1kΩ, fios condutores (jumpers) e uma protoboard;

## Software
- **Linguagens**: C++ para Arduino
- **IDE**: Arduino IDE

---

## Configuração do Ambiente

## Passo 1: Instalação do Software

- **Arduino IDE**: Baixe e instale o arduino IDE a partir do https://www.arduino.cc/en/software.

## Passo 2: Configuração da Placa

1. Com o software Arduino IDE aberto, conecte a placa Arduino ao computador via USB.
2. Clique no quadro “Select Board” e em seguida “Select other board and port” como mostram nas imagens abaixo:

<img src="Tutorial 1.png" alt="tela do arduino" />

<img src="Tutorial 2.png" alt="tela do arduino" />

3. Digite no quadro ou pesquise pela placa “Arduino Mega” ou “Mega 2560”.
 
 <img src="Tutorial 3.png" alt="tela do arduino" />

4. Escolha o port onde a placa Arduino está conectada.

---

## Montagem do Circuito 

Para montar o circuito, siga as instruções abaixo e se preciso analise o circuito modelo da imagem:

1. Preparação da Protoboard e Conexão do GND:
- Conecte o pino **GND** do Arduino à linha de alimentação negativa (linha preta) da protoboard. Esta linha servirá como terra para todo o circuito.

2. Conecte o piezo buzzer e o sensor de temperatura:
- Coloque os dois atuadores na protoboard, deixando espaço suficiente entre eles para as conexões.

3. Conexão do Resistor:
- Conecte um resistor de 1kΩ a entrada positiva do sensor de temperatura, isso diminuirá a corrente evitando com que o sensor venha a entrar em curto.

4. Conexão da Linha Positiva da Protoboard:
- Conecte os terminais positivos (indicado com um +) da protoboard ao pino **5V** do Arduino para fornecer alimentação estável aos componentes do circuito.

5. Conexão dos atuadores aos Pinos do Arduino:
- Piezo Buzzer: Conecte o terminal positivo do piezo ao pino **~11** e o negativo no terra do circuito.
- Sensor de temperatura LM35: Conecte o terminal do resistor do sensor ao terminal positivo da protoboard, o terminal central ao pino **A0** e o terminal restante ao terra.

<img src="Circuito 1.png" alt="circuito simulado" />

---

## Programação

## Passo 1: Configuração dos Atuadores

Definiremos a ligação dos pinos aos terminais dos atuadores
```cpp
//Definição dos pinos
const int alarme = 11; //Pino do Piezo Buzzer
int pin = A0; //Pino do Sensor
float temp = 0; //Variável que receberá o valor obtido pelo sensor


void setup(){
  //configuração do alarme
  pinMode(alarme, OUTPUT);
  Serial.begin(9600);
}
```

## Passo 2: Configuração do sensor de temperatura e execução

Essa parte do código irá, por meio de alguns cálculos matemáticos, transformar os sinais analógicos do sensor de temperatura em algo visível para o usuário e máquina.

```cpp
void loop()
{
  //executável que vai rodar a função temperatura
    temperatura();
}
void temperatura()
{
  //configuração do sensor, transformará sinais analógicos em sinais visiveis para o usuário
  temp = analogRead(pin)*5; // Multiplicação pela tensão de entrada.
  temp = temp/1024; // Divisão pelo numero de possibilidades que o arduino pode processar o dado analógico do sensor de temperatura (0 - 1023) é simplesmente uma transformação de dado analógico para digital.
  temp = temp-0.4971; // Essa linha é uma correção para os dados do sensor de temperatura utilizado, verifique se o seu sensor vai funcionar sem esta linha em especifico.
  temp = temp*100; // Multiplicação por 100 para transformar o dado digital em temperatura.
  Serial.print(temp);
    Serial.println("C");
  //definição da temperatura
if (temp >= 36)
{
  //tone para definir como o alarme tocará o som
    tone(alarme, 1000, 1000);
    Serial.println("QUENTE, muita gente em área sensivel");
}
//delay para resposta do sinal e ativar o alarme
delay(2000);
}
```

---

## Teste e validação

Para garantir que o projeto funcione corretamente, realize os seguintes testes:

1. **Verificação da Conexão dos atuadores**: Certifique-se de que o piezo buzzer e o sensor de temperatura estão conectados nos pinos corretos e orientados com os terminais certos.
2. **Teste da Sequência**: Carregue o código para o Arduino e observe a ocorrência de algum erro de digitação, sintaxe ou lógica
3. **Ajuste de Tempo**: Se necessário, ajuste o tempo de delay para modificar a duração do alarme

---

## Expansão e Melhoria

Sugestões para melhoria do projeto, como: 
- Trocar o sistema de alarme para notificação pessoal responsável poder lidar com o problema sem sons altos que podem acabar por atrapalhar tratamentos hospitalares.
- Introdução a rede IoT para monitoramento remoto.

---

# Referências
1. Link da simulação: https://www.tinkercad.com/things/kn0QDPxIEFB-sensor-de-temperatura-com-piezo?sharecode=ipkQi37zlBnBepOepR5eI2nSm_RfoOpNBUo8sZZqTX4

2. Documentação do Arduino: https://docs.arduino.cc/

3. Tutorial para sensor de temperatura LM35: https://youtu.be/VjHfjkd5KuE?si=UXcTlQhuX7iZRdcG

---

Esse tutorial fornece introdução à sensores para arduino, simulando um sistema de monitoramento de temperatura para ambientes hospitalares.