#include <iostream>

using namespace std;

void block(bool (&board)[8][8], int i, int j) {
    for (int i_it = 0; i_it < 8; i_it++) {
        board[i_it][j] = true;
    }

    for (int j_it = 0; j_it < 8; j_it++) {
        board[i][j_it] = true;
    }
    
    int i1 = i; int j1 = j;
    while (i1 >= 0 && j1 >= 0) {
        board[i1][j1] = true;
        i1--; j1--;
    }

    int i2 = i; int j2 = j;
    while (i2 < 8 && j2 < 8) {
        board[i2][j2] = true;
        i2++; j2++;
    }

    int i3 = i; int j3 = j;
    while (i3 >= 0 && j3 >= 0 && i3 < 8 && j3 < 8) {
        board[i3][j3] = true;
        i3++;
        j3--;
    }

    int i4 = i; int j4 = j;
    while (i4 >= 0 && j4 >= 0 && i4 < 8 && j4 < 8) {
        board[i4][j4] = true;
        i4--;
        j4++;
    }
}

int main() {
    bool board[8][8];
    
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    bool valid = true;
    int queens = 0;

    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            char x;
            cin >> x;
            if (x == '*') {
                if (board[i][j]) {
                    valid = false;
                }
                block(board, i, j);
                queens++;
            }
        }
    }

    // for (size_t i = 0; i < 8; i++) {
    //     for (size_t j = 0; j < 8; j++) {
    //         cout << (board[i][j] ? "X" : ".");
    //     }
    //     cout <<endl;
    // }
    
    
    if (valid && queens == 8) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
}