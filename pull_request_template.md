![image](https://github.com/user-attachments/assets/9eb246f3-1a40-4d23-8a0d-32f9dc7aaefb)# Pull Request - Projeto Maloca das iCoisas

## Descrição do Pull Request

### O que foi implementado:

Implementação de um sistema de localização de equipamentos médicos usando IoT.
Configuração de dispositivos RFID e gateways IoT (Raspberry Pi) para rastrear cadeiras de rodas e desfibriladores.
Desenvolvimento de uma interface de mapa interativo com Leaflet.js, mostrando as localizações em tempo real.


### Contexto e Motivação:

Equipamentos médicos essenciais, como desfibriladores, muitas vezes não estão prontamente disponíveis em emergências. 
Este sistema oferece rastreamento preciso e uma interface visual para melhorar a gestão interna, reduzindo atrasos no atendimento.


## Testes Realizados

### Descrição dos Testes:
Teste de comunicação entre o leitor RFID e o Raspberry Pi usando uma etiqueta simulada.
Simulação de rastreamento no Tinkercad, verificando a leitura de UID de etiquetas RFID.
Testes na interface de mapa para verificar a atualização em tempo real das localizações.


### Resultados dos Testes:
Leituras de etiquetas RFID foram reconhecidas corretamente pelo Raspberry Pi.
A interface de mapa exibiu atualizações precisas de localização conforme dados enviados pelos gateways.


## Checklist

- [ ] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [ ] Código foi testado e validado em ambiente de desenvolvimento com hardware real (Raspberry Pi) e simulação (Tinkercad).
- [ ] Documentação atualizada para refletir as mudanças realizadas.
- [ ] Código escrito e comentado em Python de acordo com os padrões do projeto.
- [ ] Testes com sensores RFID incluídos e detalhados na descrição dos testes.

## Tipo de Mudança

- [ ] Correção de bug
- [ ] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [ ] Documentação

## Informações Adicionais

### Hardware Utilizado:
1. Arduino Uno.
2. Jumples.
3. Leitor RFID RC522 para rastreamento.
4. Etiquetas RFID fixadas nos equipamentos médicos.


### Simulação Utilizado:
Tinkercad para simulação básica de leitura RFID. Porém, ocorre que o simulador não possui o Leitor RFID para que o teste seja realizado, porem com base no que foi ensinado aos alunos durante as aulas, foi possivel realizar a montagem e teste aplicado no prototipo.


### Observações:

Closes #

---


