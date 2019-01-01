def findx(s):
    u = [x for x in s if x.isupper()]
    l = [x for x in s if x.islower()]
    if (len(u) == 0  or len(l) == 0):
        print (-1)
        return
    a= "".join(u)
    b = "".join(l)
    c= sorted(a,reverse=True)
    d= sorted(b,reverse=True)
    count = 0
    for i in c:
        for j in d:
            #print(i.lower(),j)
            if i.lower() == j:
                print (i)
                return
                
    if count == 0:
        print(-1)

q = int(input())
for i in range(q):
    s = input()
    findx(s)
    