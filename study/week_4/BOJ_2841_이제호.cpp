#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[7];	//���� ���� �����̹Ƿ� pair ���� 1���� ���
int N, P;
int line, pret, cnt = 0;

void inputpriority(void)
{
    for (int i = 0; i < N; i++)
    {
        cin >> line >> pret;
        sort(v[line].begin(), v[line].end());

        while (!v[line].empty() && v[line].back() > pret)  {    //��������ʰ� ���� �Էµ� ������ ���������� ������ ���� ���� �� �� ����
            v[line].pop_back();                                
            cnt++;                                              //�հ����� �����ϹǷ� 1�� ī��Ʈ
        }
        if (!v[line].empty() && v[line].back() == pret) continue; //������� �ʰ� ���ٸ� �����ϸ� �ǹǷ� ī��Ʈ ���� �ݺ������� ���ư�

        v[line].push_back(pret);                                //���� �ʴٸ� ���� ������ ȥ�� ���� ū���̹Ƿ� �հ��� ƨ��鼭 ī��Ʈ 1 �߰�                    
        cnt++;
    }
    
    
}

int main(void)
{
    cin >> N >> P;
    inputpriority();
    cout << cnt<<endl;
}