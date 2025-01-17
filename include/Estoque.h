#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "ProdutoPorPeso.h"
#include "ProdutoPorUnidade.h"

class Estoque {
    public:
        Estoque(); 
        ~Estoque(); 

        //ordenar por nome
        void sortEstoque(void);

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
        void imprimirEstoque(void);
        int getSize(int);

    private:
        vector<ProdutoPorUnidade> produtosUnidade;
        vector<ProdutoPorPeso> produtosPeso;
};

#endif
