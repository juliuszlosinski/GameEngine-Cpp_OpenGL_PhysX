#pragma once

/// Za��czenie nag��wka do wypisywania.
#include <stdio.h>

/// Za��czenia nag��wka do u�ywania OpenGL oraz rozszerze�.
#include <GL\glew.h>

class ShadowMap
{
public:
	/// Konstruktor.
	ShadowMap();

	/// Inicjalizacja (inicjalizacja parametr�w tekstury).
	virtual bool Init(GLuint width, GLuint height);

	/// Zapisywanie.
	virtual void Write();

	/// Wczytywanie.
	virtual void Read(GLenum textureUnit);

	/// Zwroc dlugosc mapy cieni/ tekstury.
	GLuint GetShadowWidth()
	{
		return shadowWidth;
	}

	/// Zwroc wysokosc mapy cieni/ tekstury.
	GLuint GetShadowHeight()
	{
		return shadowHeight;
	}

	/// Destruktor.
	~ShadowMap();

protected:
	GLuint FBO;          // Identyfikator bufora ramki (ang.: Frame Buffer Object).
	GLuint shadowMap;    // Identyfikator mapy cieni (identyfikator tekstury).
	
	GLuint shadowWidth;  // Dlugosc mapy cieni, �eby pasowa�a do g��wnej ramki.
	GLuint shadowHeight; // Wysokosc mapy cieni, �eby pasowa�a do g��wnej ramki.
};

