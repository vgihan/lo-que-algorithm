n, p = map(int,input().split())
melody = []
for i in range(n) :
    melody.append(list(map(int,input().split())))
## 입력
flat = [] 
## 비교 배열
cnt,d = 0,0
## 손가락 움직임 입력중에서 현재 순서
for i in melody :
    if i not in flat :   ## 눌려져 있지 않다면 누르고 카운트
        flat.append(i)
        cnt += 1
    box = []
    for j in range(d-1,-1,-1) :
        if melody[j][0] == i[0] and melody[j][1] <= i[1] :
            break
        if melody[j][0] == i[0] and melody[j][1] > i[1] and melody[j] not in box: ## box는 중복방지
            cnt += 1
            box.append(melody[j])
    
    d+=1

print(flat)
print(cnt)