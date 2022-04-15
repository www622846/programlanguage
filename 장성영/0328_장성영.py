#나이 계산
'''import time
now = time.time()
thisYear = int(1970 + now//(365 * 24 * 60 * 60))
print("올해는 " + str(thisYear)+"입니다.")
age = int(input("몇 살이신지요? "))
_age = 2050 - thisYear + age
print("2050년에는 %d살 이시군요." % _age)
year = int(input("추정년도를 입력해주세요. "))
_age = year - thisYear + age
print("{0}년에는 {1}살이시군요.".format(year, _age))'''

#직각 삼각형의 빗변의 길이를 구하는 프로그램
'''a = int(input("첫번째 길이를 입력해주세요."))
b = int(input("두번째 길이를 입력해주세요."))
c = (a**2 + b**2)**1/2
print("답은 %.1f입니다." % c)'''

#친구들의 리스트 생성하기
'''f_ls = []
"""f_1 = str(input("친구의 이름을 입력하시오: "))
f_ls.append(f_1)
f_2 = str(input("친구의 이름을 입력하시오: "))
f_ls.append(f_2)
f_3 = str(input("친구의 이름을 입력하시오: "))
f_ls.append(f_3)
f_4 = str(input("친구의 이름을 입력하시오: "))
f_ls.append(f_4)
f_5 = str(input("친구의 이름을 입력하시오: "))
f_ls.append(f_5)"""

for i in range(0, 5):
    f = str(input("친구의 이름을 입력하시오: "))
    f_ls.append(f)
    
Num = int(input("몇 번째 친구를 출력할까요?")) - 1

print(f_ls[Num])
print(f_ls)'''


#암호문만들기

"""Ori = str(input("평문 입력 : "))
'''le = -len(Ori)-1
Pa = Ori[-1: le: -1]
'''
Pa = Ori[:: -1]
print("암호문 :",Pa)"""
