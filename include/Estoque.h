#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "ProdutoPorPeso.h"
#include "ProdutoPorUnidade.h"

class Estoque {
    public:
        Estoque(); 
        ~Estoque(); 
                   
        //Insert
        void adicionarProdutoPeso(ProdutoPorPeso);
        void adicionarProdutoUnidade(ProdutoPorUnidade);

        //Remove
        void removerProdutoUnidade(string);
        void removerProdutoPeso(string);

        //Search
        ProdutoPorUnidade *searchProdutoU(string);
        ProdutoPorPeso *searchProdutoP(string);

        //Print
        void imprimirEstoque(int = 0, bool = true);
        int getSize(int);

    private:
        vector<ProdutoPorUnidade> produtosUnidade;
        vector<ProdutoPorPeso> produtosPeso;
};

#endif
