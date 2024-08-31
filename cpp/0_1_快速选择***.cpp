/*
c++ 快速选择出第k大元素，同理也可以解决top k问题
时间复杂度为O(n)
*/
#include <iostream>
#include <vector>

using namespace std;
vector<int> nums = {2, 1231, 5, 7, 24, 1, 4, 123, 6, 9, 8, 10, 0, 3};

void swap(int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int partition(int left, int right) {
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
    return i;
}

/*
 * 需要排序[left, right]，并保证top k个排到了后k位
 */
void quick_select(int left, int right, int k) {
    if (left <= right) {
        int pivot_index = partition(left, right); // 划分为左右两个区间，返回的中枢
        int border = right - k + 1; // 如果保证top k排到后k位，需要的border
        if (pivot_index == border) {
            return;
        } else if (pivot_index > border) {
            quick_select(left, pivot_index - 1, k - (right - pivot_index + 1));
        } else {
            quick_select(pivot_index + 1, right, k);
        }
    }
}

int main() {
    quick_select(0, nums.size() - 1, 3);
    for (int num: nums) {
        cout << num << " ";
    }
    // 1 0 2 6 3 5 4 7 10 9 8 24 123 1231 
}