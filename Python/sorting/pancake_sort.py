def flip(arr, k):
    """
    Reverses the order of the first k elements of the array.
    This is the "spatula flip" operation.
    """
    left = 0
    while left < k:
        arr[left], arr[k] = arr[k], arr[left]
        left += 1
        k -= 1

def pancake_sort(arr):
    """
    Sorts an array in ascending order using the Pancake Sort algorithm.

    Args:
        arr: A list of comparable elements.
    """
    current_size = len(arr)
    while current_size > 1:
        # Find the index of the maximum element in the unsorted subarray arr[0...current_size-1]
        max_index = arr.index(max(arr[0:current_size]))

        if max_index != current_size - 1:
            # 1. Move the maximum element to the front (if it's not already there)
            if max_index != 0:
                flip(arr, max_index)

            # 2. Flip the array to move the maximum element to its correct sorted position
            flip(arr, current_size - 1)
        
        # Reduce the size of the array to be considered in the next pass
        current_size -= 1
    return arr
