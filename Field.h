/*******************************************************************************/
/** Diese Klasse ist für das komplette Feld zuständig. In dieser Klasse sind  **/
/** die Funktionen, durch die man die Simulation steuern kann.                **/
/*******************************************************************************/

#ifndef _FIELD_H_
#define _FIELD_H_

#include <SDL/SDL.h>

struct Cell {
    bool ActualState;
    bool LastState;
    Cell *Neighbor[8];
};

class Field {
    private:
        Cell GameField[50][50];

    public:
        Field();
        ~Field();

        Cell* GetNeighbor(int Pos_Neighbor, int X, int Y);

        void CalculateNewState();
        void Change_State(int Pos_X, int Pos_Y, bool newState);
        void NextStep();
        void ResetActualState();
        void ResetLastState();

        bool GetActualState(int Pos_X, int Pos_Y);
        bool GetLastState(int Pos_X, int PosY);
};

enum {
    DEAD = 0,
    ALIVE = 1
};

enum {
    UPPER_LEFT = 0,
    UPPER_MIDDLE,
    UPPER_RIGHT,
    MIDDLE_LEFT,
    MIDDLE_RIGHT,
    LOWER_LEFT,
    LOWER_MIDDLE,
    LOWER_RIGHT
};

#endif
