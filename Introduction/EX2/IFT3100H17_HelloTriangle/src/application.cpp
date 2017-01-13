// IFT3100H17_HelloTriangle/application.cpp
// Classe principale de l'application.

#include "Application.h"

// fonction invoquée à l'initialisation de l'application
void Application::setup()
{
  ofSetWindowTitle("HelloTriangle");

  ofSetFrameRate(1);

  pointRadius = 8;
}

// fonction invoquée lors d'une mise à jour de la logique de l'application
void Application::update()
{
  vertex1X = ofRandom(0, ofGetWidth());
  vertex1Y = ofRandom(0, ofGetHeight());
  vertex2X = ofRandom(0, ofGetWidth());
  vertex2Y = ofRandom(0, ofGetHeight());
  vertex3X = ofRandom(0, ofGetWidth());
  vertex3Y = ofRandom(0, ofGetHeight());

  colorR = ofRandom(0, 255);
  colorG = ofRandom(0, 255);
  colorB = ofRandom(0, 255);

  ofLog() << setprecision(4) << "<triangle: v1:("
    << vertex1X << ", " << vertex1Y << ") v2:("
    << vertex2X << ", " << vertex2Y << ") v3:("
    << vertex3X << ", " << vertex3Y << ")>";
}

// fonction invoquée lors d'une mise à jour du rendu de la fenêtre de l'application
void Application::draw()
{
  ofClear(191);

  ofSetColor(colorR, colorG, colorB);

  ofDrawTriangle(
    vertex1X, vertex1Y,
    vertex2X, vertex2Y,
    vertex3X, vertex3Y);

  ofSetColor(0);

  ofDrawEllipse(vertex1X, vertex1Y, pointRadius, pointRadius);
  ofDrawEllipse(vertex2X, vertex2Y, pointRadius, pointRadius);
  ofDrawEllipse(vertex3X, vertex3Y, pointRadius, pointRadius);
}
