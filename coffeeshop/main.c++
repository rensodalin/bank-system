//main section
// main section here 
#include<iostream>
#include <fstream>
#include<iomanip>
#include "queue.h"
#include "Report.h"
#include "survey.h"
using namespace std;
int salesstop=0;
int smallCupSales =0 ,mediumCupSales=0,largeCupSales=0;//track sale
int costSmallCup=0,costMediumCup=0,costLargeCup=0;//track cost
double totalsalecost =0, dailyincome=0; //track total and income for the day
int todaytopsale[20];
int idtopsale=0 , topcoffesellingquantity=0;
time_t now=time(0);
tm* ltm = localtime(&now);
int currentday=ltm->tm_mday;
int currentMonth=1+ltm->tm_mon;
int currentyear=1900 +ltm->tm_year;
coffemenu coffeemenulist[20];
int i=0;
void findtopsell(){
    for(int i=0;i<15;i++){
        if(todaytopsale[i]<todaytopsale[i+1]){
            idtopsale=i+1;
            topcoffesellingquantity=todaytopsale[i+1];
        }
    }
    for(int i=0;i<15;i++){
        if(todaytopsale[idtopsale]<todaytopsale[i]){
            idtopsale=i;
            topcoffesellingquantity=todaytopsale[i];
        }
    }
}





