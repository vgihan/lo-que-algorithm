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
void find(void)											//�Ʊ� ��� ã��
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
void bfs(int fish, int xx, int yy)			//x,y�� ȥ������ �ʰ��ϱ����� xx yy ���
{
	if (visited[xx][yy] == true)	return;
	visited[xx][yy] = true;
	int rx = 0;
	int ry = 0;
	
	for (int i = 0; i < 4; i++) {
		rx = bx[i] + xx;									//4���� Ž��
		ry = by[i] + yy;
		if (rx<0 || rx>N || ry<0 || ry>N)	continue;	//Ž������ �ε��� �ʰ� ����
		if (space[rx][ry] > fish)			continue;	//��⺸�� ū ��� ���ư���
		if (space[rx][ry] < fish&& space[rx][ry]>0) {						//���հ�
			feedcnt++;									//���� ī��Ʈ
			cnt += abs(rx - x) + abs(ry - y);			//�Ÿ�����
			//cout << cnt<<endl;
			x = rx;										//ã�� ��� ���������� �̵�
			y = ry;
		}
		if (feedcnt == fish) {							//���̸� �ٸ��� ��� ũ�Ⱑ Ŀ��ä�� Ž��	
			fish++;
			feedcnt = 0;
		}
		bfs(fish, rx, ry);								//���̸� �� ���� ������ ��� �ٽ� ���� Ž�� ��
	
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