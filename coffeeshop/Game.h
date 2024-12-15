#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// Tic Tac Toe game data
char Sign[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool discountEarned = false; // Tracks if the customer earned a discount

// Check for winner
int Check_Winner() {
    if (Sign[1] == Sign[2] && Sign[2] == Sign[3]) return 1;
    if (Sign[1] == Sign[4] && Sign[4] == Sign[7]) return 1;
    if (Sign[1] == Sign[5] && Sign[5] == Sign[9]) return 1;
    if (Sign[2] == Sign[5] && Sign[5] == Sign[8]) return 1;
    if (Sign[3] == Sign[6] && Sign[6] == Sign[9]) return 1;
    if (Sign[3] == Sign[5] && Sign[5] == Sign[7]) return 1;
    if (Sign[4] == Sign[5] && Sign[5] == Sign[6]) return 1;
    if (Sign[7] == Sign[8] && Sign[8] == Sign[9]) return 1;

    // Check for draw
    if (Sign[1] != '1' && Sign[2] != '2' && Sign[3] != '3' && 
        Sign[4] != '4' && Sign[5] != '5' && Sign[6] != '6' && 
        Sign[7] != '7' && Sign[8] != '8' && Sign[9] != '9')
        return 0;

    return -1; // Game continues
}

// Display the Tic Tac Toe board
void ShowBoard() {
    system("cls");
    cout << "\n\tTic Tac Toe\n";
    cout << "  Player 1 Sign : Customer => (X)" << endl;
    cout << "  Player 2 Sign : Staff    => (O)" << endl;

    cout << "._______________________. " << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << Sign[1] << "   |   " << Sign[2] << "   |   " << Sign[3] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << Sign[4] << "   |   " << Sign[5] << "   |   " << Sign[6] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|   " << Sign[7] << "   |   " << Sign[8] << "   |   " << Sign[9] << "   |" << endl;
    cout << "|_______|_______|_______|" << endl
         << endl;
}

// Tic Tac Toe game logic
void Game1() {
    // Reset game state
    for (int i = 1; i <= 9; i++) Sign[i] = '0' + i;

    int player = 1, i;
    char choice, PlayerSign;

    do {
        ShowBoard();
        player = (player % 2) ? 1 : 2; // Switch between Player 1 and Player 2

        cout << "Player " << player << ", Enter Your Choice: ";
        cin >> choice;

        PlayerSign = (player == 1) ? 'X' : 'O';

        // Update the board based on the player's choice
        if (choice >= '1' && choice <= '9' && Sign[choice - '0'] == choice) {
            Sign[choice - '0'] = PlayerSign;
        } else {
            cout << " << Invalid Input! Please choose again >>" << endl;
            continue;
        }

        i = Check_Winner(); // Check the game status
        player++;

    } while (i == -1);

    ShowBoard();
    if (i == 1) {
        cout << "==>\aPlayer " << --player << " wins!" << endl;
        if (player == 1) {
            cout << "Congratulations! You got a $1 discount!" << endl;
            discountEarned = true;
        } else {
            cout << "Our staff won. No discount earned. Try next time!" << endl;
        }
    } else {
        cout << "---x--- \aGame Draw ---x---" << endl;
    }
    system("pause");
}
