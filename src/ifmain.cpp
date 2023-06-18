#include "ifmain.h"

bool running = true;

int main(int argc, char *argv[]){
    Estoque estoque; 

    mainMenu(estoque);
    
    return 0;
}

void mainMenu(Estoque &estoque){
    while(running){
        cout << " 1 - Atender Cliente" << endl;
        cout << " 2 - Gerenciar Estoque" << endl;
        cout << " 3 - Sair" << endl;
        cout << endl;

        string option;
        cin >> option;
        cout << endl;
        
        switch(stoi(option)){
            case 1:
                break;
            case 2:
                estManageMenu(estoque);
                break;
            case 3:
                running = false;
                break;
            default:
                break;
        }
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

        string option;
        cin >> option;
        cout << endl;

        switch(stoi(option)){
            case 1:
                estoque.imprimirEstoque();
                break;
            case 2: // Search
                SearchProdutoMenu(estoque);
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

void SearchProdutoMenu(Estoque &estoque){
    string escolhaTipoProduto;
    cout << "Escolha o tipo de produto: " << endl;
    cout << " 1 - Produto por unidade" << endl;
    cout << " 2 - Produto por peso" << endl;
    cin >> escolhaTipoProduto;

    switch(stoi(escolhaTipoProduto)){
        case 1:
            {
            string indiceProdutoString;
            cout << "Digite o índice do produto por unidade: ";
            cin.ignore();
            getline(cin, indiceProdutoString);
            try {
                int indiceProduto = stoi(indiceProdutoString);
                estoque.recuperarDadosDoProduto(1, indiceProduto - 1, true);
            }
            catch (invalid_argument& e) {
                cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
            }
            break;
            }


        case 2:
            {
            string indiceProdutoString;
            cout << "Digite o índice do produto por peso: ";
            cin.ignore();
            getline(cin, indiceProdutoString);

            try {
                int indiceProduto = stoi(indiceProdutoString);
                estoque.recuperarDadosDoProduto(2, indiceProduto - 1, true);
            }
            catch (invalid_argument& e) {
                cout << "\aERROR - ENTRADA INVALIDA - ERROR" << endl;
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

    switch(stoi(escolhaTipoProduto)){
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

    switch(stoi(escolhaTipoProduto)){
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