#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
char stop;
char keyboard_layout[8]={'D','F','J','K','d','f','j','k'};
string leaderboard[5][4];//={"1","NAMAE_NASHI","0","0"};//RANK, NAME, TIME, SCORE
int highscore[5];//4,3,2,1,0
int rank_order[5];
void welcomeScr();
void g_Content();
void setting();
void rankdotiwit_initialize();
void rankdotiwit_overwrite(int rank, string time, int score, string name);
void pause();
string samp(int samp);
int main()
{
	while(EOF)
	{	
		system("cls");
		rankdotiwit_initialize();
		system("cls");
		welcomeScr();
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
	printf("VER:v0.10.0");
	printf("\nREV:21/01/02");
	printf("\n\n   _      _  _               _     __  _       _    _      _  ");
	printf("\n  (_)  __| || | ____      __| |_  / _|(_) ___ | |_ | |__  (_) ___");
	printf("\n  | | / _` || |/ /\\ \\ /\\ / /| __|| |_ | |/ __|| __|| '_ \\ | |/ __|");
	printf("\n  | || (_| ||   <  \\ V  V / | |_ |  _|| |\\__ \\| |_ | | | || |\\__ \\");
	printf("\n  |_| \\__,_||_|\\_\\  \\_/\\_/   \\__||_|  |_||___/ \\__||_| |_||_||___/.EXE");
	printf("\n\n[SPACE] START \n[  S  ] SET KEY LAYOUT");
	printf("\nCURRENT KEY LAYOUT: %c%c%c%c\n\n",keyboard_layout[0],keyboard_layout[1],keyboard_layout[2],keyboard_layout[3]);
	printf("MADE BY DABRiXPERT\n");
	printf("Twitter: @buriku_nayoni\n");
	printf("\n[LEADERBOARD]\n\n");
	printf(" # |       NAME      |	    TIME/DATE      |   SCORE   |\n");
	printf("========================================================\n");
	for (int i = 0; i <= 4; i++)
	{
		string str;
		int len,space;
		str = leaderboard[i][1];
		len = str.length();
		space = 15-len; 
		cout<<" "<<rank_order[i]+1<<" | "<<leaderboard[i][1];
		for (int j = 1; j <= space; j++)
		{
			cout<<" ";
		}
		cout<<" | "<<leaderboard[i][2]<<" | ";
		printf(" %8d |\n", highscore[i]);
		if(i != 4)
		{
			printf("--------------------------------------------------------\n");
		}
	}
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
	int rank_remain = 5;
	string name;
	char input;
	while(gameover==0)
	{
		for(int i = 0; i <= 12; i++)
		{
			cout<<line[i];
		}
		cout<<line[13];
		printf("  %c %c %c %c  ",keyboard_layout[0],keyboard_layout[1],keyboard_layout[2],keyboard_layout[3]);
		printf("\n\nSCORE:%6d\n\n",score);
		if(score >= highscore[0])
		{
			rank_remain = 0;
		}
		else if(score >= highscore[1])
		{
			rank_remain = 1;
		}
		else if(score >= highscore[2])
		{
			rank_remain = 2;
		}
		else if(score >= highscore[3])
		{
			rank_remain = 3;
		}
		else if(score >= highscore[4])
		{
			rank_remain = 4;
		}
		else
		{
			rank_remain = 5;
		}
//-------------------------------------------------------------------------------------------------
		if(rank_order[rank_remain] == 0 && rank_remain < 5)
		{
			printf("NEW HIGHSCORE!\n");
		}
		else if(rank_remain <= 4)
		{
			printf("[NEXT #%d, %d LEFT.]\n", rank_order[rank_remain], highscore[rank_remain-1] - score);
		}
		else
		{
			printf("[NEXT #%d, %d LEFT.]\n", rank_order[rank_remain-1]+1, highscore[rank_remain-1] - score);
		}
		printf("\nPRESS SPACE TO PAUSE");
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
	system("cls");
	printf("  ____     _     __  __  _____    ___ __     __ _____  ____\n");
	printf(" / ___|   / \\   |  \\/  || ____|  / _ \\\\ \\   / /| ____||  _ \\ \n");
	printf("| |  _   / _ \\  | |\\/| ||  _|   | | | |\\ \\ / / |  _|  | |_) |\n");
	printf("| |_| | / ___ \\ | |  | || |___  | |_| | \\ V /  | |___ |  _ < \n");
	printf(" \\____|/_/   \\_\\|_|  |_||_____|  \\___/   \\_/   |_____||_| \\_\\");
	printf("\n\nYOUR SCORE:%4d\n",score);
	if(rank_remain <= 4)
	{
		if(rank_order[rank_remain] == 0)
		{
			printf("\nYOU'RE IN 1ST PLACE!!!\nENTER YOUR NAME: ");
		}
		else if (rank_order[rank_remain] == 1)
		{
			printf("\nYOU'RE IN 2ND PLACE!!\nENTER YOUR NAME: ");
		}
		else if (rank_order[rank_remain] == 2)
		{
			printf("\nYOU'RE IN 3RD PLACE!\nENTER YOUR NAME: ");
		}
		else if (rank_order[rank_remain] == 3)
		{
			printf("\nYOU'RE IN 4TH PLACE\nENTER YOUR NAME: ");
		}
		else if (rank_order[rank_remain] == 4)
		{
			printf("\nYOU'RE IN 5TH PLACE\nENTER YOUR NAME: ");
		}
		cin>>name;
		while(name.length() > 15)
		{
			printf("NAME TOO LONG! 15 CHARACTERS ONLY! \n");
			printf("ENTER YOUR NAME: ");
			cin>>name;
		}
		time_t t = time(NULL);
		struct tm* stime=localtime(&t);
		char time[32];
		snprintf(time,sizeof(time),"%02d:%02d:%02d %02d/%02d/%04d",stime->tm_hour,stime->tm_min,stime->tm_sec,stime->tm_mday, 1+stime->tm_mon, 1900+stime->tm_year);
		rankdotiwit_overwrite(rank_remain, time, score, name);
	}
	else 
	{
		do
		{
			system("cls");
			printf("  ____     _     __  __  _____    ___ __     __ _____  ____\n");
			printf(" / ___|   / \\   |  \\/  || ____|  / _ \\\\ \\   / /| ____||  _ \\ \n");
			printf("| |  _   / _ \\  | |\\/| ||  _|   | | | |\\ \\ / / |  _|  | |_) |\n");
			printf("| |_| | / ___ \\ | |  | || |___  | |_| | \\ V /  | |___ |  _ < \n");
			printf(" \\____|/_/   \\_\\|_|  |_||_____|  \\___/   \\_/   |_____||_| \\_\\");
			printf("\n\nYOUR SCORE:%4d\n",score);
			printf("\nPRESS SPACE TO CONTINUE.\n");
		}while(getch() != 32);
		stop = 0;
	}
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
	printf(" ____    _    _   _  ____   _____ \n"); 
	printf("|  _ \\  / \\  | | | |/ ___| | ____|\n");
	printf("| |_) |/ _ \\ | | | |\\___ \\ |  _|  \n");
	printf("|  __// ___ \\| |_| | ___) || |___ \n");
	printf("|_|  /_/   \\_\\\\___/ |____/ |_____|\n");
	printf("\nPRESS SPACE TO CONTINUE.");
	stop = getch(); 
	if(stop != 32)
		pause();
	system("cls");
}
void rankdotiwit_initialize()//CONSTRUCTING
{
	FILE *iFile;
	iFile = fopen("rank.iwit", "r");
	if (iFile == NULL)
	{
		fclose(iFile);
		iFile = fopen("rank.iwit", "w+");
		for (int i = 0; i <= 4; i++)
		{
			stringstream rank,score;
			rank << "0";
			fputs(rank.str().c_str(), iFile);
			fputs("\n---------------\n--:--:-- --/--/----\n", iFile);
			score << "0";
			fputs(score.str().c_str(), iFile);
			fputs("\n", iFile);
		}
	}
	fclose(iFile);
	ifstream rFile("rank.iwit", ios::in | ios::out);
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			getline(rFile, leaderboard[i][j]);
		}
	}
	rFile.close();
	for (int i = 0; i <= 4; i++)
	{
		istringstream(leaderboard[i][3]) >> highscore[i];
		istringstream(leaderboard[i][0]) >> rank_order[i];
	}
	boolean flag_score = false;
	boolean flag_rank = false;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 4; j >= i; j--)
		{
			if(highscore[i]<highscore[j])
			{
				flag_score = true;
			}
		}
	}
	if(flag_score == true)
	{
		cout<<"SOMETHING WRONG WITH rank.iwit, PROGRAM ABORT."<<endl;
		cout<<"[ERR_WRONG_SORT]"<<endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 4; j >= i; j--)
		{
			if(leaderboard[i][0] > leaderboard[j][0] && rank_order[i]>rank_order[j] && highscore[i]!=highscore[j])
			{
				flag_rank = true;
			}
		}
	}
	if(flag_score == true)
	{
		cout<<"SOMETHING WRONG WITH rank.iwit, PROGRAM ABORT."<<endl;
		cout<<"[ERR_WRONG_RANK]"<<endl;
		system("pause");
		exit(1);
	}
}
void rankdotiwit_overwrite(int rank, string time, int score, string name)//CONSTRUCTING
{
	int flag = 0;
	//---------------------------
	stringstream ss_rank,ss_score;
	string s_rank, s_score;
	ss_rank << rank;
	ss_score << score;
	s_rank = ss_rank.str();
	s_score = ss_score.str();
	//----------------------------
	if (rank != 4)
	{
		for (int i = 3; i >= rank; i--)//ORDER
		{
			for (int j = 1; j <= 3; j++)//NAME, TIME, SCORE
			{
				highscore[i+1] = highscore[i];
				leaderboard[i+1][j] = leaderboard[i][j];
				//flag++;
			}
		}
	}
	leaderboard[rank][1] = name;
	leaderboard[rank][2] = time;
	leaderboard[rank][3] = s_score;
	highscore[rank] = score;
	for (int i = 0; i <= 4; i++)//RANK
	{
		if(i == 0)
		{
			rank_order[i] = 0;
			leaderboard[i][0] = "0";
		}
		else
		{
			if(highscore[i-1]==highscore[i])
			{
				stringstream rank_sort;
				rank_order[i] = rank_order[i-1];
				rank_sort << leaderboard[i-1][0];
				leaderboard[i][0] = rank_sort.str();
			}
			else
			{
				stringstream rank_sort;
				rank_order[i] = i;
				rank_sort << i;
				leaderboard[i][0] = rank_sort.str();
			}	
		}
	}
	int rm = remove("rank.iwit");
	FILE *spawn;
	spawn = fopen("rank.iwit", "w+");
	fclose(spawn);
	ofstream iFile("rank.iwit", ios::in | ios::out);
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			iFile<<leaderboard[i][j]<<endl;
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