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

    void UseLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation,
                  GLfloat diffuseIntensityLocation, GLfloat positionLocation,
                  GLfloat constantLocation, GLfloat linearLocation, GLfloat exponentLocation);

    /// Destruktor.
    ~PointLight();

private:
    glm::vec3 position; // Pozycja zrodla swiatla.
    
    // Wsp�czynniki odw. r�wnania kwadratowego do obliczenia wsp��czynnika t�umienia �wiat�a.
    // 1/(ax^2 + bx + c) 
    GLfloat constant; // Stala ~ c.
    GLfloat linear; // Liniowy ~ b.
    GLfloat exponent; // Eksponent ~ a.

};

