// IFT3100H17_ClearScreen/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

// énumération de différents modes pour effacer un framebuffer
enum class ClearMode {NONE, DEFAULT, BLACK, WHITE, GRAY, COLOR, RANDOM};

class Renderer
{
public:

  ClearMode clearMode;

  int clearColorGray;

  int clearColorRed;
  int clearColorGreen;
  int clearColorBlue;

  bool hasChanged;

  Renderer();

  void setup();
  void draw();

  void clear() const;
  void clearToBlack() const;
  void clearToWhite() const;
  void clearToGray(int g);
  void clearToColor(int r, int g, int b);
  void clearToRandom();

  ~Renderer();
};
