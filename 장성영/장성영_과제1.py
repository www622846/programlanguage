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
    p = ip % (10**(length-i)) // (10**(length-i-1))
    if p != 0:
        reverse += p * (10**(i))
if reverse == ip:
    print("숫자를 거꾸로 해도 같습니다.")
else:
    print("숫자를 거꾸로 하면 다릅니다")
    print("거꾸로 한 숫자는 : %d입니다."%reverse)
