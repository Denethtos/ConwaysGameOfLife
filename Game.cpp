#include "Game.h"
Game::Game()
{
    running = true;
    OnSimulate = false;

    Surf_Display   = NULL;
    Surf_Grid      = NULL;
    Surf_CellAlive = NULL;
    Surf_CellDead  = NULL;
    Surf_ButtonStart = NULL;
    Surf_ButtonStop  = NULL;
    Surf_ButtonReset = NULL;

    Rct_ButtonStart;
    Rct_ButtonStop;
    Rct_ButtonReset;
}

Game::~Game()
{
    running = false;
    OnSimulate = false;

    delete Surf_Display;
    delete Surf_Grid;
    delete Surf_CellAlive;
    delete Surf_CellDead;
    delete Surf_ButtonStart;
    delete Surf_ButtonStop;
    delete Surf_ButtonStart;
}

int Game::GamePerform() {
    if(GameInit() == false) {
        return 1;
    }

    SDL_Event Event;

    while(running == true) {
        while(SDL_PollEvent(&Event)) {
            GameEvent(&Event);
        }
        GameLoop();
        GameRender();
    }

    GameCleanUp();

    return 0;
}


SDL_Surface* Game::BmpLoad(char* File) {
    SDL_Surface *Surf_Return = SDL_DisplayFormat(SDL_LoadBMP(File));
    return Surf_Return;
}
