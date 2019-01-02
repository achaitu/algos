#!/bin/python3

#author = Chaitu

import sys

s = "0"
i = 0
while (len(s) < 1000):
    #print(len(s) )
    t = ""
    b = []
    for i in range (len(s)):
        #print ( i )
        k = int(s[i])
        b.append(1 - (k))
        t = t + str(b[i])
    s = s + str(t)
    #print(s)


def duplication(x):
    return s[x]
    

q = int(input().strip())
for a0 in range(q):
    x = int(input().strip())
    result = duplication(x)
    print(result)
