#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[7];	//줄의 수는 고정이므로 pair 말고 1차로 계산
int N, P;
int line, pret, cnt = 0;

void inputpriority(void)
{
    for (int i = 0; i < N; i++)
    {
        cin >> line >> pret;
        sort(v[line].begin(), v[line].end());

        while (!v[line].empty() && v[line].back() > pret)  {    //비어있지않고 현재 입력된 프렛이 오름차순의 마지막 값의 끝이 될 때 까지
            v[line].pop_back();                                
            cnt++;                                              //손가락을 떼야하므로 1씩 카운트
        }
        if (!v[line].empty() && v[line].back() == pret) continue; //비어있지 않고 갔다면 재사용하면 되므로 카운트 없이 반복문으로 돌아감

        v[line].push_back(pret);                                //같지 않다면 현재 프렛은 혼자 가장 큰값이므로 손가락 튕기면서 카운트 1 추가                    
        cnt++;
    }
    
    
}

int main(void)
{
    cin >> N >> P;
    inputpriority();
    cout << cnt<<endl;
}