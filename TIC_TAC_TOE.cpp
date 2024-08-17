#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 3;  
char board[SIZE][SIZE] = { ' ' };  
char currentPlayer = 'X';  

void printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << ' ';
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool checkWin() {
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

bool BoardFull() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void playerMoves() {
    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "Invalid move Please Try again.\n";
        }
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";

    while (true) {
        printBoard();
        playerMoves();

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (BoardFull()) {
            printBoard();
            cout << "The game is a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}