#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Game.h"
#include "GenericPlayer.h"
#include "Hand.h"
#include "House.h"
#include "Player.h"

using namespace std;

int main() {
    cout << "Welcome to Blackjack! Have fun playing!" << endl;
    char playAgain;

    //plays the game for as long as the user wants to
    do {
        Game myGame;
        myGame.setPlayers();
        myGame.playGame();

        cout << "Do you want to play again? (y/n) ";
        cin >> playAgain;
        cout << endl;

        while(playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
            cout << "That is not a answer! Please input y to keep hitting or n to stop hitting: ";
            cin >> playAgain;
            cout << endl;
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! I hope you had fun!" << std::endl;

    return 0;

}
