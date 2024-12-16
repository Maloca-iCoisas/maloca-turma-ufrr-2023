# Pull Request - Sistema de Monitoramento de Umidade com Arduino

## Descrição do Pull Request

**O que foi implementado:**
- Sistema de monitoramento de umidade utilizando Arduino Uno e sensor DHT22.
- Funcionalidade de alerta visual com LED caso a umidade ultrapasse um limite predefinido.
- Código base para leitura e exibição dos valores de umidade no monitor serial.

**Contexto e Motivação:**
O projeto visa oferecer uma solução simples e prática para monitorar a umidade em ambientes internos, como quartos ou estufas. Este sistema pode ser utilizado como ponto de partida para projetos mais complexos, como monitoramento remoto ou integração com sistemas IoT.

---

## Testes Realizados

**Descrição dos Testes:**
- **Teste do Sensor DHT22:** Validação das leituras de umidade em diferentes condições.
- **Teste do LED:** Verificação do acionamento correto do LED ao exceder o limite de umidade.
- **Exibição no Monitor Serial:** Checagem da precisão dos valores exibidos.

**Resultados dos Testes:**
- Todas as funcionalidades apresentaram resultados consistentes com as especificações.
- O sensor DHT22 respondeu de forma precisa às mudanças de umidade.
- O LED foi acionado corretamente ao ultrapassar o limite estabelecido.

---

## Checklist

- [x] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [x] Código foi testado e validado em hardware real (Arduino Uno e sensor DHT22).
- [x] Documentação atualizada com instruções de montagem, programação e teste.
- [x] Código comentado para facilitar entendimento e futuras expansões.

---

## Tipo de Mudança

- [ ] Correção de bug
- [x] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [x] Documentação

---

## Informações Adicionais

**Hardware Utilizado:**
- Arduino Uno, Sensor DHT22, LED, resistores, protoboard

**Observações:**
- O sistema funciona com limites de umidade predefinidos (60%), podendo ser ajustado facilmente no código.
- Futuras expansões podem incluir exibição em display LCD ou envio de dados para a nuvem.

---

## Issue Relacionada

Closes #
