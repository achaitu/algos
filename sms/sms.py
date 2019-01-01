from collections import Counter
n = int(input())
a = []
temp = input()
for i in range((n)):
	a.append(temp)
	temp = input()
#print(a)
#dic = {"a": '2',"b": '2',"c": '2',"d": '3',"e": '3',"f": '3',"g": '4',"h": '4',"i": '4',"j": '5',"k": '5',"l": '5',"m": '6',"n": '6',"o": '6',"p": '7',"q": '7',"r": '7',"s": '7',"t": '8',"u": '8,"v": '8',"w": '9',"x": '9',"y": '9',"z":'9'}


dic = {"a": 2,"b": 2,"c": 2,"d": 3,"e": 3,"f": 3,"g": 4,"h": 4,"i": 4,"j": 5,"k": 5,"l": 5,"m": 6,"n": 6,"o": 6,"p": 7,"q": 7,"r": 7,"s": 7,"t": 8,"u": 8,"v":8,"w": 9,"x": 9,"y": 9,"z":9}

def getsmsnum(i):
	temp2 = ""
	for char in i:
		temp2  = temp2 + str(dic[char])
	return temp2


val = []
for i in a:
	num = getsmsnum(i)
	val.append(num)
#print(val)

data = Counter(val)
ans = data.most_common()
print(ans[0][0])