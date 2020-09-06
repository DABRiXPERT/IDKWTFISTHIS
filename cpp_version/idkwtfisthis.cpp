#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
int highscore=0;
void welcomeScr();
void g_Content();
string samp(int samp);
int main()
{
	for(;;)
	{
		do 
		{
			system("cls");
			welcomeScr();
			printf("\n\nHIGHSCORE:%4d", highscore);
		}while(getch() != 32);
		g_Content();
	}
	system("pause");
	return 0;
}
void welcomeScr()//welcome_screen
{
	printf("VER:0.052.200906\n\n\n");
	printf("PRESS SPACE TO START THE GAME.\n\n\n");
	printf("MADE BY DABRiXPERT\n");
	printf("Twitter: @buriku_nayoni\n");
}
void g_Content()//game
{
	srand(time(NULL));
	system("cls");
	char e_game;
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
		switch(getch())
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
				in = 999;
		}
		if(in != l[12] && in != 999)
		{
			gameover++;
		}
		else if(in == l[12] && in != 999)
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
		else
			system("cls");
	}
	do 
	{
		system("cls");
		printf("GAME OVER!\n");
		printf("YOUR SCORE:%4d\n",score);
		if(score>highscore)
		{
			printf("\nNEW BEST SCORE!!!\n");
		}
		printf("\nPRESS SPACE TO GO BACK TO TITLE SCREEN.");
	}while(getch() != 32);
	if(score>highscore)
	{
		highscore = score;
	}
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
