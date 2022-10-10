#include <iostream>
#include <cstdlib>
#include "function.h"


using namespace std;

string nome();
char simbolo();

int main(){

    bool *partita = new bool (true); //Variabile partita in corso o meno
    char **campo = new char *[3];
    bool *turno = new bool (true); //player 1 = true, player 2 = false
    for(int i=0; i<3; i++){
        campo[i] = new char [3];

    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3;j++){
            campo[i][j] = '?';
        }
    }

    system("cls");
    cout << "Benvenutx nel TRIS 2.13 di Gamessmile!\n";
    cout << "Clicca [SPAZIO] per selezionare i dati dei player!!\n";
    system("pause");
    system("cls");
    player p1(simbolo(), nome("Player Uno"));
    system("cls");
    player p2(simbolo(), nome("Player Due"));
    system("cls");
    
    while(*partita == true){
        system("cls");
        StampaCampa(campo);
        if(*turno==true){
            insert(campo,p1);
            
            if(wincondition(campo, p1)==false){
                system("cls");
                StampaCampa(campo);
                *partita = wincondition(campo, p1);
                
            }
            *turno=false;
        }
        else{
            insert(campo,p2);
            
            if(wincondition(campo, p2)==false){
                system("cls");
                StampaCampa(campo);
                *partita = wincondition(campo, p2);
                
            }
            *turno = true;
        }

    }
    system("pause");
}