import math

def jump_search(arr, x):
    n = len(arr)
    step = int(math.sqrt(n))
    prev = 0

    # Jump ahead in blocks to find the block where x might be present
    while prev < n and arr[min(step, n) - 1] < x:
        prev = step
        step += int(math.sqrt(n))
        if prev >= n:
            return -1

    # Linear search within the block
    for i in range(prev, min(step, n)):
        if arr[i] == x:
            return i
    return -1

# Example usage
# arr = [11, 15, 23, 45, 70]
# x = 45
# print("Jump Search:", jump_search(arr, x))  # Output: 3
