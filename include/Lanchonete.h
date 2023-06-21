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
    double lucros = 0;

    std::vector<Pedido> historicoPedidos;

public:
    Lanchonete();

    Estoque estoque;
    void setNomeLanchonete(std::string);
    void setTelefone(int);
    void setEndereco(std::string, std::string, std::string, int);
    void imprimeEndereco();

    std::string getNome();
    int getTelefone();
    double getLucro();
    ~Lanchonete();
};

#endif
