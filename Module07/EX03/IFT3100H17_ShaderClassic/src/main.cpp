// IFT3100H17_ShaderClassic/main.cpp
// Exemple de projet qui supporte une version moderne (3.3) et une version de base (2.1)
// du pipeline programmable de OpenGL, avec shader en version 330 et 120 respectivement.
// Dans chaque cas, quatre shaders sont disponibles (touches 1-4), soit :
// un shader de couleur de remplissage uniforme,
// un shader avec modèle d'illumination de Lambert,
// un shader avec modèle d'illumination de Gouraud,
// un shader avec modèle d'illumination de Phong et
// un shader avec modèle d'illumination de Blinn-Phong.
// Certains attributs sont animés (facteur de brillance spéculaire) ou interactifs (position de la source de lumière).

#include "ofMain.h"
#include "application.h"

// point d'entrée de l'application
int main()
{
  // paramètres du contexte de rendu OpenGL
  ofGLWindowSettings windowSettings;

  windowSettings.width  = 1024;
  windowSettings.height = 512;

  // sélection de la version de OpenGL : option #1
  //windowSettings.setGLVersion(2, 1);

  // sélection de la version de OpenGL : option #2
  windowSettings.setGLVersion(3, 3);

  // création de la fenêtre
  ofCreateWindow(windowSettings);

  // démarrer l'exécution de l'application
  ofRunApp(new Application());
}
