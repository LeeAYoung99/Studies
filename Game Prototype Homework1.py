# 금도끼 은도끼 리메이크

import random
import time
# import os  # C언어의 #include <Windows.h>랑 비슷한 기능인거같다


def print_my_resource(gold_axe, silver_axe, iron_axe, my_money, firewood):
    print('@@@ 현재 가지고 있는 도끼의 갯수 @@@')
    print('금도끼:', gold_axe, '개')
    print('은도끼:', silver_axe, '개')
    print('쇠도끼:', iron_axe, '개')

    print('@@@ 현재 내 돈:', my_money, '냥@@@')
    print('@@@ 현재 내 장작:', firewood, '개@@@')


def print_current_rate(gold_axe_price, silver_axe_price, iron_axe_price, firewood_price):
    print('***현재 시장의 가격***')
    print('금도끼 가격:', gold_axe_price)
    print('은도끼 가격:', silver_axe_price)
    print('쇠도끼 가격:', iron_axe_price)
    print('장작 가격:', firewood_price)


def money_rate_change(a, b, price):
    # a,b는 price가 뻥튀기 되는 범위 (0~20)
    rate = random.randint(1, 10)
    price = int((random.randint(a, b)) * price * 0.1)
    return price


def checkdays(days):
    if days >= 11:
        print('그렇게 열 흘 동안 5만냥을 벌지 못한 당신은 어머니에게 안 좋은 일이 일어났다는 것을 알고 부리나케 뛰어갔습니다.')
        time.sleep(2)
        print('돌아갔지만 어머님은 이미 하늘나라로 가신 상태였습니다.')
        time.sleep(2)
        print('Ending 5(Bad). 지나버린 열흘')
        quit()


# 인트로

print("당신은 어느 한 숲속에 가난한 나무꾼입니다")
time.sleep(2)

print("매일 나무를 베서 입에 풀칠을 하고 살던 어느 날이였습니다.")
time.sleep(2)

print("어머니가 아프기 시작했죠. 당신은 마을에서 소문난 명의를 찾아가기로 하였습니다.")
time.sleep(2)

print('')
print("명의는 진단을 내리더니 열 흘 안에 오만냥을 모아 오지 않으면 모친을 살려주지 않겠다는 충격적인 말을 하였습니다.")
time.sleep(2)

print("당신은 명의의 돈독 오른 말에 이가 갈렸지만 어쩔 수 없이 돈을 모으기 위해 나무를 베러 갔습니다.")
time.sleep(2)
print('')

print("하지만 당신은 나무를 열심히 베다가 소중하게 여기는 쇠도끼를 모르고 물에 빠뜨려 버렸습니다!")
time.sleep(2)

print("그런데 갑자기, 물속에서 산신령이 나타났습니다!")
time.sleep(2)

ran_num = random.randint(1, 3)

# 보유한 도끼 개수

gold_axe = 0
silver_axe = 0
iron_axe = 0

# 보유한 도끼들과 장작의 가격

gold_axe_price = 5000
silver_axe_price = 1000
iron_axe_price = 800
firewood_price = 400

# 현재 내 돈, 장작의 갯수

my_money = 5000
firewood = 40

print('산신령: 이 금도끼가 너의 것이냐')
answer = input('네 또는 아니오를 입력하세요:')
print('')

if answer == '네' and ran_num == 1:
    print('산신령: 양심이 없는 사람이구구나! 네 도끼를 가져가겠다!')
    time.sleep(2)
    print('Ending 1(Normal). Don\'t count your chickens before they hatch....')
    quit()
elif answer == '네':
    print('산신령: 좋다. 그럼 이 금도끼를 너에게 주겠다.')
    print('[System] 금도끼를 획득하였습니다')
    print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
    gold_axe += 1
elif answer == '아니오':
    print('그렇다면 이 은도끼가 너의 것이냐')
    answer = input('네 또는 아니오를 입력하세요:')
    ran_num = random.randint(1, 3)
    if answer == '네' and ran_num == 1:
        print('산신령: 양심이 없는 사람이구구나! 네 도끼를 가져가겠다!')
        time.sleep(2)
        print('Ending 1(Normal). Don\'t count your chickens before they hatch....')
        quit()
    elif answer == '네':
        print('산신령: 좋다. 그럼 이 은도끼를 너에게 주겠다.')
        print('')
        print('[System] 은도끼를 획득하였습니다')
        print('')
        print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
        silver_axe += 1
    elif answer == '아니오':
        print('산신령: 호오.. 그럼 이 낡은 쇠도끼가 너의 것이냐')
        answer = input('네 또는 아니오를 입력하세요:')
        if answer == '네':
            print('산신령: 보기 드물게 양심이 있는 청년이구만! 금도끼 은도끼 쇠도끼를 모두 너에게 주겠다.')
            gold_axe += 1
            silver_axe += 1
            iron_axe += 1
            print('')
            print('[System] 금도끼, 은도끼, 쇠도끼를 획득하였습니다')
            print('')
            print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
        elif answer == '아니오':
            print('산신령: 아니.. 어떻게 자신이 돈을 벌어야 하는 도끼를 가지지 않겠다고 답변하는지.. 불효 자식이 따로 없구만..')
            time.sleep(2)
            print('Ending 2(Normal). 행운은 멍청이를 싫어하는 법이지!')
            quit()
else:
    print('산신령: 네 아니오로 대답을 하지 않는 프로그래머를 괴롭히는 못된 아이에겐 벌을 주겠다..')
    time.sleep(2)
    print('Ending 6(Special).대답하란대로 하자!!ㅠㅠㅠ')

time.sleep(3)
print('')
print('당신은 생각했어요. 돈이 급한데 산신령의 말대로 하면 돈이 더 잘 벌리지 않을까?')
time.sleep(2)
print('그래서 가지고 있는 돈을 오만냥까지 불리기로 했습니다')
time.sleep(2)
print('그렇게 생각한 당신은 시장으로 걸어갔습니다.')
print('')

days = 1

tip = ['구매/판매/장작 베기를 하면 하루가 지나갑니다.', '한 번에 한 종류의 물건밖에 사고 팔 수 없습니다.', '하루가 지나가면 시세가 바뀌게 됩니다.', '장작의 시세는 변화량이 적습니다.',
       '도끼가 없으면 장작을 벨 수 없습니다.']
while True:
    checkdays(days)
    print('')
    print('~', days, '번째 날 ~')
    print('')

    print_my_resource(gold_axe, silver_axe, iron_axe, my_money, firewood)
    print('')
    print_current_rate(gold_axe_price, silver_axe_price, iron_axe_price, firewood_price)
    print('')
    print('☆오늘의 Tip.', end='')
    print(random.choice(tip))

    time.sleep(1)
    print('1.구매')
    print('2.판매')
    print('3.장작 베기')
    print('4.명의 찾아가기(5만냥 이상 모았을때 가기)')
    choose = input()

    if choose == '1':
        while True:
            print('구매할 물건의 번호를 선택해 주세요. 1.금도끼(', gold_axe, '개 보유 2.은도끼(', silver_axe, '개 보유 3.쇠도끼', iron_axe, '개 보유')
            choose = input()
            if choose == '1':
                print('몇 개 구매하시겠습니까?')
                how_much = int(input())
                if (gold_axe_price * how_much) > my_money:
                    print('가지고 있는 돈보다 구매하려는 물건의 액수가 너무 많습니다!!')
                    continue
                else:
                    print('구매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money -= (gold_axe_price * how_much)
                    gold_axe += how_much
                    break
            elif choose == '2':
                print('몇 개 구매하시겠습니까?')
                how_much = int(input())
                if (silver_axe_price * how_much) > my_money:
                    print('가지고 있는 돈보다 구매하려는 물건의 액수가 너무 많습니다!!')
                    continue
                else:
                    print('구매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money -= (silver_axe_price * how_much)
                    silver_axe += how_much
                    break
            elif choose == '3':
                print('몇 개 구매하시겠습니까?')
                how_much = int(input())
                if (iron_axe_price * how_much) > my_money:
                    print('가지고 있는 돈보다 구매하려는 물건의 액수가 너무 많습니다!!')
                    continue
                else:
                    print('구매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money -= (iron_axe_price * how_much)
                    iron_axe += how_much
                    break
            else:
                print('잘 못 입력하셨습니다')
                continue
    elif choose == '2':
        while True:
            print('판매할 물건의 번호를 선택해 주세요. 1.금도끼(', gold_axe, '개 보유) 2.은도끼(', silver_axe, '개 보유) 3.쇠도끼(', iron_axe,
                  '개 보유) 4.장작(', firewood, '개 보유)')
            choose = input()
            if choose == '1':
                print('몇 개 판매하시겠습니까?')
                how_much = int(input())
                if how_much > gold_axe:
                    print('가지고 있는 금도끼의 개수보다 판매하려는 물건의 개수가 너무 많습니다!!')
                    continue
                else:
                    print('판매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money += (gold_axe_price * how_much)
                    gold_axe -= how_much
                    break
            elif choose == '2':
                print('몇 개 판매하시겠습니까?')
                how_much = int(input())
                if how_much > silver_axe:
                    print('가지고 있는 은도끼의 개수보다 판매하려는 물건의 개수가 너무 많습니다!!')
                    continue
                else:
                    print('판매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money += (silver_axe_price * how_much)
                    silver_axe -= how_much
                    break
            elif choose == '3':
                print('몇 개 판매하시겠습니까?')
                how_much = int(input())
                if how_much > iron_axe:
                    print('가지고 있는 쇠도끼의 개수보다 판매하려는 물건의 개수가 너무 많습니다!!')
                    continue
                else:
                    print('판매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money += (iron_axe_price * how_much)
                    iron_axe -= how_much
                    break
            elif choose == '4':
                print('몇 개 판매하시겠습니까?')
                how_much = int(input())
                if how_much > firewood:
                    print('가지고 있는 장작의 개수보다 판매하려는 장작의 개수가 너무 많습니다!!')
                    continue
                else:
                    print('판매 완료! 하루가 지나갑니다')
                    days += 1
                    my_money += (firewood * how_much)
                    firewood -= how_much
                    break
            else:
                print('잘 못 입력하셨습니다')
                continue
    elif choose == '3':
        if (gold_axe + silver_axe + iron_axe) == 0:
            print('도끼가 없어 장작을 벨 수 없습니다...')
            continue
        else:
            print('당신은 장작을 베기 시작했습니다! 뚝딱뚝딱...')
            time.sleep(3)
            new_firewood = random.randint(18, 24)
            firewood += new_firewood
            print(new_firewood, '개의 장작을 베어 총 ', firewood, '개의 장작을 보유하게 되었습니다!')
            days += 1
    elif choose == '4':
        if my_money < 50000:
            print('당신은 명의를 찾아가기로 하였습니다....')
            time.sleep(3)
            print('명의: 이런.. 당신은 가지고 있는 돈이 너무 적소!')
            print('안타깝게도 돈을 구하지 못한 당신은 아픈 어머니를 살려 내지 못하게 되었습니다.')
            time.sleep(1)
            print('Ending 3(Bad). 자본주의에 물든 조선')
            quit()
        else:
            print('당신은 명의를 찾아가기로 하였습니다....')
            time.sleep(3)
            print('명의: 돈을 제대로 가져오셨군! 자 여기, 조선에서 제일로 버금가는 약초를 찾아왔소.')
            print('당신은 어머니를 골병에서 구하게 되었습니다!')
            print('Ending 4.(True). 당신은 효자입니다.')
            print('걸린 날짜:', days, '일')
            quit()
    else:
        print('숫자만 넣어주세용...')
        continue

    gold_axe_price = money_rate_change(6, 20, gold_axe_price)
    silver_axe_price = money_rate_change(7, 15, silver_axe_price)
    iron_axe_price = money_rate_change(8, 12, iron_axe_price)
    firewood_price = money_rate_change(9, 11, firewood_price)

    # os.system('cls')
    # os.system('pause')

    '''
    -메모장- 
    게임 밸런스 조절하기
    눈에 편하게 만들기 
    화면 지우기, 멈추기
    도끼의 갯수가 0일때 장작 베기를 할 수 없게 만들기 o
    '''
