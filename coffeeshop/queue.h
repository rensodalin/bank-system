#include<iostream>
using namespace std;
struct coffemenu{
    int No;
    string type;
    double s;
    double M;
    double L;
};
struct Element{
    string name[100];
    string size[100];
    int number[100];
    int ordersize;
    Element *next;
};
struct Queue{
    int n;
    Element *front;
    Element *tail;
};
Queue *creatqueue(){
    Queue *q =new Queue();
    q->front=NULL;
    q->tail=NULL;
    q->n=0;
    return q;
}

