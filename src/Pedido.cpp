#include "Pedido.h"

#include <iostream>

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

