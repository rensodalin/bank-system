#include<iostream>
using namespace std;

//Vadhana move form Main to queue
struct CoffeeMenu{
     int No;
     string Type;
     double S;
     double M;
     double L;
};
struct Element
{
	string name[50];
  	string size[50];
	int number[50];
  	int ordersize;
	Element *next;
};

struct Queue
{
	int n;
	Element *front;
	Element *tail;
};

Queue *MakeNewList()
{
	Queue *qs = new Queue();
	qs->front = NULL;
	qs->tail = NULL;
	qs->n = 0;
	return qs;
}

