#pragma once

// Zaladowanie GLEW.
#include <GL\glew.h>

// Za�adowanie nag��wka z powszechnie u�ywanymi warto�ciami.
#include "CommonValues.h"

class Texture
{
public:
	/// Konstruktor.
	Texture();

	/// Konstrutkor.
	Texture(const char* fileLoc);

	/// �adowanie tekstury bez kana�u alpha.
	bool LoadTexture();

	/// �adowanie tekstury z kanalem alpha.
	bool LoadTextureA();

	/// U�ywanie tekstury.
	void UseTexture();

	/// Usuni�cie tekstury.
	void ClearTexture();

	/// Destruktor.
	~Texture();
private:
	GLuint textureID;
	int width; // Dlugosc tekstury.
	int height; // Wysokosc tekstury.
	int bitDepth; // Glebia.

	const char* fileLocation; // Lokalizacja pliku z tekstura.
};

