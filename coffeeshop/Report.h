//report hear
#include <fstream>
#include <iostream>
using namespace std;

string Name[20] = {"Bullet","Crown","Hot_Latte","Cappucino","Mocha","Cacoa","Vannila_Frape","Caramel_Frape","Salted_Caramel","Ice_Latte","Cappucino_BS","Espresso","Americano","Machhiato","Marochhino"};
int Likes[20];

void MostLike(){
     int LikeID=0,Amug=0;
     for (int i = 0; i < 20; i++)
     {
          if (Likes[i] < Likes[i+1])
          {
               LikeID = i+1;
               Amug = Likes[i+1];
          }
     }
     for (int i = 0; i < 20; i++)
     {
          if (Likes[LikeID] < Likes[i])
          {
               LikeID = i;
               Amug = Likes[i];
          }
     }
     cout << "Most Order Coffee is "<< Name[LikeID] << " times : " << Amug << endl;
     for (int r = 0; r < 15; r++)
     {
          Likes[r] = 0;
     }
}

void WriteData(int Date,int Mouth,int year,int SCup,int MCup,int LCup,double Income,int CoffeeID,int Nub){
     fstream Write;
     Write.open("Data.txt",ios::app);
     Write<<Date<<" "<<Mouth<<" "<<year<<" "<<SCup<<" "<<MCup<<" "<<LCup<<" "<<Income<<" "<<CoffeeID<<" "<<Nub<<endl;
     Write.close();
}

void Report_Day(int Day,int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0,Coffeeid=0,CoffeeNub=0;
     double TotalIncome=0;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          double tmpincmone;
          int tmpSCup,tmpMCup,tmpLCup;
          Read>>Report_Date>>Report_Month>>Report_Year>>tmpSCup>>tmpMCup>>tmpLCup>>tmpincmone>>Coffeeid>>CoffeeNub;

          if (Report_Date == Day && Report_Month == Month && Report_Year == Year)
          {
               Check++;
               total_SCup = total_SCup + tmpSCup;
               total_MCup = total_MCup + tmpMCup;
               total_LCup = total_LCup + tmpLCup;
               TotalIncome = TotalIncome + tmpincmone;
               Likes[Coffeeid] = Likes[Coffeeid] + CoffeeNub;
          }
          
     }
     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << "Total Cup: "<<Report_TotalCup << " Total s Cup: "<< total_SCup << " Total M Cup: "<<total_MCup<< " Total L Cup: "<<total_LCup<< " Total income: "<<TotalIncome<<endl;
          MostLike();
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_month(int Month,int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0,Coffeeid=0,CoffeeNub=0;
     double TotalIncome=0;
     int Check=0;
     int tmpIncome;
     int tmpSCup,tmpMCup,tmpLCup;
     fstream Read;
     Read.open("Data.txt",ios::in);
    while (Read >> Report_Date >> Report_Month >> Report_Year >> tmpSCup >> tmpMCup >> tmpLCup >> tmpIncome >> Coffeeid >> CoffeeNub) {
    if (Report_Month == Month && Report_Year == Year) {
        Check++;
        total_SCup += tmpSCup;
        total_MCup += tmpMCup;
        total_LCup += tmpLCup;
        TotalIncome += tmpIncome;
        Likes[Coffeeid] += CoffeeNub;
    }
}

     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << "Total Cup: "<<Report_TotalCup << " Total s Cup: "<< total_SCup << " Total M Cup: "<<total_MCup<< " Total L Cup: "<<total_LCup<< " Total income: "<<TotalIncome<<endl;
          MostLike();
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
     
}

void Report_year(int Year){
     int Report_Date,Report_Month,Report_Year;
     int Report_TotalCup=0,total_SCup=0,total_MCup=0,total_LCup=0,Coffeeid=0,CoffeeNub=0;
     double TotalIncome=0;
     int Check=0;
     fstream Read;
     Read.open("Data.txt",ios::in);
     while (!Read.eof())
     {
          double tmpincmone;
          int tmpSCup,tmpMCup,tmpLCup;
          Read>>Report_Date>>Report_Month>>Report_Year>>tmpSCup>>tmpMCup>>tmpLCup>>tmpincmone>>Coffeeid>>CoffeeNub;

          if (Report_Year == Year)
          {
               Check++;
               total_SCup = total_SCup + tmpSCup;
               total_MCup = total_MCup + tmpMCup;
               total_LCup = total_LCup + tmpLCup;
               TotalIncome = TotalIncome + tmpincmone;
               Likes[Coffeeid] = Likes[Coffeeid] + CoffeeNub;
          }
          
     }
     Report_TotalCup = total_SCup + total_MCup + total_LCup;
     Read.close();
     if (Check != 0)
     {
          cout << " Total Cup: "<<Report_TotalCup << " Total s Cup: "<< total_SCup << " Total M Cup: "<<total_MCup<< " Total L Cup: "<<total_LCup<< " Total income: "<<TotalIncome<<endl;
          MostLike();
     }
     else{
          cout <<"Data Not Exist"<<endl;
     }
}