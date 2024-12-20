#include <iostream>
#include <fstream>
#include <iomanip>
#include "Report.h"
#include "Queue.h"
#include "Game.h"
#include "Survey.h"
using namespace std;

int Stop=0;
int today_Scup=0,today_Mcup=0,today_Lcup=0;
int cos_Scup=0,cos_Mcup=0,cos_Lcup=0;
double Cos_Total=0,today_income = 0;
int Today_Top_Sells[20],ID_Top_Sel,Number_Top_Sell;

time_t now = time(0);
tm *ltm = localtime(&now);

int today_Date = ltm->tm_mday
   ,today_Month = 1 + ltm->tm_mon
   ,today_Year = 1900 + ltm->tm_year
;

CoffeeMenu List[20];
int i = 0;

void FindTopSell(){
     for (int r = 0; r < 15; r++)
     {
          if (Today_Top_Sells[r] < Today_Top_Sells[r+1])
          {
               ID_Top_Sel = r+1;
               Number_Top_Sell = Today_Top_Sells[r+1];     
          }
     }
     for (int r = 0; r < 15; r++)
     {
          if (Today_Top_Sells[ID_Top_Sel] < Today_Top_Sells[r])
          {
               ID_Top_Sel = r;
               Number_Top_Sell = Today_Top_Sells[r];     
          }
     }
}
void ReadDataToCoffee(){
     fstream listCoffee;
     listCoffee.open("CoffeeList.txt",ios::in);
     int N,Price;
     double SPrice,MPrice,LPrice;
     string Name;
     while (!listCoffee.eof())
     {
          listCoffee >> N >> Name >> SPrice >> MPrice >> LPrice;
          List[i].No = N;
          List[i].Type = Name;
          List[i].S = SPrice;
          List[i].M = MPrice;
          List[i].L = LPrice;
          i++;
     }
     listCoffee.close();
}

void ReadData(){
    fstream F1;
    float priceS,priceM,priceL;
    string cafe;
    string line;

    F1.open("Menu.txt", ios::in);
    while(!F1.eof()){
    getline(F1,line);
    cout<<line<<endl;
    }
    F1.close();
}
bool password(string password)
{
  if(password == "Haven1122")
  {
    return true;
  }
  else
  {
    return false;
  }
}


double discount(double Price, bool discountEarned, int totalCups) {
    if (Price < 0) {
        cout << "Invalid input!! Please try again.\n\n";
        return -1; // Return error for invalid input
    }

    double discountAmount = 0.0; // Default no discount

    // Apply game discount first if earned
    if (discountEarned) {
        Price -= 1.0;  // Subtract $1 if the game discount is earned
        cout << "\nCongratulations! You earned a $1 discount from the game." << endl;
    }

    // Ensure that price doesn't drop below $1 after the game discount

    // If the customer buys more than 10 cups, apply a general discount
    if (totalCups > 10) {
        if (Price >= 10 && Price < 20) {
            discountAmount = Price * 5 / 100; // 5% discount
            cout << "\nDiscount: 5%";
        } else if (Price >= 20 && Price <= 50) {
            discountAmount = Price * 10 / 100; // 10% discount
            cout << "\nDiscount: 10%";
        } else if (Price > 50) {
            discountAmount = Price * 20 / 100; // 20% discount
            cout << "\nDiscount: 20%";
        }
    }

    // Apply general discount after game discount
    double AfterDiscount = Price - discountAmount;

    // Ensure that price is not less than $1 after all discounts
    if (AfterDiscount < 0.0) {
        AfterDiscount = 0.0;
    }

    return AfterDiscount; // Return the final price after all discounts
}
void priceCar(CoffeeMenu Menu[], int type[], int Size[], int number[], int arrSize, bool discountEarned) {
    Cos_Total = 0;
    double totalPrice = 0, afCal;
    int totalCups = 0; // Track the total number of cups purchased
    int smallcups=0,mediumcups=0,largecups=0;
    system("color 01");

    ofstream outFile("Data.txt", ios::app); // Open file in append mode
    if (!outFile.is_open()) {
        cout << "Error: Unable to open Data.txt for writing.\n";
        return;
    }

    // Get the current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    outFile << "Order Details (" 
            << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << ltm->tm_year + 1900 << "):\n";

    for (int oS = 0; oS < arrSize; oS++) {
        totalPrice = 0;
        totalCups += number[oS]; // Add number of cups to the total
        if (Size[oS] == 1) smallcups += number[oS]; // Small
        else if (Size[oS] == 2) mediumcups += number[oS]; // Medium
        else if (Size[oS] == 3) largecups += number[oS]; // Large

        Today_Top_Sells[type[oS]] = Today_Top_Sells[type[oS]] + number[oS];

          outFile << "Coffee ID           : " << type[oS] + 1 << "\n";

        if (type[oS] == 0) {
            cout << "Bullet" << "\t\t";
          outFile << "Type                : Bullet\n";
        } else {
            cout << Menu[type[oS]].Type << "\t\t";
          outFile << "Type                : " << Menu[type[oS]].Type << "\n";
        }

        // Apply price based on cup size
        if (Size[oS] == 1) { // Small
            afCal = Menu[type[oS]].S * number[oS];
            totalPrice = totalPrice + afCal;
            cout << Menu[type[oS]].S << "\t\t" << number[oS] << "\t" << totalPrice << "$" << endl;
            Cos_Total = Cos_Total + totalPrice;
          outFile << "Cup Size            : Small\n";
        } else if (Size[oS] == 2) { // Medium
            afCal = Menu[type[oS]].M * number[oS];
            totalPrice = totalPrice + afCal;
            cout << Menu[type[oS]].M << "\t\t" << number[oS] << "\t" << totalPrice << "$" << endl;
            Cos_Total = Cos_Total + totalPrice;
          outFile << "Cup Size            : Medium\n";
        } else if (Size[oS] == 3) { // Large
            afCal = Menu[type[oS]].L * number[oS];
            totalPrice = totalPrice + afCal;
            cout << Menu[type[oS]].L << "\t\t" << number[oS] << "\t" << totalPrice << "$" << endl;
            Cos_Total = Cos_Total + totalPrice;
          outFile << "Cup Size            : Large\n";
        }

          outFile << "Number of Cups      : " << number[oS] << "\n";
          outFile << "Price per Cup       : $" << (Size[oS] == 1 ? Menu[type[oS]].S : Size[oS] == 2 ? Menu[type[oS]].M : Menu[type[oS]].L) << "\n";
          outFile << "Total for this item : $" << totalPrice << "\n";
          outFile << "----------------------\n";
    }

    // Apply discounts after calculating the total price
    Cos_Total = discount(Cos_Total, discountEarned, totalCups);

    // Output the final price after all discounts
    cout << "\nThe total cost is " << Cos_Total << "$" << endl;
    today_income = Cos_Total + today_income;

    // Save discount details and total cost to file
    if (discountEarned) {
        outFile << "Discount Applied: $1\n"; // Example discount value
    }
    outFile << "Total Price (after discount): $" << Cos_Total << "\n";
    outFile << "-----------------------------------\n\n";

    outFile.close(); // Close the file
    cout << "Order saved to Data.txt successfully!\n";
}




void DateCheck(){
     
     cout << " - Year  :" << 1900 + ltm->tm_year<<endl;
     cout << " - Month : "<< 1 + ltm->tm_mon<< endl;
     cout << " - Day   : "<< ltm->tm_mday << endl;
     cout << " - Date saved."<<endl;
}

int main(){
     system("cls");
     //Start UP
     Queue *s;
     s = MakeNewList();
     DateCheck();
     ReadDataToCoffee();
     
     AppendDate();

     bool discountEarned = false;

     //Write below here
      int choice;
     while (true)
     {
          Menu:
          system("color 05");
          cout<<"\n\n\t\t----------Welcome to Haven-Cafe !!!---------"<<endl;
          cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
          cout<<" 1. Coffee Menu"<<endl;
          cout<<" 2. Game"<<endl;
          cout<<" 3. Order management"<<endl;
          cout<<" 4. Survey"<<endl;
          cout<<" 5. Admin"<<endl;
          cout<<" 6. Exit"<<endl;
          cout<<" \n=> Please enter your choice : ";cin>>choice;
          if (choice==1){
               cout<<"\n  ++ Coffee Menu ::"<<endl;
               char more;
               int n = 0;
               int typeofcoffee[10];
               int typeofcup[10];
               int numberofcup[10];
               Order:
               system("color 0A");
               cout<<"\n\n\t\t----------Welcome to Haven-Cafe !!!---------"<<endl;
               cout<<"\t\t----------      Free to ENJOY       ---------"<<endl;
               ReadData();
               IDorder:
               cout << " - Enter The ID of the Coffee : ";
               cin >> typeofcoffee[n];
               typeofcoffee[n] = typeofcoffee[n] - 1;
               if (List[typeofcoffee[n]].No == 0 || typeofcoffee[n] > 20)
               {
                    goto IDorder;
               }
               cout << " - Enter The Size of the Coffee: \n 1. Small\n 2. Medium\n 3. Large\n 4. Menu\n";
               cout <<" => ";
               cin >> typeofcup[n];
               if (typeofcup[n] == 4 || typeofcup[n] > 4)
               {
                    goto IDorder;
               }
               AmountCoff:
               cout << " - How many Cup u want ? \n(-1 Back to Menu) => : ";
               cin >> numberofcup[n];
               if (numberofcup[n] == -1)
               {
                    goto IDorder;
               }
               else if (numberofcup[n] < 0)
               {
                    cout <<" !!<< ONLY BIGGER THEN 0 >>";
                    goto AmountCoff;
               }
       
               wantmore:
               cout << " - Do You want to get more ?\n ( 1. Yes , 2. No ) ";
               cout<<" => ";
               cin >> more;
               
               if (more == '1')
               {
                    n++;
                    goto Order;
               }
               else if (more == '2')
               {
                    n++;
                    cout<<" \n >> Here is your Reciept : \n";
                    enqueue(s,typeofcoffee,typeofcup,numberofcup,n,List);
                    system("color 01");
                    cout << "Coffee \t\t Price per Cup \t Total cup \t Total: \n";
                    priceCar(List, typeofcoffee, typeofcup, numberofcup, n, discountEarned);
                    goto Menu;

               }
               else
               {
                    goto wantmore;
               }
          }
          if (choice == 2)
          {
          cout << "\n ++ Game For Customer (Waiting for Serve)::" << endl;
          system("cls");
          char an;
          cout << " ----->>   Game   <<-----" << endl;
          cout << " |     Tic Tac Toe       |" << endl;
          cout << " ------------------------" << endl;

          // Ask if the user is ready to start the game
          cout << " - Are you Ready to Start The Game ?\n  1. Yes , 2. No \n => ";
          cin >> an;

          // Use a while loop to handle invalid inputs and allow for a choice
          while (true)
          {
               system("cls");
               if (an == '1') {
                    cout << " \t<< Game Start !! >>\n" << endl;
                    char GameChoice;
                    srand(time(NULL));
                    GameChoice = (rand() % 3) + 1;

                    if (GameChoice == 1) {
                         Game1();
                         discountEarned=true; // Call the game function to start the game
                         goto Menu;
                    }

                    // After game ends, return to menu


               } else if (an == '2') {
                    cout << " << Exit Game!! >>" << endl;
                    goto Menu;  // Exit the loop and go back to the menu

               } else {
                    cout << " << Invalid Input! Please choose again >>" << endl;
                    cout << " - Are you Ready to Start The Game ?\n  1. Yes , 2. No \n => ";
                    cin >> an;
               }
          }
          }

    
          if (choice == 3){
               cout<<"\n ++ Customer Order ::"<<endl;
               int select;
               do
               {
                    again:
                    cout<<"  1.Display Order\n  2. Remove a Order (It has been served)\n  3. Back\n";
                    cout<<" \nEnter your choice : ";
                    cin>>select;
                    if(select==1)
                    {
                         Display_Queue_Cos(s);
                         cout<<"--------------------------------\n";
                         
                    }
                    else if(select==2)
                    {
                        string pass;
                         cout << "(e)For exit"<<endl;
                         cout << " ++ Password : ";
                         cin >> pass;
                         if (!password(pass))
                         {
                              cout << " << Wrong Password >>\n";
                              goto again;
                         }
                         else if (pass == "e")
                         {
                              goto again;
                         }
                         system("cls");
                         Dequeue(s);
                         cout << "Remove Successful\n";
                    }
                    else if(select==3)
                    {
                         goto Menu;
                    }
                    else{
                         cout<<" << Invalid input >> \n"<<endl;
                         goto again;
                    }
               }while(select!=4);

          }
          if (choice == 5)
          {
               system("color 04");
               cout<<"\n ++ Admin ::"<<endl;
               Wrpass:
               string pass;
               cout << "(e)For exit"<<endl;
               cout << " ** Password : ";
               cin >> pass;
               if (pass == "e")
               {
                    goto Menu;
               }
               else if (!password(pass))
               {
                    cout << " << Wrong Password >>\n";
                    goto Wrpass;
               }
               system("cls");
               int select;
               int RDay,Rmonth,Ryear;
               while(true){
                    cout << "1. Report Day\n";
                    cout << "2. Report Month\n";
                    cout << "3. Report year\n";
                    cout << "4. Survey Report\n";
                    cout << "5. Exit\n";
                    cout << " => ";
                    cin >> select;

            if (select == 1) {
                cout << " - Enter Day: ";
                cin >> RDay;
                cout << " - Enter Month: ";
                cin >> Rmonth;
                cout << " - Enter Year: ";
                cin >> Ryear;
                Report_Day(RDay, Rmonth, Ryear);
            }
            else if (select == 2) {
                cout << " - Enter Month: ";
                cin >> Rmonth;
                cout << " - Enter Year: ";
                cin >> Ryear;
                Report_Month(Rmonth,Ryear);
            }
            else if (select == 3) {
                cout << " - Enter Year: ";
                cin >> Ryear;
                Report_Year(Ryear);
            }
            else if (select == 4) {
                ReadSurvey();
               
            }
            else if (select == 5) {
                break;  // Exit from the loop to return to the main menu
            }
            else {
                cout << "  << Invalid input  >>\n" << endl;
               }
                    
               
               }
          }
          if (choice == 4)
          {
               system("cls");
               cout<<"\n ++ Customer Survey ::"<<endl;
               int k=1;
               char answer1;string answer2;
               char anSurvey;
               while(true){
                    Strate:
                    cout<<" \nWould you like to Do the Survey with Haven ?"<<endl;
                    cout<<" 1. Yes , 2. No"<<endl;
                    cout<<" => ";
                    cin>>anSurvey;
               if(anSurvey == '1'){
                    cout<<" Please read Question Carefully !!"<<endl;
                    ReadSurveyQ();
                    
                    for(k=1;k<=3;k++){
                         cout<<" Q : "<<k;
                         cout<<". (1. Good , 2. Normal, 3. Bad)"<<endl;
                         cout<<" => Answer : ";cin>>answer1;
                         while(answer1>'3' ){
                              cout<<" << Invalid Input! ";
                              cout<<"Please Input agian>>"<<endl;
                              cout<<"  Q : "<<k;
                              cout<<". (1. Good , 2. Normal, 3. Bad)"<<endl;
                              cout<<" => Answer : ";cin>>answer1;}
                              WriteSurvey1(k,answer1);
                         }
                         for(k=4;k<=5;k++){
                              if(k==4){
                                   cout<<" Q : "<<k;
                                   cout<<". (1. Yes, 2. No)"<<endl;
                                   cout<<" => Answer : ";cin>>answer1;
                                   while(answer1>'2' ){
                                   cout<<" << Invalid Input! ";
                                   cout<<"Please Input agian>>"<<endl;
                                   cout<<"  Q : "<<k;
                                   cout<<". (1. Yesc, 2. No)"<<endl;
                                   cout<<" => Answer : ";cin>>answer1;}
                                   WriteSurvey1(k,answer1);
                              }
                              else{
                                   cout<<" Q : "<<k;
                                   cout<<" => Feedbaack Or Suggestion : ";
                                   cin.ignore();
                                   getline(cin,answer2);
   
                                   WriteSurvey2(k,answer2);
                                   cout<<"\n";
                              }
                         }
               }
               else if(anSurvey=='2'){
                    cout<<" <<Exit Survey>>"<<endl;
                    cout<<" xxx- Thanks You for Visiting Us -xxx"<<endl;
                    goto Menu;
               }
               else{
               cout<<" << Invalid Input! ";
               cout<<"Please choose again >>"<<endl;
               goto Strate;
               }
               goto Menu;

               }
          }
          if (choice == 6)
          {
               cout<<"\n + Close Shop ::"<<endl;
               break;
          }          
     }
         
     FindTopSell();

     return 0;
     }
