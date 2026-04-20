import os
import time

array_remedios = [{"nome": "Zolpidem", "valor": 67.90, "ativo": False}, {"nome": "Paracetamol",
                                                                         "valor": 5.25, "ativo": True}, {"nome": "Clorazepam", "valor": 1000.00, "ativo": False}]


def menu():
    print("""
    ╭━━━╮╱╱╱╱╱╱╱╱╱╱╭╮
    ┃╭━━╯╱╱╱╱╱╱╱╱╱╱┃┃
    ┃╰━━┳━━┳━┳╮╭┳━━┫┃╭━━┳━━┳━━╮
    ┃╭━━┫╭╮┃╭┫╰╯┃╭╮┃┃┃╭╮┃╭━┫╭╮┃
    ┃┃╱╱┃╭╮┃┃┃┃┃┃╭╮┃╰┫╰╯┃╰━┫╭╮┃
    ╰╯╱╱╰╯╰┻╯╰┻┻┻╯╰┻━┻━━┻━━┻╯╰╯""")
    print("1. Cadastrar remédio")
    print("2. Listar remédios")
    print("3. Alterar estado do remédio")
    print("4. Sair")


def exibir_opcoes():
    try:
        escolha = int(input("Escolha uma opção: "))
        if escolha == 1:
            cadastrar_remedio()
        elif escolha == 2:
            listar_remedios()
        elif escolha == 3:
            print("Alterar remédio") #implementar Status 
        elif escolha == 4:
            print("Sair do programa")
        else:
            print("Opção inválida")
    except:
        print("Opção inválida, tente outra")


def cadastrar_remedio():
    os.system('cls')
    print("-- Cadastrar remédio --")

    nome_remedio = input("Digite o nome do remédio: ")
    valor_remedio = float(input("Digite o valor do remédio: "))
    remedio_nome = {"nome": nome_remedio,
                    "valor": valor_remedio, "ativo": False}
    array_remedios.append(remedio_nome)

    print(f"O remédio {nome_remedio} foi adicionado com sucesso!")
    time.sleep(2)
    voltar_ao_menu_principal()


def listar_remedios():
    os.system('cls')
    print("-- Listar remédio --")
    for remedio in array_remedios:
        print(
            f"Nome: {remedio['nome']} - Valor: {remedio['valor']} - Status: {remedio['ativo']} ")
    voltar_ao_menu_principal()

def voltar_ao_menu_principal():
    input('\nDigite uma tecla para voltar ao menu ')
    main()


def main():
    os.system('cls')
    menu()
    exibir_opcoes()


if __name__ == '__main__':
    main()
