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
void Produto::setNome(std::string nome) 
{
    this->nome = nome;
}

void Produto::setCodigo(int codigo) 
{
    this->codigo = codigo;
}

void Produto::setPreco(float preco) 
{
    this->preco = preco;
}

Produto::~Produto() {}
