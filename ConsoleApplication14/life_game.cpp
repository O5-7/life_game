#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

int group[60][60];
int group_n[60][60];
int x = 0,y = 0;
char b[3] = { "■" };
char w[2] = {32,32};
char line[300];
char all[30101];
char n[2] = {"\n"};
char oo[3] = { "■" };


int live_count()
{
	int count;
	count = group[x + 1][y + 1] + group[x - 1][y - 1] + group[x + 1][y - 1] + group[x - 1][y + 1] + group[x + 1][y] + group[x - 1][y] + group[x][y + 1] + group[x][y - 1];
	return count;
}
void graph()
{
	memset(all, 0, sizeof(all));
	memset(line, 0, sizeof(line));
	system("cls");
	x = 0;
	y = 0;
	do
	{
		x = 0;
		do
		{
			if (group[x][y] == 1)
			{
				strcat_s(line, b);
			}
			else
			{
				strcat_s(line, w);
			}
			x++;
		} while(x != 60);
		strcat_s(all, line);
		strcat_s(all, n);
		memset(line, 0, sizeof(line));
		y++;
	} while (y != 60);
	printf("%s", all);
	x = 0;
	y = 0;
}
void run()
{
	x = 1;
	y = 1;
	do
	{
		do
		{
			if (group[x][y] == 1)
			{
				if (live_count() < 2)
					group_n[x][y] = 0;
				if (live_count() == 2 || live_count() == 3)
					group_n[x][y] = 1;
				if (live_count() > 3)
					group_n[x][y] = 0;
			}
			else if(group[x][y] == 0)
			{
				if (live_count() == 3)
					group_n[x][y] = 1;
			}
			x++;
		} while (x != (60-1));
		y++;
		x = 1;
	} while (y != (60-1));

	x = 1;
	y = 1;
	do
	{
		do
		{
			group[x][y] = group_n[x][y];
			x++;
		} while (x != 60-1);
		y++;
		x = 1;
	} while (y != 60-1);
}

int main()
{
	srand(1);
	x = 0;
	y = 0;
	do
	{
		x = 0;
		do
		{
			group[x][y] = rand()%2;
			x++;
		} while (x != 60);
		y++;
	} while (y != 60);
	x = 0;
	y = 0;
	do
	{
		graph();
		run();
		Sleep(1);
	} while (1==1);
	return 0;

}