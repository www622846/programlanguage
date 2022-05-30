#팩토리얼
def np(num):
    if  num > 0:
        return num * np(num-1)
    else:
        return 1

#피보나치
def fibonacci(num):
    if num == 1:
        return 0
    elif num == 2:
        return 1
    return fibonacci(num-1) + fibonacci(num-2)
