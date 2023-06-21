#ifndef LANCHONETE_H
#define LANCHONETE_H

#include <string>

#include "Estoque.h"
#include "Pedido.h"

class Lanchonete {
    public:
        Estoque estoque;
        void abrirDBs(void);
};

#endif
