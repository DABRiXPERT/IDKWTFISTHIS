#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;
int highscore=0;
char stop;
char keyboard_layout[8]={'D','F','J','K','d','f','j','k'};
void welcomeScr();
void g_Content();
void setting();
void pause();
string samp(int samp);
int main()
{
	for(;;)
	{
		
		system("cls");
		welcomeScr();
		printf("\n\nHIGHSCORE:%4d", highscore);
		stop = getch(); 
		if(stop == 32)
			g_Content();
		else if(stop == 83 || stop == 115)
	        setting();		
	}
	system("pause");
	return 0;
}
void welcomeScr()//welcome_screen
{
	printf("VER:0.065.201030\n\n\n");
	printf("PRESS SPACE TO START THE GAME.");
	printf("\nPRESS S TO SWITCH THE KEY LAYOUT.");
	printf("\nCURRENT KEY LAYOUT: %c%c%c%c\n\n\n",keyboard_layout[0],keyboard_layout[1],keyboard_layout[2],keyboard_layout[3]);
	printf("MADE BY DABRiXPERT\n");
	printf("Twitter: @buriku_nayoni\n");
}
void g_Content()//game
{
	srand(time(NULL));
	system("cls");
	char e_game;
	int tmp;   string temp;
	int l[13]; string line[14];
	line[13] = "-----------\n";
	for(int i = 0; i <= 12; i++)
	{
		l[i] = rand()%4+1;
		line[i] = samp(l[i]);
		cout<<line[i];
	}
	cout<<line[13];
	printf("  %c %c %c %c  ",keyboard_layout[0],keyboard_layout[1],keyboard_layout[2],keyboard_layout[3]);
	printf("\n\nREADY...");
	Sleep(998);
//-------------------------------------------------------------------------------------------------
	system("cls");
	int in,score=0;
	int gameover=0;
	char input;
	while(gameover==0)
	{
		for(int i = 0; i <= 12; i++)
		{
			cout<<line[i];
		}
		cout<<line[13];
		printf("  %c %c %c %c  ",keyboard_layout[0],keyboard_layout[1],keyboard_layout[2],keyboard_layout[3]);
		printf("\n\nSCORE:%6d",score);
		printf("\nH-SCORE:%4d",highscore);
		printf("\nPRESS SPACE TO PAUSE",highscore);
		input = getch();
		if(input == 32)
		{
			pause();
		}
//-------------------------------------------------------------------------------------------------
		if(input == keyboard_layout[0] || input == keyboard_layout[4])
			in = 1;
		else if(input == keyboard_layout[1] || input == keyboard_layout[5])
			in = 2;
		else if(input == keyboard_layout[2] || input == keyboard_layout[6])
			in = 3;
		else if(input == keyboard_layout[3] || input == keyboard_layout[7])
			in = 4;
		else
			in = 999;
//-------------------------------------------------------------------------------------------------
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
	stop = 0;
}
void setting()//setting
{
	system("cls"); 
	printf(" |  |  |  |  | \n");
	printf(" |  |  |  |  | \n");
	printf(" |  |  |  |  | \n");
	printf("---------------\n");
	printf("  K0 K1 K2 K3  \n\n");
	for(int i = 0; i <= 3; i++)
	{
		//STILL CONSTRUCTING
		printf("SELECT K%d: ", i);
		scanf("%s", &keyboard_layout[i]);
		if(i >= 0)
		{
			for(int j = 0; j < i; j++)	
			{
				if(keyboard_layout[i] == keyboard_layout[j])
				{
					printf("THE KEY WAS OCCUPIED!\n");
					i--;
				}
			}
		}
	}
	for(int i = 0; i <= 3; i++)
	{
		if(keyboard_layout[i] >= 65 && keyboard_layout[i] <= 90)
		{
			keyboard_layout[i+4] = keyboard_layout[i] + 32; 
		}
		else if(keyboard_layout[i] >= 97 && keyboard_layout[i] <= 122)
		{
			keyboard_layout[i+4] = keyboard_layout[i]; 
			keyboard_layout[i] = keyboard_layout[i+4] - 32;
		}
		else
		{
			keyboard_layout[i+4] = keyboard_layout[i]; 
		}
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
void pause()//pause in game
{
	system("cls");
	stop = 0;
	printf("PRESS SPACE TO CONTINUE PLAYING.");
	stop = getch(); 
	if(stop != 32)
		pause();
	system("cls");
}
