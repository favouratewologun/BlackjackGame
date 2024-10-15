//class Game that connects all the other classes together and runs a full game of blackjack

#include "Game.h"
#include <iostream>
#include <string>
#include "Deck.h"
#include "Player.h"
#include <algorithm>

//sets the number of players in the game
void Game::setPlayers() {
    std::cout << "How many players? (1-7) ";
    std::cin >> numberPlayers;
    std::cout << std:: endl;

    while (numberPlayers < 1 || numberPlayers > 7){
        std::cout << "That is not a good number of players! Please choose a number between 1 and 7 (inclusive): ";
        std::cin >> numberPlayers;
    }

    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
        numberPlayers = 0; // Reset numberPlayers to ensure it enters the loop again
    }

    std::cout << std::endl;

    std::string name;
    for (int i = 0; i < numberPlayers; i++) {
        std::cout << "What is the name of Player " << i+1 << "? ";
        std::cin >> name;
        std::cout << std::endl;
        std::string stringName = name;
        Player name;
        name.setName(stringName);
        allPlayers.push_back(name);

    }
}

//plays the game
void Game::playGame() {

    //initialization and dealing of cards
    Deck newDeck;
    House theHouse;
    newDeck.populate();
    newDeck.shuffle();
    std::vector<Player>::iterator player;
    std::vector<Player> potentialWinner;
    int i = 0;
    for (player = allPlayers.begin(); player < allPlayers.end(); player++) {
        newDeck.initialDeal(player->myHand);
        allPlayers[i].playerStats();
        i++;
    }

    newDeck.initialDeal(theHouse.myHand);
    theHouse.houseStats('y');
    std::cout << std::endl << std::endl;

    //allows each player to hit until they want to stop or they bust
    for (auto player : allPlayers) {
        player.playerStats();

        if (player.myHand.getTotal() == 21) {
            std::cout << "You got 21!! Let's see how the house does..." << std::endl;
            potentialWinner.push_back(player);
            continue;
        }

        char hit;


        do {
            std::cout << player.getName() << ", do you want to hit? (y/n) ";
            std::cin >> hit;

            while (hit != 'y' && hit != 'Y' && hit != 'n' && hit != 'N') {
                std::cout << "That is not a valid answer! Please input y to keep hitting or n to stop hitting: ";
                std::cin >> hit;
            }


            if (hit == 'n' || hit == 'N') {
                std::cout << std::endl;
                break;
            } else {
                std::cout << std::endl;
                player.myHand.add(newDeck.deckOfCards[0]); //add cards, determine if ace is 11 or 1
                newDeck.deckOfCards.erase(newDeck.deckOfCards.begin());
                player.playerStats();
                char keepGoing = player.check();
                if (keepGoing == 'n' || keepGoing == '-')
                    break;

                //                   std::cout << std::endl;

            }

        } while (hit == 'Y' || hit == 'y');

        if (player.myHand.getTotal() <= 21) {
            potentialWinner.push_back(player);
        }


    }

    std::cout<<std::endl;

    //makes the house keep hitting until it busts or is in the appropriate range
    theHouse.houseStats('n');
    char houseHit;

    do {
        std::cout << "The house will keep hitting." << std::endl << std::endl;

        theHouse.myHand.add(newDeck.deckOfCards[0]);
        newDeck.deckOfCards.erase(newDeck.deckOfCards.begin());
        theHouse.houseStats('n');
        houseHit = theHouse.houseCheck();
        if (houseHit == 'n' || houseHit == '-')
            break;

    } while (houseHit == 'y');


    if (houseHit == 'n') {
        for (auto player : potentialWinner)
            player.win(player.getName());


    } else if (houseHit == '-') {
        for (auto player : potentialWinner) {
            if (player.myHand.getTotal() > theHouse.myHand.getTotal())
                player.win(player.getName());
            else if (player.myHand.getTotal() == theHouse.myHand.getTotal())
                player.push(player.getName());
            else
                player.lose(player.getName());
        }
    }


    //clears players' and house's cards
    for (auto player : allPlayers) {
        player.myHand.clear();
    }

    theHouse.myHand.clear();

}


