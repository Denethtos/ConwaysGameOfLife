/*******************************************************************************/
/** Diese Klasse ist für die einzelnen Felder zuständig. Sie beinhaltet Funk- **/
/** tionen, welche die Routinen für die Simulation erleichtern.               **/
/*******************************************************************************/

#ifndef _CELL_H_
#define _CELL_H_

#include <SDL/SDL.h>

class Cell {
    private:
        bool ActualState;
        bool LastState;

        Cell *Neighbor[8];

    public:
        Cell();
        ~Cell();

        void setNeighbor(int Pos_Neighbor, Cell *NewNeighbor);
        void NextStep();
        void ChangeState(bool State);

        bool GetNeighborState(int Pos_Neighbor);
        bool GetActualState();
        bool GetLastState();
};

enum {
    ALIVE = true,
    DEAD  = false
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
