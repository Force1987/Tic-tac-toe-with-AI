#include <iostream>
using namespace std;
#include<windows.h>
#include <ctime>

void results(int win, int lose)
{
	cout << "Ñ÷¸ò " << win << " : " << lose;
	if (win > lose)cout << " â ïîëüçó ÈÃÐÎÊÀ\n";
	else if (win < lose)cout << " â ïîëüçó ÊÎÌÏÜÞÒÅÐÀ\n";
	else cout << " ðàâíûé.\n";
}

void draw(char arr[3][3])
{
	system("cls");
	cout << " ÊÐÅÑÒÈÊÈ-ÍÎËÈÊÈ\n\n     0  1  2" << endl;
	for (short i = 0; i < 3; i++)
	{
		cout << "   " << i;
		for (short j = 0; j < 3; j++)
			cout << char(124) << " " << char(124);
		cout << endl << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	char arr[3][3]{};
	bool ai, zero;
	int win = 0, lose = 0;
	short ch = 0, cv = 0, cd = 0, cr = 0, bh = -1, bhr = -1, bv = -1, bvr = -1, bd = -1, br = -1, checkh = -1, checkv = -1, iwinh = -1, iwinv = -1, a, b, res;
	draw(arr);
	system("pause");
	while (true) {
		res = 0;
		draw(arr);
		cout << "Áðîñàåì æðåáèé\n";
		ai = rand() % 2;
		Sleep(1000);
		if (ai == true) cout << "Ïåðâûì õîäèò ÊÎÌÏÜÞÒÅÐ";
		else cout << "Ïåðâûì õîäèò ÈÃÐÎÊ";
		cout << endl;
		Sleep(1000);
		while (true)
		{

			zero = false;
			ch = 0, cv = 0, cd = 0, cr = 0;
			if (ai == true)
			{
				checkh = -1, checkv = -1, iwinh = -1, iwinv = -1; bh = -1, bhr = -1, bv = -1, bvr = -1, bd = -1, br = -1;
			}
			system("cls");
			cout << " ÊÐÅÑÒÈÊÈ-ÍÎËÈÊÈ\n\n     0  1  2" << endl;
			for (short i = 0; i < 3; i++)
			{
				cout << "   " << i;
				if (i != 0 && res == 0)
				{
					ch = 0;
					cv = 0;
				}
				for (short j = 0; j < 3; j++)
				{
					cout << char(124);
					if (arr[i][j] != 0)
					{
						cout << arr[i][j];
					}
					else
					{
						cout << " ";
						zero = true;
					}
					cout << char(124);
					if (i == 0 && res == 0)
					{
						if (arr[i][j] == 'X')ch++;
						if (arr[i][j] == 'O')ch--;
						if (arr[i][j] == 0) bh = j;
						if (arr[j][i] == 'X')cv++;
						if (arr[j][i] == 'O')cv--;
						if (arr[j][i] == 0)bv = j;
						if (arr[j][j] == 'X')cd++;
						if (arr[j][j] == 'O')cd--;
						if (arr[j][j] == 0)bd = j;
						if (arr[j][2 - j] == 'X')cr++;
						if (arr[j][2 - j] == 'O')cr--;
						if (arr[j][2 - j] == 0)br = j;
						if (j == 2) {
							if (ch == 3) res = 1;
							if (ch == -3) res = 2;
							if (cv == 3) res = 1;
							if (cv == -3) res = 2;
							if (cd == 3) res = 1;
							if (cd == -3) res = 2;
							if (cr == 3) res = 1;
							if (cr == -3) res = 2;
							if (ai == true && arr[1][1] != 0 && res == 0)
							{
								if (ch == 2) checkh = i;
								if (ch == -2) iwinh = i;
								if (cv == 2) checkv = i;
								if (cv == -2) iwinv = i;
							}
						}
					}
					else if (res == 0)
					{
						if (arr[i][j] == 'X')ch++;
						if (arr[i][j] == 'O')ch--;
						if (arr[j][i] == 'X')cv++;
						if (arr[j][i] == 'O')cv--;
						if (iwinh < 0 && iwinv < 0)
						{
							if (arr[i][j] == 0) if (checkh < 0)bh = j; else bhr = j;
							if (arr[j][i] == 0) if (checkv < 0)bv = j; else bvr = j;
						}
						if (j == 2)
						{
							if (ch == 3) res = 1;
							if (ch == -3) res = 2;
							if (cv == 3) res = 1;
							if (cv == -3) res = 2;
							if (ai == true && arr[1][1] != 0 && res == 0 && iwinh < 0 && iwinv < 0)
							{
								if (ch == -2) { iwinh = i; if (checkh > 0)bh = bhr; }
								if (cv == -2) { iwinv = i; if (checkv > 0)bv = bvr; }
								if (ch == 2 && checkh < 0 && iwinh < 0 && iwinv < 0) checkh = i;
								if (cv == 2 && checkv < 0 && iwinh < 0 && iwinv < 0) checkv = i;
							}
						}
					}
				}
				cout << endl << endl;
			}
			if (zero == false && res == 0)res = 3;
			if (res > 0)
			{
				if (res == 1)
				{
					cout << "Òû ïîáåäèë\n";
					win++;
					results(win, lose);
				}
				else if (res == 2)
				{
					cout << "Ïîáåäèë êîìïüþòåð\n";
					lose++;
					results(win, lose);
				}
				else if (res == 3)
				{
					cout << "Íè÷üÿ\n";
					results(win, lose);
				}
				break;
			}
			if (ai == false)
			{
				do {
					cout << "Ââåäèòå àäðåñ êëåòêè: ";
					cin >> a >> b;
				} while (arr[a][b] != 0 || a < 0 || b < 0 || a>2 || b>2);
				arr[a][b] = 'X';
			}
			else
			{
				cout << "Õîä êîìïüþòåðà";
				Sleep(1000);
				if (arr[1][1] == 0)arr[1][1] = 'O';
				else if (iwinh >= 0)arr[iwinh][bh] = 'O';
				else if (iwinv >= 0)arr[bv][iwinv] = 'O';
				else if (cd == -2)arr[bd][bd] = 'O';
				else if (cr == -2)arr[br][2 - br] = 'O';
				else if (checkh >= 0)arr[checkh][bh] = 'O';
				else if (checkv >= 0)arr[bv][checkv] = 'O';
				else if (cd == 2)arr[bd][bd] = 'O';
				else if (cr == 2)arr[br][2 - br] = 'O';
				else
				{
					do
					{
						a = rand() % 3;
						b = rand() % 3;
					} while (arr[a][b] != 0);
					arr[a][b] = 'O';
				}
			}
			ai = !ai;
		}
		cout << "Ñûãðàåì åù¸?    1-äà/0-íåò\n";
		cin >> ai;
		if (ai == 1)
		{
			for (short i = 0; i < 3; i++)
			{
				for (short j = 0; j < 3; j++)
				{
					arr[i][j] = 0;
				}
			}
		}
		else break;
	}
}