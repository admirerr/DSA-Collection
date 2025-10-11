import math

def interpolation_search(arr, target):
    """
    Perform interpolation search to find the target value in the given sorted list.

    Parameters:
        arr (list): The sorted list to be searched.
        target: The value to be searched for.

    Returns:
        int: The index of the target value if found, otherwise -1.
    """
    low = 0
    high = len(arr) - 1
    while low <= high and target >= arr[low] and target <= arr[high]:
        pos = low + ((high - low) // (arr[high] - arr[low])) * (target - arr[low])
        if arr[pos] == target:
            return pos
        elif arr[pos] < target:
            low = pos + 1
        else:
            high = pos - 1
    return -1

# Example usage:
arr = [2, 3, 4, 10, 40]
target = 10
result = interpolation_search(sorted(arr), target)
if result != -1:
    print(f"Interpolation Search: Element found at index {result}")
else:
    print("Interpolation Search: Element not found")
