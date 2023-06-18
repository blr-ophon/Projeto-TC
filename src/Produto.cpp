#include "Produto.h"

Produto::Produto(string nome, string codigo, string preco) 
{
    this->nome = nome;
    this->codigo = codigo;
    this->preco = preco;
}


string Produto::getNome()  
{
    return nome;
}

string Produto::getCodigo()  
{
    return codigo;
}

string Produto::getPreco()  
{
    return preco;
}


//lembrar de verificar sua utilidade
void Produto::setNome(std::string str) 
{
    nome = str;
}

void Produto::setCodigo(string str) 
{
    codigo = str;
}

void Produto::setPreco(string str) 
{
    preco = str;
}

Produto::~Produto() {}
