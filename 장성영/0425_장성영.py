#범인 찾기 게임
'''
import random
roomCount = int(input("방의 갯수 설정 : "))
score = 30
count = 0
print("기본점수 :",score)
SusRoom = random.randint(1,roomCount)
print("="*20)
while True:
    sol = int(input("범인이 숨은 방은 : "))
    count +=1
    if(sol > roomCount or sol < 1):
        print("%d번 방은 없습니다."%sol)
        continue
    if(sol != SusRoom):
        print(sol,"번 방에는 범인이 없습니다.")
        SusRoom = random.randint(1, roomCount)
        score -= 10
    else:
        print(SusRoom,"번 방에는 범인이 있습니다.")
        print(count,"만에 범인 체포!")
        score += 100
        print("게임 종료")
        print("점수 : ",score)
        break
'''
#약수 구하기
'''
ip = int(input("정수를 입력하시오"))
d = 1
print("%d의 약수" % ip)
while True:
    if(ip % d == 0):
        print("%d "%d, end = "")
    d+=1
    if(d > ip):
        break
'''

#최대공약수 구하기
'''
ip_1 = int(input("정수1를 입력 : "))
ip_2 = int(input("정수2를 입력 : "))
max_ip = 0
min_ip = 0
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
