// IFT3100H17_Move/main.cpp
// Mouvement dans l'espace sur le plan XZ à partir de l'état des flèches du clavier.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}