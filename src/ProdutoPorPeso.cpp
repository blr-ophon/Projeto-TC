#include "ProdutoPorPeso.h"

ProdutoPorPeso::ProdutoPorPeso(string peso, string nome, string codigo, string preco)
    : Produto(nome, codigo, preco) 
{
    this->peso = peso;
}

ProdutoPorPeso::~ProdutoPorPeso(void){
}

string ProdutoPorPeso::getPeso()  
{
    return peso;
}

//lembrar de verificar sua utilidade
void ProdutoPorPeso::setPeso(string str) 
{
    peso = str;
}
