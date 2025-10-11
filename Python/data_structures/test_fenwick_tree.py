import pytest

from data_structures.fenwick_tree import FenwickTree


def test_prefix_and_range_sum_basic():
    arr = [1, 2, 3, 4, 5]
    ft = FenwickTree(arr)
    assert ft.prefix_sum(0) == 1
    assert ft.prefix_sum(2) == 6
    assert ft.range_sum(1, 3) == 9


def test_add_and_update():
    arr = [0, 0, 0, 0]
    ft = FenwickTree(arr)
    ft.add(2, 5)
    assert ft.range_sum(0, 3) == 5
    ft.update(2, 2)
    assert ft.range_sum(0, 3) == 2


def test_out_of_bounds_and_edge_cases():
    arr = [1]
    ft = FenwickTree(arr)
    with pytest.raises(IndexError):
        ft.add(5, 1)
    assert ft.range_sum(0, 0) == 1
    assert ft.range_sum(1, 10) == 0
