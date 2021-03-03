#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int earliest = 0;
int cnt = 0;

struct timetable
{
	int start, end;
};

struct timetable table[100000];

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> table[i].start >> table[i].end;
	}
}

int cmp(timetable a, timetable b) //����ü�� �����ϴ� ��, ��� end �� ���� ���������ϰ�
{								  //�� ���� start �� �������� ��
	if (a.end == b.end) 
		return a.start < b.start;
	return a.end < b.end;
}

//void search(int cnt, int start)
//{
//	int check=0;
//	for (int i = ; i < N; i++)
//	{
//		if (table[i].start >= start)
//		{
//			search(cnt + 1, table[i].end);
//			check++;
//		}
//	}
//	if (check == 0)
//	{
//		maxcnt = max(maxcnt, cnt);
//		return;
//	}
//}

//void search(int cnt, int next_start, int start)
//{
//	int earliest_End = 987654321;
//	int endcheck = 0;
//
//	for (int i = start; i < N; i++)
//	{
//		if (next_start <= table[i].start)
//		{
//			start = i;
//			endcheck++;
//			break;
//		}
//	}
//	if (endcheck == 0)
//	{
//		maxcnt = cnt;
//		return;
//	}
//	for (int i = start; i < N; i++)
//	{
//		if (table[i].end < earliest_End)
//		{
//			earliest_End = table[i].end;
//			next_start = table[i].end;
//		}
//	}
//	search(cnt+1, next_start, start);
//}




void solve()
{
	sort(table, table + N, cmp); // ����ü ����

	for (int i = 0; i < N; i++)
	{
		cout << table[i].start << " " << table[i].end << endl;
	}

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cnt++;
			earliest = table[i].end; // ���� ���� ������ ȸ�� ������ ī������ ���ָ� ��
		}							 // �������� ������ ���־��� ������ ����
		else {
			if (table[i].start >=earliest) {
				cnt++;
				earliest = table[i].end;
			}
		}
	}
}


void output()
{
	printf("%d", cnt);
}

int main()
{
	input();
	solve();
	output();

	return 0;
}