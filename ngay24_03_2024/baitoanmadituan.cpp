//
// Created by ASUS on 3/24/2024.
//

//Bài toán này yêu cầu di chuyển của quân mã trên bàn cờ vua
// sao cho quân mã đi qua mỗi ô của bàn cờ một lần duy nhất.
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
int board[MAXN][MAXN];
// Một bước đi hợp lệ của quân mã sẽ như sau: |x| + |y| = 3 ( Với x,y > 0).
int moveX[] = {2, 1, -1, -2, -2, -1, 1, 2};
int moveY[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

//Check co vuot qua gioi han ban co && da di qua nuoc do hay chua:
bool isSafe(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && board[x][y] == -1); //-1 la chua di qua
}

void PrintBoard() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

//ham chinh de duyet qua
bool KnightTour(int x, int y, int moveCount) {
    if (moveCount == n * n) {
        return true;
    }
    for (int i = 0; i < 8; ++i) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];
        if (isSafe(nextX, nextY)) {
            board[nextX][nextY] = moveCount;
            if (KnightTour(nextX, nextY, moveCount + 1)) {
                return true;
            }
            board[nextX][nextY] = -1; // Backtrack
        }
    }

    return false;
}

int main() {
    cout << "Nhap kich thuoc ban co (n x n): ";
    cin >> n;

    // Initialize the board
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = -1; // -1 indicates unvisited cell
        }
    }
    // Start from cell (0, 0)
    int startX = 0, startY = 0;
    board[startX][startY] = 0; // Starting position
    if (KnightTour(startX, startY, 1)) {
        cout << "Ket qua:\n";
        PrintBoard();
    } else {
        cout << "Khong ton tai ket qua nao!\n";
    }
    return 0;
}