from collections import Counter

def cocktail_sort(arr, freq):
    n=len(arr)
    swapped=True
    start=0
    end=n-1
    while swapped:
        swapped=False
        for i in range(start,end):
            if (freq[arr[i]],-arr[i])<(freq[arr[i+1]],-arr[i+1]):
                arr[i],arr[i+1]=arr[i+1],arr[i]
                swapped=True
        if not swapped: break
        swapped=False
        end-=1
        for i in range(end-1,start-1,-1):
            if (freq[arr[i]],-arr[i])<(freq[arr[i+1]],-arr[i+1]):
                arr[i],arr[i+1]=arr[i+1],arr[i]
                swapped=True
        start+=1

if __name__=="__main__":
    arr=[4,6,2,4,3,2,2,6]
    freq=Counter(arr)
    cocktail_sort(arr,freq)
    print(arr)
