#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include <GL\glew.h>

class Shader
{
public:
	Shader(); // Konstruktor.

	/// CreateFromString(...) -> CompileShader(...) -> 2x AddShader(...) -> Mamy program z shader'ami oraz lokalizacje uniform'ow (projekcji oraz modelu). 
	/// CreateFromFiles(...) -> 2 x ReadFile(...) -> CompileShader(...) -> 2x AddShader(...) -> Mamy program z shader'ami oraz lokalizacje uniform'ow (projekcji oraz modelu).

	void CreateFromString(const char* vertexCode, const char* fragmentCode); // Utworz shader z ���cucha znak�w.
	void CreateFromFiles(const char* vertexLocation, const char* fragmentLcation); // Utworzenie shadera z plik�w.

	std::string ReadFile(const char* fileLocation); // Czytanie z pliku.

	GLuint GetProjectionLocation(); // Uzyskaj lokalizacje macierzy projekcji.
	GLuint GetModelLocation(); // Uzyskaj lokalizacje macierzy modelu.
	GLuint GetViewLocation(); // Uzyskaj lokalizacje macierzy widoku.
	
	GLuint GetAmbientIntensityLocation(); // Uzyskaj lokalizacje moc oswietlenia otoczenia.
	GLuint GetAmbientColourLocation(); // Uzyskaj lokalizacje koloru otoczenia.

	GLuint GetDiffuseIntensityLocation(); // Uzyskaj lokalizacje mocy oswietlenia rozproszonego.
	GLuint GetDirectionLocation(); // Uzykaj lokalizacje kierunku swiatla rozproszonego.

	GLuint GetSpecularIntensityLocation(); // Uzyskaj lokalizacje mocy oswietlenia.
	GLuint GetShininessLocation(); // Uzyskaj lokalizacje wspolczynnika skupienia mocy.
	
	GLuint GetEyePosition(); // Uzyskaj lokalizacje uniformu dla polozenia kamery.

	void UseShader(); // U�yj shader'a.
	void ClearShader(); // Wyczy�� shader.

	~Shader(); // Destruktor.
private:
	GLuint shaderID; // Identyfikator shader'a.
	GLuint uniformProjection; // Identyfikator uniformu projekcji.
	GLuint uniformModel; // Identyfikator uniformu modelu.
	GLuint uniformView; // Identyfikator macierzy widoku.
	GLuint uniformEyePosition; // Identyfikator uniformu pozycji kamery.

	GLuint uniformAmbientIntensity; // Identyfikator uniformu wspolczynnika oswietlenia otoczenia.
	GLuint uniformAmbientColour; // Identyfikator koloru otoczenia.

	GLuint uniformDiffuseIntensity; // Identyfikator uniformu mocy oswietlenia rozproszonego.
	GLuint uniformDirection; // Kierunek swiatla rozproszonego.

	GLuint uniformSpecularIntensity; // Identyfikator polozenia mocy oswietlenia.
	GLuint uniformShininess; // Identyfikator uniformu mocy skupienia swiatla.

	void CompileShader(const char* vertexCode, const char* fragmentCode); // Kompiluj shader.
	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType); // Za��cz shader do programu.
};

