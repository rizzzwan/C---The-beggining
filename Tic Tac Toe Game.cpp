#include<iostream>
using namespace std;

// Function to print the Tic-Tac-Toe board
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

// Function to check if there's a winner
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Columns
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Main diagonal
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Anti diagonal
        return true;
    }
    return false;
}

// Function to check if the board is full (for a draw)
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
    char currentPlayer = 'X';  // Start with Player 1 (X)

    // Game loop
    while (true) {
        printBoard(board);  // Display the board

        cout << "\tPlayer " << (currentPlayer == 'X' ? "1 [X]" : "2 [O]") << " turn: ";
        cin >> choice;

        // Determine row and column based on the choice
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Check if the chosen cell is valid
        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = currentPlayer;  // Mark the board with the current player's symbol
        } else {
            cout << "Invalid choice! Try again.\n";
            continue;  // Skip to the next iteration of the loop
        }

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "\nPlayer " << (currentPlayer == 'X' ? "1 [X]" : "2 [O]") << " wins!\n";
            break;
        }

        // Check if the game is a draw
        if (checkDraw(board)) {
            printBoard(board);
            cout << "\nThe game is a draw!\n";
            break;
        }

        // Switch player for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
