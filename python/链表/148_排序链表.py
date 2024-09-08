from common import ListNode, build_list_by_nums, iter_link_list
from typing import Optional


class Solution:

    def sortList_by_insert_sort(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """ 采用插入排序更优雅，swap改为交换结点，会超时 """
        p = head
        while p:
            p0 = p
            min_p = p0
            while p0:
                if p0.val < min_p.val:
                    min_p = p0
                p0 = p0.next

            tmp_v = min_p.val
            min_p.val = p.val
            p.val = tmp_v
            p = p.next

        return head

    def merge(self, p1: ListNode, p2: ListNode):
        head0 = ListNode(-1)
        p = head0
        while p1 and p2:
            if p1.val < p2.val:
                p.next = p1
                p1 = p1.next
            else:
                p.next = p2
                p2 = p2.next
            p = p.next
        if p1:
            p.next = p1
        if p2:
            p.next = p2
        return head0.next

    def find_mid(self, head: ListNode):
        slow_pre = ListNode(-1, head)
        fast, slow = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            slow_pre = slow_pre.next
        return slow_pre, slow

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        """ 采用归并排序 """
        if not head or not head.next:
            return head
        # 打断成左右两部分
        right_pre, right = self.find_mid(head)
        right_pre.next = None
        left = head
        # print("left:", iter_link_list(left))
        # print("right:", iter_link_list(right))
        return self.merge(self.sortList(left), self.sortList(right))


if __name__ == "__main__":
    s = Solution()

    for nums in [
        [4, 2, 1, 3],
        [-1, 5, 3, 4, 0],
        [4, 2, 6, 8, 7],
        [1, 2, 3],
        [8, 1, 4, 2, 3, 6, 5, 7, 9, 0]
    ]:
        _head = build_list_by_nums(nums)
        print(iter_link_list(s.sortList(_head)))
        print("-" * 50)
