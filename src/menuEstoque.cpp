#include "ifmain.h"

void Menu_estoque(Estoque &estoque){
    bool loop = true;
    while(loop){
        cout << "\n------MENU DO GERENCIAMENTO DE ESTOQUE------" << endl;
        cout << " 1 - Ver estoque" << endl;
        cout << " 2 - Procurar produto" << endl;
        cout << " 3 - Adicionar produto" << endl;
        cout << " 4 - Remover produto" << endl;
        cout << " 5 - Voltar" << endl;
        cout << "--------------------------------------------" << endl;
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
                Menu_estoqueSearch(estoque);
                break;
            case 3: //Insert
                Menu_estoqueAdd(estoque);
                break;
            case 4: //Remove
                Menu_estoqueDel(estoque);
                break;
            case 5:
                loop = false;
                break;
            default:
                break;
        }
    }
}

void Menu_estoqueSearch(Estoque &estoque){
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

void Menu_estoqueAdd(Estoque &estoque){
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

void Menu_estoqueDel(Estoque &estoque){
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
