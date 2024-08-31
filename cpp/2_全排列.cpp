/*
沿着顺指针进行赋值
滴滴贪吃蛇
*/
#include <iostream>
#include <vector>

using namespace std;

vector<string> get_all_rank(string s) {
    vector<string> res;
    if (s.size() == 1) {
        res.push_back(s);
        return res;
    }
    for (int i = 0; i < s.size(); i++) {
        // 重点记忆，获得中间值，以及左右两侧的
        string pivot_s = s.substr(i, 1);
        string left_s = s.substr(0, i);
        string right_s = s.substr(i + 1, s.size() - i);
        for (const string& ss: get_all_rank(left_s + right_s)) {
            res.push_back(pivot_s + ss);
        }
    }
    return res;
}

int main() {
    for (const string& s: get_all_rank("abc")) {
        cout << s << endl;
    }
}