//survey here
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

void ReadSurveyQ() {
    fstream Survey1;
    string line1;

    Survey1.open("SurveyFile.txt", ios::in);
    if (!Survey1) {
        cout << "Error: Unable to open SurveyFile.txt" << endl;
        return;
    }

    while (getline(Survey1, line1)) {
        cout << line1 << endl;
    }

    Survey1.close();
}

void WriteSurvey1(int q_no, char answer1) {
    fstream Write1;
    cout << "\n";
    Write1.open("QuestionInReport.txt", ios::app);
    if (!Write1) {
        cout << "Error: Unable to open QuestionInReport.txt for writing." << endl;
        return;
    }
    Write1 << " Question" << q_no << " : " << answer1 << " ,";
    Write1.close();
}

void WriteSurvey2(int q_no, string answer2) {
    fstream Write2;
    Write2.open("QuestionInReport.txt", ios::app);
    if (!Write2) {
        cout << "Error: Unable to open QuestionInReport.txt for writing." << endl;
        return;
    }
    Write2 << " " << q_no << " Feedback : " << answer2 << endl;
    Write2.close();
}

// Display survey reports in Admin part
void ReadSurvey() {
    fstream Survey2;
    string line2;

    Survey2.open("QuestionInReport.txt", ios::in);
    if (!Survey2) {
        cout << "Error: Unable to open QuestionInReport.txt" << endl;
        return;
    }

    while (getline(Survey2, line2)) {
        cout << line2 << endl;
    }

    Survey2.close();
}

// Append Date for each survey entry
void AppendDate() {
    fstream WriteDate;
    WriteDate.open("QuestionInReport.txt", ios::app);
    if (!WriteDate) {
        cout << "Error: Unable to open QuestionInReport.txt for appending date!" << endl;
        return;
    }

    // Get current date
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_mday;
    int month = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    // Write the date to the file
    WriteDate << "\nDate: " << day << "/" << month << "/" << year << endl;
    WriteDate.close();
}
void CheckSurveyReport(int day, int month, int year) {
    fstream Survey2;
    string line2;
    bool surveyFound = false;  // To track if survey data is found for the given date
    bool datePrinted = false;  // To track if the date has been printed

    Survey2.open("QuestionInReport.txt", ios::in);
    if (!Survey2) {
        cout << "Error: Unable to open QuestionInReport.txt" << endl;
        return;
    }

    while (getline(Survey2, line2)) {
        // Look for the date in the format "Date: day/month/year"
        size_t datePos = line2.find("Date: ");
        if (datePos != string::npos) {
            int surveyDay, surveyMonth, surveyYear;
            // Parse the date line correctly
            int result = sscanf(line2.c_str(), "Date: %d/%d/%d", &surveyDay, &surveyMonth, &surveyYear);

            // Ensure the date was successfully parsed
            if (result == 3) {
                // If the date matches, print it and start printing the survey data
                if (surveyDay == day && surveyMonth == month && surveyYear == year) {
                    if (!datePrinted) {
                        cout << line2 << endl;  // Print the date once
                        datePrinted = true;
                    }
                    surveyFound = true;  // Found survey data for the specified date
                }
            }
        }
        // Only print feedback after the date is printed
        else if (datePrinted && line2.find("Feedback") != string::npos) {
            cout << line2 << endl;  // Print feedback
        }
    }

    // If no survey data found for the specified date, print nothing
    if (!surveyFound) {
        cout << "No survey data found for the given date." << endl;
    }

    Survey2.close();
}
