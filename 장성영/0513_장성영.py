def BMI(W, H = 1.73):
    BMI = W/(H**2)
    print("BMI :", BMI)
    return BMI

def resultBMI(result):
    if result < 18.5:
        print("저체중입니다.")
    elif result < 23:
        print("정상입니다.")
    elif result < 25:
        print("과체중입니다.")
    elif result < 30:
        print("경도비만입니다.")
    else:
        print("고도비만입니다.")

#남녀 체질량 지수

def BMIIn():
    gender =int(input("남자는 1, 여자는 0"))
    height = float(input("키(m)를 입력하시오"))
    '''if gender == 0:
        W = height ** 2 * 21
    elif gender == 1:
        W = height ** 2 * 22
    else:
        print("다시입력하시오")
        return'''
    W = height ** 2 * (21 + gender)

    print("표준체중 :", W)
    return W

def fat(result, rW):
    f = ((float)(rW)/result) * 100
    print("비만도 :", f)

#환전

