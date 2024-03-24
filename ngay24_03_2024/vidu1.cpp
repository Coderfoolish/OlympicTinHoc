//
// Created by ASUS on 3/24/2024.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100;
int arr[MAXN];
int b[MAXN];
int n;

void PrintArr() {
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 1; j <= n; ++j) {
        if (b[j] == 0) {
            b[j] = 1;
            arr[i] = j;
            if (i == n) // Kiểm tra nếu đã điền đầy mảng arr
                PrintArr(); // In ra mảng arr
            else
                Try(i + 1); // Gọi đệ quy để điền tiếp phần tử tiếp theo
            b[j] = 0; // Trả lại trạng thái ban đầu để thử các giá trị khác
        }
    }
}

int main() {
    cout << "Enter n: ";
    cin >> n;
    Try(1); // Bắt đầu từ vị trí 1 của mảng arr
    return 0;
}