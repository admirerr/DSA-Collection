from collections import Counter

def bucket_sort(arr, freq):
    max_freq=max(freq.values())
    buckets=[[] for _ in range(max_freq+1)]
    for num in arr:
        buckets[freq[num]].append(num)
    result=[]
    for f in range(max_freq,0,-1):
        for val in sorted(set(buckets[f])):
            result.extend([val]*freq[val])
    return result

if __name__=="__main__":
    arr=[4,6,2,4,3,2,2,6]
    freq=Counter(arr)
    arr=bucket_sort(arr,freq)
    print(arr)
