def cal_grade(score):
    if score >= 80:
        grade = 'A'
    elif (score >= 70) and (score < 80):
        grade = 'B'
    elif (score >= 60) and (score < 70):
        grade = 'C'
    elif (score >= 50) and (score < 60):
        grade = 'D'
    else:
        grade = 'F'
        
    return grade
        
# Input Section
no_student = int(input('Numbers of Students: '))
test1 = []
test2 = []
test3 = []
total = []
for i in range(no_student):
    print('Please input score of student{}.'.format(i+1))
    test1.append(int(input('Test1 : ')))
    test2.append(int(input('Test2 : ')))
    test3.append(int(input('Test3 : ')))
    total.append(test1[i]*0.3+test2[i]*0.3+test3[i]*0.4)
# Output Section
for i in range(no_student):    
    print('Average score of Student{} is {:0.1f}, Grade {}.'.format(i,total[i],cal_grade(total[i])))







