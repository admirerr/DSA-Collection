from collections import Counter

def tim_sort(arr,freq):
    return sorted(arr,key=lambda x:(-freq[x],x))

if __name__=="__main__":
    arr=[4,6,2,4,3,2,2,6]
    freq=Counter(arr)
    arr=tim_sort(arr,freq)
    print(arr)
