/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
*/
#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

class Solution {
public:

    int get_index(int i, int j, int n) {
        // ***要加j而不是i**
        return i * n + j;
    }

    int find(vector<int> &group, int index) {
        if (group[index] != index) {
            // ***重点***
            group[index] = find(group, group[index]);
        }
        return group[index];
    }

    void merge(vector<int> &group, int index1, int index2) {
        int group1 = find(group, index1), group2 = find(group, index2);
        if (group1 != group2) {
            // ***重点***
            group[group1] = group2; 
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        // ***不一定是正方形**
        int row = grid.size(), col = grid[0].size();
        // 初始化归属数组
        vector<int> group = vector<int>(row * col);
        for (int i = 0; i < row * col; i++) {
            group[i] = i;
        }

        // 并查
        vector<vector<int>> directions = {
                {1,  0},
                {-1, 0},
                {0,  1},
                {0,  -1}
        };
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                int index = get_index(i, j, col);
                for (auto dir: directions) {
                    int i2 = i + dir[0], j2 = j + dir[1];
                    if (i2 >= 0 && i2 < row && j2 >= 0 && j2 < col && grid[i2][j2] == '1') {
                        int index2 = get_index(i2, j2, col);
                        merge(group, index, index2);
                    }
                }
            }
        }
        unordered_set<int> set;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    set.insert(find(group, get_index(i, j, col)));
                }
            }
        }
        return set.size();
    }
};


int main() {
    vector<vector<char>> grid = {
            {'1', '1', '1'},
            {'0', '1', '0'},
            {'1', '1', '1'}
    };
    Solution s = Solution();
    int num = s.numIslands(grid);
    cout << num;
    return 0;

}