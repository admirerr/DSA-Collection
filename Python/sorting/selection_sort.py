from collections import Counter

def selection_sort(arr, freq):
    n = len(arr)
    for i in range(n):
        max_idx = i
        for j in range(i+1, n):
            if (freq[arr[j]], -arr[j]) > (freq[arr[max_idx]], -arr[max_idx]):
                max_idx = j
        arr[i], arr[max_idx] = arr[max_idx], arr[i]

if __name__ == "__main__":
    arr = [4,6,2,4,3,2,2,6]
    freq = Counter(arr)
    selection_sort(arr,freq)
    print(arr)
