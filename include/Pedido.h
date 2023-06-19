#ifndef PEDIDO_H
#define PEDIDO_H

#include <string>
#include <vector>

#include "ProdutoPorUnidade.h"
#include "ProdutoPorPeso.h"
#include "Estoque.h"

class Pedido{
private:
    std::string nomeCliente;
    int codigoPedido;
    float valorTotal;

    std::vector<ProdutoPorUnidade> produtosUnidades;
    std::vector<ProdutoPorPeso> produtosPesos;

public:
    //print
    void imprimirPedido(void);

    //insert
    void adicionarProdutounidade(ProdutoPorUnidade);
    void adicionarProdutopeso(ProdutoPorPeso);

    //delete
    void removerProdutounidade(string);
    void removerProdutopeso(string);

    void setNome(std::string nome);
    void setCodigo(int codigo);
    std::string getNome();
    int getCodigo();
    float getValorTotal();
};

#endif
