# Fenwick Tree (Binary Indexed Tree)

This folder contains an implementation of the Fenwick Tree (Binary Indexed Tree)
for range sum queries and point updates. The implementation is in
`fenwick_tree.py` and includes a small example and public API:

- FenwickTree(data: List[int])
- add(index: int, delta: int)
- prefix_sum(index: int) -> int
- range_sum(left: int, right: int) -> int
- update(index: int, value: int)

See `test_fenwick_tree.py` for usage examples used by the test suite.
# Segment Tree (Python)

This folder contains a Segment Tree implementation used for range queries (sum) and point updates.

Files:
- `segment_tree.py` — SegmentTree implementation (range sum, point update)

Usage:
```python
from segment_tree import SegmentTree

arr = [1, 3, 5, 7, 9, 11]
st = SegmentTree(arr)
print(st.range_sum(1, 3))
st.update(1, 10)
print(st.range_sum(1, 3))
```
