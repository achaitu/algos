temp = input()
N = int(temp)
a = []
for i in range(N):
  a.append(int(input()))
#print(a)
 
StoredBest = [0 for i in range(N)]

StoredBest[1]=1
for i in range(N):
  tmax = 1
  for j in range(i):
    if a[i] > a[j] :
      tmax=max(tmax,StoredBest[j]+1)
  StoredBest[i]=tmax
 
def max(A):
  M = A[0]
  for i in range(len(A)):
    if M < A[i]:
      M = A[i]
  return M

print(max(StoredBest))

    
  