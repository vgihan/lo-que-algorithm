from collections import deque

n = int(input())

def bfs(coorX,coorY,cursize) :
    visit =[[0] *n for i in range(n)]
    getTime = [[0] * n for i in range(n)]
    eat = []
    visit[coorX][coorY] = 1
    dq = deque()
    dq.append([coorX,coorY])
    
    while len(dq) > 0 :
        # print(dq)
        x,y = dq.popleft()
        
        for i in range(4) :
            cx = x + goX[i]
            cy = y + goY[i]
            if 0<= cx<n and 0<=cy<n :
                if field[cx][cy] <= cursize and visit[cx][cy] != 1:
                    visit[cx][cy] = 1
                    getTime[cx][cy] = getTime[x][y] + 1
                    dq.append([cx,cy])
                    if 0 < field[cx][cy] < cursize :
                        eat.append([cx,cy,getTime[cx][cy]])

    if len(eat) == 0 :
        return -1, -1, -1
    eat.sort(key = lambda x : (x[2],x[0],x[1]))
    field[eat[0][0]][eat[0][1]] = 0
    return eat[0][0], eat[0][1], eat[0][2]


field = []
current = []
sz = 2
cnt = 0
for i in range(n) :
    fieldMini = list(map(int,input().split()))
    field.append(fieldMini)
    for j in range(n) :
        if fieldMini[j] == 9 :
            current.append(i)
            current.append(j)
            field[i][j] = 0

goX = [0,-1,0,1]  ## 좌상우하
goY = [-1,0,1,0]

time = 0
while True :
    if cnt == sz :
        cnt =0
        sz +=1
    cx, cy, ctime = bfs(current[0],current[1],sz)
    # print(sz,cnt)
    # print(cx, cy, ctime)
    # print(field[0][3])
    if cx < 0 :
        break
    time += ctime
    cnt +=1 
    current[0] = cx
    current[1] = cy

print(time)
        

'''
# def getTime(sz) :

n = int(input())
size = 2
field,exceptZero = [],[]

coor = []
for i in range(n) :
    fieldMini = list(map(int,input().split()))
    field.append(fieldMini)
    if 9 in fieldMini :
        coor.append(i)
        coor.append(fieldMini.index(9))
    # box = [x for x in fieldMini if x > 0]
    # box.sort()
    # exceptZero.append(box)

print(field)
# print(exceptZero)
print(coor)

coorFish = [[],[],[],[],[],[]]
for i in range(n) :
    for j in range(n) :
        if field[i][j] > 0 and field[i][j] != 9:
            coorFish[field[i][j]-1].append([i,j])

print(coorFish)
timeLi = []
# time,cnt = 0,0
# while(True) :
#     coorFish = []
#     for i in range(n) :
#         if len(exceptZero[i]) > 0 :
#             if min(exceptZero[i]) < size :
#                 coorFish.append(i)
    
'''