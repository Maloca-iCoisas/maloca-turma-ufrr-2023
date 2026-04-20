# Sistema de Notificação de Medicamento

**Descrição:** Neste tutorial, vamos desenvolver um sistema automatizado para lembrar o usuário de tomar medicamentos. O sistema utiliza um display LCD, um buzzer, um servo motor e botões de confirmação e cancelamento. O projeto permite cadastrar medicamentos, definir horários de alerta e controlar o acesso ao compartimento dos remédios com um servo motor, garantindo que somente pessoas autorizadas possam acessar os medicamentos por meio de uma senha.

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

Este projeto visa criar um sistema de lembrete para medicamentos com um controle de acesso. O sistema permite que o usuário cadastre o nome do medicamento e o tempo de alarme, e use uma senha para desbloquear um compartimento controlado por servo motor. O alarme será acionado quando for hora de tomar o medicamento e o servo motor abrirá o "porta-remédio" para que o medicamento possa ser retirado. Somente pessoas com a senha correta poderão acessar os medicamentos.

---

## Requisitos

### Hardware

- **Placa**: Arduino Uno ou similar
- **Display LCD**: 16x2 LCD com comunicação paralela
- **Buzzer**: Para emitir o alarme sonoro
- **Servo Motor**: Para abrir o compartimento do remédio
- **Botões**: Para confirmação e cancelamento do alarme
- **Outros componentes**: Jumpers, resistores

### Software

- **Linguagem**: C++ para programação do Arduino
- **IDE**: Arduino IDE
- **Bibliotecas**: 
  - `LiquidCrystal` para controle do display LCD
  - `Servo` para controle do motor servo

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

1. **Arduino IDE**: Baixe e instale a [Arduino IDE](https://www.arduino.cc/en/software) se ainda não a tiver instalada.
![imagm alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/tutorial-4/tutoriais/Sistema%20de%20Notifica%C3%A7%C3%A3o%20de%20Medicamentos/download%20arduino.png?raw=true)
3. **Bibliotecas**: As bibliotecas `LiquidCrystal` e `Servo` já estão incluídas na IDE do Arduino, não sendo necessário instalar manualmente.

### Passo 2: Configuração das Placas
- **Configuração no Arduino:**
1. Conecte a placa Arduino ao computador utilizando o cabo USB;
2. Na IDE do Arduino, clique em "Select other board and port" (Selecionar outra placa e porta);
3. Escolha a opção "Arduino Mega or Mega 2560";
4. Por último, selecione a porta correta na IDE do Arduino.
   
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/tutorial-4/tutoriais/Sistema%20de%20Notifica%C3%A7%C3%A3o%20de%20Medicamentos/arduino.png?raw=true)

---

## Montagem do Circuito

1. **LCD**: Conecte os pinos do display LCD ao Arduino conforme o código:
   - rs → pino 12
   - en → pino 11
   - d4 → pino 5
   - d5 → pino 4
   - d6 → pino 3
   - d7 → pino 2

2. **Buzzer**: Conecte o buzzer ao pino 7 do Arduino.

3. **Botões**: Conecte o botão de confirmação ao pino 10 e o botão de cancelamento ao pino 6.

4. **Servo Motor**: Conecte o servo motor ao pino 13.

> **Nota:** O servo motor pode ser usado para abrir o compartimento do medicamento, como um "porta-remédio", quando a senha for inserida corretamente.

# Circuito
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/tutorial-4/tutoriais/Sistema%20de%20Notifica%C3%A7%C3%A3o%20de%20Medicamentos/Circuito%20Notifica%C3%A7%C3%A3o.png?raw=true)

# Vista Esquemática
![imagem alt](https://github.com/sktapn/maloca-turma-ufrr-2023_Abrah-o/blob/tutorial-4/tutoriais/Sistema%20de%20Notifica%C3%A7%C3%A3o%20de%20Medicamentos/Esquema%20Notifica%C3%A7%C3%A3o.png?raw=true)

---

## Programação
A programação será dividida em várias partes para facilitar a compreensão e implementação:

1. [Configuração do Sistema](#configuração-do-sistema)
2. [Cadastro do Medicamento e Alarme](#cadastro-do-medicamento-e-alarme)
3. [Controle de Alarme e Acesso ao Porta-Remédio](#controle-de-alarme-e-acesso-ao-porta-remédio)
4. [Funções Auxiliares](#funções-auxiliares)

> **Nota:** Você pode encontrar o código completo no link do simulador.

### Passo 1: Configuração do Sistema

O sistema começa solicitando uma senha para liberar o acesso ao compartimento do medicamento. Após a senha correta, o usuário pode cadastrar o nome do medicamento, definir o tempo de alarme e o sistema irá acionar o servo motor para liberar o compartimento.

```cpp
#include <LiquidCrystal.h>
#include <Servo.h>

// Pinos do LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pinos do Buzzer
const int buzzer = 7;

// Pinos dos Botões
const int botaoConfirmacao = 10;  // Botão de confirmação
const int botaoCancelar = 6;      // Botão de cancelamento

// Servo Motor
Servo servoMotor;
const int pinoServo = 13;

// Variáveis
bool medConfirmada = false;
unsigned long alarmeHorario;
unsigned long intervaloAlarme = 60000; // Tempo inicial de 1 minuto
unsigned long ultimoAtualizaMinutos = 0;
String nomeRemedio = "";
int tempoAlertas = 1; // Tempo inicial para os alertas (em minutos)
const String senhaCorreta = "1234";
bool sistemaAberto = false;
```

### Passo 2: Cadastro do Medicamento e Alarme

Após a senha correta ser inserida, o usuário poderá cadastrar o nome do medicamento e o tempo de alarme. O sistema exibirá as informações no LCD e aguardará a confirmação do usuário.

```cpp
void cadastrarRemedio() {
    lcd.clear();
    exibirCentralizado("SISTEMA");
    exibirNaSegundaLinha("Digite nome:");
    while (true) {
        String entrada = lerSerial();
        if (entrada.length() > 0) {
            nomeRemedio = entrada;
            break;
        }
    }

    exibirCentralizado("SISTEMA");
    exibirNaSegundaLinha("Remedio:");
    lcd.print(nomeRemedio);
    delay(2000);

    lcd.clear();
    exibirCentralizado("SISTEMA");
    exibirNaSegundaLinha("Tempo (min):");
    while (true) {
        String tempoInput = lerSerial();
        if (tempoInput.length() > 0) {
            tempoAlertas = tempoInput.toInt();
            if (tempoAlertas > 0) break;
        }
    }
}
```
### Passo 3: Controle de Alarme e Acesso ao "Porta-Remédio"

Quando o alarme atingir o tempo definido, o buzzer será acionado e o servo motor abrirá o "porta-remédio" para o usuário. 

```cpp
void confirmarMed() {
    medConfirmada = true;
    lcd.clear();
    exibirCentralizado("SISTEMA");
    exibirNaSegundaLinha("Medicado!");
    servoMotor.write(0); // Retorna o servo à posição inicial
    alarmeHorario = millis() + intervaloAlarme; // Configura o alarme novamente
    delay(2000);
    medConfirmada = false;
}
```
### Passo 4: Funções Auxiliares

Aqui estão algumas funções auxiliares importantes, como a função para ler entradas da serial e as funções para exibir textos no LCD de forma centralizada ou na segunda linha.

```cpp
// Função para ler a entrada da serial
String lerSerial() {
    String entrada = "";
    while (Serial.available()) {
        char caractere = Serial.read();
        entrada += caractere;
    }
    return entrada;
}

// Funções para exibição no LCD
void exibirCentralizado(String texto) {
    int posicao = (16 - texto.length()) / 2;
    lcd.setCursor(posicao, 0);
    lcd.print(texto);
}

void exibirNaSegundaLinha(String texto) {
    lcd.setCursor(0, 1);
    lcd.print(texto);
}
```

---

## Teste e Validação

- **Testando o Cadastro:** Certifique-se de que o nome do remédio e o tempo de alarme são corretamente inseridos e exibidos no LCD.
- **Testando o Alarme:** Verifique se o buzzer e o servo motor são acionados corretamente quando o tempo de alarme chega.
- **Testando o Controle de Acesso:** Quando a senha correta for inserida, o sistema deve liberar o acesso ao "porta-remédio", acionando o servo motor para abrir o compartimento.

---

## Expansões e Melhorias

- **Adicionar Conectividade:** Conectar o sistema a um smartphone via Bluetooth ou Wi-Fi para notificar o usuário.
- **Integração com Banco de Dados:** Armazenar histórico de medicamentos e horários de alertas.
- **Interface de Usuário:** Melhorar a interface LCD para exibir informações adicionais como dosagem do medicamento.

---

## Referências

- Link simulação: https://www.tinkercad.com/things/fXkFnPR8OHN-projeto?sharecode=I50j_Ad-6Bizm6An5BivC08k58G4rzCm1WprxK8c_7E
- ArduinoIDE: https://www.arduino.cc/
- Tinkercad: https://www.tinkercad.com/

---




