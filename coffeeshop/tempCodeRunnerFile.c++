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
                cout << " - Enter Date: ";
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