# import sys
# sys.setrecursionlimit(3000)

def sol_fow(ch,lr) :
    global forward
    if len(forward) == n :
        return
    print(ch,lr)
    print(forward)
    for i in range(n) :
        if tree[i][0] == ch :
            if tree[i][lr] != '.' :
                if ch not in forward :
                    forward += ch
                    sol_fow(tree[i][lr],1)
                else :
                    for k in range(n) :
                        for j in range(3) :
                            if tree[k][j] == ch :
                                ch = tree[k][0]
                                k = n+1
                                break
                    sol_fow(ch,2)
            else:
                if ch not in forward and ch != '.' :
                    forward += ch
                if lr ==1 and tree[i][2] != '.' :
                    sol_fow(tree[i][2],1)
                else :
                    for k in range(n) :
                        for j in range(3) :
                            if tree[k][j] == ch :
                                ch = tree[k][0]
                                k = n+1
                                break
                    sol_fow(ch,2)

def sol_mid(ch,lr) :
    global mid
    # print(1)
    if len(mid) == n :
        return
    for i in range(n) :
        if tree[i][0] == ch :
            if tree[i][lr] != '.' :
                ch = tree[i][lr]
                lr = 1
            else :
                lr = 2
                if ch in mid :
                    for k in range(n) :
                        for j in range(3) :
                            if tree[k][j] == ch :
                                ch = tree[k][0]
                                k = n+1
                                break
                    while ch in mid :
                        for k in range(n) :
                            for j in range(3) :
                                if tree[k][j] == ch :
                                    ch = tree[k][0]
                                    k = n+1
                                    break
                    mid += ch

                else :
                    mid += ch
            break
    sol_mid(ch,lr)
        
def sol_back(ch,lr) :
    global back
    if len(back) == n :
        return
    for i in range(n) :
        if tree[i][0] == ch :
            if tree[i][lr] != '.' :
                if tree[i][lr] not in back :
                    ch = tree[i][lr]
                    lr = 1
                else :
                    back += ch
                    for k in range(n) :
                        for j in range(3) :
                            if tree[k][j] == ch :
                                ch = tree[k][0]
                                k = n+1
                                break
            else :
                if lr == 1 :
                    lr = 2
            
                else : 
                    back += ch
                    for k in range(n) :
                        for j in range(3) :
                            if tree[k][j] == ch :
                                ch = tree[k][0]
                                k = n+1
                                break
            break                    

    sol_back(ch,lr)
    
    
n = int(input())
tree = []
for i in range(n) :
    tree.append(list(input().split()))

forward, mid, back = '','',''

sol_fow('A',1) 

sol_mid('A',1) 

sol_back('A',1)

print(forward)
print(mid)
print(back)