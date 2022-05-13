#함수

def JSY():
    print("학과 : 정보통신공학과")
    print("학번 : 20214119")

#인수 전달

def JSY_2(name):
    print("학과 : 정보통신공학과")
    print("학번 : 20214119")
    print("이름 : %s"%name)



def JSY_3(name ,grade):
    print("학과 : 정보통신공학과")
    print("학번 : 20214119")
    print("이름 : %s"%name)
    print("학년 : %d"%grade)


#시작, 끝수 더하기 

def get_sum(start, end):
    sum = 0
    for i in range(start, end+1):
        sum += i
    print("{}부터 {}까지 합은 {}입니다.".format(start,end,sum))

    
