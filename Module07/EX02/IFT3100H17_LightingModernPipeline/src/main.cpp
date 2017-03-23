// IFT3100H17_LightingModernPipeline/main.cpp
// Démonstration de différents types de lumières et de matériaux du pipeline moderne de OpenGL (version 4.0).
// La scène contient trois modèles : un cube, une sphère et un teapot.
// Chaque modèle possède son propre matériau.
// L'éclairage de la scène est une lumière ambiante, directionnelle, pontuelle et projecteur.

#include "ofMain.h"
#include "application.h"

// point d'entrée de l'application
int main()
{
  // paramètres du contexte de rendu OpenGL
  ofGLWindowSettings windowSettings;

  windowSettings.width  = 1024;
  windowSettings.height = 512;

  // sélection de la version de OpenGL
  windowSettings.setGLVersion(4,0);

  // création de la fenêtre
  ofCreateWindow(windowSettings);

  // démarrer l'exécution de l'application
  ofRunApp(new Application());
}
