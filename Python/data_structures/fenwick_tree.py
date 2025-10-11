"""Fenwick Tree (Binary Indexed Tree) implementation.

Supports point updates and prefix / range sum queries in O(log n) time.

Usage example:
>>> arr = [1, 2, 3, 4, 5]
>>> ft = FenwickTree(arr)
>>> ft.prefix_sum(3)  # sum of first 3 elements (0-based index)
6
>>> ft.range_sum(1, 3)
9
"""
from typing import List


class FenwickTree:
    """Fenwick (Binary Indexed) Tree for integer sums.

    Internals use 1-based indexing for the tree array while external
    API uses 0-based indexing for convenience.
    """

    def __init__(self, data: List[int]):
        if data is None:
            raise ValueError("data must be a list, got None")
        self.n = len(data)
        # internal tree uses 1-based indexing
        self.tree = [0] * (self.n + 1)
        for idx, val in enumerate(data):
            self.add(idx, val)

    def _lsb(self, i: int) -> int:
        return i & -i

    def add(self, index: int, delta: int) -> None:
        """Add `delta` to element at `index` (0-based)."""
        if not (0 <= index < self.n):
            raise IndexError("index out of range")
        i = index + 1
        while i <= self.n:
            self.tree[i] += delta
            i += self._lsb(i)

    def prefix_sum(self, index: int) -> int:
        """Return sum of elements [0..index] inclusive (0-based)."""
        if index < 0:
            return 0
        if index >= self.n:
            index = self.n - 1
        i = index + 1
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= self._lsb(i)
        return s

    def range_sum(self, left: int, right: int) -> int:
        """Return sum of elements in [left..right] inclusive (0-based)."""
        if left > right:
            return 0
        if left < 0:
            left = 0
        if right < 0:
            return 0
        if left >= self.n:
            return 0
        if right >= self.n:
            right = self.n - 1
        return self.prefix_sum(right) - self.prefix_sum(left - 1)

    def update(self, index: int, value: int) -> None:
        """Set element at `index` to `value` (0-based)."""
        current = self.range_sum(index, index)
        delta = value - current
        self.add(index, delta)


if __name__ == "__main__":
    # simple smoke test
    arr = [1, 2, 3, 4, 5]
    ft = FenwickTree(arr)
    print(ft.range_sum(0, 4))
    ft.add(2, 5)
    print(ft.range_sum(0, 4))
