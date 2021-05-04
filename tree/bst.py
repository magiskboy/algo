class BST:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    @classmethod
    def from_arr(cls, arr):
        root = BST(arr.pop(0))
        for x in arr:
            root.insert(x)
        return root

    def insert(self, value):
        if self.value == value:
            return

        if value < self.value:
            if self.left:
                self.left.insert(value)
            else:
                self.left = BST(value)

        else:
            if self.right:
                self.right.insert(value)
            else:
                self.right = BST(value)

    def get(self, value):
        if value == self.value:
            return  True

        if value < self.value:
            if self.left:
                return self.left.get(value)
            return False
        else:
            if self.right:
                return self.right.get(value)
            return False

    def remove(self, value):
        curr = self
        parent = None
        while curr:
            if value == curr.value: break

            parent = curr
            if value < curr.value: curr = curr.left
            else: curr = curr.right

        if not curr: return

        # Case 1: deleted node has left node and right node
        if curr.left and curr.right:
            p = curr
            q = curr.left
            while 1:
                if q.right:
                    p = q
                    q = q.right
                else:
                    break

            # swap value between rightmost of left node and deleted node
            curr.value = q.value

            if p is curr:
                p.left = None
            else:
                p.right = None
            return

        # Case 2: Deleted node has left node or right node or is leaf node
        new_node = curr.left or curr.right
        if parent.left is curr: parent.left = new_node
        else: parent.right = new_node

    def __iter__(self):
        yield self.value
        if self.left:
            yield from self.left
        if self.right:
            yield from self.right

if __name__ == '__main__':
    arr = [2,3,5,4,1,9]
    bst = BST.from_arr(arr)
    print(list(bst))
    print(bst.get(10), bst.get(5))
    bst.remove(2)
    print(list(bst))