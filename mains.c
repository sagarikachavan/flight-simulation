#include<stdio.h>
#include "flight.h"
void main()
{
	struct airport a;
	int i;     /*increment*/
	int pri;  /*Pseudo random integer*/
	int curtime; /*Current time:one unit=time taken for take off in runway 1 and landing in runway 2*/
	int endtime;  /*Total number of time units to run*/
	double expectarrive; /*Number of planes arriving in one unit in runway 1*/
	double expectdepart; /*Number of planes newly ready to take off from runway 2*/
	struct plane temp;
	initairport(&a);
	start(&endtime,&expectarrive,&expectdepart);
	printf("Endtime: %d\n",endtime);//not necessary just for checking
	idle(&a,curtime);
	for(curtime=1;curtime<=endtime;curtime++)
	{  //printf("%d",expectarrive);
		pri=(rand() % endtime);
		//printf("%d",pri);
		for(i=1;i<=pri;i++)  /*Add to landing queue*/
		{  //printf("hi");
			newplane(&a,curtime,ARRIVE);
			if(apfull(a,'l'))
			  refuse(&a,ARRIVE);
			else
			  apaddqueue(&a,'l');
		}
		pri=(rand() % endtime);
		for(i=1;i<=pri;i++)  /*Add to takeoff queue*/
		{
			newplane(&a,curtime,DEPART);
			if(apfull(a,'t'))
			  refuse(&a,DEPART);
			else
			  apaddqueue(&a,'t');
		}
		if(!(apempty(a,'l')))  /*Bring plane to land*/
		{
			temp=apdelqueue(&a,'l');
			land(&a,temp,curtime);
		}
		else
		{
			if(!(apempty(a,'t')))/*Allow plane to take off*/
			{
				temp=apdelqueue(&a,'t');
				fly(&a,temp,curtime);
			}
			else
			   idle(&a,curtime);   /*Runway idle*/
		}
	}
conclude(&a,endtime);  /*Finish simulation*/
getch();
}
