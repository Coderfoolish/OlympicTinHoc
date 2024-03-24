//
// Created by ASUS on 3/24/2024.
//

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int arr[MAXN];
int n;
bool column[MAXN], diagonal1[2 * MAXN - 1], diagonal2[2 * MAXN - 1];

void PrintBoard() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr[i] == j) cout << "Q ";
            else cout << ". ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Solve(int i) {
    for (int j = 1; j <= n; ++j) {
        if (!column[j] && !diagonal1[i - j + n - 1] && !diagonal2[i + j - 1]) {
            arr[i] = j;
            column[j] = diagonal1[i - j + n - 1] = diagonal2[i + j - 1] = true;
            if (i == n)
                PrintBoard();
            else
                Solve(i + 1);
            column[j] = diagonal1[i - j + n - 1] = diagonal2[i + j - 1] = false;
        }
    }
}

int main() {
    cout << "Nhap so quan hau (N): ";
    cin >> n;
    Solve(1);
    return 0;
}