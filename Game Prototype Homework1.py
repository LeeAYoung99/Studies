# 금도끼 은도끼 리메이크

import random
import time

def print_my_resource(gold_axe,silver_axe,iron_axe,my_money,firewood):
    print('@@@ 현재 가지고 있는 도끼의 갯수 @@@')
    print('금도끼:',gold_axe,'개')
    print('은도끼:',silver_axe,'개')
    print('쇠도끼:',iron_axe,'개')
    
    print('@@@ 현재 내 돈:',my_money,'냥@@@')
    print('@@@ 현재 내 장작:',firewood,'개@@@')

def print_current_rate(gold_axe_price,silver_axe_price,iron_axe_price,firewood_price):
    print('***현재 시장의 가격***')
    print('금도끼 가격:',gold_axe_price)
    print('은도끼 가격:',silver_axe_price)
    print('쇠도끼 가격:',iron_axe_price)
    print('장작 가격:',firewood_price)

def money_rate_change(a,b,price):
    #a,b는 price가 뻥튀기 되는 범위 (0~2)
    rate=random.randint(1,10)
    price=int((random.randint(a,b))*price)
    return price
                

#인트로

print("당신은 어느 한 숲속에 가난한 나무꾼입니다")
time.sleep(2)

print("매일 나무를 베서 입에 풀칠을 하고 살던 어느 날이였습니다.")
time.sleep(2)

print("어머니가 아프기 시작했죠. 당신은 마을에서 소문난 명의를 찾아가기로 하였습니다.")
time.sleep(2)

print("명의는 진단을 내리더니 백 일 안에 오만냥을 모아 오지 않으면 모친을 살려주지 않겠다는 충격적인 말을 하였습니다.")
time.sleep(2)

print("당신은 명의의 돈독 오른 말에 이가 갈렸지만 어쩔 수 없이 돈을 모으기 위해 나무를 베러 갔습니다.")
time.sleep(2)

print("하지만 당신은 나무를 열심히 베다가 소중하게 여기는 쇠도끼를 모르고 물에 빠뜨려 버렸습니다!")
time.sleep(2)

print("그런데 갑자기, 물속에서 산신령이 나타났습니다!")
time.sleep(2)

ran_num=random.randint(1,3)

#보유한 도끼 개수

gold_axe=0
silver_axe=0
iron_axe=0

#보유한 도끼들과 장작의 가격

gold_axe_price=2000
silver_axe_price=500
iron_axe_price=300
firewood_price=70

# 현재 내 돈, 장작의 갯수

my_money=0
firewood=0

rumor=('김 돌쇠:오늘은 ','김 첨지:')

print('산신령: 이 금도끼가 너의 것이냐')
answer=input('네 또는 아니오를 입력하세요:')

if answer=='네' and ran_num==1:
    print('산신령: 양심이 없는 사람이구구나! 네 도끼를 가져가겠다!')
    time.sleep(2)
    print('Ending 1. 욕심을 부려선 안된다...')
    quit()
elif answer=='네':
    print('산신령: 좋다. 그럼 이 금도끼를 너에게 주겠다.')
    print('[System] 금도끼를 획득하였습니다')
    print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
    gold_axe+=1
elif answer=='아니오':
    print('그렇다면 이 은도끼가 너의 것이냐')
    answer=input('네 또는 아니오를 입력하세요:')
    ran_num=random.randint(1,3)
    if answer=='네' and ran_num==1:
        print('산신령: 양심이 없는 사람이구구나! 네 도끼를 가져가겠다!')
        time.sleep(2)
        print('Ending 1. Don\'t count your chickens before they hatch....')
        quit()
    elif answer=='네':
        print('산신령: 좋다. 그럼 이 은도끼를 너에게 주겠다.')
        print('[System] 은도끼를 획득하였습니다')
        print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
        silver_axe+=1
    elif answer=='아니오':
        print('산신령: 호오.. 그럼 이 낡은 쇠도끼가 너의 것이냐')
        answer=input('네 또는 아니오를 입력하세요:')
        if answer=='네':
            print('산신령: 보기 드물게 양심이 있는 청년이구만! 금도끼 은도끼 쇠도끼를 모두 너에게 주겠다.')
            gold_axe+=1
            silver_axe+=1
            iron_axe+=1
            print('[System] 금도끼, 은도끼, 쇠도끼를 획득하였습니다')
            print('산신령: 그리고 나무만 베는 것이 아니라 장사를 해서 돈을 모으는 것이 빨리 어머니를 치료하는 데 좋지 않겠나!')
        elif answer=='아니오':
            print('산신령: 아니.. 어떻게 자신이 돈을 벌어야 하는 도끼를 가지지 않겠다고 답변하는지.. 불효 자식이 따로 없구만..')
            time.sleep(2)
            print('Ending 2. 행운은 멍청이를 싫어하는 법이지!')
            quit()

time.sleep(3)
print('')
print('당신은 생각했어요. 산신령의 말대로 하면 돈이 더 잘 벌리지 않을까?')
time.sleep(2)
print('그래서 가지고 있는 돈을 오만냥까지 불리기로 했습니다')
time.sleep(2)
print('그렇게 생각한 당신은 시장으로 걸어갔습니다.')
print('')

days=1

while True:
    print('~',days,'번째 날 ~')
    print('')
    
    print_my_resource(gold_axe,silver_axe,iron_axe,my_money,firewood)
    print('')
    print_current_rate(gold_axe_price,silver_axe_price,iron_axe_price,firewood_price)
    print('')
    print('Tip. 구매/판매/장작 베기를 하면 하루가 지나갑니다. 하루가 지나가면 시세가 바뀌게 됩니다.')
    print('\t소문 듣기를 통해 구매를 할지, 판매를 할지, 장작을 벨지 정하세요!')
    time.sleep(1)
    print('1.구매')
    print('2.판매')
    print('3.장작 베기')
    print('4.소문 듣기')
    print('5.명의 찾아가기(5만냥 이상 모았을때 가기)')
    choose=input()

    gold_axe_price=money_rate_change(0.1,2.0,gold_axe_price)
    silver_axe_price=money_rate_change(0.5,1.5,silver_axe_price)
    iron_axe_price=money_rate_change(0.8,1.2,iron_axe_price)
    firewood_axe_price=money_rate_change(0.5,1.5,firewood_price)
    
    if choose==1:
        
    elif choose==2:
    elif choose==3:
    elif choose==4:
    elif choose==5:
