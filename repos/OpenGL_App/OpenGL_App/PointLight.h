#pragma once
#include "Light.h"

class PointLight : public Light
{
public:
    /// Konstruktor.
    PointLight();

    /// Konstruktor.
    PointLight(GLfloat red, GLfloat green, GLfloat blue, 
               GLfloat aIntensity, GLfloat dIntensity,
               GLfloat xPos, GLfloat yPos, GLfloat zPos, 
               GLfloat con, GLfloat lin, GLfloat exp);

    /// Uzywanie swiatla.
    void UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
                  GLuint diffuseIntensityLocation, GLuint positionLocation,
                  GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation);
    
    /// Destruktor.
    ~PointLight();

protected:
    glm::vec3 position; // Pozycja zrodla swiatla.
    
    // Wsp�czynniki odw. r�wnania kwadratowego do obliczenia wsp��czynnika t�umienia �wiat�a.
    // 1/(ax^2 + bx + c) 
    GLfloat constant; // Stala ~ c.
    GLfloat linear; // Liniowy ~ b.
    GLfloat exponent; // Eksponent ~ a.
};

