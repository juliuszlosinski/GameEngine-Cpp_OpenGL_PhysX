#pragma once

// Za��czenie nag��wka z wektorem.
#include <vector>

// Za��czenie nag��wka z operacjami na �a�cuchach znak�w.
#include <string>

// Za��czenie nag��wka z nowoczesn� wersj� OpenGL.
#include <GL\glew.h>

// Za��czenie nag��wka z powszechnie u�ywanymi warto�ciami.
#include "CommonValues.h"

// Za��czenie nag��wka z macierzami.
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

// Za��czenie nag��wka z siatk�.
#include "Mesh.h"

// Za��czenie nag��wka z shaderem.
#include "Shader.h"

class Skybox
{
public:
	/// Konstruktor.
	Skybox();

	/// Konstrutkor.
	Skybox(std::vector<std::string> faceLocations);

	/// Rysowanie.
	void DrawSkybox(glm::mat4 viewMatrix, glm::mat4 projectionMatrix);

	/// Destruktor.
	~Skybox();
private:
	Mesh* skyMesh; // Siatka skybox'a.
	Shader* skyShader; // Shader do shadera.

	GLuint textureId; // Identyfikator tekstury.
	GLuint uniformProjection; // Identyfikator uniformu projekcji.
	GLuint uniformView; // Identyfikator uniformu widoku.
};

