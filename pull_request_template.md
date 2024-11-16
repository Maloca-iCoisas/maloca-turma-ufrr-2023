# Pull Request - Projeto Maloca das iCoisas

## Descrição do Pull Request

### O que foi implementado:
- Implementação de um tutorial para o sensor ultrassônico HC-SR04 com Arduino, incluindo código, diagrama de conexão e instruções detalhadas.

### Contexto e Motivação:
-  Este tutorial busca facilitar o uso do sensor HC-SR04 para medir distâncias em projetos IoT, servindo como base para aplicações em monitoramento de proximidade em contextos hospitalares.

## Testes Realizados

### Descrição dos Testes:
- Hardware:
Montagem do circuito com Arduino Uno, sensor HC-SR04 e jumpers.
Verificação de alimentação e sinais de controle (pinos TRIG e ECHO).
- Software:
Código testado no Arduino IDE, verificando leituras no monitor serial.
Simulação no WokWi para avaliar funcionamento sem hardware real.


### Resultados dos Testes:
- Distâncias foram medidas com precisão em ambientes reais e simulados.
- Código executado sem erros ou falhas de compilação.

## Checklist

- [x] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [x] Código foi testado e validado em ambiente de desenvolvimento com hardware real (Arduino, Raspberry Pi, ESP32) ou simulação (workwi).
- [x] Documentação atualizada para refletir as mudanças realizadas.
- [x] Código escrito e comentado em **C** ou **Python** de acordo com os padrões do projeto.
- [x] Testes com sensores e atuadores específicos incluídos e detalhados na descrição dos testes.

## Tipo de Mudança

- [ ] Correção de bug
- [x] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [x] Documentação

## Informações Adicionais

### Hardware Utilizado:
- Arduino Uno
- Sensor Ultrassônico HC-SR04
- Protoboard e jumpers

### Simulação Utilizada:
- https://wokwi.com/projects/407047625786887169

### Observações:
- Código testado com intervalos de 1 segundo entre medições.
- Valores exibidos no monitor serial podem ser ajustados para exibir em unidades diferentes (cm, mm, etc.).

## Issue Relacionada
Closes #
