
import matplotlib.pyplot as plt
import time
from numpy.random import randint
time.clock = time.time

def bubble_sort(arr):
    n=len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if(arr[j]>arr[j+1]):
                arr[i],arr[j+1]=arr[j+1],arr[j]



def selection_sort(arr):
    n=len(arr)
    for i in range(n):
        k=i
        for j in range (i+1,n):
            if(arr[k]>arr[j]):
                k=j
        arr[k],arr[i]=arr[i],arr[k]

def merge(arr,lb,ub,mid):
    i=lb
    j=mid+1
    temp=list()
    while(i<=mid and j<=ub):
        if(arr[i]<arr[j]):
            temp.append(arr[i])
            i+=1
        else:
            temp.append(arr[j])
            j+=1
    while(i<=mid):
        temp.append(arr[i])
        i+=1
    while(j<=ub):
        temp.append(arr[j])
        j+=1
    k=0
    for i in range (lb,ub+1):
        arr[i]=temp[k]
        k+=1

def merge_sort(arr,lb,ub):
    if(lb>=ub):
        return
    mid=lb+(ub-lb)//2
    merge_sort(arr,lb,mid)
    merge_sort(arr,mid+1,ub)
    merge(arr,lb,ub,mid)



def insertion_sort(arr):
    n=len(arr)
    for i in range (n):
        for j in range(i,0,-1):
            if arr[j]<arr[j-1]:
                arr[j],arr[j-1]=arr[j-1],arr[j]
            else:
                break

def partiton(arr,lb,ub):
    pivot=arr[lb]
    i=lb
    j=ub
    while(i<=j):
        while(  j>=i and arr[i]<=pivot):
            i+=1
        while(j>=i  and arr[j]>=pivot ):
            j-=1
        if(i<j):
            arr[i],arr[j]=arr[j],arr[i]
    arr[lb],arr[j]=arr[j],arr[lb]
    return j


def quick_sort(arr,lb,ub):
    
    if lb<ub:
        p=partiton(arr,lb,ub)
        quick_sort(arr,lb,p-1)
        quick_sort(arr,p+1,ub)

arr=list()
elements=list()
times_bs = list()
times_ss = list()
times_is = list()
times_ms = list()
times_qs = list()
temp=list()
for i in range (1,5):
    arr = randint(0, 1000* i, 1000 * i)
    elements.append(len(arr))

    temp=arr.copy()
    start=time.clock()
    quick_sort(temp,0,len(arr)-1)
    end=time.clock()
    times_qs.append(end-start)
    print("Quick Sort for length",len(arr),"is",end-start)

    temp=arr.copy()
    start=time.clock()
    bubble_sort(temp)
    end=time.clock()
    times_bs.append(end-start)
    print("Bubble Sort for length",len(arr),"is",end-start)

    temp=arr.copy()
    start=time.clock()
    selection_sort(temp)
    end=time.clock()
    times_ss.append(end-start)
    print("Selection Sort for length",len(arr),"is",end-start)

    temp=arr.copy()
    start=time.clock()
    insertion_sort(temp)
    end=time.clock()
    times_is.append(end-start)
    print("Insertion Sort for length",len(arr),"is",end-start)
    temp=arr.copy()
    start=time.clock()
    merge_sort(temp,0,len(arr)-1)
    end=time.clock()
    times_ms.append(end-start)
    print("Merge Sort for length",len(arr),"is",end-start)

plt.xlabel('List Length')
plt.ylabel('Time Complexity')
plt.plot(elements, times_bs, label ='Bubble Sort')
plt.plot(elements, times_ss, label ='Selection Sort')
plt.plot(elements, times_is, label ='Insertion Sort')
plt.plot(elements, times_ms, label ='Merge Sort')
plt.plot(elements, times_qs, label ='Quick Sort')

plt.grid()
plt.legend()
plt.show()



    
