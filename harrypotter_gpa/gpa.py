courses = []
grades={"A":10,"AB":9,"B":8,"BC":7,"C":6,"CD":5,"D":4}
students = {}
temp = input()
temp = input()
while (temp!="Students"):
  courses.append(temp)
  temp = input()
temp = input()
while (temp != "Grades"):
  s = temp.split("~")
  students.update({s[0]: [s[1]]})
  #students.append(temp)
  temp = input()
temp = input()  
while (temp != "EndOfInput"):
  g = temp.split("~")
  students[g[3]].append(grades[g[4]])
  #print(students)
  #grades.update({g[3]:[g[0],g[4]]})
  temp = input()

for key in sorted(students.keys()):
	value = students[key]
	length = len(value)
	if(length == 1):
		gpa = 0
	else:
		gpa = sum(value[1:length])/((length-1))
	#print(sum(value[1:length]))
	#print(gpa)
	print(key+"~"+value[0]+"~"+str(round(gpa,2)))