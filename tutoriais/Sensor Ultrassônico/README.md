# Título do Tutorial

**Descrição:** Este tutorial ensina a criar um sistema de medição de altura para exames pediátricos usando o sensor ultrassônico HC-SR04 e o display LCD com interface I2C no Raspberry Pi Pico. O projeto é voltado para aplicações em saúde, como triagens médicas, em que a medição precisa e rápida da altura de crianças é essencial.

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

O projeto utiliza o sensor ultrassônico HC-SR04 para medir a altura de crianças durante exames pediátricos. A medição é exibida em tempo real em um display LCD conectado ao Raspberry Pi Pico via interface I2C. Este sistema é projetado para ser simples, acessível e altamente funcional em ambientes médicos.

---

## Requisitos

### Hardware

- **Placa**: Raspberry Pi Pico.
- **Sensores**: HC-SR04 (sensor ultrassônico).
- **Atuadores**: Display LCD com interface I2C.
- **Outros componentes**: Jumpers e protoboard.

### Software

- **Linguagens**: MicroPython.
- **IDE**: Thonny.
- **Bibliotecas**: utime (incluída no MicroPython).
- **Plataforma de Simulação**: Wokwi.

---

## Configuração do Ambiente

### Passo 1: Instalação do Software

- **Plataforma de Simulação**: Use o Wokwi para simular o circuito antes de implementá-lo fisicamente.
1. Crie uma conta na plataforma wokwi pelo site: https://wokwi.com/
2.Na página inicial, clique no ícone do seu perfil para abrir o menu:


<div>
  <img align="center" height "200em" src="https://github.com/user-attachments/assets/769a8b1e-4870-4da2-a7b4-0727df7fbbc4" width="300"/>
<div>

3. No menu, clique em My projects.
4. Depois disso, clique em New Project;
5. A partir disso, você selecionará a placa Raspberry Pi Pico W:
   
<div>
  <img align="center" height "200em" src="https://github.com/user-attachments/assets/2ec1f0c4-84f0-4522-84e6-7de530d3e2b7" width="400"/>
<div>
6. Por fim, escolha a linguagem MicroPython para programar.

<div>
  <img align="center" height "200em" src="https://github.com/user-attachments/assets/8d8acd5e-1218-42f4-b057-76cc71e8dd57" width="400"/>
<div>


## Montagem do Circuito

Conecte os componentes conforme o diagrama abaixo:

<div>
  <img align="center" height "200em" src="https://github.com/user-attachments/assets/ccf673fa-cad8-4bca-acd1-f4837209e730" width="500"/>
<div>

- **Pinagem dos Componentes:**

  ## 1. HC-SR04:
    - VCC → Fonte de 5V.
    - GND → GND.
    - Trigger → GPIO 3.
    - Echo → GPIO 2.
   ## 1. Display LCD com I2C:
    - VCC → Fonte de 5V.
    - GND → GND.
    - SDA → GPIO 0.
    - SCL → GPIO 1.
  
## Programação

### Passo 1: Configuração dos Sensores e Atuadores

Neste projeto, vamos configurar o LCD diretamente no código final do main.py, criando uma classe para controle do LCD. Essa parte do código está entre as importações de bibliotecas e o início do código principal.


```python
# Classe para controle do LCD
class I2cLcd:
    def __init__(self, i2c, i2c_addr, num_lines, num_columns):
        self.i2c = i2c
        self.i2c_addr = i2c_addr
        self.num_lines = num_lines
        self.num_columns = num_columns
        self._init_lcd()

    def _init_lcd(self):
        self._write_cmd(0x33)  # Initialization
        self._write_cmd(0x32)  # Set to 4-bit mode
        self._write_cmd(0x28)  # 2 lines, 5x7 matrix
        self._write_cmd(0x0C)  # Display on, cursor off
        self._write_cmd(0x06)  # Entry mode set

    def _write_cmd(self, cmd):
        self._send(cmd, 0)

    def _write_data(self, data):
        self._send(data, 1)

    def _send(self, data, mode):
        high = mode | (data & 0xF0) | 0x04  # High nibble with EN
        low = mode | ((data << 4) & 0xF0) | 0x04  # Low nibble with EN
        self.i2c.writeto(self.i2c_addr, bytearray([high, high & ~0x04]))  # High nibble
        self.i2c.writeto(self.i2c_addr, bytearray([low, low & ~0x04]))  # Low nibble

    def clear(self):
        self._write_cmd(0x01)

    def putstr(self, string):
        for char in string:
            self._write_data(ord(char))
```

### Passo 2: Processamento e Lógica de Alerta

Após as configurações necessárias, adicione a lógica para o funcionamento do sistema:

```python
import machine
import utime
from machine import I2C, Pin

# Configuração do LCD
i2c = I2C(0, sda=Pin(0), scl=Pin(1), freq=400000)  # Ajuste os pinos conforme necessário
lcd = I2cLcd(i2c, 0x27, 2, 16)  # Endereço I2C do módulo LCD pode variar

# Configuração do sensor ultrassônico
trigger = machine.Pin(3, machine.Pin.OUT)
echo = machine.Pin(2, machine.Pin.IN)

def measure_distance():
    trigger.low()
    utime.sleep_us(2)
    trigger.high()
    utime.sleep_us(10)
    trigger.low()

    while echo.value() == 0:
        signal_off = utime.ticks_us()
    while echo.value() == 1:
        signal_on = utime.ticks_us()

    time_passed = utime.ticks_diff(signal_on, signal_off)
    distance = (time_passed * 0.0343) / 2
    return distance

while True:
    distance = measure_distance()
    height = round(distance, 2)  # Altura arredondada
    print("Altura:", height, "cm")

    # Atualizar o LCD
    lcd.clear()
    lcd.putstr(f"Altura:\n{height} cm")
    
    utime.sleep(1)
```

## Teste e Validação

Descreva os testes para validar cada parte do projeto:

1. **Simulação no Wokwi**: Configure o circuito e carregue o código, em seguida, inicie a simulação e verifique a altura exibida no LCD e no console.
2. **Testes físicos**: Conecte os componentes a uma protoboard e meça a altura utilizando o sensor ultrassônico posicionado verticalmente.


---

## Expansões e Melhorias

Sugestões para melhorar o projeto, como:

- **Comunicação com Wi-Fi:** Use um módulo ESP32 para enviar dados para um servidor remoto.
- **Armazenamento de dados:** Salve as leituras em um banco de dados local ou na nuvem.

---

## Referências

Liste todas as referências e links úteis para guias, bibliotecas, e materiais adicionais que ajudem a complementar o tutorial.
- **Documentação do wokwi**: https://docs.wokwi.com/pt-BR/
- **Link da simulação**: https://wokwi.com/projects/407048082190109697


