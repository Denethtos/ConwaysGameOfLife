/*******************************************************************************/
/** In dieser Funktion werden alle Aufräumarbeiten getätigt, welche nicht in  **/
/** den Destruktoren der Klassen gemacht werden konnten.                      **/
/*******************************************************************************/

#include "Game.h"

void Game::GameCleanUp() {
    SDL_FreeSurface(Surf_ButtonStart);
    SDL_FreeSurface(Surf_ButtonStop);
    SDL_FreeSurface(Surf_ButtonReset);
    SDL_FreeSurface(Surf_Grid);
    SDL_FreeSurface(Surf_Display);
    SDL_FreeSurface(Surf_CellAlive);
    SDL_FreeSurface(Surf_CellDead);
    atexit(SDL_Quit);
}
