# Pull Request - Projeto Maloca das iCoisas

## Descrição do Pull Request

**O que foi implementado:**
- Sistema de monitoramento e gerenciamento de estoque de medicamentos com ESP32 e display OLED.
- Funcionalidades principais de **Cadastro**, **Listagem** e **Retirada de Medicamentos** usando entrada via teclado matricial.
- Interface de exibição com um menu inicial para navegação nas opções.

**Contexto e Motivação:**
O projeto visa otimizar a gestão de medicamentos em farmácias, permitindo o cadastro rápido de novos itens, consulta ao estoque e remoção de medicamentos, integrando os recursos da ESP32 com display OLED e teclado matricial. Este sistema pode ser expandido para armazenar dados em nuvem e adicionar mais sensores e atuadores.

---

## Testes Realizados

**Descrição dos Testes:**
- **Teste do Teclado Matricial**: Verificação de cada tecla e mapeamento correto no sistema.
- **Teste de Display**: Checagem da exibição de mensagens no display OLED, especialmente no menu inicial e nas telas de confirmação.
- **Funcionalidade de Cadastro**: Cadastro de medicamentos com nomes e códigos digitados, garantindo que sejam armazenados corretamente.
- **Listagem no Display**: Validação da apresentação de todos os medicamentos cadastrados no display.
- **Retirada de Medicamentos**: Teste de exclusão de itens e atualização da lista, com exibição dos itens restantes.

**Resultados dos Testes:**
- Todos os testes retornaram resultados consistentes com as especificações. O sistema responde corretamente às teclas do teclado matricial, exibe mensagens claras no display e armazena dados conforme esperado.

---

## Checklist

- [x] Código atende às normas do projeto e foi formatado de acordo com as diretrizes.
- [x] Código foi testado e validado em ambiente de desenvolvimento com ESP32 e display SSD1306.
- [x] Documentação atualizada para refletir as mudanças realizadas.
- [x] Código escrito e comentado em Python, de acordo com os padrões do projeto.
- [x] Testes específicos com teclado matricial e display OLED incluídos e detalhados na descrição dos testes.

---

## Tipo de Mudança

- [ ] Correção de bug
- [x] Nova funcionalidade
- [ ] Alteração de funcionalidade existente
- [x] Documentação

---

## Informações Adicionais

**Hardware Utilizado:**
- ESP32, Display OLED SSD1306, Teclado Matricial 4x4

**Simulação Utilizada:**
- Testes iniciais em ambiente de simulação no Tinkercad e validação em hardware real.

**Observações:**
- Esse PR implementa o núcleo do sistema. Futuras expansões podem incluir comunicação Wi-Fi e armazenamento remoto dos dados.

---

## Issue Relacionada

Closes #
