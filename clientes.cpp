#include <iostream>
#include <ctime>
#define MAX_CADASTRO 50

using namespace std;

struct dataNascimento
{
    int dia, mes, ano;
    int diasNascimento, diasAtual, idade;
    int diaAtual, mesAtual, anoAtual;

    void lerDataNascimento()
    {
        cout << "Digite o dia de nascimento : ";
        cin >> dia;
        cout << "Digite o mes de nascimento : ";
        cin >> mes;
        cout << "Digite o ano de nascimento : ";
        cin >> ano;
    }

    void calcularIdade()
    {
        time_t t;
        struct tm infoTempo;

        time(&t);
        infoTempo = *localtime(&t);

        diaAtual = infoTempo.tm_mday;
        mesAtual = infoTempo.tm_mon + 1;
        anoAtual = infoTempo.tm_year + 1900;

        idade = calculoIdade();
    }

    int calculoIdade()
    {
        diasNascimento = dia + (mes * 30) + (ano * 365);

        diasAtual = diaAtual + (mesAtual * 30) + (anoAtual * 365);

        idade = (diasAtual - diasNascimento) / 365;

        return idade;
    }
};

struct cadastroCliente
{

    dataNascimento data;
    string nome;
    char sexo;

    void ler()
    {
        cin.ignore();
        cout << "Digite seu nome: ";
        getline(cin, nome);

        data.lerDataNascimento();
        data.calcularIdade();

        cout << "Digite seu sexo (M ou F): ";
        cin >> sexo;
    }

    void imprimir()
    {
        cout << "Nome: " << nome << endl;
        cout << "Data de nascimento: " << data.dia << "-" << data.mes << "-" << data.ano << endl;
        cout << "Idade: " << data.idade << endl;
        cout << "Sexo: " << sexo << endl;
    }
};

int main()
{
    cadastroCliente c[MAX_CADASTRO];
    int quantidadeCliente = 0;

    int opcao;

    do
    {
        cout << "  ======================= " << endl;
        cout << "MENU" << endl;
        cout << "1 - Cadastrar cliente." << endl;
        cout << "2 - Listar clientes." << endl;
        cout << "3 - Sair" << endl;

        cin >> opcao;

        switch (opcao)
        {

        case 1:
            if (quantidadeCliente >= MAX_CADASTRO)
            {
                cout << "Você ja cadastrou o numero máximo de clientes" << endl;
                break;
            }
            c[quantidadeCliente].ler();

            quantidadeCliente++;

            break;

        case 2:

            if (quantidadeCliente == 0)
            {
                cout << "Nenhum cliente cadastrado" << endl;
                break;
            }

            for (int i = 0; i < quantidadeCliente; i++)
            {

                cout << "Cliente " << i + 1 << ": " << endl;

                c[i].imprimir();
            }

            break;
        };

    } while (opcao != 3);

    return 0;
}
