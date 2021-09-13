#pragma once

// Za��czenie pliku nag��wkowego z GLEW.
#include <GL\glew.h>

// Za��czenie pliku nag��wkowego z macierzemi z GLM.
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

// Za��czenie pliku nag��wkoego z GLFW.
#include <GLFW\glfw3.h>

class Camera
{
public:
	/// Konstruktor.
	Camera();
	Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch, GLfloat startMoveSpeed, GLfloat startTurnSpeed);

	/// Kontrol za pomoca klawiatury.
	void keyControl(bool* keys, GLfloat deltaTime);

	/// Kontrola za pomoca myszki (obrot).
	void mouseControl(GLfloat xChange, GLfloat yChange);

	/// Uzyskanie pozycji kamery.
	glm::vec3 getCameraPosition();

	/// Obliczanie macierzy widoku, �eby�my mogli widzie� rzeczy z perspektywy kamery.
	glm::mat4 calculateViewMatrix();

	/// Destruktor.
	~Camera();
private:
	glm::vec3 position; // Pozycja kamery.
	glm::vec3 front; // Okresla kierunek, ktory jest na przeciwko kamery.
	glm::vec3 up; // Okresla kierunek, ktory jest do gory od kamery.
	glm::vec3 right; // Okresla kierunek, ktory jest na prawo od kamery.
	glm::vec3 worldUp; // Punkt referencyjny do, kt�rego b�dziemy sie odnosi� np. niebo.

	// Te wartosci beda aktualizowaly front oraz right.
	GLfloat yaw;	// K�t odchylenia -> na prawo lub lewo (o� Y).
	GLfloat pitch;	// K�t pochylenia -> do g�ry lub na d� (o� X).

	GLfloat moveSpeed; // Szybkosc poruszania si�.
	GLfloat turnSpeed; // Szybkosc obrotu.

	// Aktualizowanie wartosci.
	void update();
};

