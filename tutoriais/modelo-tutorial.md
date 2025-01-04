# Tranca inteligente

**Descrição:** Para lidar com o problema de furto de medicamentos este projeto visa implementar uma medida de segurança inteligente para o usuário"

---

## Índice

1. [Introdução](#introdução)
2. [Requisitos](#requisitos)
3. [Montagem do Circuito](#montagem-do-circuito)
4. [Programação](#programação)
5. [Expansões e Melhorias](#expansões-e-melhorias)
6. [Referências](#referências)

---

## Introdução
O furto de medicamentos ocorre diariamente no Brasil, muitas vezes estes produtos são reintroduzidos em mercados irregulares, aumentando a escassez e tornando a medicação mais cara e inacessível a quem precisa. O projeto aqui apresentado visa acabar com isso, introduzindo uma medida de segurança mais acessível, uma tranca inteligente.

---

## Requisitos

### Hardware
- 1 Arduino UNO;

– 1 Micro Servo Motor SG90;

– 3 Jumpers Macho x Macho;

– 1 Potenciômetro.

### Software

- **Linguagens**: C para Arduino
- **IDE**: Arduino IDE
- **Bibliotecas**: servo.h

---

## Montagem do Circuito

![montagem-fisica-1](https://github.com/user-attachments/assets/05d2e107-9113-4f1f-a67d-096ba5c3002a)


---

## Programação

### Passo 1: Configuração dos Sensores e Atuadores

**C para Arduino UNO:**

```cpp
#include Servo.h; // Inclui a Biblioteca Servo.h
 
Servo meuservo; // Inicializa o servo no modo de teste
int angulo = 0; // Ajusta o ângulo inicial do Servo
int potencio = A0; // Inicializa o pino analógico para o potenciômetro
 
void setup() { 
meuservo.attach(9); // Define que o Servo está conectado a Porta 9
} 
 
void loop() {
angulo = analogRead(potencio); // Faz a leitura do valor do potenciômetro
angulo = map(angulo, 0, 1023, 0, 179); // Associa o valor do potenciômetro ao valor do ângulo
meuservo.write(angulo); // Comando para posicionar o servo no ângulo especificado
delay(5);
} 
```

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- Integrar com senha
- Adicionar componente de leitura de digital
---

## Referências

https://www.usinainfo.com.br/blog/controle-de-posicao-servo-motor-com-arduino/?srsltid=AfmBOorw3vSPbE3vF61JssF31aMwkPyc7pJztTPEqOXXAoHtLb0GBnpy

