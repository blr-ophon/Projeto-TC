#ifndef PRODUTOPORPESO_H
#define PRODUTOPORPESO_H

#include "Produto.h"

class ProdutoPorPeso : public Produto 
{
private:
    string peso;

public:
    ProdutoPorPeso(string, string, string, string);
    ~ProdutoPorPeso();

    string getPeso();
    void setPeso(string);
};

#endif
