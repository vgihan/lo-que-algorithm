n, m = map(int,input().split())
arr,numLi = [],[]

for i in range(n) :
    arrStr = input()
    arr.append(arrStr)
    numLi.append(arrStr.count('1'))

box = [[]*n for i in range(n)]

for i in range(n) :
    checkStr  = '11'
    if numLi[i] > 1 :
        while checkStr in arr[i] :
            box[i].append(arr[i].index(checkStr))
            checkStr += '1'

print(arr)
print(numLi)
print(box)