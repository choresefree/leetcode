import random
from typing import List


def merge(nums1: List[int], nums2: List[int]):
    """ 合并两个有序的数组 """
    n1, n2 = len(nums1), len(nums2)
    merged_nums = [0] * (n1 + n2)
    i, i1, i2 = 0, 0, 0
    while i1 < n1 and i2 < n2:
        if nums1[i1] < nums2[i2]:
            merged_nums[i] = nums1[i1]
            i1 += 1
        else:
            merged_nums[i] = nums2[i2]
            i2 += 1
        i += 1
    for ii in range(i1, n1):
        merged_nums[i] = nums1[ii]
        i += 1
    for ii in range(i2, n2):
        merged_nums[i] = nums2[ii]
        i += 1
    return merged_nums


def sort(nums: List[int]):
    """ 顺便温习下归并排序 """
    n = len(nums)
    if n == 1:
        return nums
    left, right = nums[:n // 2], nums[n // 2:]
    return merge(sort(left), sort(right))


if __name__ == "__main__":
    _nums = [random.randint(0, 100) for _ in range(20)]
    print(_nums)
    print("target:", sorted(_nums))
    print(sort(_nums))
