def fibonacci_search(arr, x):
    n = len(arr)
    f2 = 0
    f1 = 1
    f = f1 + f2

    while f < n:
        f2 = f1
        f1 = f
        f = f1 + f2

    offset = -1

    while f > 1:
        i = min(offset + f2, n - 1)

        if arr[i] < x:
            f = f1
            f1 = f2
            f2 = f - f1
            offset = i
        elif arr[i] > x:
            f = f2
            f1 = f1 - f2
            f2 = f - f1
        else:
            return i

    if f1 and offset + 1 < n and arr[offset + 1] == x:
        return offset + 1

    return -1

arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
target = 85
result = fibonacci_search(arr, target)
print(f"Target {target} found at index: {result}")
