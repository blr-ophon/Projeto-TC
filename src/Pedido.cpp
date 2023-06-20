#include "Pedido.h"

#include <iostream>
#include <cstdio>


void Pedido::realizarPedido(Estoque *estoque){
    /*
     * Verifica se ha produtos disponiveis. Realiza a compra e atualiza o estoque
     */
    for(int i = 0; i < (int) produtosUnidades.size(); i++){
        ProdutoPorUnidade produtoPedido = produtosUnidades[i];
        ProdutoPorUnidade *produtoEstoque = estoque->searchProdutoU(produtoPedido.getNome());
         
        if(produtoEstoque){
            unsigned int total = stoi(produtoEstoque->getQuantidade());
            unsigned int desejado = stoi(produtoPedido.getQuantidade());

            if(total - desejado < 0){
                cout << "Parte da venda nao processada. Produto em falta:" << endl;
                cout << "> Nome: " << produtoPedido.getNome() << endl;
                cout << "> Quantidade desejada: " << desejado << endl;
                cout << "> Quantidade em estoque: " << total << endl << endl;

            }else{
                //Realiza compra e Atualiza Estoque
                char buf[50];
                sprintf(buf, "%d", total - desejado);
                string newAmount_str(buf);
                produtoEstoque->setQuantidade(newAmount_str);
            }
        }
    }
    for(int i = 0; i < (int) produtosPesos.size(); i++){
        ProdutoPorPeso produtoPedido = produtosPesos[i];
        ProdutoPorPeso *produtoEstoque = estoque->searchProdutoP(produtoPedido.getNome());
         
        if(produtoEstoque){
            float total = stoi(produtoEstoque->getPeso());
            float desejado = stoi(produtoPedido.getPeso());

            if(total - desejado < 0){
                cout << "Parte da venda nao processada. Produto em falta:" << endl;
                cout << "> Nome: " << produtoPedido.getNome() << endl;
                cout << "> Quantidade desejada: " << desejado << endl;
                cout << "> Quantidade em estoque: " << total << endl << endl;

            }else{
                //Realiza compra e Atualiza Estoque
                char buf[50];
                sprintf(buf, "%f", total - desejado);
                string newAmount_str(buf);
                produtoEstoque->setPeso(newAmount_str);
            }
        }
    }

    produtosUnidades.clear();
    produtosPesos.clear();
}

void Pedido::imprimirPedido(void){
    cout << "----PEDIDO----" << endl;
    for(int i = 0; i < (int) produtosUnidades.size(); i++){
        ProdutoPorUnidade produto = produtosUnidades[i];
        cout << "> Nome: " << produto.getNome() << endl;
        cout << "-- Codigo: " << produto.getCodigo() << endl;
        cout << "-- Preço: " << produto.getPreco() << endl;
        cout << "-- Quantidade: " << produto.getQuantidade() << endl << endl;
    }
    for(int i = 0; i < (int) produtosPesos.size(); i++){
        ProdutoPorPeso produto = produtosPesos[i];
        cout << "> Nome: " << produto.getNome() << endl;
        cout << "-- Codigo: " << produto.getCodigo() << endl;
        cout << "-- Preço: " << produto.getPreco() << endl;
        cout << "-- Peso: " << produto.getPeso() << endl << endl;
    }

    cout << endl;
}

void Pedido::adicionarProdutounidade(ProdutoPorUnidade produto) {
    this -> produtosUnidades.push_back (produto);
}

void Pedido::adicionarProdutopeso(ProdutoPorPeso produto) {
    this -> produtosPesos.push_back (produto);
}

void Pedido::removerProdutounidade(string nome) {
    for(int i = 0; i < (int) produtosUnidades.size(); i++){
        if(produtosUnidades[i].getNome() == nome){
            produtosUnidades.erase(produtosUnidades.begin() + i); 
        }
    }
}

void Pedido::removerProdutopeso(string nome) {
    for(int i = 0; i < (int) produtosPesos.size(); i++){
        if(produtosPesos[i].getNome() == nome){
            produtosPesos.erase(produtosPesos.begin() + i); 
        }
    }
}

void Pedido::setNome(std::string nome) {
    this -> nomeCliente = nome;
}

void Pedido::setCodigo(int codigo) {
    this -> codigoPedido = codigo;
}

std::string Pedido::getNome(){
    return nomeCliente;
}

int Pedido::getCodigo(){
    return codigoPedido;
}

float Pedido::getValorTotal(){
    float total = 0;
    for(int i = 0; i < produtosUnidades.size(); i++){
        total += stof(produtosUnidades[i].getPreco());
    };
    for(int i = 0; i < produtosPesos.size(); i++){
        total += stof(produtosPesos[i].getPreco());
    };
    this->valorTotal = total;
    return valorTotal;
}

