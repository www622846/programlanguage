#유클리드 호재법으로 최대공약수 구하기
'''
ip_1 = int(input("정수1를 입력 : "))
ip_2 = int(input("정수2를 입력 : "))
if ip_1 > ip_2:
    max_ip = ip_1
    min_ip = ip_2
else:
    max_ip = ip_2
    min_ip = ip_1

while True:
    re = max_ip % min_ip
    if re == 1:
       print("서로 서로소입니다.")
       break
    elif re == 0:
        print("두 수의 최대공약수 : %d"%min_ip)
        break
    else:
        max_ip = min_ip
        min_ip = re
'''

#숫자 맞추기 게임
'''
import random

ans =random.randint(1, 100)
print("1부터 100사이의 숫자를 맞추시오")
chance = 1

while True:
    print("=" * 30)
    ip = int(input("숫자를 입력하시오 : "))
    if ans == ip:
        print("축하합니다. 시도횟수 : %d" %chance)
        break
    elif ans > ip:
        print("입력한 숫자가 답보다 작습니다.")
    else:
        print("입력한 숫자가 답보다 큽니다.")
    chance += 1
'''

#과제 (369)
'''
for i in range(1, 101):
    if i % 3 == 0:
        print("짝", end=', ')
    elif i == 100:
        print("%d" %i, end='')
    else:
        print("%d" %i, end=', ')'''

#과제 거꾸로 숫자

ip = int(input("숫자를 입력하시오 : "))
length = 0
while True:
    length += 1
    if ip % 10**length == ip:
        break
reverse=0
for i in range(0, length):
    p = ip // (10**i)
    if p != 1:
        print(p % (10**(length-i-1)))
    else:
        p = 1
    if p != 0:
        reverse += p * (10**(length-i-1))
        print(reverse)
print(reverse)
    
