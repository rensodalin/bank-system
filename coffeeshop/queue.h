#include <iostream>
using namespace std;


struct CoffeeMenu
{
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
    Queue *qs =new Queue();
    qs->front=NULL;
    qs->tail=NULL;
    qs->n = 0;
    return qs;
}


void enqueue(Queue *qs, int name[], int size[], int number[], int arrSize, CoffeeMenu Menu[])
{
    Element *e = new Element();
    e->ordersize = arrSize;
    for (int i=0; i<arrSize; i++)
    {
        e->number[i] = number[i];
        if(name[i] == 0)
        {
            e->name[i] = "Crystal";
            if (size[i] == 1)
            {
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else
            {
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] ==1)
        {
            e->name[i] = "Artic";
            if (size[i] == 1)
            {
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else{
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] == 2)
        {
            e->name[i] = "Hot_Latte";
            if(size[i] == 1)
            {
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else{
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] == 3)
        {
            e->size[i] = "Cappucino";
            if(size[i] == 1){
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else{
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] == 4)
        {
            e->size[i] = "Mocha";
            if(size[i] == 1)
            {
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else{
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] == 5)
        {
            e->name[i] = "Cocoa";
            if(size[i] == 1)
            {
                e->size[i] = "Small";
            }
            else if(size[i] == 2)
            {
                e->size[i] = "Medium";
            }
            else if(size[i] == 3)
            {
                e->size[i] = "Large";
            }
            else{
                e->size[i] = "Invalid";
            }
        }
        else if(name[i] == 6)
        {
            e->name[i] = "Vannila_Frape";
	        if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
			    e->size[i] = "Medium";
	    	}
     		else if(size[i] == 3)
	    	{
		    	e->size[i] = "Large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 7)
        {
            e->name[i] = "Caramel_Frape";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "Medium";
	    	}
	    	else if(size[i] == 3)
		    {
			    e->size[i] = "Large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 8)
        {
            e->name[i] = "Salted_Caramel";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	 	    else if(size[i] == 2)
	    	{
		    	e->size[i] = "Medium";
	       	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "Large";
		    }
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 9)
        {
            e->name[i] = "Ice_Latte";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
	    		e->size[i] = "Medium";
	    	}
	    	else if(size[i] == 3)
		   {
			   e->size[i] = "Large";
	    	}
	    	else
	    	{
	    		e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 10)
        {
            e->name[i] = "Americano";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	     	else if(size[i] == 2)
		    {
		    	e->size[i] = "Medium";
	     	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "Large";
	    	}
		    else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 11)
        {
            e->name[i] = "Espresso";
	    	if(size[i] == 1)
    		{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "Medium";
	    	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "Large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else if(name[i] == 12)
        {
            e->name[i] = "Americano";
	     	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
		    else if(size[i] == 2)
	     	{
		     	e->size[i] = "Medium";
	    	}
		    else if(size[i] == 3)
		    {
		    	e->size[i] = "Large";
	    	}
	        else
		    {
		    	e->size[i] = "Invalid";
		    }
        }
        else if(name[i] == 13)
        {
            e->name[i] = "Machhiato";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "Medium";
	    	}
		    else if(size[i] == 3)
		    {
			    e->size[i] = "Large";
		    }
	    	else
	    	{
		    	e->size[i] = "Invalid";
		    }
        }
        else if(name[i] == 14)
        {
            e->name[i] = "Matcha Latte";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
	    	else if(size[i] == 2)
	    	{
		    	e->size[i] = "Medium";
	    	}
	    	else if(size[i] == 3)
	    	{
		    	e->size[i] = "Large";
	    	}
	    	else
	    	{
		    	e->size[i] = "Invalid";
	    	}
        }
        else 
        {
            e->name[i] = "Invalid";
	    	if(size[i] == 1)
	    	{
		    	e->size[i] = "Small";
	    	}
		    else if(size[i] == 2)
	     	{
		    	e->size[i] = "Medium";
	    	}
	    	else if(size[i] == 3)
	    	{
	 	    	e->size[i] = "Large";
	    	}
	    	else
	    	{
		     	e->size[i] = "Invalid";
	    	}
        }
    }

    e->next = NULL;
    if(qs->n == 0)
    {
        qs->front = e;
        qs->tail = e;
    }
    else{
        qs->tail->next = e;
        qs->tail = e;
    }
    qs->n = qs->n + 1;
}

void Dequeue(Queue *qs)
{
    Element *tmp;
    tmp = qs->front;
    if(qs->n == 0)
    {
        cout <<"<< Cannot delete because there is no element in the queue. "<< endl;
    }
    else{
        qs->front = qs->front->next;
		delete tmp;
		qs->n = qs->n - 1;
    }
}

void Display_Queue_Cos(Queue *qs)
{
    Element *tmp;
    tmp = qs->front;
    int cos_order_number = 1;

    if(qs->n == 0)
    {
        cout <<"<< Cannot dispaly because there is no element in the queue. >>"<< endl;
    }
    else
    {
        while(tmp != NULL)
        {
            cout << "Order: "<< cos_order_number << endl;

            for(int i=0; i<tmp->ordersize; i++)
            {
                cout<<" Coffee|Size|Amount : ";
                cout<<tmp->name[i]<<"\t"<<tmp->size[i]<<"\t"<< tmp->number[i];
                cout << endl;
            }
            tmp = tmp->next;
            cos_order_number++;
            cout << endl;
        }
    }
}