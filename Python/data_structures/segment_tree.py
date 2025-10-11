"""Segment Tree (Range Sum Query) implementation

This file adds a clean, well-documented Python Segment Tree implementation for
range sum queries and point updates. It follows the repository contribution
conventions: a single file under `Python/data_structures/` with clear comments
and function docstrings.

Complexity:
- Build: O(n)
- Query: O(log n)
- Update: O(log n)

Example usage:
>>> arr = [1, 3, 5, 7, 9, 11]
>>> st = SegmentTree(arr)
>>> st.range_sum(1, 3)  # sum from index 1 to 3 -> 3+5+7 = 15
15
>>> st.update(1, 10)  # arr[1] = 10
>>> st.range_sum(1, 3)
22
"""

from typing import List


class SegmentTree:
    """A minimal segment tree supporting range sum queries and point updates.

    Attributes:
        n (int): number of elements
        tree (List[int]): internal tree array (size 4*n)
    """

    def __init__(self, data: List[int]):
        if data is None:
            raise ValueError("data must not be None")
        self.n = len(data)
        self.tree = [0] * (4 * self.n if self.n else 1)
        if self.n:
            self._build(1, 0, self.n - 1, data)

    def _build(self, node: int, l: int, r: int, data: List[int]) -> None:
        if l == r:
            self.tree[node] = data[l]
            return
        mid = (l + r) // 2
        self._build(node * 2, l, mid, data)
        self._build(node * 2 + 1, mid + 1, r, data)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def update(self, idx: int, value: int) -> None:
        """Point update: set data[idx] = value."""

        def _update(node: int, l: int, r: int):
            if l == r:
                self.tree[node] = value
                return
            mid = (l + r) // 2
            if idx <= mid:
                _update(node * 2, l, mid)
            else:
                _update(node * 2 + 1, mid + 1, r)
            self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

        if idx < 0 or idx >= self.n:
            raise IndexError("index out of range")
        _update(1, 0, self.n - 1)

    def _query(self, node: int, l: int, r: int, ql: int, qr: int) -> int:
        if ql > r or qr < l:
            return 0
        if ql <= l and r <= qr:
            return self.tree[node]
        mid = (l + r) // 2
        return (self._query(node * 2, l, mid, ql, qr)
                + self._query(node * 2 + 1, mid + 1, r, ql, qr))

    def range_sum(self, left: int, right: int) -> int:
        """Return sum of elements in index range [left, right] (inclusive)."""
        if left < 0 or right >= self.n or left > right:
            raise IndexError("invalid query range")
        return self._query(1, 0, self.n - 1, left, right)


if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(arr)
    print(st.range_sum(1, 3))
    st.update(1, 10)
    print(st.range_sum(1, 3))
