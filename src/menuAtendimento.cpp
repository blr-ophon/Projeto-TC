#include "ifmain.h"

void Menu_atendimento(Lanchonete &lanchonete){

    Pedido pedido;

    bool loop = true;
    while(loop){
        cout << "\n-------MENU DE ATENDIMENTO AO CLIENTE-------" << endl;
        cout << " 1 - Listar produtos em estoque" << endl;
        cout << " 2 - Adicionar produto ao pedido" << endl;
        cout << " 3 - Remover produto do pedido" << endl;
        cout << " 4 - Ver pedido" << endl;
        cout << " 5 - Finalizar pedido" << endl;
        cout << " 6 - Voltar" << endl << endl;
        cout << "--------------------------------------------" << endl;

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
                Menu_atendimentoAdd(lanchonete, pedido);
                break;

            case 3: //Remover do carrinho
                Menu_atendimentoDel(pedido);
                break;

            case 4: //Ver carrinho
                pedido.imprimirPedido();
                break;

            case 5: //Finalizar pedido
                pedido.realizarPedido(&lanchonete.estoque);
                break;

            case 6:
                loop = false;
                break;

            default:
                break;
        }
    }
}

void Menu_atendimentoAdd(Lanchonete &lanchonete, Pedido &pedido){
    cout << "Nome do produto:"<< endl;
    string nomeProduto;
    cin >> nomeProduto;

    cout << "Quantidade (unidade ou kg)"<< endl;
    string amount;
    cin >> amount;

    ProdutoPorUnidade *produtoU = lanchonete.estoque.searchProdutoU(nomeProduto);
    ProdutoPorPeso *produtoP = lanchonete.estoque.searchProdutoP(nomeProduto);

    if(produtoU){
        ProdutoPorUnidade tmp_produtoU = *produtoU;
        tmp_produtoU.setQuantidade(amount);
        pedido.adicionarProdutounidade(tmp_produtoU);

    }else if(produtoP){
        ProdutoPorPeso tmp_produtoP = *produtoP;
        tmp_produtoP.setPeso(amount);
        pedido.adicionarProdutopeso(tmp_produtoP);

    }else{
        cout << "Produto não encontrado."<< endl << endl;
    }
}

void Menu_atendimentoDel(Pedido &pedido){
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

