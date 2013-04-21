/*******************************************************************************/
/** In dieser Funktion werden alle programmrelevanten Events behandelt.       **/
/*******************************************************************************/

#include "Game.h"

void Game::GameEvent(SDL_Event *Event) {
    switch(Event->type) {
        case SDL_QUIT: {
            running = false;
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            if(Event->button.button == SDL_BUTTON_LEFT) {
                if(Event->button.y < 25) {
                    if(Event->button.x < 150) {
                        OnSimulate = true;
                    }
                    else if(Event->button.x < 300) {
                        OnSimulate = false;
                    }
                    else {
                        OnSimulate = false;
                        GameOfLife.ResetActualState();
                        GameOfLife.ResetLastState();
                    }
                }
                else if(Event->button.y > 25) {
                    if(OnSimulate == false) {
                        int Pos_X = Event->button.x / 10;
                        int Pos_Y = (Event->button.y - 25) / 10;

                        if(GameOfLife.GetActualState(Pos_X, Pos_Y) == ALIVE) {
                            GameOfLife.Change_State(Pos_X, Pos_Y, DEAD);
                        }
                        else {
                            GameOfLife.Change_State(Pos_X, Pos_Y, ALIVE);
                        }
                    }
                }
            }
            break;
        }
    }
}
