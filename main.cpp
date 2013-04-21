/*******************************************************************************/
/** Conways Game of Life                                                      **/
/** Die main{}-funktion startet das Programm ung gibt bei ener fehlerfreien   **/
/** ausführung des Simulation 0 zurück. Wenn es einen Fehler gibt, gibt die   **/
/** Funktion 1 zurück.                                                        **/
/*******************************************************************************/

#include "Game.h"

int main(int argc, char* argv[]) {
    Game myGame;

    return myGame.GamePerform();
}
