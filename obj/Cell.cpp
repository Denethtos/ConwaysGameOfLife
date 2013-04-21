#include "Cell.h"

Cell::Cell() {
    for(int i = 0; i < 8; i++) {
        Neighbor[i] = NULL;
    }
}

Cell::~Cell() {
    for(int i = 0; i < 8; i++) {
        delete Neighbor[i];
    }
}

void Cell::setNeighbor(int Pos_Neighbor, Cell *NewNeighbor) {
}

void Cell::NextStep() {
}

void Cell::ChangeState(bool State) {
}

bool Cell::GetNeighborState(int Pos_Neighbor) {
    return Neighbor[Pos_Neighbor]->GetLastState();
}

bool Cell::GetActualState() {
}

bool Cell::GetLastState() {
    return LastState;
}
