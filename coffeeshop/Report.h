

#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm> // for fill
#include <iomanip>   // for setprecision
using namespace std;

struct Order {
    int coffeeID;
    string coffeeType;
    string cupSize;
    int numCups;
    double pricePerCup;
    double totalForItem;
};

string Name[20] = {"Bullet","Crown","Hot_Latte","Cappucino","Mocha","Cacoa","Vannila_Frape","Caramel_Frape","Salted_Caramel","Ice_Latte","Cappucino_BS","Espresso","Americano","Machhiato","Marochhino"};
int Likes[20];

void MostLike() {
    int LikeID = 0;
    int Amug = Likes[0];
    
    for (int i = 1; i < 20; i++) {
        if (Likes[i] > Amug) {
            Amug = Likes[i];
            LikeID = i;
        }
    }
    cout << "Most Ordered Coffee is " << Name[LikeID] << " with " << Amug << " likes.\n";
    
    // Reset Likes array to 0 if required
    fill(begin(Likes), end(Likes), 0);
}

void WriteData(int Day, int Month, int Year, vector<Order> orders) {
    fstream Write;
    Write.open("Data.txt", ios::app);  // Open the file in append mode
    
    if (!Write.is_open()) {
        cout << "Error opening the file for writing.\n";
        return;
    }

    // Write the header for the report
    Write << "Order Details (" << Day << "/" << Month << "/" << Year << "):\n";

    double totalPrice = 0.0;  // Initialize total price for the day

    // Loop through each order and write the details to the file
    for (const auto& order : orders) {
        Write << "Coffee ID: " << order.coffeeID << endl;
        Write << "Type: " << order.coffeeType << endl;
        Write << "Cup Size: " << order.cupSize << endl;
        Write << "Number of Cups: " << order.numCups << endl;
        Write << "Price per Cup: $" << order.pricePerCup << endl;
        Write << "Total for this item: $" << order.totalForItem << endl;
        Write << "----------------------\n";  // Separator for each order
        
        totalPrice += order.totalForItem;  // Add the total for this order to the day's total
    }

    // Calculate the total price after applying a discount (if any)
    double discount = 0.1;  // Example discount of 10%
    double discountedTotalPrice = totalPrice - (totalPrice * discount);

    // Write the total price (after discount)
    Write << "Total Price (after discount): $" << discountedTotalPrice << endl;
    Write << "-----------------------------------\n";  // Separator for the day

    Write.close();  // Close the file after writing
}

void Report_Day(int day, int month, int year) {
    fstream Read;
    Read.open("Data.txt", ios::in); // Open the file in read mode

    if (!Read.is_open()) {
        cout << "Error opening the file for reading.\n";
        return;
    }

    string line;
    bool foundData = false; // To track if any matching data is found
    int totalSmall = 0, totalMedium = 0, totalLarge = 0;
    double totalIncomeAfterDiscount = 0.0;

    while (getline(Read, line)) {
        // Check if the line contains the date in the format "Order Details (day/month/year):"
        size_t pos = line.find("Order Details");
        if (pos != string::npos) {
            // Extract the date part from the line
            string datePart = line.substr(pos + 15); // Skip "Order Details (" and extract the rest

            // Extract the day, month, and year from the date part (format: day/month/year)
            int orderDay, orderMonth, orderYear;
            sscanf(datePart.c_str(), "%d/%d/%d", &orderDay, &orderMonth, &orderYear); // Extract day, month, year

            // If the day, month, and year match the input, process this order
            if (orderDay == day && orderMonth == month && orderYear == year) {
                foundData = true;

                // Read and process the associated data
                while (getline(Read, line)) {
                    if (line.find("Order Details") != string::npos || line.empty()) {
                        break; // Stop if a new header starts or there's an empty line
                    }

                    // Check and count the cup sizes (ensure the format matches exactly)
                    if (line.find("Cup Size: Small") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalSmall += numCups;
                        }
                    } else if (line.find("Cup Size: Medium") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalMedium += numCups;
                        }
                    } else if (line.find("Cup Size: Large") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalLarge += numCups;
                        }
                    }

                    // Extract the total price for the item and add it to the total income
                    size_t pricePos = line.find("Total Price (after discount): $");
                    if (pricePos != string::npos) {
                        string priceStr = line.substr(pricePos + 31);

                        // Clean up the price string
                        priceStr.erase(0, priceStr.find_first_not_of(" \t"));
                        priceStr.erase(priceStr.find_last_not_of(" \t") + 1);
                        priceStr.erase(remove(priceStr.begin(), priceStr.end(), '$'), priceStr.end());

                        try {
                            double itemPrice = stod(priceStr); // Convert to a number
                            totalIncomeAfterDiscount += itemPrice;
                        } catch (const invalid_argument&) {
                            cout << "Error converting price: " << priceStr << endl;
                        }
                    }
                }
            }
        }
    }

    if (foundData) {
        // Display the summary of the report
        cout << "\nSummary for " << day << "/" << month << "/" << year << ":\n";
        cout << "Total Small Cups: " << totalSmall << endl;
        cout << "Total Medium Cups: " << totalMedium << endl;
        cout << "Total Large Cups: " << totalLarge << endl;
        cout << "Total Income for the Day: $" << fixed << setprecision(2) << totalIncomeAfterDiscount << endl;
    } else {
        cout << "No data found for the specified date.\n";
    }

    Read.close(); // Close the file
}
void Report_Month(int month, int year) {
    fstream Read;
    Read.open("Data.txt", ios::in); // Open the file in read mode

    if (!Read.is_open()) {
        cout << "Error opening the file for reading.\n";
        return;
    }

    string line;
    bool foundData = false; // To track if any matching data is found
    int totalSmall = 0, totalMedium = 0, totalLarge = 0;
    double totalIncomeAfterDiscount = 0.0;

    while (getline(Read, line)) {
        // Check if the line contains the date in the format "Order Details (day/month/year):"
        size_t pos = line.find("Order Details");
        if (pos != string::npos) {
            // Extract the date part from the line
            string datePart = line.substr(pos + 15); // Skip "Order Details (" and extract the rest

            // Extract the day, month, and year from the date part (format: day/month/year)
            int orderDay, orderMonth, orderYear;
            sscanf(datePart.c_str(), "%d/%d/%d", &orderDay, &orderMonth, &orderYear); // Extract day, month, year

            // If the month and year match the input, process this order
            if (orderMonth == month && orderYear == year) {
                foundData = true;

                // Read and process the associated data
                while (getline(Read, line)) {
                    if (line.find("Order Details") != string::npos || line.empty()) {
                        break; // Stop if a new header starts or there's an empty line
                    }

                    // Check and count the cup sizes (ensure the format matches exactly)
                    if (line.find("Cup Size: Small") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalSmall += numCups;
                        }
                    } else if (line.find("Cup Size: Medium") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalMedium += numCups;
                        }
                    } else if (line.find("Cup Size: Large") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalLarge += numCups;
                        }
                    }

                    // Extract the total price for the item and add it to the total income
                    size_t pricePos = line.find("Total Price (after discount): $");
                    if (pricePos != string::npos) {
                        string priceStr = line.substr(pricePos + 31);

                        // Clean up the price string
                        priceStr.erase(0, priceStr.find_first_not_of(" \t"));
                        priceStr.erase(priceStr.find_last_not_of(" \t") + 1);
                        priceStr.erase(remove(priceStr.begin(), priceStr.end(), '$'), priceStr.end());

                        try {
                            double itemPrice = stod(priceStr); // Convert to a number
                            totalIncomeAfterDiscount += itemPrice;
                        } catch (const invalid_argument&) {
                            cout << "Error converting price: " << priceStr << endl;
                        }
                    }
                }
            }
        }
    }

    if (foundData) {
        // Display the summary of the report
        cout << "\nSummary for " << month << "/" << year << ":\n";
        cout << "Total Small Cups: " << totalSmall << endl;
        cout << "Total Medium Cups: " << totalMedium << endl;
        cout << "Total Large Cups: " << totalLarge << endl;
        cout << "Total Income for the Month: $" << fixed << setprecision(2) << totalIncomeAfterDiscount << endl;
    } else {
        cout << "No data found for the specified month.\n";
    }

    Read.close(); // Close the file
}

void Report_Year(int year) {
    fstream Read;
    Read.open("Data.txt", ios::in); // Open the file in read mode

    if (!Read.is_open()) {
        cout << "Error opening the file for reading.\n";
        return;
    }

    string line;
    bool foundData = false; // To track if any matching data is found
    int totalSmall = 0, totalMedium = 0, totalLarge = 0;
    double totalIncomeAfterDiscount = 0.0;

    while (getline(Read, line)) {
        size_t pos = line.find("Order Details");
        if (pos != string::npos) {
            string datePart = line.substr(pos + 15); 
            int orderDay, orderMonth, orderYear;
            sscanf(datePart.c_str(), "%d/%d/%d", &orderDay, &orderMonth, &orderYear); 

            if (orderYear == year) {
                foundData = true;
                while (getline(Read, line)) {
                    if (line.find("Order Details") != string::npos || line.empty()) {
                        break; 
                    }
                    if (line.find("Cup Size: Small") != string::npos) {
                        getline(Read, line); 
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalSmall += numCups;
                        }
                    } else if (line.find("Cup Size: Medium") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalMedium += numCups;
                        }
                    } else if (line.find("Cup Size: Large") != string::npos) {
                        getline(Read, line); // Read the next line for "Number of Cups"
                        if (line.find("Number of Cups:") != string::npos) {
                            int numCups = 0;
                            sscanf(line.c_str(), "Number of Cups: %d", &numCups);
                            totalLarge += numCups;
                        }
                    }
                    size_t pricePos = line.find("Total Price (after discount): $");
                    if (pricePos != string::npos) {
                        string priceStr = line.substr(pricePos + 31);
                        priceStr.erase(0, priceStr.find_first_not_of(" \t"));
                        priceStr.erase(priceStr.find_last_not_of(" \t") + 1);
                        priceStr.erase(remove(priceStr.begin(), priceStr.end(), '$'), priceStr.end());

                        try {
                            double itemPrice = stod(priceStr); // Convert to a number
                            totalIncomeAfterDiscount += itemPrice;
                        } catch (const invalid_argument&) {
                            cout << "Error converting price: " << priceStr << endl;
                        }
                    }
                }
            }
        }
    }

    if (foundData) {
        // Display the summary of the report
        cout << "\nSummary for the year " << year << ":\n";
        cout << "Total Small Cups: " << totalSmall << endl;
        cout << "Total Medium Cups: " << totalMedium << endl;
        cout << "Total Large Cups: " << totalLarge << endl;
        cout << "Total Income for the Year: $" << fixed << setprecision(2) << totalIncomeAfterDiscount << endl;
    } else {
        cout << "No data found for the specified year.\n";
    }

    Read.close(); // Close the file
}









