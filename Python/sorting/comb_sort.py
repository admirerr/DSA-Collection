from collections import Counter

def comb_sort(arr, freq):
    n=len(arr)
    gap=n
    shrink=1.3
    sorted_flag=False
    while not sorted_flag:
        gap=int(gap/shrink)
        if gap<=1:
            gap=1
            sorted_flag=True
        i=0
        while i+gap<n:
            if (freq[arr[i]],-arr[i])<(freq[arr[i+gap]],-arr[i+gap]):
                arr[i],arr[i+gap]=arr[i+gap],arr[i]
                sorted_flag=False
            i+=1

if __name__=="__main__":
    arr=[4,6,2,4,3,2,2,6]
    freq=Counter(arr)
    comb_sort(arr,freq)
    print(arr)
