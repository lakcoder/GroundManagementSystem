#include<stdio.h>
#include<stdlib.h>

#define Nsize 30
#define Gsize 100
//..................STRUCTURE..................//
	
struct date
{
	int dd, mm, yyyy, H, M, S;
};

struct sport
{
	char name[Nsize];
	int rate;
	struct date d[Nsize];			//date and timings available
};

struct ground
{
	char name[Nsize];
	char city[Nsize];
	char state[Nsize];
	struct sport games[Gsize];		//games it can hold
}groundDB[Gsize];

struct data 				
{
	char sportName[Nsize];			
	char groundName[Nsize];
	char city[Nsize];
	struct date timing;
}database[Gsize];				//database of scheduled games

//..Initailise the database with default values..//

void intialiseDB()
{
	int i,j,k;
	for(i=0; i<Gsize; i++)
	{
		groundDB[i].name[0]='\0';
		groundDB[i].city[0]='\0';
		groundDB[i].state[0]='\0';
		for(j=0; j<Gsize; j++)
		{
			groundDB[i].games[j].name[0]='\0';	
			groundDB[i].games[j].rate=-1;
			for(k=0; k<Nsize; k++)
			{			
				groundDB[i].games[j].d.dd=-1;
				groundDB[i].games[j].d.mm=-1;
				groundDB[i].games[j].d.yyyy=-1;
				groundDB[i].games[j].d.H=-1;
				groundDB[i].games[j].d.M=-1;
				groundDB[i].games[j].d.S=-1;
			}
		}
		database[i].sportName[0]='\0';
		database[i].name[0]='\0';
		database[i].city[0]='\0';
		database[i].timing.dd=-1;
		database[i].timing.mm=-1;
		database[i].timing.yyyy=-1;
		database[i].timing.H=-1;
		database[i].timing.M=-1;
		database[i].timing.S=-1;
	}
}		
	
void getGroundInfo()
{	
	char c[Nsize]
	printf("Enter city name : ");
	scanf("%s",c);
	for(i=0; groundDB[i].name[0]!='\0' && i<Gsize; i++)
	{
		if()


