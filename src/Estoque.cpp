#include "Estoque.h"

#include <iostream>
#include <fstream>

//TODO: usar enum para os 'estoques', com um ANY ao invés de all
//TODO: testar os dois removerProduto
//TODO: testar salvamento e recuperacao de dados em memoria externa.

using namespace std;

Estoque::Estoque() {
    /*
     * Abre o banco e carrega em memoria
     */
    ifstream arquivoUnidade("EstoqueProdutoUnidade.txt");
    if (arquivoUnidade.is_open())
    {
        string quantidade, nome, codigo, preco;
        while (getline(arquivoUnidade, quantidade))
        {
            getline(arquivoUnidade, nome);
            getline(arquivoUnidade, codigo);
            getline(arquivoUnidade, preco);
            ProdutoPorUnidade produtoUnidade(quantidade, nome, codigo, preco);
            produtosUnidade.push_back(produtoUnidade);
        }
        arquivoUnidade.close();
    }


    ifstream arquivoPeso("EstoqueProdutoPeso.txt");
    if (arquivoPeso.is_open())
    {
        string peso, nome, codigo, preco;
        while (getline(arquivoPeso, peso))
        {
            getline(arquivoPeso, nome);
            getline(arquivoPeso, codigo);
            getline(arquivoPeso, preco);
            ProdutoPorPeso produtoPeso(peso, nome, codigo, preco);
            produtosPeso.push_back(produtoPeso);
        }
        arquivoPeso.close();
    }
}


Estoque::~Estoque() {
    /*
     * Salva os arquivos da memoria para o banco
     */
    ofstream arquivoUnidade("EstoqueProdutoUnidade.txt");
    if (arquivoUnidade.is_open())
    {
        for (int i = 0; i < (int) produtosUnidade.size(); i++)
        {
            arquivoUnidade << produtosUnidade[i].getQuantidade() << endl;
            arquivoUnidade << produtosUnidade[i].getNome() << endl;
            arquivoUnidade << produtosUnidade[i].getCodigo() << endl;
            arquivoUnidade << produtosUnidade[i].getPreco() << endl;
        }
        arquivoUnidade.close();
    }

    ofstream arquivoPeso("EstoqueProdutoPeso.txt");
    if (arquivoPeso.is_open())
    {
        for (int i = 0; i < (int) produtosPeso.size(); i++)
        {
            arquivoPeso << produtosPeso[i].getPeso() << endl;
            arquivoPeso << produtosPeso[i].getNome() << endl;
            arquivoPeso << produtosPeso[i].getCodigo() << endl;
            arquivoPeso << produtosPeso[i].getPreco() << endl;
        }
        arquivoPeso.close();
    }
}

void Estoque::adicionarProdutoPeso(ProdutoPorPeso ProdutoP) {
    /*
     * Adiciona novo produto (por peso) na memoria 
     */
    this->produtosPeso.push_back(ProdutoP);
}

void Estoque::adicionarProdutoUnidade(ProdutoPorUnidade ProdutoP) {
    /*
     * Adiciona novo produto (por unidade) na memoria 
     */
    this->produtosUnidade.push_back(ProdutoP);
}

void Estoque::removerProdutoUnidade() {
    /*
     * Remove produto (por unidade) da memoria.
     */
    bool sair = false;
    int entrada;
    if (produtosUnidade.size() == 0) {
        cout << "Sem Produtos no estoque" << endl;
        system("pause");
    }
    else {
        try {
            //que porra... ???
            do {
                cout << "Selecione um produto (1-" << produtosUnidade.size() << ")" << endl;
                cin >> entrada;

                if (cin.fail()) {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if (entrada > 0 && entrada <= produtosUnidade.size()) {
                    sair = true;
                }
                else {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    system("pause");
                    system("cls");
                }
            } while (!sair);
            vector<ProdutoPorUnidade>::iterator it;
            it = produtosUnidade.begin() + entrada - 1;
            produtosUnidade.erase(it);
        }
        catch (const exception& ligador) {
            cout << "" << ligador.what() << endl;
        }
    }
}

void Estoque::removerProdutoPeso() {
    /*
     * Remove produto (por Peso) da memoria.
     * TODO: Refazer
     */
    bool sair = false;
    int entrada;
    if (produtosPeso.size() == 0) {
        cout << "Sem Produtos no estoque" << endl;
        system("pause");
    }
    else {
        try {
            // Por que ;-;
            do {
                cout << "Selecione um produto (1-" << produtosPeso.size() << ")" << endl;
                cin >> entrada;

                if (cin.fail()) {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    cin.clear();
                    cin.ignore();
                }
                else if (entrada > 0 && entrada <= produtosPeso.size()) {
                    sair = true;
                }
                else {
                    cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
                    system("pause");
                    system("cls");
                }
            } while (!sair);
            vector<ProdutoPorPeso>::iterator it;
            it = produtosPeso.begin() + entrada - 1;
            produtosPeso.erase(it);
        }
        catch (const exception& ligador) {
            cout << "" << ligador.what() << endl;
        }
    }
}


void Estoque::imprimirEstoque(int estoque, bool all) {
    /*
     * 'estoque' indica se é por unidade ou por peso, all para qualquer um
     */
    if (estoque == 1 || all) {
        cout << "Produtos por unidade: " << endl;
        for (int i = 0; i < produtosUnidade.size(); i++) {
            cout << produtosUnidade[i].getNome() << " | Quantidade: " << produtosUnidade[i].getQuantidade() << endl;
        };
    };
    if (all) { cout << "------------------------" << endl; };
    if (estoque == 2 || all) {
        cout << "Produtos por peso: " << endl;
        for (int i = 0; i < produtosPeso.size(); i++) {
            cout << produtosPeso[i].getNome() << " | Quantidade: " << produtosPeso[i].getPeso() << endl;
        };
    };
}

void Estoque::recuperarDadosDoProduto(int estoque, int produto, bool all) {
    /*
     * estoque indica se é por unidade ou por peso, all para qualquer um.
     * Produto indica o id do produto pra encontrar?
     * Estoque in-mem
     */
    bool imprimirPorUnidade = (estoque == 1) || (all && estoque != 2);
    bool imprimirPorPeso = (estoque == 2) || all;

    if (imprimirPorUnidade && produtosUnidade.size() > 0) {
        cout << "Produtos por unidade: " << endl;
        for (int i = 0; i < produtosUnidade.size(); i++) {
            if (produto == i) {
                cout << produtosUnidade[i].getNome() << " | Quantidade: " << produtosUnidade[i].getQuantidade() << endl;
            }
        }
    }
    else if (imprimirPorPeso && produtosPeso.size() > 0) {
        cout << "Produtos por peso: " << endl;
        for (int i = 0; i < produtosPeso.size(); i++) {
            if (produto == i) {
                cout << produtosPeso[i].getNome() << " | Quantidade: " << produtosPeso[i].getPeso() << endl;
            }
        }
    }
}

int Estoque::getSize(int estoque) {
    /*
     * retorna a quantidade de items no estoque (in-mem)
     */
    switch(estoque){
        case 1:
            return produtosUnidade.size();
        case 2:
            return produtosPeso.size();
        default:
            //opção invalida
            return 0;
    }
}

ProdutoPorPeso Estoque::getpeso(int entrada) {
    /*
     * Pesquisa em memoria pelo peso de um produto. 
     * Seria melhor com hashmap, mas o professor quer vetor ¯\_(ツ)_/¯
     */
    return produtosPeso[entrada];
}
ProdutoPorUnidade Estoque::getunidade(int entrada) {
    /*
     * Pesquisa em memoria pela unidade de um produto.
     * Seria melhor com hashmap, mas o professor quer vetor ¯\_(ツ)_/¯
     */
    return produtosUnidade[entrada];
}

