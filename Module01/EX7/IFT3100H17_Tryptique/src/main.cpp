// IFT3100H17_Tryptique/main.cpp
// Exemple d'échantillonnage dans une image chargée en mémoire pour en extraire 3 images différentes,
// qui sont affichées sur une rangée avec un espacement horizontal et vertical.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);

  ofRunApp(new Application());
}
