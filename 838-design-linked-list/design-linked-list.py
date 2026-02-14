class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class MyLinkedList:

    def __init__(self):
        self.left = ListNode(0)   # dummy head
        self.right = ListNode(0)  # dummy tail
        self.left.next = self.right
        self.right.prev = self.left

    def get(self, index: int) -> int:
        cur = self.left.next
        while cur != self.right and index > 0:
            cur = cur.next
            index -= 1
        
        if cur != self.right and index == 0:
            return cur.val
        return -1

    def addAtHead(self, val: int) -> None:
        node = ListNode(val)
        prev = self.left
        next = self.left.next
        
        prev.next = node
        node.prev = prev
        node.next = next
        next.prev = node

    def addAtTail(self, val: int) -> None:
        node = ListNode(val)
        prev = self.right.prev
        next = self.right
        
        prev.next = node
        node.prev = prev
        node.next = next
        next.prev = node

    def addAtIndex(self, index: int, val: int) -> None:
        cur = self.left.next
        while cur != self.right and index > 0:
            cur = cur.next
            index -= 1
        
        if index == 0:
            node = ListNode(val)
            prev = cur.prev
            next = cur
            
            prev.next = node
            node.prev = prev
            node.next = next
            next.prev = node

    def deleteAtIndex(self, index: int) -> None:
        cur = self.left.next
        while cur != self.right and index > 0:
            cur = cur.next
            index -= 1
        
        if cur != self.right and index == 0:
            prev = cur.prev
            next = cur.next
            prev.next = next
            next.prev = prev
