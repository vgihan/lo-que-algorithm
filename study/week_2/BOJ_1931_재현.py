n = int(input())
time = []
  
for i in range(n) :                       ####  입력
    a = list(map(int,input().split()))
    time.append(a)
time.sort()                               ### 먼저 시작시간으로 정렬
time.sort(key = lambda x:x[1])            ### 종료 시간 기준으로 정렬
answer = []
# print(time)

answer.append(time[0])                    ### 시작은 처음이니까 배열에 넣어주고
for i in range(1,len(time)) :             ### 베얼 1부터 시작해서
    if answer[-1][1] <= time[i][0] :      ### 현재 시작시간이 전 끝나는 시간보다 뒤이거나 같으면 배열에 추가
        answer.append(time[i])
# print(answer)
print(len(answer))
