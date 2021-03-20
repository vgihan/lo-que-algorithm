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
void permutation(int pos);	//Ÿ�� ���Ʈ ����
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
		for (int j = 1; j < 3; j++) {		//1~3�翡 ���ڰ������� ���� �÷���
			if (base[j]) cnt++;
		}
		score += cnt;
		return;
	}
	base[0] = true;							//Ȩ���� ����
	for (int i = 3; i >=0; i--) {			//�������� ���ϸ� ���� ���� �ö�
		if (base[i] && i + shot > 3) {
			score++;
			base[i] = false;
			continue;
		}	
		base[i + shot] = base[i];			//��Ÿ �����ŭ �Ű���
		base[i] = 0;						//���� �ڸ��� ����
	}

}

void permutation(int pos)
{
	if (pos == 9) {
		game();							//�ѹ� ���ĵɶ����� ���� ����
		return;
	}
											//���� ��
	for (int i = 1; i <= 9; i++) {
		if (selected[i] == true)	continue;		//�̹� i��° Ÿ���� ������ ���� Ÿ���� Ȯ����
		selected[i] = true;						//���ǹ� ����� Ÿ�� ���� üũ
		order[i] = pos;								//Ÿ��(i)�� ��� ����(pos)�� �������� üũ	
		permutation(pos + 1);						//i�� �����ϱ����� ���� Ÿ�� üũ�Ϸ���
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
		for (i = 0; i < 4; i++) base[i] = false;	//�̴��� ���������� ���̽� �ʱ�ȭ
		while (out < 3) {
			j++;									//1���� �����ϵ��� ���� ��ġ + �ѹ� �� ������ ���� Ÿ��
			j = j % 10;								//9��Ÿ�ڰ� �Ѿ�� �ٽ� 1��Ÿ�ڷ� ���ư�
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
	if (bigscore < score)	bigscore = score;//��Ⱑ �� ������ ���� �� �� ū �� ����
	score = 0;
}

int main(void)
{
	input();
	selected[4] = true;		//4�� Ÿ�ڴ� ����
	order[4] = 1;				//4��Ÿ�ڴ� 1�� �ڸ��� ��
	permutation(2);
	cout << bigscore;
}