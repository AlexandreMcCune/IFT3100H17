// IFT3100H17_ImageImport/main.cpp
// Exemple d'importation et d'affichage en pleine fenêtre d'une image,
// chargée à partir d'un fichier qui se trouve dans le répertoire ./bin/data
// ou à partir d'une image qui est glissée-déposée sur la fenêtre de l'application.

#include "ofMain.h"
#include "application.h"

int main( )
{
  ofSetupOpenGL(512, 512, OF_WINDOW);

  ofRunApp(new Application());
}
