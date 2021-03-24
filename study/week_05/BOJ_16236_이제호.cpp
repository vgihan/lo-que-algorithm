#include <iostream>


using namespace std;

int rcnt = 0;
int space[21][21];
int visited[21][21];
int N;
int x, y;
int cnt = 0;
int feedcnt = 0;
int bx[4] = { 0, -1, 1, 0 };
int by[4] = { -1, 0, 0, 1 };

void input(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> space[i][j];
}
void find(void)											//아기 상어 찾기
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (space[i][j] == 9) {
				x = i;
				y = j;
				return;
			}

}
void bfs(int fish, int xx, int yy)			//x,y와 혼동되지 않게하기위해 xx yy 사용
{
	if (visited[xx][yy] == true)	return;
	visited[xx][yy] = true;
	int rx = 0;
	int ry = 0;
	
	for (int i = 0; i < 4; i++) {
		rx = bx[i] + xx;									//4방향 탐색
		ry = by[i] + yy;
		if (rx<0 || rx>N || ry<0 || ry>N)	continue;	//탐색지에 인덱스 초과 방지
		if (space[rx][ry] > fish)			continue;	//고기보다 큰 경우 돌아가기
		if (space[rx][ry] < fish&& space[rx][ry]>0) {						//먹잇감
			feedcnt++;									//먹이 카운트
			cnt += abs(rx - x) + abs(ry - y);			//거리측정
			//cout << cnt<<endl;
			x = rx;										//찾은 경우 그지점으로 이동
			y = ry;
		}
		if (feedcnt == fish) {							//먹이를 다먹은 경우 크기가 커진채로 탐색	
			fish++;
			feedcnt = 0;
		}
		bfs(fish, rx, ry);								//먹이를 다 먹지 못했을 경우 다시 넓이 탐색 들어감
	
	}
}

int main(void)
{
	find();
	input();
	int fish = 2;
	bfs(fish, x, y);
	cout << cnt;
}