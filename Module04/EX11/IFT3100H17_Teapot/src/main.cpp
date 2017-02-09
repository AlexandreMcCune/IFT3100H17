// IFT3100H17_Teapot/main.cpp
// Exemple de chargement et de rendu de plusieurs instances d'un teapot importé à partir d'un fichier de géométrie externe (format .obj).

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);
  ofRunApp(new Application());
}
