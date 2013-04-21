/*******************************************************************************/
/** In dieser Funktion wird der Bildschirm gerendert und anschlieﬂend auf dem **/
/** Bildschirm ausgegeben.                                                    **/
/*******************************************************************************/

#include "Game.h"

void Game::GameRender() {
    SDL_BlitSurface(Surf_Grid, NULL, Surf_Display, NULL);
    SDL_BlitSurface(Surf_ButtonStart, NULL, Surf_Display, &Rct_ButtonStart);
    SDL_BlitSurface(Surf_ButtonStop, NULL, Surf_Display, &Rct_ButtonStop);
    SDL_BlitSurface(Surf_ButtonReset, NULL, Surf_Display, &Rct_ButtonReset);

    SDL_Rect *Rct_Cell = new SDL_Rect;

    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            Rct_Cell->x = (X * 10);
            Rct_Cell->y = (Y * 10) + 25;

            if(GameOfLife.GetActualState(X, Y) == ALIVE) {
                SDL_BlitSurface(Surf_CellAlive, NULL, Surf_Display, Rct_Cell);
            }
            else {
                SDL_BlitSurface(Surf_CellDead, NULL, Surf_Display, Rct_Cell);
            }
        }
    }

    SDL_Flip(Surf_Display);
}
