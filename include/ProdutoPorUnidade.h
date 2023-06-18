#ifndef PRODUTOPORUNIDADE_H
#define PRODUTOPORUNIDADE_H

#include <string>
#include "Produto.h"

class ProdutoPorUnidade : public Produto 
{
private:
    string quantidade;

public:
    ProdutoPorUnidade(string, string, string, string);
    ~ProdutoPorUnidade();
    string getQuantidade();
    void setQuantidade(string);
};


#endif
