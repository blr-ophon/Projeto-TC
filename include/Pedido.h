#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <vector>

#include "ProdutoPorUnidade.h"
#include "ProdutoPorPeso.h"
#include "Estoque.h"

class Pedido{
    private:
        std::vector<ProdutoPorUnidade> produtosUnidades;
        std::vector<ProdutoPorPeso> produtosPesos;

    public:
        void realizarPedido(Estoque*);
        
        //print
        void imprimirPedido(void);

        //insert
        void adicionarProdutounidade(ProdutoPorUnidade);
        void adicionarProdutopeso(ProdutoPorPeso);

        //delete
        void removerProdutounidade(string);
        void removerProdutopeso(string);
};

#endif
