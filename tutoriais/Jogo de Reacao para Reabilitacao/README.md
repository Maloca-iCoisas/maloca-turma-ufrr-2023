# Jogo de Reação para Reabilitação

**Descrição**: Este projeto é um Jogo de Reação desenvolvido para ajudar na reabilitação de pacientes. Utiliza um ESP32, LEDs e botões para medir o tempo de reação do usuário. O código foi desenvolvido em MicroPython e o circuito foi simulado na plataforma Wokwi.

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

O Jogo de Reação foi projetado para treinar e avaliar o tempo de reação de pacientes em processos de reabilitação. O jogo funciona de forma simples: um LED acende e o usuário deve pressionar o botão correspondente o mais rápido possível. O tempo de reação é registrado e pode ser usado para monitorar o progresso ao longo do tempo.

---

## Requisitos

### Hardware

- **Placa**: ESP32
- **Atuadores**: LEDs, Botões.
- **Outros componentes**: Resistores para LEDs, Protoboard e jumpers.

### Software

- **Linguagens**: MicroPython
- **IDE**: Thonny ou VSCode com extensão MicroPython
- **Simulador**: [Wokwi](https://wokwi.com/)

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Thonny Python**: Configuração do Thonny para programar em Python.
- **MicroPython para ESP32**: Baixe e instale o firmware do MicroPython para ESP32 e conecte o ESP32 ao seu computador e configure o Thonny para usar o MicroPython.
- **Bibliotecas**: No Thonny, instale as bibliotecas necessárias para o display SSD1306:

```bash
# Instalar bibliotecas do Python
pip install esptool
```
### Passo 2: Configuração das Placas

- **ESP32**: Conecte o ESP32 ao computador via USB e configure-o na IDE Thonny.

## Montagem do Circuito

1. Conecte os LEDs aos pinos GPIO do ESP32 através de resistores.
2. Conecte os botões a outros pinos GPIO, utilizando resistores pull-down para evitar leituras erradas.
3. Verifique a fiação para garantir que cada botão corresponda a um LED.
4. Simule o circuito no Wokwi para validação.

Link da simulação: [Simulação no Wokwi](https://wokwi.com/projects/402609002044694529)

<img src="Modelo do Circuito.png" alt="Modelo Wokwi" />

---

## Programação

### Passo 1: Configuração dos Leds e Botões

```python
import machine
import utime
import urandom

pressed = False
led = machine.Pin(15, machine.Pin.OUT)
button_left = machine.Pin(18, machine.Pin.IN, machine.Pin.PULL_DOWN)
button_right = machine.Pin(19, machine.Pin.IN, machine.Pin.PULL_DOWN)
fastest_button = None

def button_handler(pin):
    global pressed
    if not pressed:
        pressed=True
        global fastest_button
        fastest_button = pin
        global timer_reaction
        
        timer_reaction = utime.ticks_diff(utime.ticks_ms(), timer_start)
        # print("Seu tempo de reação foi " + str(timer_reaction) + " milisegundos!")
        # print("PARABÉNS JOGADOR!")

led.value(1)
utime.sleep(urandom.uniform(5, 10))
led.value(0)

timer_start = utime.ticks_ms()
button_left.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)
button_right.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)

while fastest_button is None:
    utime.sleep(1)
if fastest_button is button_left:
    print("Jogador da esquerda Venceu! Por " + str(timer_reaction) + " milisegundos")
elif fastest_button is button_right:
    print("Jogador da direita Venceu! Por " + str(timer_reaction) + " milisegundos")
```

---

## Teste e Validação

1. Suba o código para o ESP32 ou inicie a simulação no Wokwi.
2. Teste o circuito pressionando os botões correspondentes aos LEDs.
3. Certifique-se de que o tempo de reação é exibido corretamente no terminal.

---

## Expansões e Melhorias

1. Adicionar diferentes níveis de dificuldade, como tempos de resposta mais curtos.
2. Implementar armazenamento de dados de desempenho em uma base local ou em nuvem.
3. Adicionar feedback sonoro para indicar erros ou sucesso.
4. Integrar com sensores adicionais para medição de outros parâmetros, como batimentos cardíacos.

---

## Referências

1. [Documentação oficial do MicroPython](https://docs.micropython.org/en/latest/)
2. [Plataforma Wokwi](https://wokwi.com/)
3. [Exemplos de projetos com ESP32](https://randomnerdtutorials.com/)
4. [Instruções oficiais Micropython para ESP32](https://micropython.org/download/ESP32_GENERIC/)