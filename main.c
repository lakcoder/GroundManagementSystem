#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nsize 30
#define Gsize 100
//..................STRUCTURE..................//

struct date
{
	int dd, mm, yyyy;
};

struct sport
{
	char name[Nsize];
	int rate;
	struct date d_avl[Nsize];
	struct date d_sch;			//date and timings available
};

struct ground
{
	char name[Nsize];
	char city[Nsize];
	char state[Nsize];
	struct sport games[Gsize];		//games it can hold
}groundDB[Gsize];

int no_of_ground()		//total number of grounds entered till now
{
	int i=0;
	while(groundDB[i].name[0]!='\0')
	{
			i++;
	}
	i++;
	return(i);
};			

int no_of_games(int index)		//total number of games given ground can hold
{
	int i=0;
	while(groundDB[index].games[i].name!='\0')
	{
			i++;
	}
	i++;
	return(i);
};			
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

void addSport(char gName[], char city[], char spName[])		//add scheduled sport to the ground
{
	int i=0,ans;
	int lo=i;
	int hi=no_of_ground();
	int flag=0,found=0;
	while(lo<hi && found==0)
	{
			mid=(ho+lo)/2;
			if(strcmp(groundDB[mid].name,gName)==0)
			{
				if(strcmp(groundDB[mid].city,city)==0)
				{
					ans=mid;
					found=1;
				}
				else if(strcmp(groundDB[mid].city,city)>0)
				{
					lo=mid+1;
				}
				else if(strcmp(groundDB[mid].city,city)<0)
				{
					hi=mid-1;
				}
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
	if(found==1)
	{
		lo=0;
		hi=no_of_games(ans);
		while(lo<hi && flag==0)
		{
			mid=(lo+hi)/2;
			if(strcmp(groundDB[ans].games[mid].name,spNmae)==0)
			{
				ans2=mid;
				flag=1;
			}
			else if(strcmp(groundDB[ans].games[mid].name,spNmae)>0)
			{
				lo=mid+1;
			}
			else if(strcmp(groundDB[ans].games[mid].name,spNmae)<0)
			{
				hi=mid-1;
			}
		}
		if(flag==1)
		{
			struct date d;
			printf("Enter the date for which it is scheduled (dd mm yyyy)")
			scanf("%d %d %d",d.dd,d.mm,d.yyyy);
			int len=no_of_games(ans);
			if(len>=gSize)
			{
				printf("FAILURE : array limit exceeded");
			}
			else
			{
				strcpy(groundDB[ans].games[len].name,spName);
				groundDB[ans].games[len].d_sch=d;
			}
			printf("SUCCESS : sport has been scheduled");
		}
		else
		{
			printf("FAILURE: the ground cannot hold this sport");
		}
	}
	else
	{
		printf("FAILURE : No such ground exist");
	}
}
void delSport(char gName[], char city[], char spName[])
{
	int i=0,ans;
	int lo=i;
	int hi=no_of_ground();
	int flag=0,found=0;
	while(lo<hi && found==0)
	{
			mid=(ho+lo)/2;
			if(strcmp(groundDB[mid].name,gName)==0)
			{
				if(strcmp(groundDB[mid].city,city)==0)
				{
					ans=mid;
					found=1;
				}
				else if(strcmp(groundDB[mid].city,city)>0)
				{
					lo=mid+1;
				}
				else if(strcmp(groundDB[mid].city,city)<0)
				{
					hi=mid-1;
				}
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
	if(found==1)
	{
		lo=0;
		hi=no_of_games(ans);
		while(lo<hi && flag==0)
		{
			mid=(lo+hi)/2;
			if(strcmp(groundDB[ans].games[mid].name,spNmae)==0)
			{
				ans2=mid;
				flag=1;
			}
			else if(strcmp(groundDB[ans].games[mid].name,spNmae)>0)
			{
				lo=mid+1;
			}
			else if(strcmp(groundDB[ans].games[mid].name,spNmae)<0)
			{
				hi=mid-1;
			}
		}
		if(flag==1)
		{	
			groundDB[ans].games[len].d_sch.dd=-1;
			groundDB[ans].games[len].d_sch.mm=-1;
			groundDB[ans].games[len].d_sch.yyyy=-1;
			printf("SUCCESS : scheduled sport has been delted");
		}
		else
		{
			printf("FAILURE: ground cannot hold such sport");
		}
	}
	else
	{
		printf("FAILURE : No such ground exist");
	}
}
