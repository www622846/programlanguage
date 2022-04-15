#성적 입력

'''score = int(input("성적을 입력하시오:"))
if score > 60:
    print("합격입니다.")
else:
    print("불합격입니다.")'''

#짝수 입력

'''i = int(input("정수를 입력하시오:"))
if i % 2 == 0:
    print("짝수입니다.")
else:
    print("홀수입니다.")'''
    
#영화 나이 계산

'''age = int(input("나이를 입력하시오:"))
if age >= 15:
    print("이 영화를 보실 수 있습니다.")
    print("영화의 가격은 10000원입니다.")
else:
    print("이 영화를 보실 수 없습니다.")
    print("다른 영화를 보시겠어요?")'''

#윤년 판단

'''year = int(input("연도를 입력하시오:"))

if year % 4 == 0:
    if year % 100 == 0:
        if year % 400 == 0:
            print("%d년은 윤년입니다." % year)
        else:
            print("%d년은 윤년이 아닙니다."% year)
    else:
        print("%d년은 윤년입니다." % year) 
else:
    print("%d년은 윤년이 아닙니다." % year)'''

'''if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0 :
    print("%d년은 윤년입니다." % year)
else:
    print("%d년은 윤년이 아닙니다."% year)'''

#동전 던지기 게임
import random
print("동전 던지기 게임을 시작합니다.")
c = random.randrange(2)
if(c == 1):
    print("동전의 앞면입니다.")
else:
    print("동전의 뒷면입니다.")
print("게임이 종료되었습니다.")
