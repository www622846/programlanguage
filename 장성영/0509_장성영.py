#값 반환(여러 개의 값 반환

def sort_num(n1, n2):
    if n1 > n2:
        '''max = n1
        min = n2'''
        return n2, n1
    else:
        '''max = n2
        min = n1'''
        return n1, n2
"""
print(sort_num(110, 210))
print(sort_num(2100, 80))"""

def calc(n1, n2):
    return n1 + n2, n1 - n2, n1 * n2, n1 / n2

n1, n2 = 200, 100
t1, t2, t3, t4 = calc(n1, n2)
"""print(n1, "+", n2, "=", t1)
print(n1, "-", n2, "=", t2)
print(n1, "*", n2, "=", t3)
print(n1, "/", n2, "=", t4)"""

#도전문제

def get_square(a, b, c):
    return a**2, b**2, c**2

x, y, z = get_square(2, 6, 3)
'''print(x,y,z)'''

#숫자를 계속 더해주는 함수
def addition(num):
    global sum 
    sum += num

sum = 0
addition(3)
addition(12)
addition(5)
print(sum)

