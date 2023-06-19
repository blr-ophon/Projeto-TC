#include "ifmain.h"

bool running = true;

int main(int argc, char *argv[]){
    Lanchonete lanchonete;

    mainMenu(lanchonete);
    
    return 0;
}

void mainMenu(Lanchonete &lanchonete){
    while(running){
        cout << " 1 - Atender Cliente" << endl;
        cout << " 2 - Gerenciar Estoque" << endl;
        cout << " 3 - Sair" << endl;
        cout << endl;

        string option_str;
        cin >> option_str;
        cout << endl;

        int option;
        try {
            option = stoi(option_str);
        } catch (const std::invalid_argument& e) {
            option = -1;
        }
        
        switch(option){
            case 1:
                pedidoManageMenu(lanchonete);
                break;
            case 2:
                estManageMenu(lanchonete.estoque);
                break;
            case 3:
                running = false;
                break;
            default:
                break;
        }
    }
}

void pedidoManageMenu(Lanchonete &lanchonete){

    Pedido pedido;

    bool loop = true;
    while(loop){
        cout << "-------MENU DO ATENDIMENTO AO CLIENTE-------" << endl;
        cout << " 1 - LISTAR PRODUTOS" << endl;
        cout << " 2 - ADICIONAR AO CARRINHO" << endl;
        cout << " 3 - REMOVER DO CARRINHO" << endl;
        cout << " 4 - VER PEDIDO" << endl;
        cout << " 5 - FINALIZAR PEDIDO" << endl;
        cout << " 6 - VOLTAR" << endl << endl;

        string option_str;
        cin >> option_str;
        cout << endl;

        int option;
        try {
            option = stoi(option_str);
        } catch (const std::invalid_argument& e) {
            option = -1;
        }

        switch(option){
            case 1: //Listar produtos
                lanchonete.estoque.imprimirEstoque();
                break;

            case 2: //Adicionar ao carrinho
                addCartMenu(lanchonete, pedido);
                break;

            case 3: //Remover do carrinho
                delCartMenu(pedido);
                break;

            case 4: //Ver carrinho
                pedido.imprimirPedido();
                break;

            case 5: //Finalizar pedido
                break;

            case 6:
                loop = false;
                break;

            default:
                break;
        }
    }
}

void addCartMenu(Lanchonete &lanchonete, Pedido &pedido){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    int option;
    try {
        option = stoi(escolhaTipoProduto);
    } catch (const std::invalid_argument& e) {
        option = -1;
    }

    switch(option){
        case 1:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;

            ProdutoPorUnidade *produto = lanchonete.estoque.searchProdutoU(nomeProduto);
            if(produto){
                pedido.adicionarProdutounidade(*produto);
            }else{
                cout << "Produto não encontrado."<< endl;
            }
            break;
            }
        case 2:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;

            ProdutoPorPeso *produto = lanchonete.estoque.searchProdutoP(nomeProduto);
            if(produto){
                pedido.adicionarProdutopeso(*produto);
            }else{
                cout << "Produto não encontrado."<< endl;
            }
            break;
            }
        default:
            break;
    }
}

void delCartMenu(Pedido &pedido){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    int option;
    try {
        option = stoi(escolhaTipoProduto);
    } catch (const std::invalid_argument& e) {
        option = -1;
    }

    switch(option){
        case 1:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            pedido.removerProdutounidade(nomeProduto);
            break;
            }
        case 2:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            pedido.removerProdutopeso(nomeProduto);
            break;
            }
        default:
            break;
    }
}

void estManageMenu(Estoque &estoque){
    bool loop = true;
    while(loop){
        cout << "------MENU DO GERENCIAMENTO DE ESTOQUE------" << endl;
        cout << " 1 - IMPRIMIR O ESTOQUE" << endl;
        cout << " 2 - PARA PROCURAR PRODUTOS" << endl;
        cout << " 3 - PARA ADCIONAR PRODUTOS" << endl;
        cout << " 4 - REMOVER PRODUTOS" << endl;
        cout << " 5 - VOLTAR" << endl;
        cout << endl;

        string option_str;
        cin >> option_str;
        cout << endl;

        int option;
        try {
            option = stoi(option_str);
        } catch (const std::invalid_argument& e) {
            option = -1;
        }

        switch(option){
            case 1:
                estoque.imprimirEstoque();
                break;
            case 2: // Search
                searchProdutoMenu(estoque);
                break;
            case 3: //Insert
                insertProdutoMenu(estoque);
                break;
            case 4: //Remove
                removeProdutoMenu(estoque);
                break;
            case 5:
                loop = false;
                break;
            default:
                break;
        }
    }
}

void searchProdutoMenu(Estoque &estoque){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    int option;
    try {
        option = stoi(escolhaTipoProduto);
    } catch (const std::invalid_argument& e) {
        option = -1;
    }

    switch(option){
        case 1:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            ProdutoPorUnidade *produto = estoque.searchProdutoU(nomeProduto);
            if(produto){
                cout << "\nProduto:"<< endl;
                cout << "> Nome: " << produto->getNome() << endl;
                cout << "> Codigo: " << produto->getCodigo() << endl;
                cout << "> Preço: " << produto->getPreco() << endl;
                cout << "> Quantidade: " << produto->getQuantidade() << endl << endl;
            }
            break;
            }
        case 2:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            ProdutoPorPeso *produto = estoque.searchProdutoP(nomeProduto);
            if(produto){
                cout << "\nProduto:"<< endl;
                cout << "> Nome: " << produto->getNome() << endl;
                cout << "> Codigo: " << produto->getCodigo() << endl;
                cout << "> Preço: " << produto->getPreco() << endl;
                cout << "> Peso: " << produto->getPeso() << endl << endl;
            }
            break;
            }
        default:
            break;
    }
}

void insertProdutoMenu(Estoque &estoque){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    int option;
    try {
        option = stoi(escolhaTipoProduto);
    } catch (const std::invalid_argument& e) {
        option = -1;
    }

    switch(option){
        case 1:
            {
            string nomeProduto;
            string codigoProduto;
            string precoProduto;
            string quantidade;

            cout << "Digite o nome do produto por unidade: ";
            cin.ignore();
            getline(cin, nomeProduto);

            cout << "Digite o código do produto: ";
            cin >> codigoProduto;

            cout << "Digite o preço do produto: ";
            cin >> precoProduto;

            cout << "Digite a quantidade do produto: ";
            cin >> quantidade;

            estoque.adicionarProdutoUnidade(ProdutoPorUnidade(quantidade, nomeProduto, codigoProduto, precoProduto));
            cout << "Produto por unidade adicionado com sucesso ao estoque." << endl;
            break;
            }

        case 2:
            {
            string nomeProduto;
            string peso;
            string codigo;
            string preco;

            cout << "Digite o nome do produto por peso: ";
            cin.ignore();
            getline(cin, nomeProduto);

            cout << "Digite o peso do produto: ";
            cin >> peso;

            cout << "Digite o codigo do produto: ";
            cin >> codigo;

            cout << "Digite o preco do produto: ";
            cin >> preco;

            estoque.adicionarProdutoPeso(ProdutoPorPeso(peso, nomeProduto, codigo, preco));
            cout << "Produto por peso adicionado com sucesso ao estoque." << endl;
            break;
            }
        default:
            break;
    }
}

void removeProdutoMenu(Estoque &estoque){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    int option;
    try {
        option = stoi(escolhaTipoProduto);
    } catch (const std::invalid_argument& e) {
        option = -1;
    }

    switch(option){
        case 1:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            estoque.removerProdutoUnidade(nomeProduto);
            cout << "Produto por unidade removido do estoque." << endl;
            break;
            }

        case 2:
            {
            cout << "Nome do produto:"<< endl;
            string nomeProduto;
            cin >> nomeProduto;
            estoque.removerProdutoPeso(nomeProduto);
            cout << "Produto por unidade removido do estoque." << endl;
            break;
            }

        default:
            break;
    }
}
