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
#include "Lanchonete.h"


void mainMenu(Lanchonete &lanchonete);

//gerenciamento de estoque
void estManageMenu(Estoque &estoque);
void insertProdutoMenu(Estoque &estoque);
void searchProdutoMenu(Estoque &estoque);
void removeProdutoMenu(Estoque &estoque);

//atendimento ao cliente
void pedidoManageMenu(Lanchonete &lanchonete);
void addCartMenu(Lanchonete &lanchonete, Pedido &pedido);
void delCartMenu(Pedido &pedido);

#endif
