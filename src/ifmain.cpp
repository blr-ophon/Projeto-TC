#include "ifmain.h"

bool running = true;

int main(int argc, char *argv[]){
    Lanchonete lanchonete;

    mainMenu(lanchonete);
    
    return 0;
}


void mainMenu(Lanchonete &lanchonete){
    while(running){
        cout << "-------------MENU DA LANCHONETE-------------" << endl;
        cout << "            ||________________||            " << endl;
        cout << "           |    ____________    |           " << endl;
        cout << "          |     |LANCHONETE|     |          " << endl;
        cout << "         |                        |         " << endl;
        cout << "         |________________________|         " << endl;
        cout << "         |    __            __    |         " << endl;
        cout << "         |   |..|          |..|   |         " << endl;
        cout << "         |___|__|__________|__|___|         " << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 1 - Atender Cliente" << endl;
        cout << " 2 - Gerenciar Estoque" << endl;
        cout << " 3 - Sair" << endl;
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
                Menu_atendimento(lanchonete);
                break;
            case 2:
                Menu_estoque(lanchonete.estoque);
                break;
            case 3:
                running = false;
                break;
            default:
                break;
        }
    }
}

