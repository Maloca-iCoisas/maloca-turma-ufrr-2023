# Tutorial: Gerenciamento de Remédios em Python

**Descrição:** Neste tutorial, você aprenderá a desenvolver um sistema simples de gerenciamento de remédios utilizando Python. O projeto é adequado para iniciantes em programação e ensina conceitos básicos como estruturas de dados, funções e interação com o usuário.

---

## Índice

1. [Introdução](#introdução)
2. [Requisitos](#requisitos)
3. [Estrutura do Projeto](#estrutura-do-projeto)
4. [Explicação do Código](#explicação-do-código)
5. [Execução e Testes](#execução-e-testes)
6. [Expansões e Melhorias](#expansões-e-melhorias)
7. [Referências](#referências)

---

## Introdução

Este projeto implementa um sistema que permite gerenciar uma lista de remédios. As funcionalidades incluem cadastro de novos remédios, listagem dos remédios existentes e alteração do status de disponibilidade. Este sistema é executado inteiramente em Python, sem necessidade de hardware externo ou circuitos.

---

## Requisitos

### Hardware
- Apenas um computador capaz de executar scripts Python.

### Software
- Python 3.6 ou superior.

---

## Estrutura do Projeto

O código é organizado da seguinte maneira:

1. **Array de Remédios**: Uma lista contendo informações sobre cada remédio (nome, valor e status de disponibilidade).
2. **Funções**:
   - `menu()`: Exibe as opções do sistema.
   - `exibir_opcoes()`: Interpreta a escolha do usuário e executa a ação correspondente.
   - `cadastrar_remedio()`: Permite adicionar novos remédios à lista.
   - `listar_remedios()`: Exibe a lista de remédios cadastrados.
   - `voltar_ao_menu_principal()`: Retorna ao menu principal após uma ação.
   - `main()`: Inicia o programa e gerencia o fluxo.

---

## Explicação do Código

### Estrutura de Dados

A lista `array_remedios` armazena os remédios como dicionários com as seguintes chaves:
- **nome**: Nome do remédio.
- **valor**: Preço do remédio.
- **ativo**: Status do remédio (disponível ou não).

Exemplo:
```python
array_remedios = [
    {"nome": "Zolpidem", "valor": 67.90, "ativo": False},
    {"nome": "Paracetamol", "valor": 5.25, "ativo": True}
]
```

### Funções Principais

#### Menu Principal
A função `menu()` exibe as opções disponíveis para o usuário:
```python
def menu():
    print("""
    1. Cadastrar remédio
    2. Listar remédios
    3. Alterar estado do remédio
    4. Sair""")
```

#### Cadastro de Remédio
O usuário pode adicionar um remédio à lista com `cadastrar_remedio()`:
```python
def cadastrar_remedio():
    nome_remedio = input("Digite o nome do remédio: ")
    valor_remedio = float(input("Digite o valor do remédio: "))
    remedio_nome = {"nome": nome_remedio, "valor": valor_remedio, "ativo": False}
    array_remedios.append(remedio_nome)
    print(f"O remédio {nome_remedio} foi adicionado com sucesso!")
```

#### Listagem de Remédios
A função `listar_remedios()` exibe os remédios cadastrados:
```python
def listar_remedios():
    for remedio in array_remedios:
        print(f"Nome: {remedio['nome']} - Valor: {remedio['valor']} - Status: {remedio['ativo']}")
```

#### Alterar Estado do Remédio (A Implementar)
Esta função permitirá alterar o status de um remédio para "ativo" ou "inativo".

---

## Execução e Testes

1. Certifique-se de ter o Python instalado.
2. Copie o código para um arquivo chamado `gerenciar_remedios.py`.
3. Execute o arquivo:
   ```bash
   python gerenciar_remedios.py
   ```
4. Teste as funcionalidades:
   - Cadastre novos remédios.
   - Liste os remédios cadastrados.
   - Implemente a alteração de status como desafio adicional.

---

## Expansões e Melhorias

Aqui estão algumas ideias para expandir o projeto:
1. **Salvar e Carregar Dados**: Salvar os remédios em um arquivo (ex.: JSON ou CSV) para persistência de dados.
2. **Interface Gráfica**: Adicionar uma interface gráfica usando bibliotecas como `tkinter` ou `PyQt`.
3. **Filtrar por Status**: Permitir listar apenas remédios ativos ou inativos.
4. **Ordenar por Preço**: Implementar ordenação da lista por preço.

---

## Referências

- Documentação oficial do [Python](https://docs.python.org/3/).
- Introdução a estruturas de dados em Python: [GeeksforGeeks](https://www.geeksforgeeks.org/python-data-structures/).

---