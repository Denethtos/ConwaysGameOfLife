/*******************************************************************************/
/** Diese Klasse steuert die komplette Performance der Simulation.            **/
/*******************************************************************************/

#ifndef _GAME_H_
#define _GAME_H_

#include "Field.h"

class Game {
    private:
        bool running;
        bool OnSimulate;

        Field GameOfLife;

        SDL_Surface *Surf_Display;
        SDL_Surface *Surf_Grid;
        SDL_Surface *Surf_CellAlive;
        SDL_Surface *Surf_CellDead;
        SDL_Surface *Surf_ButtonStart;
        SDL_Surface *Surf_ButtonStop;
        SDL_Surface *Surf_ButtonReset;

        SDL_Rect Rct_ButtonStart;
        SDL_Rect Rct_ButtonStop;
        SDL_Rect Rct_ButtonReset;

    public:
        Game();
        ~Game();

        SDL_Surface* BmpLoad(char* File);

        bool GameInit();

        int GamePerform();

        void GameEvent(SDL_Event *Event);
        void GameLoop();
        void GameRender();
        void GameCleanUp();
};
#endif
