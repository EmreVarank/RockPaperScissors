#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    int choice, computer, x, player_score = 0, computer_score = 0;
    string name;
    int round;

	//loop for main menu
     while (true) {
        cout << "Welcome to the Rock Paper Scissors game." << endl;
        cout << "Press 1 to start the game, 2 for rules, and 3 to exit." << endl;
        cin >> x;

    if (x == 1) {
        cout << "Enter your name: ";
        cin >> name;

       //specifying the number of rounds 
        cout << "How many rounds do you want to play ";
        cin >> round;


        for (int i = 0; i < round; i++) {
        	cout << "   " << endl;
            cout << "Press 1 for Rock, 2 for Paper, and 3 for Scissors: " << endl;
            cin >> choice;
            if(choice > 3 || choice < 1){
            	cout << "Invalid choice. Please try again." << endl;
			}
            cout << "   " << endl;

            srand(time(NULL));
            computer = 1 + rand() % 3;

            if (computer == 1) {
                cout << "Computer's choice = Rock" << endl;
            } else if (computer == 2) {
                cout << "Computer's choice = Paper" << endl;
            } else {
                cout << "Computer's choice = Scissors" << endl;
            }

            if (choice == computer) {
                cout << "Round draw." << endl;
                cout << "   " << endl;
            } else if ((choice == 1 && computer == 3) || 
                       (choice == 2 && computer == 1) || 
                       (choice == 3 && computer == 2)) {
                cout << "You Won." << endl;
                cout << "   " << endl;
                player_score++;
            } else {
                cout << "You Lost." << endl;
                cout << "   " << endl;
                computer_score++;
            }

            cout << "SCOREBOARD\n";
            cout << name << " : " << player_score << " | Computer : " << computer_score << endl;
        }

        // scoreboard
        if (player_score > computer_score) {
            cout << "\nGame Over! Winner is: " << name << endl; 
        } else if (computer_score > player_score) {
            cout << "\nGame Over! Winner is: Computer" << endl;
        } else {
            cout << "\nGame Over! Its tie." << endl;
        }

    } 
	//rules
	else if (x == 2) {
    	cout << "   " << endl;
        cout << "Each round is worth 1 point.\nNeither side receives points in case of a tie.\nRock > Scissors\nScissors > Paper\nPaper > Rock" << endl;
        cout << "   " << endl;
    }
	// over 
	 else if (x == 3) {
        cout << "Exiting..." << endl;
    } else {
        cout << "You made an invalid choice, redirecting to the main menu." << endl;
    }
}
    return 0;
}

