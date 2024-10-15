//class Generic Player that has functions of a basic player (house or real player)

#include "GenericPlayer.h"
#include <iostream>

//indicates the player has busted
bool GenericPlayer::isBusted() {
    return 1;
}

//outputs that the player busted
void GenericPlayer::bust() {
    std::cout << "Bust!!";

}
