import pytest
from segment_tree import SegmentTree


def test_segment_tree_basic():
    arr = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(arr)
    assert st.range_sum(1, 3) == 15
    st.update(1, 10)
    assert st.range_sum(1, 3) == 22


def test_range_errors():
    st = SegmentTree([1, 2, 3])
    with pytest.raises(IndexError):
        st.range_sum(-1, 2)
    with pytest.raises(IndexError):
        st.range_sum(0, 3)
    with pytest.raises(IndexError):
        st.range_sum(2, 1)


def test_update_errors():
    st = SegmentTree([1, 2, 3])
    with pytest.raises(IndexError):
        st.update(-1, 5)
    with pytest.raises(IndexError):
        st.update(3, 5)


def test_empty_array():
    st = SegmentTree([])
    with pytest.raises(IndexError):
        st.range_sum(0, 0)
    with pytest.raises(IndexError):
        st.update(0, 1)
