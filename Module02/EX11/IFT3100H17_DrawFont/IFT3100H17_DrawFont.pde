// IFT3100H17_DrawFont.pde
// Animation avec différentes polices de caractères à des positions aléatoires.

// paramètres
int nbOfFont = 10;

// tableau de chaînes de caractères
String[] strFont = {
  "Blackmoor",
  "Consolas",
  "Corsiva",
  "Courier",
  "Edwardian",
  "Helvetica",
  "Jazz",
  "Mistral",
  "Princetown",
  "Rosewood"
};

// tableau de chaînes de caractères
String[] strModule = {
  "1. Image",
  "2. Dessin vectoriel",
  "3. Transformation",
  "4. Géométrie",
  "5. Caméra",
  "6. Pipeline de rendu",
  "7. Illumination",
  "8. Lancer de rayon",
  "9. Topologie",
  "10. Effets visuels"
};

// chaînes de caractères
String strCourseID = "IFT3100H17";
String strCourseTitle = "Infographie";
String strSubject = "Les 10 modules théoriques du cours";

// variables
int indexCurrentFont;

int alpha;
int direction;

int offset;

float xPosition;
float yPosition;

color colorBack;
color colorFill;

// polices de caractères
PFont fontBlackmoor;
PFont fontConsolas;
PFont fontCorsiva;
PFont fontCourier;
PFont fontEdwardian;
PFont fontHelvetica;
PFont fontJazz;
PFont fontMistral;
PFont fontPrincetown;
PFont fontRosewood;

// police sélectionnée parmi l'ensemble
PFont font;

String strCurrentFont;
String strCurrentModule;
String strDisplay;

void setup()
{
  size(960,540);
  frameRate(60);

  // valeurs initiales
  alpha = 255;
  direction = -1;
  offset = 2;

  // chargement des polices de caractères (à partir du répertoire /data)
  fontBlackmoor  = loadFont("BlackmoorLetPlain-64.vlw");
  fontConsolas   = loadFont("Consolas-Bold-64.vlw");
  fontCorsiva    = loadFont("MonotypeCorsiva-64.vlw");
  fontCourier    = loadFont("Courier-Bold-64.vlw");
  fontEdwardian  = loadFont("EdwardianScriptITC-64.vlw");
  fontHelvetica  = loadFont("HelveticaNeue-Medium-64.vlw");
  fontJazz       = loadFont("JazzLetPlain-64.vlw");
  fontMistral    = loadFont("Mistral-64.vlw");
  fontPrincetown = loadFont("PrincetownLET-64.vlw");
  fontRosewood   = loadFont("RosewoodStd-Regular-64.vlw");

  // sélectionner un module au hasard
  selectRandomModule();

  // sélectionner une position au hasard
  selectRandomPosition();

  // sélectionner des couleurs au hasard
  selectRandomColor();

  // sélectionner une font au hasard
  selectRandomFont();
}

void draw()
{
  background(colorBack);

  // affichage du nom de la police de caractères
  strDisplay = strCurrentFont;

  textAlign(LEFT);
  textSize(24);
  fill(colorFill, 255);

  text(strDisplay, 15, 30);
  
  // affichage du sujet
  strDisplay = strSubject;

  textAlign(RIGHT);
  textSize(32);
  fill(colorFill, 255);

  text(strDisplay, width - 8, height - 36);

  // affichage de l'identifiant et du titre du cours
  strDisplay = strCourseID + " ~ " + strCourseTitle;

  textAlign(RIGHT);
  textSize(24);

  text(strDisplay, width - 8, height - 8);

  // affichage du nom du module
  strDisplay = strCurrentModule;

  textAlign(CENTER);
  textSize(64);
  fill(colorFill, alpha);

  text(strDisplay, xPosition, yPosition);

  // animer la valeur de transparence (fade in / fade out)
  if(direction == -1)
    alpha -= offset * 0.75f;
  else if(direction == 1)
    alpha += offset * 1.25f;

  if(alpha < 0) // à exécuter à la fin du fade out
  {
    // borne minimum pour la transparence
    alpha = 0;

    // changer la direction de l'animation (fade in)
    direction = 1;

    // redémarrer l'animation avec d'autres valeurs aléatoires
    selectRandomModule();
    selectRandomPosition();
    selectRandomColor();
    selectRandomFont();
  }
  else if(alpha > 255) // à exécuter à la fin du fade in
  {
    // borne maximum pour la transparence
    alpha = 255;

    // changer la direction de l'animation (fade out)
    direction = -1;
  }
}

// fonction qui sélectionne une position au hasard en évitant les positions trop près du bord de la fenêtre
void selectRandomPosition()
{
  xPosition = random(0, width / 2.0f) + width / 4.0f;
  yPosition = random(0, height / 2.0f) + height / 4.0f;
}

// fonction qui sélectionne un module au hasard (lenght - 1 puisque les indides de tableau commençent à 0)
void selectRandomModule()
{
  strCurrentModule = strModule[int(random(strModule.length - 1))];
}

// fonction qui sélectionne une couleur au hasard pour l'arrière-plan et pour le texte
void selectRandomColor()
{
  colorBack = color(random(31, 63), random(31, 63), random(31, 63), 255);
  colorFill = color(random(63, 255), random(63, 255), random(63, 255), 255);
}

// fonction qui sélectionne une police de caractères au hasard
void selectRandomFont()
{
  indexCurrentFont = int(random(nbOfFont - 1));
  strCurrentFont = strFont[indexCurrentFont];
  
  switch(indexCurrentFont)
  {
    case 0:
      font = fontBlackmoor;
      break;
    case 1:
      font = fontConsolas;
      break;
    case 2:
      font = fontCorsiva;
      break;
    case 3:
      font = fontCourier;
      break;
    case 4:
      font = fontEdwardian;
      break;
    case 5:
      font = fontHelvetica;
      break;
    case 6:
      font = fontJazz;
      break;
    case 7:
      font = fontMistral;
      break;
    case 8:
      font = fontPrincetown;
      break;
    case 9:
      font = fontRosewood;
      break;
  }
  
  println("font: " + strCurrentFont);

  // couleur au hasard
  selectRandomColor();

  // sélectionner la police de caractères active
  textFont(font);
}