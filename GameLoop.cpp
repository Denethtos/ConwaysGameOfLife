/*******************************************************************************/
/** In dieser Funktion wird die Simulation "berechnet".                       **/
/*******************************************************************************/

#include "Game.h"

void Game::GameLoop() {
    if(OnSimulate == true) {
        SDL_Delay(250);
        GameOfLife.NextStep();
        GameOfLife.CalculateNewState();
    }
}
