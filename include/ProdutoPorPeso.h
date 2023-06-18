#ifndef PRODUTOPORPESO_H
#define PRODUTOPORPESO_H

#include "Produto.h"

class ProdutoPorPeso : public Produto 
{
private:
    string peso;

public:
    ProdutoPorPeso(string, string, string, string);
    string getPeso();

    //lembrar de verificar sua utilidade
    void setPeso(string);
    ~ProdutoPorPeso();
};

#endif
