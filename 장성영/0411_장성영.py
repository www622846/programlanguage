#range()함수
'''
"""for i in range(1,6, 1):
     print(i, end = " ")"""
for i in range(10,0, -1):
     print(i, end = " ")'''
#짝수
"""for i in range(2, 101, 2):
    print(i, end=" ")"""
#숫자의 합
"""sum = 0
for i in range(1, 101):
    sum += i
print("1부터 100까지의 합은 {}입니다.".format( sum))
"""
#도전
"""sum = 0
st = int(input("시작 값 : "))
en = int(input("끝 값 : "))
for i in range(st, en + 1):
    sum += i
print("{}부터 {}까지의 합은 {}입니다.".format(st, en, sum))"""
#팩토리얼 계산하기
"""ui = int(input("정수를 입력하시오 : "))
sum = 1
for i in range(1, ui+1):
    sum *= i
print("{}!은 {}이다.".format(ui, sum))"""
#구구단 세로
"""for i in range(1, 10): 
    print("=== {}단 ===".format(i))
    for j in range(1, 10):
        print("{} * {} = {}".format(i, j,i*j))"""
#구구단 가로
"""for i in range(1, 10):
    print("=== {}단 ===".format(i), end = "\t")
print()
for i in range(1, 10):
    for j in range(1, 10):
        print("{} * {} = {}".format(j, i,i*j), end = "\t")
print()"""
#도전문제
sum = 0
for i in range(50, 101):
    if(i % 3 == 0 or i % 5 == 0):
        sum += i
print("3, 5의 배수의 합 : {}".format(sum))
