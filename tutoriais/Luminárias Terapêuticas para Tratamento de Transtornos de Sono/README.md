# Luminárias Terapêuticas para Tratamento de Transtornos de Sono

## Descrição

Neste tutorial, vamos desenvolver um sistema de luminárias terapêuticas inteligentes usando um ESP32, um display OLED e um teclado matricial, projetado para auxiliar no tratamento de transtornos de sono, como insônia e desregulação do ciclo circadiano. Durante o desenvolvimento, você irá aprender a controlar ciclos de iluminação simulando o nascer e o pôr do sol, configurar perfis de terapia de luz e criar uma interface interativa com menus. Este projeto é ideal para estudantes, makers e profissionais interessados em tecnologia para saúde e bem-estar, além de aplicações de IoT residencial.

## Índice

- [Introdução](#introdução)
- [Requisitos](#requisitos)
- [Configuração do Ambiente](#configuração-do-ambiente)
- [Montagem do Circuito](#montagem-do-circuito)
- [Programação](#programação)
- [Passo 2: Processamento e Lógica de Ciclos de Luz](#passo-2-processamento-e-lógica-de-ciclos-de-luz)
- [Teste e Validação](#teste-e-validação)
- [Expansões e Melhorias](#expansões-e-melhorias)
- [Referências](#referências)

## Introdução

O sono de qualidade é fundamental para a saúde física e mental. Diversos transtornos, como insônia ou jet lag, podem ser mitigados com o uso da terapia de luz, que auxilia na regulação do ciclo circadiano. Este projeto propõe uma solução simples e acessível de luminária terapêutica, capaz de simular ambientes de luz adequados para melhorar o ritmo biológico do usuário. Integrado ao conceito de IoT, o sistema pode futuramente ser conectado a serviços de nuvem para monitoramento e ajustes remotos.

## Requisitos

### Hardware

- **Placa**: ESP32 DevKit V1
- **Sensores/Componentes**:
  - Teclado Matricial 4x4
  - Display LCD 16x2 ou OLED 0.96" I2C
- **LEDs**:
  - LEDs de Alta Potência (Branco Quente e Branco Frio)
  - Driver para LEDs ou MOSFETs para controle de potência
  - Fonte de Alimentação 12V para LEDs + conversor para ESP32 (5V -> 3.3V)
- **Outros Componentes**:
  - Jumpers, Protoboard ou PCB
  - Resistores para LEDs (se necessário)
  - Botão de Reset (opcional)

### Software

- **Linguagens**: C/C++ (Arduino para ESP32)
- **IDE**: Arduino IDE (configurado para ESP32)
- **Bibliotecas Necessárias**:
  - Keypad
  - LiquidCrystal
  - WiFi (para futuras expansões)

### Requisitos Adicionais

- **Controle de LEDs**: O código permite alternar os LEDs entre os modos de "quente", "frio", "modo terapia" (ambos os LEDs ligados simultaneamente) e "desligado".
- **Monitoramento de Tempo**: Após ativar um LED, ele será desligado automaticamente após um tempo definido. A funcionalidade de reset também está disponível.
- **Display LCD**: O display exibe o status atual dos LEDs, tempo restante, e outras informações sobre as ações realizadas.

## Configuração do Ambiente

1. **Instale o Arduino IDE**:
   - Faça o download do Arduino IDE [aqui](https://www.arduino.cc/en/software).
   - Instale o suporte para o ESP32 no Arduino IDE seguindo os passos disponíveis [neste link](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/).

2. **Bibliotecas**:
   - No Arduino IDE, vá até `Sketch > Incluir Biblioteca > Gerenciar Bibliotecas`.
   - Procure e instale as seguintes bibliotecas:
     - **Keypad**
     - **LiquidCrystal**

3. **Configuração do ESP32**:
   - Conecte seu ESP32 à porta USB do seu computador.
   - Selecione a placa ESP32 correta no menu `Ferramentas > Placa > ESP32 Dev Module`.

## Montagem do Circuito

<div>
  <img align="center" height "180em" src="https://github.com/user-attachments/assets/17ad6258-52ce-488d-ba69-6a476441c2d9" width="750"/>
<div>

1. **Teclado Matricial 4x4**:
   - Conecte os pinos do teclado aos pinos digitais do ESP32 conforme a configuração no código.
   - Certifique-se de conectar os pinos corretos para que as teclas sejam reconhecidas.

2. **Display LCD**:
   - Para um display LCD 16x2 com interface I2C, conecte os pinos `SDA` e `SCL` aos pinos correspondentes no ESP32.
   - Se estiver utilizando um display OLED, o procedimento é o mesmo.

3. **LEDs**:
   - Conecte os LEDs de alta potência (quente e frio) aos pinos do ESP32 via MOSFETs ou drivers adequados, garantindo que a alimentação dos LEDs seja separada da alimentação do ESP32.

4. **Fios e Alimentação**:
   - Assegure-se de que todos os componentes estão conectados corretamente com fios de boa qualidade.
   - Use uma fonte de alimentação apropriada para os LEDs (geralmente 12V) e um regulador de 5V para alimentar o ESP32.

## Programação

O código no ESP32 controla os LEDs com base nas teclas pressionadas no teclado matricial e exibe informações no display LCD. Cada tecla realiza uma ação específica, como ligar ou desligar os LEDs, alterar o tempo de permanência, e resetar os timers.

### Passo 2: Processamento e Lógica de Ciclos de Luz

O código permite o controle de dois LEDs (quente e frio) usando um teclado matricial e um display LCD. O usuário pode pressionar teclas específicas para alternar os estados dos LEDs, ligando-os ou desligando-os. A tecla '1' alterna o LED "quente", a tecla '2' faz o mesmo para o LED "frio", a tecla 'A' liga ambos os LEDs simultaneamente em um "modo terapia", e a tecla 'B' desliga ambos os LEDs.

Além disso, o código implementa um tempo de permanência para os LEDs, ou seja, após um LED ser ligado, ele será desligado automaticamente após um tempo definido pelo usuário. O tempo é configurado ao pressionar a tecla 'C', e se o tempo for alcançado, o LED é desligado. A tecla 'D' reseta o tempo, deixando os LEDs no modo manual, sem desligamento automático. O LCD exibe constantemente o estado dos LEDs e informações sobre as ações realizadas.

Esse processo permite ao usuário interagir facilmente com os LEDs, definindo tempos de permanência e controlando-os de maneira simples e intuitiva, enquanto o LCD fornece feedback visual das ações.

## Teste e Validação

### 1. Teste do Teclado Matricial:
- **Objetivo**: Verificar se as teclas são corretamente detectadas.
- **Teste**: Pressione cada tecla ('1' a 'D') e veja se o LCD exibe corretamente a tecla pressionada.
- **Critério de Sucesso**: O LCD deve mostrar a tecla pressionada corretamente.

### 2. Teste do Display LCD:
- **Objetivo**: Validar se o LCD exibe as informações corretamente.
- **Teste**: Observe se o LCD exibe as mensagens corretas, como "Luminária ON" e os estados dos LEDs.
- **Critério de Sucesso**: O LCD deve mostrar as informações atualizadas e corretas.

### 3. Teste dos LEDs:
- **Objetivo**: Verificar se os LEDs acendem e apagam corretamente.
- **Teste**: Pressione as teclas '1' e '2' para alternar os LEDs "quente" e "frio". Observe se eles acendem e apagam.
- **Critério de Sucesso**: Os LEDs devem acender e apagar conforme esperado, e o LCD deve refletir isso.

### 4. Teste do Modo Terapia ('A'):
- **Objetivo**: Validar se ambos os LEDs acendem ao pressionar 'A'.
- **Teste**: Pressione 'A' e observe se ambos os LEDs acendem.
- **Critério de Sucesso**: Os LEDs devem acender e o LCD deve exibir "Modo Terapia".

### 5. Teste de Desligamento dos LEDs ('B'):
- **Objetivo**: Verificar se os LEDs desligam ao pressionar 'B'.
- **Teste**: Pressione 'B' e veja se os LEDs desligam.
- **Critério de Sucesso**: Os LEDs devem apagar e o LCD deve exibir "Tudo OFF".

### 6. Teste do Tempo de Permanência ('C'):
- **Objetivo**: Verificar se o tempo de desligamento automático dos LEDs funciona.
- **Teste**: Defina o tempo pressionando 'C', ligue um LED e veja se ele desliga automaticamente após o tempo.
- **Critério de Sucesso**: O LED deve apagar automaticamente após o tempo definido.

### 7. Teste de Reset do Tempo ('D'):
- **Objetivo**: Validar se o reset do tempo funciona corretamente.
- **Teste**: Pressione 'D' e veja se o LED permanece ligado até que o usuário o desligue manualmente.
- **Critério de Sucesso**: O LED deve ficar ligado até ser desligado manualmente.

### 8. Teste do Sistema Completo:
- **Objetivo**: Verificar se todo o sistema funciona corretamente.
- **Teste**: Interaja com o sistema pressionando as teclas e verificando os LEDs e o LCD.
- **Critério de Sucesso**: O sistema deve funcionar sem falhas, com LEDs e LCD respondendo corretamente.

## Expansões e Melhorias

- **Controle de Brilho dos LEDs**: Adicionar um potenciômetro ou uma tecla específica para ajustar o brilho dos LEDs.
- **Feedback Auditivo com Buzzer**: Incluir um buzzer para fornecer feedback sonoro.
- **Controle Remoto via Bluetooth ou Wi-Fi (ESP32)**: Adicionar um módulo Bluetooth ou Wi-Fi para controlar os LEDs remotamente.
- **Melhorias na Interface do LCD**: Adicionar um menu de navegação no display LCD.
- **Função de Alarme para Uso Excessivo**: Incluir um alarme (sonoro ou visual) caso os LEDs fiquem ligados por mais tempo do que o esperado.

## Referências

- **Keypad Library (Teclado Matricial)**: Biblioteca para facilitar o uso de teclados matriciais com Arduino: [Keypad Library - Arduino](https://www.arduino.cc/reference/en/libraries/keypad/)
- **LiquidCrystal Library (Display LCD)**: Biblioteca padrão para controlar displays LCD com Arduino: [LiquidCrystal - Arduino](https://www.arduino.cc/en/Reference/LiquidCrystal)
- **ESP32 Wi-Fi Library (Comunicação sem fio para ESP32)**: Biblioteca para habilitar a comunicação Wi-Fi no ESP32: [Wi-Fi Library for ESP32](https://github.com/espressif/arduino-esp32)
- **Ciclo Circadiano e Terapia de Luz**: Artigo da National Sleep Foundation sobre o ciclo circadiano e a terapia de luz: [National Sleep Foundation - Circadian Rhythm](https://www.sleepfoundation.org/circadian-rhythm)
- **Terapia de Luz para Transtornos do Sono**: Guia sobre o uso da terapia de luz para transtornos de sono: [American Academy of Sleep Medicine - Light Therapy](https://aasm.org/clinical_resources/therapy-light/)
- **Introdução à Terapia de Luz para Ciclo Circadiano**: Resumo sobre a terapia de luz e seu impacto no ciclo circadiano: [Sleep Foundation - Light and Sleep](https://www.sleepfoundation.org/light-and-sleep)
