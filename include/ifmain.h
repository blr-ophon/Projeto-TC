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
void Menu_estoque(Estoque &estoque);
void Menu_estoqueAdd(Estoque &estoque);
void Menu_estoqueSearch(Estoque &estoque);
void Menu_estoqueDel(Estoque &estoque);

//atendimento ao cliente
void Menu_atendimento(Lanchonete &lanchonete);
void Menu_atendimentoAdd(Lanchonete &lanchonete, Pedido &pedido);
void Menu_atendimentoDel(Pedido &pedido);

#endif
