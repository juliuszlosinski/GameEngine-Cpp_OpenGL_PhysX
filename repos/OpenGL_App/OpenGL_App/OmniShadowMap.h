#pragma once
#include "ShadowMap.h"
class OmniShadowMap : public ShadowMap
{
public:
	/// Konstruktor.
	OmniShadowMap();

	/// Inicjalizacja (inicjalizacja parametr�w tekstury).
	bool Init(GLuint width, GLuint height);

	/// Zapisywanie.
	void Write();

	/// Wczytywanie.
	void Read(GLenum textureUnit);

	/// Destruktor.
	~OmniShadowMap();
};

