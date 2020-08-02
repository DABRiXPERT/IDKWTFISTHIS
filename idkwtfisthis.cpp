#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
void welcomeScr();
int g_Content();
string samp(int samp);
int main()
{
	int m_score=0,highscore=0;
	title:
	char s_game; //s_game=start_the_game
	system("cls");
	welcomeScr();
	printf("\n\nHIGHSCORE:%4d", highscore);
	in:
	s_game = getch();
	if(s_game == 32)
	{
		m_score=g_Content();
		if(m_score>highscore)
		{
			highscore = m_score;
			printf("\n\nNEW BEST SCORE!!!");
			system("pause");
		}
		goto title;
	}
	else
	{
		goto in;
	}
	system("pause");
	return 0;
}
void welcomeScr()//welcome_screen
{
	printf("VER:0.01.200802\n\n\n");
	printf("PRESS SPACE TO START THE GAME.\n\n\n");
	printf("MADE BY DABRiXPERT\n");
	printf("Twitter: @buriku_nayoni\n");
}
int g_Content()//game
{
	srand(time(NULL));
	system("cls");
	int tmp;   string temp;
	int l[13]; string line[15];
	line[13] = "-----------\n";
	line[14] = "  D F K L  ";
	for(int i = 0; i <= 12; i++)
	{
		l[i] = rand()%4+1;
		line[i] = samp(l[i]);
		cout<<line[i];
	}
	cout<<line[13];
	cout<<line[14];
	printf("\n\nREADY...");
	Sleep(998);
//-------------------------------------------------------------------------------------------------
	system("cls");
	int in,score=0;
	char input;
	int gameover=0;
	while(gameover==0)
	{
		for(int i = 0; i <= 12; i++)
		{
			cout<<line[i];
		}
		cout<<line[13];
		cout<<line[14];
		printf("\n\nSCORE:%4d",score);
		none://wrong input(null)
		input = getch();
		switch(input)
		{
			case 'D':
			case 'd':
				in = 1;
				break;
			case 'F':
			case 'f':
				in = 2;
				break;
			case 'K':
			case 'k':
				in = 3;
				break;
			case 'L':
			case 'l':
				in = 4;
				break;
			default:
				goto none;
		}
		if(in != l[12])
		{
			gameover++;
		}
		else
		{
			for(int i = 12; i >= 1; i--)
			{
				l[i] = l[i-1];
				line[i] = line[i-1];
			}
			l[0] = rand()%4+1;
			line[0] = samp(l[0]);
			score++;
			system("cls");
		}
	}
	system("cls");
	printf("GAME OVER!\n");
	printf("YOUR SCORE:%4d",score);
	system("pause");
	return score;
}
string samp(int samp)//note_sample 
{
	if(samp == 0)
		return " | | | | |\n";
	if(samp == 1)
		return " |*| | | |\n";
	if(samp == 2)
		return " | |*| | |\n";
	if(samp == 3)
		return " | | |*| |\n";
    if(samp == 4)
		return " | | | |*|\n";
}
