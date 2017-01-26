// IFT3100H17_DrawVectorPrimitives/renderer.h
// Classe responsable du rendu de l'application.

#pragma once

#include "ofMain.h"

// énumération des différents types de primitives vectorielles
enum class VectorPrimitive {NONE, PIXEL, POINT, LINE, RECTANGLE, ELLIPSE};

// structure de primitive vectorielle générique
typedef struct
{
  VectorPrimitive type;          // 1 * 4 = 4  octets
  float         position1   [2]; // 2 * 4 = 8  octets
  float         position2   [2]; // 2 * 4 = 8  octets
  float         strokeWidth;     // 1 * 4 = 4  octets
  unsigned char strokeColor [4]; // 4 * 1 = 4  octets
  unsigned char fillColor   [4]; // 4 * 1 = 4  octets
} StructVectorPrimitive;         //       = 32 octets

class Renderer
{
public:

  VectorPrimitive drawMode;

  StructVectorPrimitive * shape;

  int count;
  int size;
  int stride;

  int index;
  int head;

  int xMousePress;
  int yMousePress;

  int xMouseCurrent;
  int yMouseCurrent;

  float strokeWidthDefault;

  unsigned char strokeColorR;
  unsigned char strokeColorG;
  unsigned char strokeColorB;
  unsigned char strokeColorA;

  unsigned char fillColorR;
  unsigned char fillColorG;
  unsigned char fillColorB;
  unsigned char fillColorA;

  bool isMouseButtonPressed;

  Renderer();

  void setup();
  void draw();

  void reset();

  void addVectorShape(VectorPrimitive type);

  void drawPixel(float x, float y) const;
  void drawPoint(float x, float y, float radius) const;
  void drawLine(float x1, float y1, float x2, float y2) const;
  void drawRectangle(float x1, float y1, float x2, float y2) const;
  void drawEllipse(float x1, float y1, float x2, float y2) const;

  void randomColorStroke();
  void randomColorFill();

  void drawZone(float x1, float y1, float x2, float y2) const;
  void drawCursor(float x, float y) const;

  ~Renderer();
};
