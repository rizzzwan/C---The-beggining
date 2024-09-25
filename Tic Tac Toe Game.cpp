#include<iostream>
using namespace std;

void printBoard(char board[3][3]) {
    cout << "\n\n    Tic Tac Toe Game \n";
    cout << "\n	Player 1[X] \n	Player 2[O]" << endl;
    cout << "\t	     |     |\n";
    cout << "\t	  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "\t	     |     |\n";
    cout << "\t	_________________\n";
    cout << "\t	     |     |\n";
    cout << "\t	  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "\t	     |     |\n";
    cout << "\t	_________________\n";
    cout << "\t	     |     |\n";
    cout << "\t	  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "\t	     |     |\n";
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int choice;
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        cout << "\tPlayer " << (currentPlayer == 'X' ? "1 [X]" : "2 [O]") << " turn: ";
        cin >> choice;

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;
        } else {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "\nPlayer " << (currentPlayer == 'X' ? "1 [X]" : "2 [O]") << " wins!\n";
            break;
        }

        if (checkDraw(board)) {
            printBoard(board);
            cout << "\nThe game is a draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
