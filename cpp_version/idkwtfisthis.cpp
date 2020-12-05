#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<string>
using namespace std;
int highscore=0;
int save=0;
char stop;
char keyboard_layout[8]={'D','F','J','K','d','f','j','k'};
string latest_record[3]={"NAMAE_NASHI","0","0"};//NAME, TIME, SCORE
void welcomeScr();
void g_Content();
void setting();
void rankdotcsv_init();
void rankdotcsv_import();
void rankdotcsv_record();
void pause();
string samp(int samp);
int main()
{
	while(EOF)
	{
		
		system("cls");
		rankdotcsv_init();
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
	printf("VER:v0.10.0_A2");
	printf("\nREV:201127PR2");
	printf("\n*IN DEV*");
	printf("\n\n   _      _  _               _     __  _       _    _      _  ");
	printf("\n  (_)  __| || | ____      __| |_  / _|(_) ___ | |_ | |__  (_) ___");
	printf("\n  | | / _` || |/ /\\ \\ /\\ / /| __|| |_ | |/ __|| __|| '_ \\ | |/ __|");
	printf("\n  | || (_| ||   <  \\ V  V / | |_ |  _|| |\\__ \\| |_ | | | || |\\__ \\");
	printf("\n  |_| \\__,_||_|\\_\\  \\_/\\_/   \\__||_|  |_||___/ \\__||_| |_||_||___/.EXE");
	printf("\n\n\nPRESS SPACE TO START THE GAME.");
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
void rankdotcsv_init()//CONSTRUCTING
{
	fstream file;
	save = 0;
	file.open("rank.csv", ios::out);//NOT EXIST OR EXIST... WHO CARES? 
    if(!file)
    {
    	printf("FAILURE ON TRYING TO OPEN rank.csv\n");
    	exit(1);
	}
	if(file.is_open()){
	    file<<"RANK"<<","<<"PLAYER"<<","<<"TIME"<<","<<"SCORE"<<"\n";
		for(int i = 1; i <= 5; i++)    
		{
			//DATA_FORMAT
		 	file<<i<<","<<"NAMAE_NASHI"<<","<<"0"<<","<<"0"<<"\n";
		}
		file<<"DO NOT TOUCH ANYTHING!!!!!!!!!!";
	}
}
void rankdotcsv_import()//CONSTRUCTING
{
	
}
void rankdotcsv_record()//CONSTRUCTING
{
	
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

