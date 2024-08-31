/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
#include <iostream>
#include <vector>

using namespace std;
/*
 * 在 C++ 中，传递 vector 这样的容器时，默认是按值传递，这意味着会进行复制。复制的开销取决于容器的大小和内容。
 * error_change 函数的 grid 参数是通过值传递的，因此会创建 grid 的副本，任何对 grid 副本的修改不会影响原始的 grid。
 */
void error_change(vector<vector<char>> grid) {
    grid[1][2] = '9';
}

void correct_change(vector<vector<char>> &grid) {
    grid[1][2] = '9';
}

int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1'},
            {'0', '1', '0'},
            {'1', '1', '1'}
    };
    error_change(grid);
    for (auto cs: grid) {
        for (auto c: cs) {
            cout << c << ' ';
        }
        cout << endl;
    }
    /*
     * 1 1 1
     * 0 1 0
     * 1 1 1 
     */
    correct_change(grid);
    for (auto cs: grid) {
        for (auto c: cs) {
            cout << c << ' ';
        }
        cout << endl;
    }
    /*
     * 1 1 1
     * 0 1 9
     * 1 1 1 
     */
    return 0;
}