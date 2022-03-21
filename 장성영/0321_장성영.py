#동전 자판기 1

'''m = int(input("투입한 돈 : "))
p = int(input("물건값 : "))
c = m - p
print("거스름돈 :",c)
print("500원 동전의 개수:", c // 500)

##coin100 = 2400 - (500 * (c//500))
c = c % 500
print("100원 동전의 개수:", c //100)'''

#p.97 3.정수

'''x = int(input("정수를 입력하시오 : "))
x1 = x%10
x2 = x // 10 % 10
x3 = x // 100 % 10
x4 = x // 1000

sum =x1 + x2 + x3 + x4


print("자릿수의 합:",sum)'''

#동전 자판기 2

'''x = int(input("지폐로 교환할 돈을 입력하세요:"))

p50000 = x // 50000
print("5만원 지폐:%d장"%p50000)
x = x % 50000
p10000 = x // 10000
print("1만원 지폐:%d장"%p10000)
x = x % 10000
p5000 = x // 5000
print("5천원 지폐:%d장"%p5000)
x = x % 5000
p1000 = x // 1000
print("1천원 지폐:%d장"%p1000)
x = x % 1000
print("나머지 잔돈:%d원" % x)'''

#p.97 4.움직이는 물체

'''weight = int(input("물체의 무게를 입력하시오(킬로그램):"))
speed = int(input("물체의 속도를 입력하시오(미터/초):"))
energy = 0.5 * weight * speed ** 2
print("물체는 %.1f (줄)의 에너지를 가지고 있습니다." % energy)'''


#터틀 그래픽
"""import turtle

t = turtle.Turtle()
t.shape("turtle")

t.forward(100)
t.left(120)
t.forward(100)
t.left(120)
t.forward(100)
t.left(120)
t.speed(0)
n = int(turtle.textinput("몇각형을 그리고 싶나요?:", ""))
for j in range(15):
    for i in range(n):
        t.forward(100)
        t.left(360/n)
    t.left(360/15)"""

