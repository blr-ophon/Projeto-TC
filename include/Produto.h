#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

using namespace std;

class Produto 
{
protected:
    string nome;
    string codigo;
    string preco;

    //lembrar de verificar sua utilidade
    //string regraManipulacao;
    //string regraTransporte;
public:
    Produto(string, string, string);
    string getNome();
    string getCodigo();
    string getPreco();

    //lembrar de verificar sua utilidade
    void setNome(string);
    void setCodigo(int codigo);
    void setPreco(float preco);

    ~Produto();
};

#endif