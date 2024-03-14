#include <iostream>
#include <iomanip>
#define MAX 10

using namespace std;

struct funcionario
{
    string nome;
    string cargo;

    double salarioBase;
    double sLiquido;

    int beneficio;
    int desconto;

    void ler()
    {
        cin.ignore();

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Cargo: ";
        getline(cin, cargo);

        cout << "Salario base: R$ ";
        cin >> salarioBase;

        cout << "Beneficio em %: ";
        cin >> beneficio;

        cout << "Descontos em %: ";
        cin >> desconto;
    }

    void imprimirFuncionario()
    {
        cout << fixed << setprecision(2);
        cout << "Nome: " << nome << endl;
        cout << "Cargo: " << cargo << endl;
        cout << "Salario base: R$ " << salarioBase << endl;
        cout << "Beneficio: " << beneficio << "%" << endl;
        cout << "Descontos: " << desconto << "%" << endl;
        cout << "Salario liquido: R$ " << salarioLiquido() << endl;
    }

    double salarioLiquido()
    {
        sLiquido = salarioBase + (salarioBase * beneficio / 100) - (salarioBase * desconto / 100);

        return sLiquido;
    }
};

struct loja
{
    funcionario funcionarios[MAX];

    int quantidadeFuncionario = 0;

    void cadastrar()
    {
        if (quantidadeFuncionario >= MAX)
        {
            cout << "Numero maximo de cadastrado realizado" << endl;
            return;
        }
        funcionarios[quantidadeFuncionario].ler();
        quantidadeFuncionario++;
    }

    void listar()
    {
        if (quantidadeFuncionario == 0)
        {
            cout << "Nenhum cadastrado realizado" << endl;
            return;
        }
        for (int i = 0; i < quantidadeFuncionario; i++)
        {   
            cout << "  ======================= " << endl;
            cout << "Funcionario: " << i + 1 << endl;
            funcionarios[i].imprimirFuncionario();
        }
    }

    void imprimirMediaSalarial()
    {
        if (quantidadeFuncionario == 0)
        {
            cout << "Nenhum cadastrado realizado " << endl;
            return;
        }

        double mediaBase = 0, mediaLiquida = 0;

        for (int i = 0; i < quantidadeFuncionario; i++)
        {
            mediaBase += funcionarios[i].salarioBase;
            mediaLiquida += funcionarios[i].sLiquido;
        }

        mediaBase /= quantidadeFuncionario;
        mediaLiquida /= quantidadeFuncionario;

        cout << fixed << setprecision(1);
        cout << "Media Salario Base: " << mediaBase << endl;
        cout << "Media Salario Liquido: " << mediaLiquida << endl;
    }

    void imprimirMaiorSalario()
    {
        if (quantidadeFuncionario == 0)
        {
            cout << "Nenhum cadastrado realizado" << endl;
            return;
        }

        double maiorBase = 0;
        int posicaoBase = -1;

        double maiorLiquido = 0;
        int posicaoLiquido = -1;

        for (int i = 0; i < quantidadeFuncionario; i++)
        {
            if (funcionarios[i].salarioBase > maiorBase)
            {
                maiorBase = funcionarios[i].salarioBase;
                posicaoBase = i;
            }
            if (funcionarios[i].sLiquido > maiorLiquido)
            {
                maiorLiquido = funcionarios[i].sLiquido;
                posicaoLiquido = i;
            }
        }

        cout << "Funcionario com maior salario base: ";
        funcionarios[posicaoBase].imprimirFuncionario();

        cout << endl;

        cout << "Funcionario com maior salario liquido: ";
        funcionarios[posicaoLiquido].imprimirFuncionario();
    }
};

int main()
{
    loja loja;
    int opcao;

    do
    {
        cout << "  ======================= " << endl;
        cout << "  - MENU - " << endl;
        cout << "1. Cadastrar" << endl;
        cout << "2. Listar funcionarios" << endl;
        cout << "3. Medias Salariais" << endl;
        cout << "4. Funcionario com maior salario" << endl;
        cout << "5. Sair" << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            loja.cadastrar();
            break;
        case 2:
            loja.listar();
            break;
        case 3:
            loja.imprimirMediaSalarial();
            break;
        case 4:
            loja.imprimirMaiorSalario();
            break;
        };

    } while (opcao != 5);

    return 0;
}
