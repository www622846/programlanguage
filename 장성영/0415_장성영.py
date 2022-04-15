#별 출력
"""for i in range(5):
    for j in range(10):
        print("*", end ='')
    print()"""
    
"""for i in range(5):
    print("*" * 10)"""
    
#별 직각삼각형
"""for i in range(1, 6):
    for j in range(i):
        print("*", end = "")
    print()"""

"""for i in range(5):
    print("*" * (i + 1))"""

#while 문
"""response = "아니"
while response == "아니":
    response = input("엄마 다됐어?")
print("먹자")"""

#1부터 10까지의 덧셈
i = 1
sum = 0
while i <= 10:
    sum += i
    i += 1
print("1부터 10까지의 합 : %d" % sum)
