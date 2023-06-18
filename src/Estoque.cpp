#include "Estoque.h"

#include <iostream>
#include <fstream>

using namespace std;

Estoque::Estoque() {
    /*
     * Abre os bancos e carrega em memoria
     */
    ifstream arquivoUnidade("BancoUnidades.txt");
    if (arquivoUnidade.is_open())
    {
        string curLine; 
        ProdutoPorUnidade tmp("", "", "", "");  
        for(int i = 0; getline(arquivoUnidade, curLine); i++){
            switch(i % 4){
                case 0:
                    tmp.setNome(curLine);
                    break;
                case 1:
                    tmp.setCodigo(curLine);
                    break;
                case 2:
                    tmp.setPreco(curLine);
                    break;
                case 3:
                    tmp.setQuantidade(curLine);
                    produtosUnidade.push_back(tmp);
                    break;
                default:
                    break;
            }
        }
        arquivoUnidade.close();
    }


    ifstream arquivoPeso("BancoPeso.txt");
    if (arquivoPeso.is_open())
    {
        string curLine; 
        ProdutoPorPeso tmp("", "", "", "");  
        for(int i = 0; getline(arquivoPeso, curLine); i++){
            switch(i % 4){
                case 0:
                    tmp.setNome(curLine);
                    break;
                case 1:
                    tmp.setCodigo(curLine);
                    break;
                case 2:
                    tmp.setPreco(curLine);
                    break;
                case 3:
                    tmp.setPeso(curLine);
                    produtosPeso.push_back(tmp);
                    break;
                default:
                    break;
            }
        }
        arquivoUnidade.close();
    }
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
