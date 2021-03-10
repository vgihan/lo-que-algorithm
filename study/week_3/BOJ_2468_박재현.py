import copy

def sol() :
    countOfSafety = []
    count = 0
    for i in range(n) :
        for k in range(len(safety)) :
            countOfSafety.append([i,safety[i][k]])
            if not([i,safety[i][k]+1] in countOfSafety or [i,safety[i][k]-1] in countOfSafety or [i-1,safety[i][k]] in countOfSafety or [i+1,safety[i][k]] in countOfSafety) :
                count += 1
    return count
            

n = int(input())
section = []
sectionMin, sectionMax = 101,0
for i in range(n) :
    sectionMini = list(map(int,input().split()))
    section.append(sectionMini)
    if min(sectionMini) <= sectionMin :    
        sectionMin = min(sectionMini)
    if max(sectionMini) >= sectionMax :
        sectionMax = max(sectionMini)

safety = [[i for i in range(n)] for k in range(n) ]
# flag = [[0 for i in range(n)] for k in range(n) ]
maxCnt = 0
# print(safety)
# print(sectionMin)
# print(sectionMax)
for i in range(sectionMin,sectionMax+1) :
    for k in range(n) :
        x=0
        for z in range(len(safety[k])) :
            if section[k][safety[k][x]] <= i :
                del safety[k][x]
            else :
                x += 1
    #     for z in safety[k] :
    #         flag[k][z] = 1
    # arr = copy.deepcopy(flag)                
    cnt = sol()
    if cnt == 0 :
        break
    maxcnt = max(maxcnt,cnt)
# print(safety)
# print(flag)
print(maxcnt)

# import copy

# def sol(count) :
#     global arr
#     while len(arr) > 0 :
#         while len(arr[0]) > 0 :
#             delete(0,arr[0][0],1)
#             count += 1
#             del arr[0][0]
            
#         if len(arr[0]) == 0 :
#             del arr[0]
#     return count

# def delete(a,b,c) :    ##  영역 나누기만 하면 됨
#     global arr
    
#     if c == 0 :
#         if b in arr[a-1] :
#             delete(a-1,b,1)
#             delete(a-1,b,3)
#             if a-1 != 0 :
#                 delete(a-1,b,0)
#             arr[a-1].remove(b)
#     elif c == 1 :
#         if b + 1 in arr[a] :
#             delete(a,b+1,1)
#             if len(arr) != 0 :
#                 delete(a,b+1,2)
#             if a != 0 :
#                 delete(a,b+1,0)
#             arr[a].remove(b+1)
#     elif c == 2 :
#         if b in arr[a+1] :
#             delete(a+1,b,1)
#             delete(a+1,b,3)
#             if a+1 != len(arr)-1 :
#                 delete(a+1,b,2)
#             arr[a+1].remove(b)
#     else : 
#         if b - 1 in arr[a] :
#             delete(a,b-1,3)
#             if len(arr) != 0 :
#                 delete(a,b-1,2)
#             if a != 0 :
#                 delete(a,b-1,0)
#             arr[a].remove(b-1)

#     print(arr)
# n = int(input())
# section = []
# for i in range(n) :
#     section.append(list(map(int,input().split())))

# safety = [[i for i in range(n)] for k in range(n) ]
# maxCnt = 0
# # for i in range(1,101) :
# #     for k in range(n) :
# #         x=0
# #         for z in range(len(safety[k])) :
# #             if section[k][safety[k][x]] <= i :
# #                 del safety[k][x]
# #             else :
# #                 x += 1
# #     arr = copy.deepcopy(safety)                
# #     cnt = sol(0)
# #     if cnt == 0 :
# #         break
# #     maxcnt = max(maxCnt,cnt)
    
# i =4
# for k in range(n) :
#     x=0
#     for z in range(len(safety[k])) :
#         if section[k][safety[k][x]] <= i :
#             del safety[k][x]
#         else :
#             x += 1
# arr = copy.deepcopy(safety)
# cnt = sol(0)

# print('-----------')
# print(safety)
# print(cnt)