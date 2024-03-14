#include <iostream>
#include <vector>
#include <algorithm>
1
#define MAX_TAMANHO 20
#define MAX_CONJUNTO 10

using namespace std;

struct Conjunto
{
    int elementos[MAX_TAMANHO];
    int tamanho;

    void conjuntoVazio()
    {
        tamanho = 0;
        cout << "Conjunto vazio criado" << endl;
    }

    void ler()
    {
        do
        {
            cout << "Digite o tamanho do conjunto: ";
            cin >> tamanho;
        } while (tamanho <= 0 || tamanho > MAX_TAMANHO);

        cout << "Digite os elementos do conjunto de tamanho " << tamanho << ": ";
        for (int i = 0; i < tamanho; i++)
        {
            cin >> elementos[i];
        }
    }

    void imprimir()
    {
        for (int i = 0; i < tamanho; i++)
        {
            cout << elementos[i] << " ";
        }
        cout << "}" << endl;
    }
};

struct TDA
{
    Conjunto conjuntos[MAX_CONJUNTO];
    int qtdConjuntos = 0;

    void criarConjuntoVazio()
    {
        if (qtdConjuntos == MAX_CONJUNTO)
        {
            cout << "Limite de conjuntos atingido" << endl;
            return;
        }
        conjuntos[qtdConjuntos].conjuntoVazio();
        qtdConjuntos++;
    }

    void lerConjunto()
    {
        if (qtdConjuntos == MAX_CONJUNTO)
        {
            cout << "Limite de conjuntos atingido" << endl;
            return;
        }
        cout << "Conjunto " << qtdConjuntos + 1 << " :" << endl;
        conjuntos[qtdConjuntos].ler();
        qtdConjuntos++;
    }

    void unir()
    {

        if (qtdConjuntos == 0)
        {
            cout << "Necessario ler dois conjunto para fazer a uniao" << endl;
            return;
        }
        else if (qtdConjuntos < 2)
        {
            cout << "Necessario ler outro conjunto para fazer a uniao" << endl;
            return;
        }

        cout << "Dos conjuntos cadastrados quais deseja unir ? (dois conjuntos)" << endl;
        for (int i = 0; i < qtdConjuntos; i++)
        {
            cout << "Conjunto " << i + 1 << ": { ";
            conjuntos[i].imprimir();
        }

        int opcaoA, opcaoB;

        do
        {
            cin >> opcaoA;
            if (opcaoA <= 0 || opcaoA > qtdConjuntos)
            {
                cout << "Escolha um Conjunto disponivel" << endl;
            }
        } while (opcaoA <= 0 || opcaoA > qtdConjuntos);

        do
        {
            cin >> opcaoB;
            if (opcaoB <= 0 || opcaoB > qtdConjuntos)
            {
                cout << "Escolha um Conjunto disponivel" << endl;
            }
            else if (opcaoB == opcaoA)
            {
                cout << "Escolha um Conjunto diferente" << endl;
            }
        } while (opcaoB <= 0 || opcaoB > qtdConjuntos || opcaoB == opcaoA);

        vector<int> resultadoUniao;
        for (int i = 0; i < conjuntos[opcaoA - 1].tamanho; i++)
        {
            resultadoUniao.push_back(conjuntos[opcaoA - 1].elementos[i]);
        }

        for (int i = 0; i < conjuntos[opcaoB - 1].tamanho; i++)
        {
            resultadoUniao.push_back(conjuntos[opcaoB - 1].elementos[i]);
        }

        sort(resultadoUniao.begin(), resultadoUniao.end());
        resultadoUniao.erase(unique(resultadoUniao.begin(), resultadoUniao.end()), resultadoUniao.end());

        cout << "Conjunto " << opcaoA << " U Conjunto " << opcaoB << ": { ";
        
        for (int i = 0; i < resultadoUniao.size(); i++)
        {
            cout << resultadoUniao[i] << " ";
        }

        cout << "}" << endl;
    }

    void intersecao()
    {

        if (qtdConjuntos == 0)
        {
            cout << "Necessario ler dois conjunto para fazer a intersecao" << endl;
            return;
        }
        else if (qtdConjuntos < 2)
        {
            cout << "Necessario ler outro conjunto para fazer a intersecao" << endl;
            return;
        }

        cout << "Dos conjuntos cadastrados quais deseja fazer a intersecao ?  (dois conjuntos)" << endl;
        for (int i = 0; i < qtdConjuntos; i++)
        {
            cout << "Conjunto " << i + 1 << ": { ";
            conjuntos[i].imprimir();
        }

        int opcaoA, opcaoB;

        do
        {
            cin >> opcaoA;
            if (opcaoA <= 0 || opcaoA > qtdConjuntos)
            {
                cout << "Escolha um Conjunto disponivel!!" << endl;
            }
        } while (opcaoA <= 0 || opcaoA > qtdConjuntos);

        do
        {
            cin >> opcaoB;
            if (opcaoB <= 0 || opcaoB > qtdConjuntos)
            {
                cout << "Escolha um Conjunto disponivel" << endl;
            }
            else if (opcaoB == opcaoA)
            {
                cout << "Escolha um Conjunto diferente" << endl;
            }
        } while (opcaoB <= 0 || opcaoB > qtdConjuntos || opcaoB == opcaoA);

        vector<int> resultadoIntersecao;

        for (int i = 0; i < conjuntos[opcaoA - 1].tamanho; i++)
        {
            for (int j = 0; j < conjuntos[opcaoB - 1].tamanho; j++)
            {
                if (conjuntos[opcaoA - 1].elementos[i] == conjuntos[opcaoB - 1].elementos[j])
                {
                    resultadoIntersecao.push_back(conjuntos[opcaoA - 1].elementos[i]);
                    break;
                }
            }
        }

        cout << "Conjunto " << opcaoA << " & Conjuto " << opcaoB << " : { ";

        for (int i = 0; i < resultadoIntersecao.size(); i++)
        {
            cout << resultadoIntersecao[i] << " ";
        }

        cout << "}" << endl;
    }

    void imprimirConjunto()
    {

        if (qtdConjuntos == 0)
        {
            cout << "Nao a conjuntos para imprimir!" << endl;
            return;
        }

        for (int i = 0; i < qtdConjuntos; i++)
        {
            cout << "Conjunto " << i + 1 << ": { ";
            conjuntos[i].imprimir();
        }
    }
};

int main()
{
    TDA conjunto;

    int opcao;

    do
    {
        cout << "  ======================= " << endl;
        cout << " - MENU -" << endl;
        cout << "1. Criar conjunto vazio" << endl;
        cout << "2. Ler os dados de um conjunto" << endl;
        cout << "3. Unir  os dois conjuntos" << endl;
        cout << "4. Fazer intersecao dos dois conjuntos" << endl;
        cout << "5. Imprimir conjuntos" << endl;
        cout << "6. Sair ." << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            conjunto.criarConjuntoVazio();
            break;
        case 2:
            conjunto.lerConjunto();
            break;
        case 3:
            conjunto.unir();
            break;
        case 4:
            conjunto.intersecao();
            break;
        case 5:
            conjunto.imprimirConjunto();
            break;
        };

    } while (opcao != 6);

    return 0;
}
