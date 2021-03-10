#include <iostream>

using namespace std;

int n;
int arr[100][100];
bool visited[101][101];
int cnt = 0;
int bigh = 0;
int big = 0;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


void area(int i, int j, int h);

void init_visit(int n)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0 ; j < n; j++) 
		{
			visited[i][j] = false;
		}
	}
}

void input(int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
}
void maxarea(int n)
{
	int h = 0;					//���� ���� ����	
	
	while (h<101)			
	{
		
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				if (visited[i][j] == 0 && arr[i][j] > h) //�湮�ϰų� ���� ����
				{
					area(i, j, h);
					cnt++;	
					//cout << cnt << endl;//���⼭ �ϳ� ȣ�� �ɶ����� �ѵ�� ã��
				}
			}
				
		}
		if (big <= cnt) 
		{
			big = cnt;		//���� ����� ���� ��
			bigh = h;		//���� ����� ������ h ���
		}
		
		//cout << h << "!!" << cnt << bigh<<endl;
		h++;
		cnt = 0;
		init_visit(n);
	}
	if (bigh == 0)
	{					
		bigh = 1;		//�� �ȿö� �⺻������ 1�̹Ƿ�
	}
	
}
void area(int a, int b,int h)
{
	int temp = h;
	visited[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = a + dx[i];
		int ny = b + dy[i];
	
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
		{
			// ���̸鼭 �湮���� �ʾҴٸ� -> �湮
			if (arr[nx][ny] >h && visited[nx][ny] == false) 
			{
				visited[nx][ny] = true;
				area(nx, ny, temp);
			}
    
		}
	}
	/*if(0<=b+1&&b+1<n)
		if (arr[a][b + 1] > h&&visited[a][b+1]==false)
		{
			visited[a][b + 1];
			area(a, b + 1, temp);
		}
	if (0 <= a + 1 && a + 1 < n)
		if (arr[a + 1][b] > h && visited[a+1][b] == false)
		{
			visited[a + 1][b];
			area(a + 1, b, temp);
		}*/
	
}

int main(void)
{
	cin >> n;
	input(n);
	init_visit(n);
	maxarea(n);
	
	//cout << big << endl;
	cout << bigh;
}