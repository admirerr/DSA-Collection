from collections import Counter

def bubble_sort(arr, freq):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if (freq[arr[j]], -arr[j]) < (freq[arr[j+1]], -arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]

if __name__ == "__main__":
    arr = [4,6,2,4,3,2,2,6]
    freq = Counter(arr)
    bubble_sort(arr,freq)
    print(arr)
