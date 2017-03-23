// IFT3100H17_ShaderClassic/renderer.cpp
// Classe responsable du rendu de l'application.

#include "renderer.h"

Renderer::Renderer(){}

void Renderer::setup()
{
  ofSetFrameRate(60);
  ofSetSphereResolution(32);
  ofSetLogLevel(OF_LOG_VERBOSE); // pour voir un log sur la compilation des shaders
  ofEnableDepthTest();

  // paramètres
  cameraOffset     = 350;
  speedMotion      = 150;
  speedOscillation = 7500;
  xInitial         = 0;
  yInitial         = -100;
  scaleCube        = 100.0f;
  scaleSphere      = 80.0f;
  scaleTeapot      = 0.618f;

  // initialisation des variables
  xOffset = xInitial;
  zOffset = yInitial;

  xDelta = speedMotion;
  zDelta = speedMotion;

  isFlipAxisY = false;

  // vecteurs de position des géométries
  positionCube   = new ofVec3f();
  positionSphere = new ofVec3f();
  positionTeapot = new ofVec3f();

  // chargement d'un modèle 3D
  teapot = new ofxAssimpModelLoader();
  teapot->loadModel("teapot.obj");

  // instanciation d'une lumière dynamique
  lightPoint = new ofLight();

  // instanciation des shaders
  shaderColorFill  = new ofShader();
  shaderLambert    = new ofShader();
  shaderGouraud    = new ofShader();
  shaderPhong      = new ofShader();
  shaderBlinnPhong = new ofShader();

  // paramétrer la version des shaders en GLSL

  switch(glVersionMajor)
  {
    case 3:
      shaderVersion = "V330";
      break;
    default:
      shaderVersion = "V120";
  }

  // charger, compiler et linker les sources des shaders
  shaderColorFill->load(
    "shader/" + shaderVersion + "/ColorFillVS.glsl",
    "shader/" + shaderVersion + "/ColorFillFS.glsl");

  shaderLambert->load(
    "shader/" + shaderVersion + "/LambertVS.glsl",
    "shader/" + shaderVersion + "/LambertFS.glsl");

  shaderGouraud->load(
    "shader/" + shaderVersion + "/GouraudVS.glsl",
    "shader/" + shaderVersion + "/GouraudFS.glsl");

  shaderPhong->load(
    "shader/" + shaderVersion + "/PhongVS.glsl",
    "shader/" + shaderVersion + "/PhongFS.glsl");

  shaderBlinnPhong->load(
    "shader/" + shaderVersion + "/BlinnPhongVS.glsl",
    "shader/" + shaderVersion + "/BlinnPhongFS.glsl");

  // shader actif au lancement de la scène
  activeShader = Shading::BLINN_PHONG;

  // initialisation de la scène
  reset();
}

void Renderer::reset()
{
  // initialisation des variables
  framebufferWidth  = ofGetWidth();
  framebufferHeight = ofGetHeight();

  // centre du framebuffer
  xCenter = framebufferWidth / 2.0f;
  yCenter = framebufferHeight / 2.0f;

  // caméra à sa position initiale
  xOffset = xInitial;
  zOffset = yInitial;

  // déterminer la position des géométries
  positionCube->set(-framebufferWidth * (1.0f/4.0f), 0, 0);
  positionSphere->set(0, 0, 0);
  positionTeapot->set(framebufferWidth * (1.0f/4.0f), 50, 0);

  // configurer la lumière ponctuelle
  lightPoint->setDiffuseColor  (ofColor(255, 255, 255));
  lightPoint->setSpecularColor (ofColor(191, 191, 191));
  lightPoint->setPointLight();

  ofLog() << "<reset>";
}

void Renderer::update()
{
  // transformer la lumière ponctuelle
  lightPoint->setGlobalPosition(
    ofMap(ofGetMouseX()/(float)framebufferWidth, 0.0f, 1.0f, - framebufferWidth / 2.0, framebufferWidth / 2.0),
    ofMap(ofGetMouseY()/(float)framebufferHeight, 0.0f, 1.0f, -framebufferHeight / 2.0, framebufferHeight / 2.0),
    -zOffset * 1.5f);

  // passer les attributs uniformes au shader de sommets
  switch(activeShader)
  {
    case Shading::COLOR_FILL:
      shaderName = "Color Fill";
      shader = shaderColorFill;
      shader->begin();
      shader->setUniform3f("color", 1.0f, 1.0f, 0.0f);
      shader->end();
      break;

    case Shading::LAMBERT:
      shaderName = "Lambert";
      shader = shaderLambert;
      shader->begin();
      shader->setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader->setUniform3f("colorDiffuse",  0.6f, 0.6f, 0.6f);
      shader->end();
      break;

    case Shading::GOURAUD:
      shaderName = "Gouraud";
      shader = shaderGouraud;
      shader->begin();
      shader->setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader->setUniform3f("colorDiffuse",  0.6f, 0.6f, 0.0f);
      shader->setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader->setUniform1f("brightness",    oscillate(ofGetElapsedTimeMillis(), 32, 5000, 0, 32));
      shader->end();
      break;

    case Shading::PHONG:
      shaderName = "Phong";
      shader = shaderPhong;
      shader->begin();
      shader->setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader->setUniform3f("colorDiffuse",  0.6f, 0.0f, 0.6f);
      shader->setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader->setUniform1f("brightness",    oscillate(ofGetElapsedTimeMillis(), 32, 5000, 0, 32));
      shader->end();
      break;

    case Shading::BLINN_PHONG:
      shaderName = "BlinnPhong";
      shader = shaderBlinnPhong;
      shader->begin();
      shader->setUniform3f("colorAmbient",  0.1f, 0.1f, 0.1f);
      shader->setUniform3f("colorDiffuse",  0.0f, 0.6f, 0.6f);
      shader->setUniform3f("colorSpecular", 1.0f, 1.0f, 0.0f);
      shader->setUniform1f("brightness",    oscillate(ofGetElapsedTimeMillis(), 32, 5000, 0, 32));
      shader->end();
      break;

    default:
      break;
  }
}

void Renderer::draw()
{
  ofBackground(0);

  ofPushMatrix();

    // position
    ofTranslate(lightPoint->getPosition());

  ofPopMatrix();

  // activer l'éclairage dynamique
  ofEnableLighting();

  // activer la lumière dynamique
  lightPoint->enable();

  ofPushMatrix();

    // inverser l'axe Y pour qu'il pointe vers le haut
    ofScale(1, isFlipAxisY ? -1 : 1);

    // transformer l'origine de la scène au milieu de la fenêtre d'affichage
    ofTranslate(xCenter + xOffset, isFlipAxisY ? -yCenter : yCenter, zOffset);

    ofPushMatrix();

      // position
      ofTranslate(
        positionCube->x,
        positionCube->y,
        positionCube->z);

      // rotation locale
      ofRotate(45.0f, 1, 0, 0);

      // activer le shader
      shader->begin();

      // passer les attributs uniformes au shader
      shader->setUniform3f("lightPosition", lightPoint->getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner un cube
      ofDrawBox(0, 0, 0, scaleCube);

      // désactiver le shader
      shader->end();

    ofPopMatrix();

    ofPushMatrix();

      // position
      ofTranslate(
        positionSphere->x,
        positionSphere->y,
        positionSphere->z);

      // activer le shader
      shader->begin();

      // passer les attributs uniformes au shader
      shader->setUniform3f("lightPosition", lightPoint->getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner une sphère
      ofDrawSphere(0, 0, 0, scaleSphere);

      // désactiver le shader
      shader->end();

    ofPopMatrix();

    ofPushMatrix();

      // position
      teapot->setPosition(
        positionTeapot->x,
        positionTeapot->y + 15, // un léger offset pour l'alignement
        positionTeapot->z);

      // dimension
      teapot->setScale(
        scaleTeapot,
        scaleTeapot,
        scaleTeapot);

      // désactiver le matériau par défaut du modèle
      teapot->disableMaterials();

      // activer le shader
      shader->begin();

      // passer les attributs uniformes au shader
      shader->setUniform3f("lightPosition", lightPoint->getGlobalPosition() * ofGetCurrentMatrix(OF_MATRIX_MODELVIEW));

      // dessiner un teapot
      teapot->draw(OF_MESH_FILL);

      // désactiver le shader
      shader->end();

    ofPopMatrix();

  ofPopMatrix();

  // désactiver la lumière
  lightPoint->disable();

  // désactiver l'éclairage dynamique
  ofDisableLighting();
}

Renderer::~Renderer()
{
  delete shaderColorFill;
  delete shaderLambert;
  delete shaderGouraud;
  delete shaderPhong;
  delete shaderBlinnPhong;

  delete lightPoint;

  delete teapot;

  delete positionCube;
  delete positionSphere;
  delete positionTeapot;
}
