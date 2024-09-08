from common import ListNode, build_list_by_nums, iter_link_list
from typing import Optional


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast, slow = head, head
        # fast走两步，low走一步，二者如果能相遇，说明有环
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
            # 说明有环，此时再建一个指针从头结点开始和slow同步走，相遇处便是环的入口
            if slow == fast:
                p = head
                while slow != p:
                    p = p.next
                    slow = slow.next
                return p
