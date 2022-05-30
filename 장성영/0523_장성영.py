import random

name = []
while 1:
    ipnum = int(input("숫자 입력 : 1(추가), 2(삭제), 3(오늘의 당번) : "))
    if ipnum == 1:
        while 1:
            ipname = input("이름 입력(입력 중지 0) : ")
            if ipname == "0":
                break
            name.append(ipname)
    elif ipnum == 2:
        renum = int(input("삭제할 순번 입력 : "))
        name.pop(renum)
        print(name)
    elif ipnum == 3:
        print("{}".format(name[random.randrange(0, len(name))]))
    else:
        break
