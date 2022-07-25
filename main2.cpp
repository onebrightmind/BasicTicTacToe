
#include "ticTacToe2.cpp"
//#include "common.h"

using  namespace std;

int main(){
    //Base declarations
    int userSelection = 0; //play game or quit
    char** gameBoard;  //2d array
    gameBoard = new char*[3];
    makeBoard(gameBoard); //set mem and initialize 0-8
    
    while(1){
        if(userSelection == 3) break;

        printPlacement();
        cout<<endl;
        printMenu();
        cin >> userSelection;
        cout<<endl;

        //plays one game
        if(userSelection==1){
            cout<< endl <<"Let's play!"<<endl<< endl;

            userVsUser(gameBoard); 
            clearBoard(gameBoard);
            cout<<endl;
        }
        else if(userSelection == 2){
            cout<< endl <<"Playing CPU!"<<endl<< endl;

            playVsCp(gameBoard); //FIX ME: Add win conditions
            clearBoard(gameBoard);
            cout<<endl;
        }
        else cout << "Bye bye!";

    }

    freeBoard(gameBoard);

    return 0;
}