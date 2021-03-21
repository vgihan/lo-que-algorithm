#include <iostream>
#include <algorithm>

using namespace std;

int N;
int p_Score[51][10];
int maxScore = 0;
int score;
int outcnt;
int p_Order[10];
int order[10];
bool BASE[4];

enum hitting
{
    OUT,
    SINGLE,
    DOUBLE,
    TRIPLE,
    HOMERUN,
};
void gamestart()
{
    int start = 1; 
    score = 0;
    for (int inning = 1; inning <= N; inning++) 
    {
        outcnt = 0;
        while (1) 
        {
            for (int i = start; i <= 9; i++) 
            {
                int hit = p_Score[inning][p_Order[i]];

                switch (hit)
                {
                    case OUT:  //아웃일 때
                        outcnt++;
                        break;
                    case SINGLE:   // 안타일 때
                        if (BASE[3] == true)
                        {
                            BASE[3] = 0;
                            score++;
                        }
                        for (int i = 3; i > 1; i--)
                        {
                            if (BASE[i - 1] == true)
                            {
                                BASE[i] = true;
                                BASE[i - 1] = false;
                            }
                        }
                        BASE[1] = 1;
                        break;
                    case DOUBLE:   // 2루타일때
                        if (BASE[3] == true)
                        {
                            BASE[3] = false;
                            score++;
                        }
                        if (BASE[2] == true)
                        {
                            BASE[2] = false;
                            score++;
                        }
                        if (BASE[1] == true)
                        {
                            BASE[1] = false;
                            BASE[3] = true;
                        }
                        BASE[2] = true;
                        break;
                    case TRIPLE:   //3루타일때
                        for (int i = 1; i <= 3; i++)
                        {
                            if (BASE[i] == 1) {
                                BASE[i] = 0;
                                score++;
                            }
                        }
                        BASE[3] = 1;
                        break;
                    case HOMERUN:  //홈런일때
                        for (int i = 1; i <= 3; i++)
                        {
                            if (BASE[i] == 1)
                            {
                                BASE[i] = 0;
                                score++;
                            }
                        }
                        score++;    // 홈런친사람도 바로 점수로 연결되므로
                }

                if (outcnt == 3) //3아웃이 되면
                {
                    if (i + 1 > 10)
                        start = 1;
                    else
                        start = i + 1;

                    for (int i = 1; i <= 3; i++)
                        BASE[i] = 0;
                   
                    break;
                }
            }
            if (outcnt == 3)
                break;
            start = 1;
        }
    }
}

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++)
		{
			cin >> p_Score[i][j];
		}
}

void solve()
{
	do
	{
		int cnt = 1;
		for (int i = 0; i < 8; i++) 
		{
			if (cnt != 4)
				p_Order[cnt] = order[i];
			else 
			{
				cnt++;
				p_Order[cnt] = order[i];
			}
			cnt++;
		}
		gamestart();
		maxScore = max(maxScore, score);
	} while (next_permutation(order,order+8));

}

void output()
{
	cout << maxScore << endl;
}

int main()
{
    for (int i = 0; i < 8; i++) //2번타자부터 9번타자까지의 번호 저장
        order[i] = i + 2;       // (위에서next_permutation을 써주기 위해)
    
	input();
    p_Order[4] = 1;
	solve();
	output();

	return 0;
}
