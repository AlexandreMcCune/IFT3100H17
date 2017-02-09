// IFT3100H17_VertexBufferSwap.cpp
// Exemple d'une section de code qui inverse en alternance deux buffers de géométrie utilisés pour la mise à jour et le rendu afin d'éviter de bloquer le pipeline de rendu.

// précondition
// - deux buffers de géométrie indépendants avec une structure identique mais des données distinctes
GLuint vboAlpha;
GLuint vboBeta;

// postcondition
// - le buffer de géométrie utilisé pour le rendu n'est pas celui dans lequel il y a mise à jour durant le même frame

// buffer de géométrie utilisé pour la mise à jour (écriture)
GLuint vboUpdate;

// buffer de géométrie utilisé pour le rendu (lecture)
GLuint vboDraw;

// booléen qui indique si on est prêt pour une inversion des buffers de géométrie
bool isReadyToSwap;

// booléen qui indique si les buffers de géométrie sont dans l'ordre initiale ou non
bool isInOrder;

if(isReadyToSwap)
{
  if(isInOrder)
  {
    vboUpdate = vboAlpha;
    vboDraw   = vboBeta;

    isInOrder = false;
  }
  else
  {
    vboUpdate = vboBeta;
    vboDraw   = vboAlpha;

    isInOrder = true;
  }

  isReadyToSwap = false;
}

if(/* mise à jour du modèle */)
{
  // sélectionner le vbo de mise à jour
  glBindBuffer(GL_ARRAY_BUFFER, vboUpdate);

  // mise à jour du buffer de géométrie
  // ...

  // inverser les buffers de géométrie lors du prochain frame
  isReadyToSwap = true;
}

// sélectionner le vbo de mise à jour
glBindBuffer(GL_ARRAY_BUFFER, vboDraw);

// rendre le buffer de géométrie avec une commande de rendu
// ... ex: glDrawArrays ou glDrawElements
