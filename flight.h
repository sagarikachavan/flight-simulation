#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#define MAX 3
#define ARRIVE 0
#define DEPART 1
//typedef enum action{ARRIVE,DEPART}Action;
struct plane
{
int id;  /*identification number of airplane*/
int tm;   /*Time arrival in queue*/
};
struct queue
{
int count;
int front;
int rear;
struct plane p[MAX];
};
void initqueue(struct queue *);
void addqueue(struct queue *,struct plane);
struct plane delqueue(struct queue *);
int size(struct queue);
int empty(struct queue);
int full(struct queue);
struct airport
{
	struct queue landing;
	struct queue takeoff;
	struct queue *pl;
	struct queue *pt;
	int idletime;   /*Number of units when runway is idle*/
	int landwait;   /*Total waiting time for planes landed*/
	int takeoffwait; /*Total waiting time for take off*/
	int nland;      /*Number of planes landed*/
	int nplanes;    /*Number of planes processed so far*/
	int nrefuse;    /*Number of planes refused of airport*/
	int ntakeoff;   /*Number of phones taken off*/
	struct plane pln;

};
void initairport(struct airport *);
void start(int *,double *,double *);
void newplane(struct airport *,int,int);
void refuse(struct airport *,int);
void land(struct airport *,struct plane,int);
void fly(struct airport *,struct plane,int);
void idle(struct airport *,int);
void conclude(struct airport *,int);
int randomnumber(double);
void apaddqueue(struct airport *,char);
struct plane apdelqueue(struct airport *,char);
int apsize(struct airport,char);
int apfull(struct airport,char);
int apempty(struct airport,char);
void myrandomsize();