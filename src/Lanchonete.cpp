#include "Lanchonete.h"

#include <iostream>
#include <fstream>

void Lanchonete::abrirDBs(void){
    /*
     * Abre os bancos e carrega dados em memoria
     */
    ifstream arquivoUnidade("DB_porUnidade.txt");
    if (arquivoUnidade.is_open())
    {
        //Le linhas uma a uma e insere no respectivo atributo por ordem
        string curLine; 
        ProdutoPorUnidade tmp("", "", "", "");  
        for(int i = 0; getline(arquivoUnidade, curLine); i++){
            switch(i % 4){
                case 0:
                    tmp.setNome(curLine);
                    break;
                case 1:
                    tmp.setCodigo(curLine);
                    break;
                case 2:
                    tmp.setPreco(curLine);
                    break;
                case 3:
                    tmp.setQuantidade(curLine);
                    //produtosUnidade.push_back(tmp);
                    estoque.adicionarProdutoUnidade(tmp);
                    break;
                default:
                    break;
            }
        }
        arquivoUnidade.close();
    }


    ifstream arquivoPeso("DB_porPeso.txt");
    if (arquivoPeso.is_open())
    {
        //Le linhas uma a uma e insere no respectivo atributo por ordem
        string curLine; 
        ProdutoPorPeso tmp("", "", "", "");  
        for(int i = 0; getline(arquivoPeso, curLine); i++){
            switch(i % 4){
                case 0:
                    tmp.setNome(curLine);
                    break;
                case 1:
                    tmp.setCodigo(curLine);
                    break;
                case 2:
                    tmp.setPreco(curLine);
                    break;
                case 3:
                    tmp.setPeso(curLine);
                    //produtosPeso.push_back(tmp);
                    estoque.adicionarProdutoPeso(tmp);
                    break;
                default:
                    break;
            }
        }
        arquivoUnidade.close();
    }
}
