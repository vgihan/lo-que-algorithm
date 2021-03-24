#include <iostream>

using namespace std;

int N;
int water[20][20];	// 필드값
int sec = 0;		// 몇초가 걸리는 지 카운트하기위한 변수
int f_size = 2;		// 아기상어의 초기 몸크기는 2
bool nofish;		// 행열을 모두 탐색했을 때 먹을 수 있는 물고기의 유무 판단
int eatingcnt;
int minDistance;
bool check[20][20];
int fishcnt = 0;

struct RandC
{
	int r, c;
};

RandC babyfish;
RandC minDfish;
RandC fish[400];

//void search_upright(int row, int column )
//{
//	int dr[] = { -1, 0 };
//	int dc[] = { 0, 1 };
//
//	for (int i = 0; i < 2; i++)
//	{
//		int next_r = row + dr[i];
//		int next_c = column + dc[i];
//
//		if (next_r<0 || next_r > N - 1 || next_c<0 || next_c > N - 1)
//			continue;
//		if(water[next_r][next_c])
//
//	}
//	
//}
//
//void search_upleft()
//{
//}
//
//void search_downright()
//{
//}
//
//void search_downleft()
//{
//}

void wherebabyfish()
{
	bool find = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (water[i][j] == 9)
			{
				babyfish.r = i;
				babyfish.c = j;
				find = true;
				break;
			}
		}
		if (find)
			break;
	}
}

void search_minDistance(int r, int c, int baby_size, int cnt, int depth)
{
	if (depth == 0)
		check[r][c] = true;

	int dr[] = { 1, -1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };

	for (int i = 0; i < 4; i++)
	{
		int next_r = r + dr[i];
		int next_c = c + dc[i];

		if (next_r<0 || next_r > N - 1 || next_c<0 || next_c > N - 1)
			continue;
		if (check[next_r][next_c]) //이미 탐색한 지점이라면 탐색하지 않는다.
			continue;
		
		
		if (water[next_r][next_c] > baby_size)
			//다음 경로의 물고기가 아기상어보다 클 때
		/*{
			if (i != 3)
				continue;
			else
				break;
		}*/
			continue;

		else if (water[next_r][next_c] == 0 || water[next_r][next_c] == baby_size)
		{
			check[next_r][next_c] = true;
			search_minDistance(next_r, next_c, baby_size, cnt+1, depth+1);
			check[next_r][next_c] = false;	// 다른 탐색에 방해되지 않도록 다시 false로 바꿔줌
		}
		// 다음 경로가 비어있거나 물고기의 크기와 상어크기가 같으면 이동가능
		else
			// 먹을 수 있는 물고기를 찾는 경우밖에 남지 않음
			// 이 경우에는 mindistance값을 찾은것이므로 cnt값 확인
		{
			cnt++;
			if (minDistance > cnt)
			{
				minDistance = cnt;
				minDfish.r = next_r;
				minDfish.c = next_c;
			}
			else if (minDistance == cnt) //같을 경우를 설정해주어야 함
			{
				if (minDfish.r > next_r)
				{
					minDistance = cnt;
					minDfish.r = next_r;
					minDfish.c = next_c;
				}
				else if (minDfish.r == next_r)
				{
					if (minDfish.c > next_c)
					{
						minDistance = cnt;
						minDfish.r = next_r;
						minDfish.c = next_c;
					}
				}
			}
			return;
		}
	}
	check[r][c] = false;
	return;
}

void input()		
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> water[i][j];
}

void solve()
{
	wherebabyfish();	// 아기상어가 처음 어디에 있는지 위치확인
	nofish = true;
	minDistance = 400;

	while (1)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (water[i][j]>0 && water[i][j] < f_size && water[i][j] != 9) // 아기상어의 위치는 생각x
				{
					nofish = false;
					fishcnt++;
				}
		if (nofish)
			break;
		search_minDistance(babyfish.r, babyfish.c, f_size, 0, 0);
		// 세부조건까지 만족하는 최소거리의 물고기까지의 거리, 위치파악
		if (minDistance == 400)
		{
			minDistance = 0;
			break;
		}
	
		babyfish.r = minDfish.r;
		babyfish.c = minDfish.c;
		// 아기상어의 위치는 먹은 물고기의 위치로 재설정
		eatingcnt += water[minDfish.r][minDfish.c];
		// 그 물고기먹고 eatingcnt 더해줌
		water[minDfish.r][minDfish.c] = 9;
		
		if (eatingcnt >= f_size)
		{
			eatingcnt = eatingcnt - f_size;
			f_size++; // 아기상어 사이즈 하나 증가
		}
		sec += minDistance;
	}
}

void output()
{
	cout << sec << endl;
}


int main()
{
	input();
	solve();
	output();

	return 0;
}