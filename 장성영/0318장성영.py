"""x = int(input("첫번째 숫자를 입력하시오 : "))
y = int(input("두번째 숫자를 입력하시오 : "))

##print("{0} + {1} = {2}".format(x, y, x+y))
##print("{0} - {1} = {2}".format(x, y, x-y))
##print("{0} * {1} = {2}".format(x, y, x*y))
##print("{0} / {1} = {2}".format(x, y, x/y))

##print(x,"+", y,"=",x+y)
##print(x,"-", y,"=",x-y)
##print(x,"*", y,"=",x*y)
##print(x,"/", y,"=",x/y)

print("%d + %d = %d"%(x,y,x+y))
print("%d - %d = %d"%(x,y,x-y))
print("%d * %d = %d"%(x,y,x*y))
print("%d / %d = %.3f"%(x,y,x/y))

print( '''야 {0:5s}야 너는 {1}시간 뒤에 시험을 볼거야
그래서 {2:5.1f}점을 받고 칭찬을 {1}번 받을 거야'''.format("장성영", 40, 123))"""

#초를 분초로 계산

'''
sec = 1000
m = 1000 // 60
reminder = 1000 % 60
print("%d분 %d초" %(m, reminder))'''

#BMI 계산
weight = float(input("몸무게 kg 단위로 입력하시오 : "))
height = float(input("키를 미터 단위로 입력하시오 : "))
bmi = weight/(height ** 2)
##print("당신의 BMI = %f"% bmi)
print("당신의 BMI =", bmi)

