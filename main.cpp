/*******************************************************************************/
/** Conways Game of Life                                                      **/
/** Die main{}-funktion startet das Programm ung gibt bei ener fehlerfreien   **/
/** ausf�hrung des Simulation 0 zur�ck. Wenn es einen Fehler gibt, gibt die   **/
/** Funktion 1 zur�ck.                                                        **/
/*******************************************************************************/

#include "Game.h"

int main(int argc, char* argv[]) {
    Game myGame;

    return myGame.GamePerform();
}
