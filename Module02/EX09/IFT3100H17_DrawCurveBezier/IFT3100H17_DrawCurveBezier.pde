// IFT3100H17_DrawCurveBezier.pde
// Animation de courbes de Bézier cubiques avec quatre points de contrôle aléatoires.

// paramètres
int colorBack = 32;
int colorFill = 255;
int colorStroke = 192;

float decay = 2.0f;
float threshold = 0.6f;

// variables
float timeStarted;
float timeElapsed;
float timeDelay;
float timeFrame;

void setup()
{
  size(960, 540);
  frameRate(60);

  timeElapsed = 0.0f;
  timeDelay = 0.0f;
  timeFrame = 0.0f;
}

void draw()
{
  timeElapsed = (millis() - timeFrame) / 1000.0f;
  timeDelay += timeElapsed;
  timeFrame = millis();

  noStroke();

  // estompement de ce qui est déjà dessiné dans la fenêtre
  fill(colorBack, decay);
  rect(0, 0, width, height);

  if(timeDelay > threshold)
  {
    stroke(colorStroke);
    strokeWeight(3.0f);
    fill(colorFill, 64);

    // dessiner une courbe de Bézier cubique en fonction de la position x et y de ses quatre points de contrôle
    bezier(
      random(0.0f, 1.0f) * width,
      random(0.0f, 1.0f) * height,
      random(0.0f, 1.0f) * width,
      random(0.0f, 1.0f) * height,
      random(0.0f, 1.0f) * width,
      random(0.0f, 1.0f) * height,
      random(0.0f, 1.0f) * width,
      random(0.0f, 1.0f) * height);

    timeDelay -= threshold;
  }
}