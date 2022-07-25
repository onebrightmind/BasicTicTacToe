/* Name: Owen Campbell
*  Purpose: First Personal Prpject. To start the path of creating in C++
*  Time log: 12/11/21 = 2.5hrs, 172 lines = make and print board
             12/12/21 = 2.5hrs  316 lines = get player info and place symbol on board
             12/14/21 = 3 hrs   365 lines = win conditions
             12/15/21 = 2hrs diagonal win condition 390 lines
             7/23/2022 = 6hrs adding play cpu functionality via minimax program, while maintaining universal character funtionality
*/      

#include <iostream>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <vector>
//#include "common.h"

using  namespace std;

char players[2]={'0','0'}; //holds each players char after updated in main game fucntions
vector<int> boardList(9,0);


//allocates mem for board and initializes it
//main
void makeBoard(char** board){ //Works
     int i,j;

    //initilizes array with spaces
    for(i=0; i<3; i++){
        board[i] = new char[3];
    }

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

//main
//helper function 
void printVector(){
    int i;
    for(i=0; i<9; i++){
        cout<<boardList[i]<<' ';
    }
    cout<<endl;
}

//Print current board after user move
void printBoard(char **board){ //Works
    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j==0 || j==1) cout<< board[i][j] << " | ";
            else cout<< board[i][j];     
        }
        cout<<endl;

        //only prints two horizontal lines
        if(i<=1){
            for(j=0; j<3; j++){
                cout<< "---";
            }
            cout<<endl;
        }
    }
}

//prints placement of nubmers on board

void printPlacement(){
    int i,j,k=0;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j==0 || j==1) cout<< k << " | ";
            else cout<< k; 

            k++;    
        }
        cout<<endl;

        //only prints two horizontal lines
        if(i<=1){
            for(j=0; j<3; j++){
                cout<< "---";
            }
            cout<<endl;
        }
    }
}

//Called two times to get symbols
//second time, pass in player one's symbol to make sure player 2 doesn't equal 1
char getPlayerSymbol(int player, char player1Symbol ='O'){ //WORKS
    //make var and save user input
    char symbol;
    cin>> symbol;
    while(1){
            //if on second user, make sure it odesnt equal the first
        if((player == 2) && (symbol == player1Symbol)){
            cout<<endl;
            cout<<"Choose a different symbol than player 1!"<<endl <<"Player 2: ";
        }
        else break;

        cin>> symbol;
    }
    return symbol;
}

//if vector at pos is 0, the spot is open, if 1, its already taken
bool checkPos(int userPosition){ //works!
    bool checker = true;
    if(boardList.at(userPosition) == 1) checker = false;
    return checker;
}

  //switch by pos
    //go to pos in board
    //check if board at pos == pos
    //hard code pos == board[][]
    //if pos==pos, board[][] = symbol
    //else cout<<"spot already taken, try again"
bool placeSymbol(char symbol, char pos, char** board){ //works!
  
    //char boardSpot;
    bool check = false;
    int pos1=0;
    switch(pos){
        case '0':
            pos1=0;
            if((check = checkPos(pos1))){
                board[0][0] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '1':
            pos1 = 1;
            if((check = checkPos(pos1))){
                board[0][1] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '2':
            pos1 = 2;
            if((check = checkPos(pos1))){
                board[0][2] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '3':
            pos1 = 3;
            if((check = checkPos(pos1))){
                board[1][0] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '4':
            pos1 = 4;
            if((check = checkPos(pos1))){
                board[1][1] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '5':
            pos1 = 5;
            if((check = checkPos(pos1))){
                board[1][2] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '6':
            pos1 = 6;
            if((check = checkPos(pos1))){
                board[2][0] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '7':
            pos1 = 7;
            if((check = checkPos(pos1))){
                board[2][1] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        case '8':
            pos1 = 8;
            if((check = checkPos(pos1))){
                board[2][2] = symbol;
                boardList.at(pos1) = 1;
            }
            else cout<<"This spot: "<< pos1<<" is taken."<<endl;
            break;

        default:
            cout<<"Error! Pick a valid board placement (0-8)"<<endl;
    }
    //board is initialized w/ 0-8, if a space isnt 0-8, it's used
   return check;
}

//Places cpu symbol on board, used for that and temporarally using Minimax
void cpuPlaceSymbol(char symbol, int pos, char**board){

    switch(pos){
        case 0:
            board[0][0] = symbol;
            boardList.at(pos) = 1;
            break;

        case 1:
            board[0][1] = symbol;
            boardList.at(pos) = 1;
            break;

        case 2:
         
            board[0][2] = symbol;
            boardList.at(pos) = 1;
            break;

        case 3:
          
            board[1][0] = symbol;
            boardList.at(pos) = 1;
            break;

        case 4:

            board[1][1] = symbol;
            boardList.at(pos) = 1;
            break;

        case 5:
        
            board[1][2] = symbol;
            boardList.at(pos) = 1;
            break;

        case 6:
          
            board[2][0] = symbol;
            boardList.at(pos) = 1;
            break;

        case 7:

            board[2][1] = symbol;
            boardList.at(pos) = 1;
            break;

        case 8:

            board[2][2] = symbol;
            boardList.at(pos) = 1;
            break;
    }
}

//Resets board and boardList at position, for cpu to use Minimax 
void removeSymbol(int pos, char**board){

    switch(pos){
        case 0:
            board[0][0] = ' ';
            boardList.at(pos) = 0;
            break;

        case 1:
            board[0][1] = ' ';
            boardList.at(pos) = 0;
            break;

        case 2:
         
            board[0][2] = ' ';
            boardList.at(pos) = 0;
            break;

        case 3:
          
            board[1][0] = ' ';
            boardList.at(pos) = 0;
            break;

        case 4:

            board[1][1] = ' ';
            boardList.at(pos) = 0;
            break;

        case 5:
        
            board[1][2] = ' ';
            boardList.at(pos) = 0;
            break;

        case 6:
          
            board[2][0] = ' ';
            boardList.at(pos) = 0;
            break;

        case 7:

            board[2][1] = ' ';
            boardList.at(pos) = 0;
            break;

        case 8:

            board[2][2] = ' ';
            boardList.at(pos) = 0;
            break;
    }
}

//Loops through entire board, checks if win var = 3 for each row
bool horizonalWin(char symbol, char** board){ //WORKS
    int i,j, win=0;
    bool winCond = false;
    //i=rows
    //j=cols
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == symbol){
                win++;
            }
            else win=0;//not needed?
        }
        if(win == 3) winCond=true;
        win=0;
    }
    return winCond;
}

//Loops through entire board, keeps count var for each col, 
//if any of them = 3, return true
bool verticalWin(char symbol,char** board){
    int i,j;
    int win1=0,win2=0,win3=0;
    bool winCond = false;
    //i=rows
    //j=cols
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){

            //col 0
            if(j==0){
                if(board[i][j] == symbol) win1++;
            } 

            //col 1
            if(j==1){
                if(board[i][j] == symbol) win2++;
            } 

            //col 2
            if(j==2){
                if(board[i][j] == symbol) win3++;
            } 
        }
    }

    if(win1 == 3 || win2 == 3 || win3 == 3) winCond=true;

    return winCond;
}

/*Since I started my board at 0 instead of 1, I believe I through off potential 
  to us a better means of checking via modulo, so I hard coded it instead
*/
bool diagonalWin(char symbol,char** board){
    int win =0;
    bool winCond = false;
    if((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol)) win = 3;
    if((board[0][2] == symbol) && (board[1][1] == symbol) && (board[2][0] == symbol)) win = 3;
    if(win==3) winCond = true;

    return winCond;
}

//does player with char m have 3 m's in a row?
bool checkWinCondition(char symbol, char** board){
    bool winCond = false;
    if(horizonalWin(symbol,board) == true) winCond = true; 
    if(verticalWin(symbol,board) == true) winCond = true;
    if(diagonalWin(symbol,board) == true) winCond = true;

    return winCond;
}

//return 1 for player 1, 2 for player 2 or CP, 3 for tie, 4, for no win yet
//tested and works properly now
int allWinConditions(char** board){
    bool win1,win2;
    int openSpots=0;

    win1 = checkWinCondition(players[0],board);
    win2 = checkWinCondition(players[1],board);

    int i,j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] ==' ') openSpots++;
        }
    }

    if(win1){
        return 1;
    }
    else if(win2){
        return 2;
    }
    else if(openSpots == 0){
        return 3;
    }
    return 4; //if no winner yet
}

int miniMaxCond(int winCond){
    int minMaxVal = 0;
    switch(winCond){
        case 1:
            minMaxVal = -1;
            //player1 won, maximizing so +1
            break;

        case 2:
            minMaxVal = 1;
            //player2 or cpu won, minimizing so -1
            break;

        case 3:
            minMaxVal = 0;
            //it was a tie
            break;
        }

    return minMaxVal;
}

int minimax(char** board, int depth, bool isMaximizing){
    //Terminating Case: There are no more moves to make due to a win or a tie
    int result = allWinConditions(board);
    if(result != 4){
        int scoreTemp = miniMaxCond(result);
        return scoreTemp;
    }
    
    if(isMaximizing){
        
        int i,score=0;
        int cpuSpot = 0;
        int bestScore=-10000000;
        //int bestSpot = 0;

        for(i=0; i<9; i++){
            //if open spot
            if(checkPos(i)){
                cpuSpot = i;
                cpuPlaceSymbol(players[1],cpuSpot,board);
                score = minimax(board,depth+1,false);
                removeSymbol(cpuSpot,board);

                if (score > bestScore){
                    bestScore = score;
                   //bestSpot = cpuSpot;
                }
            }
        }
        return bestScore;
    }
    else{
        int i,score;
        int spot = 0;
        int bestScore=10000000;
       // int bestSpot = 0;

        for(i=0; i<9; i++){
            //if open spot
            if(checkPos(i)){
                spot = i;
                cpuPlaceSymbol(players[0],spot,board);
                score = minimax(board,depth+1,true);
                removeSymbol(spot,board);

                if (score < bestScore){
                    bestScore = score;
                    //bestSpot = spot;
                }
            }
        }
        return bestScore;
    }
}

//main
//make a play vs pc option and a play vs another option
void printMenu(){  //Works
    cout<<"   MENU"<< endl;
    cout<<"----------"<<endl;
    cout<<"1. Play A Multi Player Match"<<endl;
    cout<<"2. Play vs CP"<<endl;
    cout<<"3. Quit"<<endl;
    cout<<"Enter 1 - 3: ";
}

 int findCpuSpot(char cpuSymbol, char**board){
    int i,score;
    bool spot = false;
    int cpuSpot = 0;
    int bestScore= -100000000;
    int bestSpot = 0;

    for(i=0; i<9; i++){
        spot = checkPos(i);
        if(spot){
            cpuSpot = i;
            cpuPlaceSymbol(cpuSymbol,cpuSpot,board);
            score = minimax(board,0,false);
            removeSymbol(cpuSpot,board);

            if (score > bestScore){
                bestScore = score;
                bestSpot = cpuSpot;
            }
        }
    }
    return bestSpot;
}

//code for playing CP Tic Tac Toe (make sep program and include )
void playVsCp(char** board){

      //Get Symbols
    char player1, cpuPlayer;
    
    cout<<"Player 1, enter your symbol: ";
    player1 = getPlayerSymbol(1);
    
    if(player1 == 'O' || player1 =='o' || player1 == '0' || player1 == 'Q') cpuPlayer = 'X';
    else cpuPlayer = 'O';
    
    //update global string for minimax function to chekc win condition
    players[0] = player1;
    players[1] = cpuPlayer;

    cout<<"1 = "<<players[0]<<endl<<"CPU = "<<players[1]<<endl;
    cout<<endl;

    printBoard(board);

      //Get position and place on board
    char userChoice, cpuChoice;
    int tie=0;
    bool boardSpot=false, win1= false,win2=false;
    
    while(1){
        //Break on tie
        if(tie==9) break;

        //Player #1 choose spot, reloop on bad spot
        while (boardSpot!=true){
            cout<<endl<<"Player #1, Choose a spot: "; 
            cin>> userChoice; 
            boardSpot = placeSymbol(player1,userChoice,board);
            if(boardSpot == false) continue;
            cout<<endl;
            printBoard(board);
        }

        if((win1=checkWinCondition(player1,board))) break;
        tie++;

        if(tie==9) break;

        boardSpot = false;
        //Player #2 choose spot, reloop on bad spot

        cout<<endl<<"CPU is choosing a spot: "; 
        // cin>> userChoice; minmax HERE
        cpuChoice = findCpuSpot(cpuPlayer,board);
        cpuPlaceSymbol(cpuPlayer,cpuChoice,board);
        //if(boardSpot == false) continue;
        cout<<endl;
        printBoard(board);


        if((win2=checkWinCondition(cpuPlayer,board))) break;
        //boardSpot=false;
        tie++;
    }
    if(win1) cout<<"Congrats Player #1, You Won!!"<<endl;
    else if(win2) cout<<"Congrats CPU, You Won!!"<<endl;
    else if(tie==9) cout<<"This match was a Tie!"<<endl;

}

//main
//code for user vs User Tic Tac Toe (make sep program? include in this file)
void userVsUser(char** board){

    //Get Symbols
    char player1, player2;
    
    cout<<"Player 1, enter your symbol: ";
    player1 = getPlayerSymbol(1);

    cout<<endl<<"Player 2, enter your symbol: ";
    player2 = getPlayerSymbol(2,player1);

    cout<<"1 = "<<player1<<endl<<"2 = "<<player2<<endl;
    cout<<endl;

    players[0] = player1;
    players[1] = player2;

    printBoard(board);

    //Get position and place on board
    char userChoice;
    int tie=0;
    bool boardSpot=false, win1= false,win2=false;
    
    while(1){
        //Break on tie
        if(tie==9) break;

        //Player #1 choose spot, reloop on bad spot
        while (boardSpot!=true){
            cout<<endl<<"Player #1, Choose a spot: "; 
            cin>> userChoice; 
            boardSpot = placeSymbol(player1,userChoice,board);
            if(boardSpot == false) continue;
            cout<<endl;
            printBoard(board);
        }

        cout<<"Current win conditions = "<<allWinConditions(board)<<endl;
        if((win1=checkWinCondition(player1,board))) break;
        
        tie++;
        if(tie==9) break;

        boardSpot = false;
        //Player #2 choose spot, reloop on bad spot
        while (boardSpot!=true){

            cout<<endl<<"Player #2, Choose a spot: "; 
            cin>> userChoice; 
            boardSpot = placeSymbol(player2,userChoice,board);
            if(boardSpot == false) continue;
            cout<<endl;
            printBoard(board);
        }

        cout<<"Current win conditions = "<<allWinConditions(board)<<endl;
        if((win2=checkWinCondition(player2,board))) break;
        boardSpot=false;
        tie++;

        
    }

    if(win1) cout<<"Congrats Player #1, You Won!!"<<endl;
    else if(win2) cout<<"Congrats Player #2, You Won!!"<<endl;
    else if(tie==9) cout<<"This match was a Tie!"<<endl;

}

//Works! //main
void clearBoard(char** board){
    int i,j;

     //clear placement boardList
    for(i=0; i<9; i++){
        boardList.at(i) = 0;
    }

    //reset board to numerical place holders
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            board[i][j] = ' ';
        
        }
    }
}

//does this free properly?? //main
void freeBoard(char** board ){
     int i;
    //initilizes array with spaces
    for(i=0; i<3; i++){
        delete[] board[i];
    }
    delete[] board;
    //cout<<"free!";
}
