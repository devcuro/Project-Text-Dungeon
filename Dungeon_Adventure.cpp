//********************************************************************
// Author.....: Andrew Hathaway
// Assignment.: Escape the Dungeon Adventure
// Description: This program is a text-based dungeon adventure game.
//              The player must navigate a series of choices in an
//              attempt to escape a mysterious underground dungeon.
//              Features include:
//              - Nested if-else logic for decision branches
//              - Switch statement for major game outcomes
//              - Input validation for robust user interaction
//              - Easter Eggs??????
//********************************************************************

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Easter Egg: Track invalid input attempts
int failCount = 0;

// Helper function to validate numeric input
int getValidatedInput(int min, int max) {
    int choice;
    while (true) {
        cout << "> ";
        cin >> choice;

        if (cin.fail() || choice < min || choice > max) {
            cin.clear(); // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            failCount++;
            if (failCount >= 5) {
                cout << "\nYou broke the game and found the hidden Dev Room!" << endl;
                cout << "Welcome, brave debugger. All doors are open to you.\nYou WIN (sort of)!" << endl;
                exit(0);
            }
            cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard rest of input
            failCount = 0; // reset on valid input
            return choice;
        }
    }
}

int main() {
    cout << "======================================" << endl;
    cout << "       Welcome to Escape the Dungeon  " << endl;
    cout << "======================================" << endl;
    cout << "You wake up in a dark, damp dungeon with two paths ahead." << endl;
    cout << "Your mission: find a way out alive." << endl;
    cout << endl;

    // Wall moment - Rickroll Easter Egg
    cout << "You see something written on the wall. Do you:\n1. Ignore it\n2. Lick it (why?)" << endl;
    int wallChoice = getValidatedInput(1, 2);
    if (wallChoice == 2) {
        cout << "\nNever gonna give you up, never gonna let you down..." << endl;
        cout << "You feel strange and pass out from licking mold. You lose!" << endl;
        return 0;
    }

    // First real decision point
    cout << "\nYou see two tunnels:\n1. Left Tunnel (faint torchlight)\n2. Right Tunnel (smells of sulfur)" << endl;
    cout << "Choose a path (1 or 2):" << endl;
    int tunnelChoice = getValidatedInput(1, 2);

    if (tunnelChoice == 1) {
        cout << "\nYou take the left tunnel and find a rusty sword and a healing potion." << endl;

        // Hug the wall moment
        cout << "You walk cautiously. Do you:\n1. Walk forward\n2. Hug the wall nervously" << endl;
        int hugWall = getValidatedInput(1, 2);

        if (hugWall == 2) {
            cout << "\nYou hug the wall... Nothing happens.\nWhat did you expect? It's a wall." << endl;
            cout << "A goblin appears... but notices your tender appreciation for the cave walls." << endl;
            cout << "He nods slowly, gives you a thumbs up, and walks away peacefully.\nYou may continue." << endl;
        } else {
            cout << "\nSuddenly, a goblin appears!" << endl;
            cout << "Do you:\n1. Fight the goblin\n2. Run away" << endl;
            int goblinChoice = getValidatedInput(1, 2);

            if (goblinChoice == 1) {
                cout << "\nYou bravely fight the goblin and win! You find a key on its body." << endl;
            } else {
                cout << "\nYou try to run but trip over a rock. The goblin catches you.\nYou lose!" << endl;
                return 0;
            }
        }

    } else {
        cout << "\nYou take the right tunnel and stumble into a spike trap.\nYou lose!" << endl;
        return 0;
    }

    // Second major decision point using switch
    cout << "\nYou reach a locked door with three keyholes." << endl;
    cout << "Which keyhole will you try?\n1. Gold-plated keyhole\n2. Rusted iron keyhole\n3. Bone-carved keyhole" << endl;
    int keyholeChoice = getValidatedInput(1, 3);

    switch (keyholeChoice) {
        case 1:
            cout << "\nA trap is triggered! Poison darts shoot out of the walls.\nYou lose!" << endl;
            break;
        case 2:
            cout << "\nThe door creaks open slowly. Light floods the dungeon.\nYou escape! You WIN!" << endl;
            break;
        case 3:
            cout << "\nA skeleton warrior rises from the floor and blocks your way.\nYou lose!" << endl;
            break;
    }

    return 0;
}
