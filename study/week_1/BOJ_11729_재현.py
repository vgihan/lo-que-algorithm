def getHanoiNum(num) :
    if num == 1 :
        return 1
    elif num == 2 :
        return 3
    else :
        hop = getHanoiNum(num-1)*2+1 
        return hop

def hanoi(num,fromT,toT,midT) :
    if num == 1 :
        print(fromT, toT)
        return
    hanoi(num-1,fromT, midT, toT)
    print(fromT,toT)
    hanoi(num-1,midT,toT,fromT)

n = int(input())
print(getHanoiNum(n))
hanoi(n,1,3,2)
