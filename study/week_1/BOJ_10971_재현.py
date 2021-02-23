n = int(input())
W = []
for i in range(n) :
    ww = list(map(int,input().split()))
    W.append(ww)
# minBox = [[] * n for i in range(n)]
# for i in range(n) :
#     minBox.append()
costBox,cost = [],0
visted = []
box = []
for z in range(n) :
    if W[0][z] != 0 :
        cost += W[0][z]
        visted.append(z) 
        i = 1
        while i < n :
            for k in range(n) :
                if W[i][k] != 0 and k not in visted :
                    cost += W[i][k]
                    visted.append(k)
                    if len(visted) == n :       
                        costBox.append(cost)
                        cost = 0 
                    break
                if i == n-1 and k == n-1 :
                    i -= 1
                    temp = visted.pop()
                    for z in range(W[i].index(temp) + 1, n) :
                        if W[i][k] != 0 and k not in visted :
                            cost += W[i][k]
                            visted.append(k)
                            if len(visted) == n :       
                                costBox.append(cost)
                                cost = 0 
                            break
            i += 1




def sol(i) :
    global visted, cost,costBox
    if len(visted) == n :       
        costBox.append(cost)
        cost = 0
    else :
        for k in range(n) :
            if  W[i][k] != 0 and k not in visted :


n = int(input())
W = []
for i in range(n) :
    ww = list(map(int,input().split()))
    W.append(ww)
# minBox = [[] * n for i in range(n)]
# for i in range(n) :
#     minBox.append()
costBox,cost = [],0
visted = []
box = []
for z in range(n) :
    if W[0][z] != 0 :
        cost += W[0][z]
        visted.append(z) 
        i = 1
        while i < n :
            k=0
            while k < n :
                if len(visted) == n :       
                    costBox.append(cost)
                    cost = 0 
                if W[i][k] != 0 and k not in visted :
                    cost += W[i][k]
                    visted.append(k)
                    break
                k+=1
            i += 1



def sol(x,y) :
    global visted, cost,costBox
    if len(visted) == n :
        tmp = 0       
        for z in range(n) :
            tmp += costBox[z]
        cost = min(cost,tmp)

    if x >=n or y >= n :
        return
        
    if W[x][y] != 0 and y not in visted :
        costBox.append(W[x][y])
        visted.append(y)
        sol(x+1,0)
        visted.pop()
        costBox.pop()
        sol(x,y+1)
    else :
        sol(x,y+1)
        


n = int(input())
W = []
for i in range(n) :
    ww = list(map(int,input().split()))
    W.append(ww)

costBox,cost = [],10000000
visted = []
box = []
sol(0,0)
print(cost)




def sol(x,y) :
    global visted, cost,costBox
    if len(visted) == n :
        costBox.append(cost)

    if x >=n or y >= n :
        return
        
    if W[x][y] != 0 and y not in visted :
        cost += W[x][y]
        visted.append(y)
        sol(x+1,0)
        visted.pop()
        cost -= W[x][y]
        sol(x,y+1)
    else :
        sol(x,y+1)
        


n = int(input())
W = []
for i in range(n) :
    ww = list(map(int,input().split()))
    W.append(ww)

costBox,cost = [],0
visted = []
box = []
sol(0,0)
print(min(costBox))


### 최종 시간 초과  ##
def sol(x,y,cost) :
    global visted, minCost
    if len(visted) == n :
        minCost = min(minCost,cost)

    if x >=n or y >= n :
        return
        
    if W[x][y] != 0 and y not in visted :
        visted.append(y)
        sol(x+1,0,cost + W[x][y])
        visted.pop()
    sol(x,y+1,cost)
    


n = int(input())
W = []
for i in range(n) :
    ww = list(map(int,input().split()))
    W.append(ww)

costBox = []
minCost = 10**7
visted = []
box = []
sol(0,0,0)
print(minCost)