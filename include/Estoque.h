#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>

#include "ProdutoPorPeso.h"
#include "ProdutoPorUnidade.h"

class Estoque {
    public:
        Estoque(); 
                   
        void adicionarProdutoPeso(ProdutoPorPeso);
        void removerProdutoPeso();
        void adicionarProdutoUnidade(ProdutoPorUnidade);
        void removerProdutoUnidade();

        ProdutoPorPeso getpeso(int);            
        ProdutoPorUnidade getunidade(int);
        void imprimirEstoque(int = 0, bool = true);
        void recuperarDadosDoProduto(int, int, bool);
        int getSize(int);

        ~Estoque(); 
    private:
        vector<ProdutoPorUnidade> produtosUnidade;
        vector<ProdutoPorPeso> produtosPeso;
};

#endif
