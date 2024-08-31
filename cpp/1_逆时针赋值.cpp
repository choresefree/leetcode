/*
沿着顺指针进行赋值
滴滴贪吃蛇
*/
#include <iostream>
#include <vector>

using namespace std;

void print_matrix(const vector<vector<int>> &matrix) {
    for (const vector<int> &row: matrix) {
        for (int num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << "-----" << endl;
}

vector<vector<int>> get_circle_matrix(int n) {
    // 初始化数组
    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        vector<int> row(n);
        matrix[i] = row;
    }
    // 初始化位置
    int x = 0, y = -1;
    vector<vector<int>> directions = {
            {0,  1},
            {1,  0},
            {0,  -1},
            {-1, 0}
    };
    int count = 0;
    while (count < n * n) {
        for (const vector<int> &dir: directions) {
            bool flag = true;
            while (flag) { // 沿一个方向移动
                int x2 = x + dir[0], y2 = y + dir[1];
                if (x2 >= 0 && x2 < n && y2 >= 0 && y2 < n && matrix[x2][y2] == 0) {
                    x = x2, y = y2;
                    count++;
                    matrix[x][y] = count;
                    if (count == n * n) {
                        return matrix;
                    }
                } else{
                    flag = false;
                }
            }
        }
    }
    return matrix;
}

int main() {
    print_matrix(get_circle_matrix(5));
    print_matrix(get_circle_matrix(10));
}