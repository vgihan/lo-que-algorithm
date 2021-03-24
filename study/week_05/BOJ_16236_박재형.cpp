#include <iostream>

using namespace std;

int N;
int water[20][20];	// �ʵ尪
int sec = 0;		// ���ʰ� �ɸ��� �� ī��Ʈ�ϱ����� ����
int f_size = 2;		// �Ʊ����� �ʱ� ��ũ��� 2
bool nofish;		// �࿭�� ��� Ž������ �� ���� �� �ִ� ������� ���� �Ǵ�
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
		if (check[next_r][next_c]) //�̹� Ž���� �����̶�� Ž������ �ʴ´�.
			continue;
		
		
		if (water[next_r][next_c] > baby_size)
			//���� ����� ����Ⱑ �Ʊ���� Ŭ ��
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
			check[next_r][next_c] = false;	// �ٸ� Ž���� ���ص��� �ʵ��� �ٽ� false�� �ٲ���
		}
		// ���� ��ΰ� ����ְų� ������� ũ��� ���ũ�Ⱑ ������ �̵�����
		else
			// ���� �� �ִ� ����⸦ ã�� ���ۿ� ���� ����
			// �� ��쿡�� mindistance���� ã�����̹Ƿ� cnt�� Ȯ��
		{
			cnt++;
			if (minDistance > cnt)
			{
				minDistance = cnt;
				minDfish.r = next_r;
				minDfish.c = next_c;
			}
			else if (minDistance == cnt) //���� ��츦 �������־�� ��
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
	wherebabyfish();	// �Ʊ�� ó�� ��� �ִ��� ��ġȮ��
	nofish = true;
	minDistance = 400;

	while (1)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (water[i][j]>0 && water[i][j] < f_size && water[i][j] != 9) // �Ʊ����� ��ġ�� ����x
				{
					nofish = false;
					fishcnt++;
				}
		if (nofish)
			break;
		search_minDistance(babyfish.r, babyfish.c, f_size, 0, 0);
		// �������Ǳ��� �����ϴ� �ּҰŸ��� ���������� �Ÿ�, ��ġ�ľ�
		if (minDistance == 400)
		{
			minDistance = 0;
			break;
		}
	
		babyfish.r = minDfish.r;
		babyfish.c = minDfish.c;
		// �Ʊ����� ��ġ�� ���� ������� ��ġ�� �缳��
		eatingcnt += water[minDfish.r][minDfish.c];
		// �� �����԰� eatingcnt ������
		water[minDfish.r][minDfish.c] = 9;
		
		if (eatingcnt >= f_size)
		{
			eatingcnt = eatingcnt - f_size;
			f_size++; // �Ʊ��� ������ �ϳ� ����
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