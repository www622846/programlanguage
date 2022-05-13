ip = int(input("정수 입력 : "))
length = 1
while True:
    if ip % 10 ** length != ip:
        length += 1
    else:
        break
reverse = 0
for i in range(length):
    re = ip // (10 ** length - i) % (length - i - 1)
    print(length-i)
    if re != 0:
        reverse += re * 10**i

print(reverse)
