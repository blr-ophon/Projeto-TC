#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stdexcept>

using namespace std;

#include "ProdutoPorPeso.h"
#include "ProdutoPorUnidade.h"
#include "Estoque.h"


void mainMenu(Estoque &estoque);
void estManageMenu(Estoque &estoque);
void insertProdutoMenu(Estoque &estoque);
void searchProdutoMenu(Estoque &estoque);
void removeProdutoMenu(Estoque &estoque);

#endif
