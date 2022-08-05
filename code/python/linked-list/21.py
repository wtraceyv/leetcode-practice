# Quicker than last time I think, but still too messy
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        top, bottom, dummy = list1, list2, ListNode()
        # setup
        if top and (not bottom or top.val <= bottom.val):
            dummy.next = top
        elif bottom and (not top or bottom.val < top.val):
            dummy.next = bottom
        # merge
        while top and bottom:
            print(top.val, bottom.val)
            if top.val <= bottom.val:
                if top.next and top.next.val <= bottom.val:
                    top = top.next
                else:
                    temp_next_top = top.next
                    top.next = bottom
                    top = temp_next_top
            elif bottom.val < top.val:
                if bottom.next and bottom.next.val < top.val:
                    bottom = bottom.next
                else:
                    temp_next_bottom = bottom.next
                    bottom.next = top
                    bottom = temp_next_bottom

        return dummy.next

# Jesus why did I not do this first
class Solution2:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy
        while list1 and list2:
          if list1.val < list2.val:
            tail.next = list1
            list1 = list1.next
          else:
            tail.next = list2
            list2 = list2.next
          tail = tail.next
        tail.next = list1 if list1 else list2
        
        return dummy.next