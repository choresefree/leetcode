from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def build_list_by_nums(nums: List[int]):
    head0 = ListNode(-1)
    p = head0
    for num in nums:
        p.next = ListNode(num)
        p = p.next
    return head0.next


def iter_link_list(head: ListNode):
    p = head
    ans = []
    while p:
        ans.append(p.val)
        p = p.next
    return ans


if __name__ == "__main__":
    pass
