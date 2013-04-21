/*******************************************************************************/
/** In dieser Funktion werden alle wichtigen Daten geladen und initiiert.     **/
/*******************************************************************************/

#include "Game.h"

bool Game::GameInit() {
    if((SDL_Init(SDL_INIT_EVERYTHING)) == -1) {
        return false;
    }

    if((Surf_Display = SDL_SetVideoMode(500, 525, 32, SDL_HWSURFACE||SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Grid = BmpLoad("./Pics/Grid.bmp")) == false) {
        return false;
    }

    if((Surf_CellAlive = BmpLoad("./Pics/CellAlive.bmp")) == false) {
        return false;
    }

    if((Surf_CellDead = BmpLoad("./Pics/CellDead.bmp")) == false) {
        return false;
    }

    if((Surf_ButtonStart = BmpLoad("./Pics/ButtonStart.bmp")) == false) {
        return false;
    }

    if((Surf_ButtonStop = BmpLoad("./Pics/ButtonStop.bmp")) == false) {
        return false;
    }

    if((Surf_ButtonReset = BmpLoad("./Pics/ButtonReset.bmp")) == false) {
        return false;
    }

    Rct_ButtonStart.x = 0;
    Rct_ButtonStart.y = 0;

    Rct_ButtonStop.x = 150;
    Rct_ButtonStop.y = 0;

    Rct_ButtonReset.x = 300;
    Rct_ButtonReset.y = 0;

    return true;
}
