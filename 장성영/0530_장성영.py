#재고 확인
"""
items = {'우유' : 2, '콜라' : 3, '과자' : 5, "종이컵" : 3, "커피우유" : 6}
while 1:
    ip = int(input("메뉴를 선택하시오 1)재고조회 2)입고 3)출고 4)종료 : "))
    if ip == 1:
        x = input("[재고] 조회의 물건을 입력하시오 : ")
        print("재고 : {}".format(items[x]))
    elif ip == 2:
        x, y = input("[입고]의 물건과 수량을 입력하시오 : ").split()
        items[x] += int(y)
        print("{} 입고 : {}".format(x, items[x]))
    
    elif ip == 3:
        x, y = input("[출고]의 물건과 수량을 입력하시오 : ").split()
        items[x] -= int(y)
        print("{} 출고 : {}".format(x, items[x]))
    elif ip == 4:
        print("프로그램을 종료합니다.")
        break
"""
f = open("python.txt", "w")
f.write('''Python is a high-level, interpreted, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation.[32]

Python is dynamically-typed and garbage-collected. It supports multiple programming paradigms, including structured (particularly procedural), object-oriented and functional programming.
It is often described as a "batteries included" language due to its comprehensive standard library.[33][34]

Guido van Rossum began working on Python in the late 1980s as a successor to the ABC programming language and first released it in 1991 as Python 0.9.0.
[35] Python 2.0 was released in 2000 and introduced new features such as list comprehensions, cycle-detecting garbage collection, reference counting, and Unicode support.
Python 3.0, released in 2008, was a major revision that is not completely backward-compatible with earlier versions. Python 2 was discontinued with version 2.7.18 in 2020.[36]3''')
f.close()
