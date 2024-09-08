from common import ListNode, build_list_by_nums, iter_link_list
from typing import Optional


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 加个伪头结点可以方便很多边界处理
        head0 = ListNode(-1, head)
        p0, p1 = head0, head0.next

        while p1 and p1.next:
            # 0 -> 1 -> 2 -> ...
            # 交换到 0 -> 2 -> 1 -> ...
            p2 = p1.next
            p0.next = p2
            p1.next = p2.next
            p2.next = p1

            p0 = p1
            p1 = p0.next

        return head0.next


if __name__ == "__main__":
    s = Solution()

    for nums in [
        [1, 2, 3, 4],
        [],
        [1, 2, 3, 4, 5, 6],
        [1, 2, 3]
    ]:
        _head = build_list_by_nums(nums)
        iter_link_list(_head)
        iter_link_list(s.swapPairs(_head))
