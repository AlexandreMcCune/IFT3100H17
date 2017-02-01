// IFT3100H17_ClearScreen/main.cpp
// Exemple de configuration de la couleur d'arrière-plan,
// avec une couleur fixe ou aléatoire (touches 1-6).

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}
