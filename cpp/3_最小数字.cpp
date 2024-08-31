/*
最小数值：将一个int数组里的值拼成一个最小的int数值
思路是冒泡排序，重写 大小判断 方法
*/
#include <iostream>
#include <vector>

using namespace std;

bool need_swap(int i, int j) {
    string s1 = to_string(i) + to_string(j);
    string s2 = to_string(j) + to_string(i);
    if (s2 < s1) {
        return true;
    }
    return false;
}


int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    unsigned long n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            if (need_swap(nums[j], nums[j + 1])) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
    for (int num: nums) {
        cout << num << " ";
    }
}