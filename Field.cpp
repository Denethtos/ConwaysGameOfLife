#include "Field.h"

Field::Field() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            for(int i = 0; i < 8; i++) {
                GameField[X][Y].Neighbor[i] = GetNeighbor(i, X, Y);
            }
        }
    }
    ResetActualState();
    ResetLastState();
}

Field::~Field() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            for(int i = 0; i < 8; i++) {
                GameField[X][Y].Neighbor[i] = NULL;
            }
        }
    }

    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            for(int i = 0; i < 8; i++) {
                delete GameField[X][Y].Neighbor[i];
            }
        }
    }
}

Cell* Field::GetNeighbor(int Pos_Neighbor, int X, int Y) {
    int Pos_X = X, Pos_Y = Y;

    if(Pos_Neighbor == UPPER_LEFT || Pos_Neighbor == UPPER_MIDDLE || Pos_Neighbor == UPPER_RIGHT) {
        if(Pos_X == 0) {
            Pos_X = 50;
        }
        else {
            Pos_X -= 1;
        }
    }
    else if(Pos_Neighbor == LOWER_LEFT || Pos_Neighbor == LOWER_MIDDLE || Pos_Neighbor == LOWER_RIGHT) {
        if(Pos_X == 50) {
            Pos_X = 0;
        }
        else {
            Pos_X += 1;
        }
    }

    if(Pos_Neighbor == UPPER_LEFT || Pos_Neighbor == MIDDLE_LEFT || Pos_Neighbor == LOWER_LEFT) {
        if(Pos_Y == 0) {
            Pos_Y = 50;
        }
        else {
            Pos_Y -= 1;
        }
    }
    else if(Pos_Neighbor == UPPER_RIGHT || Pos_Y == MIDDLE_RIGHT || Pos_Neighbor == LOWER_RIGHT) {
        if(Pos_Y == 50) {
            Pos_Y = 0;
        }
        else {
            Pos_Y += 1;
        }
    }

    return &GameField[Pos_X][Pos_Y];
}

void Field::NextStep() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            GameField[X][Y].LastState = GameField[X][Y].ActualState;
        }
    }
}

/// Immer nur nach Field::NextStep() verwenden!
void Field::CalculateNewState() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            int NeighborAlive = 0;

            for(int i = 0; i < 8; i++) {
                if(GameField[X][Y].Neighbor[i]->LastState == ALIVE) {
                    NeighborAlive += 1;
                }
                else {
                    NeighborAlive = NeighborAlive;
                }
            }

            if(GameField[X][Y].LastState == DEAD) {
                if(NeighborAlive == 3) {
                    GameField[X][Y].ActualState = ALIVE;
                }
                else {
                    GameField[X][Y].ActualState = DEAD;
                }
            }
            else {
                if(NeighborAlive == 2 || NeighborAlive == 3) {
                    GameField[X][Y].ActualState = ALIVE;
                }
                else {
                    GameField[X][Y].ActualState = DEAD;
                }
            }
        }
    }
}

void Field::Change_State(int Pos_X, int Pos_Y, bool newState) {
    GameField[Pos_X][Pos_Y].ActualState = newState;
}

void Field::ResetActualState() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            GameField[X][Y].ActualState = DEAD;
        }
    }
}

void Field::ResetLastState() {
    for(int X = 0; X < 50; X++) {
        for(int Y = 0; Y < 50; Y++) {
            GameField[X][Y].LastState = DEAD;
        }
    }
}

bool Field::GetActualState(int Pos_X, int Pos_Y) {
    return GameField[Pos_X][Pos_Y].ActualState;
}

bool Field::GetLastState(int Pos_X, int Pos_Y) {
    return GameField[Pos_X][Pos_Y].LastState;
}
