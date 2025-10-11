from collections import Counter

def shell_sort(arr, freq):
    n=len(arr)
    gap=n//2
    while gap>0:
        for i in range(gap,n):
            temp=arr[i]
            j=i
            while j>=gap and (freq[arr[j-gap]],-arr[j-gap])<(freq[temp],-temp):
                arr[j]=arr[j-gap]
                j-=gap
            arr[j]=temp
        gap//=2

if __name__=="__main__":
    arr=[4,6,2,4,3,2,2,6]
    freq=Counter(arr)
    shell_sort(arr,freq)
    print(arr)
