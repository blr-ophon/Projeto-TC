#ifndef LANCHONETE_H
#define LANCHONETE_H

#include <string>

#include "Estoque.h"
#include "Pedido.h"

class Lanchonete {
private:
    struct Endereco{
        std::string cidade;
        std::string bairro;
        std::string rua;
        int numero;
    };

    std::string nomeLoja;
    Endereco endereco;
    int telefone;
    double lucros;

    std::vector<Pedido> historicoPedidos;

public:
    Estoque estoque;

    Lanchonete();
    void realizarPedido(Pedido*);
    void removerPedido(int);
    void setNomeLanchonete(std::string);
    std::string getNome();
    void setEndereco(std::string, std::string, std::string, int);
    void imprimeEndereco();
    double getLucro();
    void setTelefone(int);
    int getTelefone();
    ~Lanchonete();
};

#endif
