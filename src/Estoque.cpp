#include "Estoque.h"

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

Estoque::Estoque() {
}


Estoque::~Estoque() {
    /*
     * Salva os arquivos da memoria para o banco
     */
    ofstream arquivoUnidade("BancoUnidades.txt");
    if (arquivoUnidade.is_open())
    {
        for (int i = 0; i < (int) produtosUnidade.size(); i++)
        {
            arquivoUnidade << produtosUnidade[i].getNome() << endl;
            arquivoUnidade << produtosUnidade[i].getCodigo() << endl;
            arquivoUnidade << produtosUnidade[i].getPreco() << endl;
            arquivoUnidade << produtosUnidade[i].getQuantidade() << endl;
        }
        arquivoUnidade.close();
    }

    ofstream arquivoPeso("BancoPeso.txt");
    if (arquivoPeso.is_open())
    {
        for (int i = 0; i < (int) produtosPeso.size(); i++)
        {
            arquivoPeso << produtosPeso[i].getNome() << endl;
            arquivoPeso << produtosPeso[i].getCodigo() << endl;
            arquivoPeso << produtosPeso[i].getPreco() << endl;
            arquivoPeso << produtosPeso[i].getPeso() << endl;
        }
        arquivoPeso.close();
    }
}


static bool comparaPorNome(Produto& a, Produto& b) {
    /*
     * Para uso em sorting
     */
    return a.getNome() < b.getNome();
}

void Estoque::sortEstoque(void){
    /*
     * Ordena por nome em ordem crescente
     */
    sort(produtosUnidade.begin(), produtosUnidade.end(), comparaPorNome);
    sort(produtosPeso.begin(), produtosPeso.end(), comparaPorNome);
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

void Estoque::removerProdutoUnidade(string key) {
    /*
     * Remove produto (por unidade) da memoria.
     */
    for(int i = 0; i < (int) produtosUnidade.size(); i++){  
        string nome = produtosUnidade[i].getNome();
        if(nome == key){
            produtosUnidade.erase(produtosUnidade.begin() + i);
            break;
        }
    }
}

ProdutoPorUnidade *Estoque::searchProdutoU(string key){
    /*
     * Busca produto (por unidade) da memoria usando nome
     */
    for(int i = 0; i < (int) produtosUnidade.size(); i++){  
        string nome = produtosUnidade[i].getNome();
        if(nome == key){
            return &produtosUnidade[i];
            break;
        }
    }

    return NULL;
}

ProdutoPorPeso *Estoque::searchProdutoP(string key){
    /*
     * Busca produto (por unidade) da memoria usando nome
     */
    for(int i = 0; i < (int) produtosPeso.size(); i++){  
        string nome = produtosPeso[i].getNome();
        if(nome == key){
            return &produtosPeso[i];
            break;
        }
    }
    return NULL;
}

void Estoque::removerProdutoPeso(string key) {
    /*
     * Remove produto (por Peso) da memoria.
     */
    for(int i = 0; i < (int) produtosPeso.size(); i++){  
        string nome = produtosPeso[i].getNome();
        if(nome == key){
            produtosPeso.erase(produtosPeso.begin() + i);
            break;
        }
    }
}


void Estoque::imprimirEstoque(void) {
    /*
     * Imprime todos os produtos em estoque
     */
    sortEstoque();  //ordena em ordem alfabetica

    cout << "Produtos por unidade: " << endl << endl;
    for (int i = 0; i < (int) produtosUnidade.size(); i++) {
        ProdutoPorUnidade produto = produtosUnidade[i];

        cout << "> Nome: " << produto.getNome() << endl;
        cout << "-- Codigo: " << produto.getCodigo() << endl;
        cout << "-- Preço: " << produto.getPreco() << endl;
        cout << "-- Quantidade: " << produto.getQuantidade() << endl << endl;
    };

    cout << "Produtos por peso: " << endl << endl;
    for (int i = 0; i < (int) produtosPeso.size(); i++) {
        ProdutoPorPeso produto = produtosPeso[i];

        cout << "> Nome: " << produto.getNome() << endl;
        cout << "-- Codigo: " << produto.getCodigo() << endl;
        cout << "-- Preço: " << produto.getPreco() << endl;
        cout << "-- Quantidade: " << produto.getPeso() << " kg" << endl << endl;
    };

    cout << endl;
}

int Estoque::getSize(int estoque){
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
