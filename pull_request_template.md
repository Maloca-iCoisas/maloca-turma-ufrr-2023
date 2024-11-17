# Pull Request - Projeto Maloca das iCoisas

## Descrição do Pull Request

### O que foi implementado:
- Sistema de monitoramento de temperatura corporal usando Arduino e sensor DHT22.
- Alerta visual (LED) ou sonoro (buzzer) quando a temperatura excede o limite pré-estabelecido.
- Código em Arduino para leitura do sensor, conversão de dados e acionamento do alerta.

### Contexto e Motivação:
- Este projeto atende à necessidade de monitorar febres de forma simples e acessível, especialmente em ambientes domésticos ou em pequenas clínicas. A solução é um exemplo prático de IoT aplicada à saúde, com potencial para melhorias, como integração com redes Wi-Fi ou exibição em displays LCD.

## Testes Realizados

### Descrição dos Testes:
- Leitura do sensor: Testado com variação de temperatura para verificar precisão dos dados capturados.
- Ativação do alerta: Simulações realizadas para garantir que o LED/buzzer responde adequadamente quando a temperatura excede 37.5°C.
- Conexão e funcionamento: Teste completo do circuito no protótipo, com análise no Serial Monitor da IDE do Arduino.

### Resultados dos Testes:
- O buzzer acionou corretamente ao detectar uma temperatura fora da faixa normal.
- Simulação no workwi confirmou a funcionalidade básica.

## Checklist

- [x] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [x] Código foi testado e validado em ambiente de desenvolvimento com hardware real (Arduino, Raspberry Pi, ESP32) ou simulação (tinkercad).
- [x] Documentação atualizada para refletir as mudanças realizadas.
- [x] Código escrito e comentado em **C** ou **Python** de acordo com os padrões do projeto.
- [x] Testes com sensores e atuadores específicos incluídos e detalhados na descrição dos testes.

## Tipo de Mudança

- [ ] Correção de bug
- [x] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [ ] Documentação

## Informações Adicionais

### Hardware Utilizado:
- Arduino Uno
- Sensor de temperatura DHT22
- Buzzer
- Resistores (10kΩ)
- Protoboard e fios jumpers

### Simulação Utilizado:
- Wokwi
- Link da simulação: https://wokwi.com/projects/414810798576345089

### Observações:
- Não foi utilizado o led neste projeto, apenas o buzzer.