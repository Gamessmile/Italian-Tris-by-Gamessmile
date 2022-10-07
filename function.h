#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "class.h"



std::string nome(std::string player){

    std::string name ="";
    std::cout << player <<" inserisca il nome da voler utilizzare durante la partita:\n";
    std::getline(std::cin, name);
    /*while(std::cin.fail()){
        std::cerr << "Errore durante l'input del nome";
        std::clearerr;
        std::getline(std::cin, *name);
    }*/
    system("cls");
    return name;
}

char simbolo(){
    std::string x = "TemplateThatShouldNotBeThereAnymoreAfterTheInput";
    std::cout << "Inserisca il simbolo da voler utilizzare durante la partita:\nScegliere entrambi lo stesso simbolo portera' l'utente a una esperienza peggiore.\n";
    std::getline(std::cin, x);
    while(x.length() > 1 || x == "?"){
        std::cout << "L'input richiesto era un unico carattere, la preghiamo di reinserire il suo simbolo\n";
        if(x=="?"){
            std::cout << "Non puo' inserire questo simbolo => '?'\n";
        }
        std::getline(std::cin, x);
    }
    system("cls");
    return (x)[0];
}

void StampaCampa(char **M){
    for(int i = 0; i<3; i++){
        std::cout << "---------------------\n|";
        for(int j = 0; j<3; j++){
            std::cout << std::setw(3);
            if(M[i][j] == '?'){
                std::cout << " " << std::setw(4) << "| ";
            }
            else{
                std::cout <<M[i][j] << std::setw(4) << "| ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------\n";
}
    
void insert(char** M, player& obj){

    std::cout << "Dove vuole inserire il suo simbolo?\nLo specifichi nel seguente modo:\nes: 1x2 (riga 1 colonna 2)\n";
    std::string input = "";

    int x = 900;
    int y = 900;
    do{
        std::getline(std::cin, input);
        const char *ptr = &(input[0]);
        x = atoi(ptr);
        x = x - 1;
        ptr = &(input[2]);
        y= atoi(ptr);
        y = y - 1;
        if(x < 0 || x >2 || y < 0 || y >2 || (input)[1] != 'x'){
            std::cerr << "Il valore deve essere compreso fra 1 e 3, deve essere formattato in tale modo (es. 1x2 (riga 1 colonna 2))\n";
            std::clearerr;
        }
        else if(M[x][y] != '?'){
            std::cerr<< "il posto da lei selezionato e' gia' occupato, proceda a selezionarne un altro\n";
            std::clearerr;
        }
    }while(x < 0 || x >2 || y < 0 || y >2 || (input)[1] != 'x' || M[x][y] != '?');

    M[x][y] = obj.getSymbol();

}

bool wincondition(char **M, player& obj){

    int contx = 0;
    int conty = 0;
    int contd = 0;

    for(int i=0; i<3; i++){

        for(int j=0; j<2; j++){
            if(M[i][j] == M[i][j+1] && M[i][j] == obj.getSymbol()){contx++;}
            if(M[j][i] == M[j+1][i] && M[j][i] == obj.getSymbol()){conty++;}
            if(contx == 2 || conty == 2 || contd == 3){
                std::cout << obj.getName() << " Ha vinto la partita!";
                return false;
            }
        }
        contx = 0;
        conty = 0;
    }

    if( M[0][0] == M[1][1] && M[1][1] == M[2][2] && M[0][0] == obj.getSymbol()){
        contd = 3;
    }

    if(contx == 2 || conty == 2 || contd == 3){

        std::cout << obj.getName() << " Ha vinto la partita!";
        return false;

    }
    contx = 0;
    for ( int i = 0; i<3; i++){
        for(int j=0; j<3; j++){
            if(M[i][j]=='?'){
                contx++;
            }
        }
    }
    if(contx == 0){
        std::cout << "La partita e' finita in pareggio!";
        return false;
    }
    return true;
}
