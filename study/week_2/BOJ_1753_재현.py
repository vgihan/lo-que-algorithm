def sol(i) :
    global answer 
    for k in range(len(container[i])) :
        if i == start - 1 :
            answer[container[i][k][1]-1] = min(container[i][k][2], answer[container[i][k][1]-1])         
            ## 참인 경우 해당 배열 위치의 기존 값과 현재 비용 비교후 입력   거짓인 경우 해당 배열 위치의 기존 값과 현재 비용 플러스 현재 출발 위치에 해당하는 정답 배열 위치의 값을 던한 값 비교
        else :
            answer[container[i][k][1]-1] = min(container[i][k][2] + answer[container[i][k][0]-1], answer[container[i][k][1]-1])
        sol(container[i][k][1]-1) 



v, e = map(int,input().split())
start = int(input())
cost = []
container = [[]*v for i in range(v)]                ### 2차원 배열로 도시 개수만큼 만들어주기

for i in range(e) :
    costMini = list(map(int,input().split()))
    cost.append(costMini)                           ### 입력받은거 배열에 넣어주고
    container[costMini[0]-1].append(costMini)       ### 출발지 기준으로 분류

# print(container)

answer = [10**7 *v for i in range(v)]               ### 최솟값 비교를 위해서 처음에 도시 만큼 큰 수 넣어주기

i =start - 1                                        ### 처음 배열 인덱스를 시작 도시로 주기
answer[i] = 0                                       ### 시작 도시는 0


sol(i)                                              ### 함수
# print(answer)
for k in answer :
    if k < 50000000 :                               ### 수보다 넘으면 INF 출력 아니면 해당 배열 값 출력
        print(k)
    else :
        print("INF")

