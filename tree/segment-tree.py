class SegmentTree:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

    @classmethod
    def from_array(cls, arr):
        if len(arr) == 1:
            return SegmentTree(arr[0])

        mid = len(arr) // 2
        left = cls.from_array(arr[0:mid])
        right = cls.from_array(arr[mid:])

        value = min(left.value, right.value)
        root = SegmentTree(value, left, right)
        return root

    def update(self, pos, value, from_, to_):
        if from_ == pos:
            self.value = value
            return

        mid = (from_ + to_) // 2
        if pos < mid:
            self.left.update(pos, value, from_, mid)
        else:
            self.right.update(pos, value, mid, to_)

        self.value = min(self.left.value, self.right.value)

    def query(self, left, right, from_, to_):
        mid = (from_ + to_) // 2
        if left <= mid < right:
            return self.value

        if mid < left:
            return self.right.query(left, right, mid, to_)

        return self.left.query(left, right, from_, mid)


if __name__ == '__main__':
    arr = [2,5,4,3,1,7,9]
    T = SegmentTree.from_array(arr)

    print(T.query(0,3,0,7))

    T.update(2, 1, 0, 7)
    print(T.query(0, 3, 0, 7))
