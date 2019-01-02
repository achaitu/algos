import numpy as np
def findmax(arr,n):
    uni = np.unique(arr)
    uni.sort()
    m1= uni[-1]
    m2= uni[-2]
    c1= arr.count(m1)
    c2 = arr.count(m2)
    print (c1*c2)
    



q = int(input())
for i in range(q):
    n = input()
    arr = list(map(int, input().split()))
    findmax(arr,n)