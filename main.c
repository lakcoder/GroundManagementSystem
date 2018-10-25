#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Nsize 30
#define Gsize 100
//..................STRUCTURE..................//

struct date
{
	int dd, mm, yyyy, H, M;
};

struct sport
{
	char name[Nsize];
	int rate;
	struct date d_sch2[Nsize];
	struct date d_sch1[Nsize];			//date and timings available
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
				groundDB[i].games[j].d_sch1[k].dd=-1;
				groundDB[i].games[j].d_sch1[k].mm=-1;
				groundDB[i].games[j].d_sch1[k].yyyy=-1;
				groundDB[i].games[j].d_sch1[k].H=-1;
				groundDB[i].games[j].d_sch1[k].M=-1;
				groundDB[i].games[j].d_sch2[k].dd=-1;
				groundDB[i].games[j].d_sch2[k].mm=-1;
				groundDB[i].games[j].d_sch2[k].yyyy=-1;
				groundDB[i].games[j].d_sch2[k].H=-1;
				groundDB[i].games[j].d_sch2[k].M=-1;
			}
		}
	}
}

void searchground(char gName[],char city[])			//search ground on the basis of name and city
{
	int ans=-1;
	int lo=0;
	int hi=no_of_ground();
	while(lo<hi && found==0)
	{
			mid=(ho+lo)/2;
			if(strcmp(groundDB[mid].name,gName)==0)
			{
				if(strcmp(groundDB[mid].city,city)==0)
				{
					ans=mid;
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
	return ans;
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

void addSport(char gName[], char city[], char spName[])		//add scheduled sport to the ground if not found add game to the ground
{
	int i=0,ans2;
	int flag=0;
	ans=searchground(gName,city);
	if(ans>=0)
	{
		lo=0;
		int num=no_of_games(ans);
		hi=num;
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
			struct date d1,d2;
			printf("Enter the start date and time for which it is scheduled (dd mm yyyy HH MM)(24 hr system)");
			scanf("%d %d %d",d1.dd,d1.mm,d1.yyyy,d1.H,d1.M);
			printf("enter the end date and time for which it is scheduled (dd mm yyyy HH MM)(24 hr system)");
			scanf("%d %d %d",d2.dd,d2.mm,d2.yyyy,d2.H,d2.M);
			if(num>=gSize)
			{
				printf("FAILURE : array limit exceeded");
			}
			else
			{
				strcpy(groundDB[ans].games[num].name,spName);
				groundDB[ans].games[num].d_sch1=d1;
				groundDB[ans].games[num].d_sch2=d2;
				printf("SUCCESS : sport has been scheduled");
			}
		}
		else if(flag==0)
		{
			goundDB[ans].games[num].name=spName;
			printf("Enter Rate per hour of game :");
			scanf("%d",goundDB[ans].games[num].rate);
			printf("SUCCESS : sport added to the ground");
		}
	}
	else
	{
		
		printf("FAILURE : No such ground exist");
	}
}
void delSport(char gName[], char city[], char spName[])
{
	int i=0,ans,ans2;
	int lo=i;
	int hi=no_of_ground();
	int flag=0,found=0;
	ans=searchground(gName,city);
	if(ans>=0)
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
			int k,j=ans2;
			i=ans;
			groundDB[i].games[j].name[0]='\0';
			groundDB[i].games[j].rate=-1;
			for(k=0; k<Nsize; k++)
			{
				groundDB[i].games[j].d_sch1[k].dd=-1;
				groundDB[i].games[j].d_sch1[k].mm=-1;
				groundDB[i].games[j].d_sch1[k].yyyy=-1;
				groundDB[i].games[j].d_sch1[k].H=-1;
				groundDB[i].games[j].d_sch1[k].M=-1;
				groundDB[i].games[j].d_sch2[k].dd=-1;
				groundDB[i].games[j].d_sch2[k].mm=-1;
				groundDB[i].games[j].d_sch2[k].yyyy=-1;
				groundDB[i].games[j].d_sch2[k].H=-1;
				groundDB[i].games[j].d_sch2[k].M=-1;
			}
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
	
void addGround()
{
	struct ground g;
	char c;
	int i=no_of_grounds(); 
	do
	{
		printf("Enter ground name: ");
		scanf("%[^\n]s",g.name);
		printf("Enter city name: ");	
		scanf("%s",g.city);
		ans=searchground(g.name,g.city);
		if(ans>=0)
			printf("ground 	allready exists");
		else
		{
			printf("Enter state:");
			scanf("%s",g.state);
		}
		printf("Do you want to enter more ground? [Y/N]");
		scanf("%c",&c);
		i++;
	}while((c=='y' || c=='Y') && i<Gsize);
	if(i>=Gsize)
	{
		printf("Array size exceeded");
	}
	else
	{
		printf("SUCCESSFULLY ENTERED THE GROUNDS");
	}
}

void delete ground()
{
	char name[Nsize],city[Nsize];
	int num=no_of_grounds();
	printf("Enter ground name:");
	scanf("%[^\n]",name);
	printf("ENter ground city:");
	scanf("%s",city);
	int i=searchground(name,city),j,k;
	if(i>=0)
	{
		while(i<num)
		{
			groundDB[i]=groundDB[i+1];
		}
		groundDB[i].name[0]='\0';
		groundDB[i].city[0]='\0';
		groundDB[i].state[0]='\0';
		for(j=0; j<Gsize; j++)
		{
			groundDB[i].games[j].name[0]='\0';
			groundDB[i].games[j].rate=-1;
			for(k=0; k<Nsize; k++)
			{
				groundDB[i].games[j].d_sch1[k].dd=-1;
				groundDB[i].games[j].d_sch1[k].mm=-1;
				groundDB[i].games[j].d_sch1[k].yyyy=-1;
				groundDB[i].games[j].d_sch1[k].H=-1;
				groundDB[i].games[j].d_sch1[k].M=-1;
				groundDB[i].games[j].d_sch2[k].dd=-1;
				groundDB[i].games[j].d_sch2[k].mm=-1;
				groundDB[i].games[j].d_sch2[k].yyyy=-1;
				groundDB[i].games[j].d_sch2[k].H=-1;
				groundDB[i].games[j].d_sch2[k].M=-1;
			}
		}
		printf("!!!SUCCESSFULLY DELETED!!!");
	}
	else
	{
		printf("!!!FAILURE : ground not found!!!");
	}
}

void update Ground()					//to be written
{
	printf("Enter ground name to be updated:");
	scanf("%[^\n]",name);
	printf("ENter ground city to be updated:");
	scanf("%s",city);
	int i=searchground(name,city),j,k;
	if(i>=0)
	{
	}
}

void getFixtureCity()				//List the games scheduled in the city
{
	char city[Nsize];
	struct date d1,d2;
	int i,found=0;
	printf("Enter the city name");
	scanf("%s",city);
	printf("Enter time range\n start date (dd mm yyyy):");
	scanf("%d %d %d",&d1.dd,&d1.mm,&d1.yyyy);
	printf("end date (dd mm yyyy):");)
	scanf("%d %d %d",&d2.dd,&d2.mm,&d2.yyyy);
	for(i=0; i<no_of_grounds(); i++)
	{
		if(strcmp(groundDB[i].city,city)==0)
		{	
			j=0;
			while(groundDB[i].games[j].name[0]!='\0')
			{
				if((groundDB[i].games[j].d_sch1.yyyy>=d1.yyyy && groundDB[i].games[j].d_sch2.yyyy<=d2.yyyy)
				&& (groundDB[i].games[j].d_sch1.mm>=d1.mm && groundDB[i].games[j].d_sch2.mm<=d2.mm)
				&&(groundDB[i].games[j].d_sch1.dd>=d1.dd && groundDB[i].games[j].d_sch2.dd<=d2.dd))
				{
					printf("%s\t%s",groundDB[i].name,groundDB[i].games[j].name);
					found=1;
				}
			}
		}
	}
	if(found==0)
	{
		printf("!!!No sport is scheduled in the city between that time range");
	}
}

void UniqueSport()
{
	char name[Nsize],city[Nsize];
	printf("Enter ground name:");
	scanf("%[^\n]s",name);
	printf("Enter ground city:");
	scanf("%s",city);
	int found,flag=0;
	int index=searchground(name,city);
	if(i<=0)
	{
		while(groundDB[index].games[j].name!='\0')
		{	
			found=0;
			while(groundDB[i].name!='\0' && found==0)
			{
				while(ground[i].games[k].name!='\0' && found ==0)
				{
					if(strcmp(groundDB[i].games[k].name,ground[index].games[j].name)==0)
					{
						found==1;
					}
					k++;
				}
				i++;
			}
			j++;
			if(found==0 && groundDB[i].name!='\0')
			{
				printf("%s \n",groundDB[index].games[j].name);
				flag=1;
			}
		}
		if(flag==1)
		{
			printf("!!!NO UNIQUE SPORT!!!");
		}
				
	}
	else
	{
		printf("No such ground exist");
	}
}
	
void SportwithGround()
{
	char spName[Nsize];
	printf("Enter sprot to be searched");
	scanf("%s",spNmae);
	int i,k;
	while(groundDB[i].name!='\0')
	{
		while(ground[i].games[k].name!='\0' && found ==0)
		{
			if(strcmp(groundDB[i].games[k].name,spName)==0)
			{
				printf("%s",groundDB[i].name);
			}
			k++;
		}
		i++;
	}
}
					
void FindLoactionForGameEvents()
{
	
		
	
