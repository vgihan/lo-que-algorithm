#include <iostream>

using namespace std;

int N;
int player[51][10];
bool selected[10];
int order[10];
bool base[7];
int score = 0; 
int bigscore = 0;

void basefun(int shot);
void permutation(int pos);	//타순 브루트 포스
void input(void);
void game(void);

void input(void)
{
	cin >> N;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= 9; j++) 
			cin >> player[i][j];
}

void basefun(int shot)
{
	if (shot == 4) {
		int cnt = 1;
		for (int j = 1; j < 3; j++) {		//1~3루에 주자가있으면 점수 플러스
			if (base[j]) cnt++;
		}
		score += cnt;
		return;
	}
	base[0] = true;							//홈주자 생각
	for (int i = 3; i >=0; i--) {			//역순으로 안하면 물고 물고 올라감
		if (base[i] && i + shot > 3) {
			score++;
			base[i] = false;
			continue;
		}	
		base[i + shot] = base[i];			//안타 결과만큼 옮겨줌
		base[i] = 0;						//원래 자리는 지움
	}

}

void permutation(int pos)
{
	if (pos == 9) {
		game();							//한번 정렬될때마다 게임 실행
		return;
	}
											//순열 끝
	for (int i = 1; i <= 9; i++) {
		if (selected[i] == true)	continue;		//이미 i번째 타순이 있으면 다음 타순을 확인함
		selected[i] = true;						//조건문 통과시 타순 저장 체크
		order[i] = pos;								//타순(i)에 몇번 선수(pos)가 들어오는지 체크	
		permutation(pos + 1);						//i가 증가하기전에 다음 타순 체크하러감
		selected[i] = false;
	}
}

void game(void)
{
	int j = 0;
	for (int i = 0; i < N; i++) {
		int out = 0;
		int ining = 0;
		ining++;
		for (i = 0; i < 4; i++) base[i] = false;	//이닝이 끝날때마다 베이스 초기화
		while (out < 3) {
			j++;									//1부터 시작하도록 위로 배치 + 한번 돌 때마다 다음 타자
			j = j % 10;								//9번타자가 넘어가면 다시 1번타자로 돌아감
			int shot = player[ining][order[j]];
			switch (shot)
			{
				case 0:
					out++;
					break;
				case 1:
					basefun(1);
					break;
				case 2:
					basefun(2);
					break;
				case 3:
					basefun(4);
					break;
				case 4:
					basefun(4);
					break;
			}
		}
	}
	if (bigscore < score)	bigscore = score;//경기가 다 끝날때 점수 비교 후 큰 값 저장
	score = 0;
}

int main(void)
{
	input();
	selected[4] = true;		//4번 타자는 제외
	order[4] = 1;				//4번타자는 1번 자리에 들어감
	permutation(2);
	cout << bigscore;
}