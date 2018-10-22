#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	struct date d_avl[Nsize];
	struct date d_sch[Nsize];			//date and timings available
};

struct ground
{
	char name[Nsize];
	char city[Nsize];
	char state[Nsize];
	struct sport games[Gsize];		//games it can hold
}groundDB[Gsize];

int no_of_ground()
{
	int i=0;
	while(groundDB[i].name[0]!='\0')
	{
			i++;
	}
	i++;
	return(i);
};			//total number of grounds entered till now

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
				groundDB[i].games[j].d_avl[k].dd=-1;
				groundDB[i].games[j].d_avl[k].mm=-1;
				groundDB[i].games[j].d_avl[k].yyyy=-1;
				groundDB[i].games[j].d_avl[k].H=-1;
				groundDB[i].games[j].d_avl[k].M=-1;
				groundDB[i].games[j].d_avl[k].S=-1;
				groundDB[i].games[j].d_sch[k].dd=-1;
				groundDB[i].games[j].d_sch[k].mm=-1;
				groundDB[i].games[j].d_sch[k].yyyy=-1;
				groundDB[i].games[j].d_sch[k].H=-1;
				groundDB[i].games[j].d_sch[k].M=-1;
				groundDB[i].games[j].d_sch[k].S=-1;
			}
		}
	}
}

void getGroundInfo(char c[])			//get grounds in the city with the sports it can hold
{
	int i,j;
	for(i=0; groundDB[i].name[0]!='\0' && i<Gsize; i++)
	{
		if(strcmp(c,groundDB[i].city)==0)
		{
			for(j=0; groundDB[i].games[i].name[0]!='\0'; j++)
			{
				printf("%s\t\t%s",groundDB[i].name,groundDB[i].games[j].name);
			}
		}
	}
}

void addSport(char gName[], char city[], char spName[])		//add sports the ground can hold
{
	int i=0;
	int lo=i;
	int hi=no_of_ground();
	int flag=0;
	while(lo<hi && flag==0)
	{
			mid=(ho+lo)/2;
			if(strcmp(groundDB[mid].name,gName)==0)
			{
				ans=mid;
				flag=1;
			}
			else if(strcmp(groundDB[mid].name,gName)>0)
			{
				lo=mid+1;
			}
			else if(strcmp(groundDB[mid].name,gName)<0)
			{
				hi=mid-1;
			}
	}
}
