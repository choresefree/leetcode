/*
c++ 快速选择出第k大元素，同理也可以解决top 问题k
时间复杂度为O(n)
*/
#include <iostream>
#include <vector>

using namespace std;
vector<int> nums = {2, 5, 7, 1, 4, 6, 9, 8, 10, 0, 3};

void swap(int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

void quick_sort(int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= pivot) {
            j -= 1;
        }
        while (i < j && nums[i] <= pivot) {
            i += 1;
        }
        swap(i, j);
    }
    swap(left, i);
    quick_sort(left, i - 1);
    quick_sort(i + 1, right);
}

int main() {
    quick_sort(0, nums.size() - 1);
    for (int num: nums) {
        cout << num << " ";
    }
    // 0 1 2 3 4 5 6 7 8 9 10 
}