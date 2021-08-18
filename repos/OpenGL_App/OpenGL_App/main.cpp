#include <stdio.h>

// Za��czenie pliku nag��wkowego z matematyk�.
#include <cmath>

// Za��czenie pliku nag��wkowego z �a�cuchami znak�w.
#include <string.h>

// Za��czenie pliku nag��wkowego z GLEW.
#include <GL/glew.h>

/// Za��czenie pliku nag��wkowego z GLFW.
#include <GLFW/glfw3.h>

// Za��czenie GLM.
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

// Ustawienie szeroko�ci oraz wysoko�ci okna.
const GLint WIDTH = 800, HEIGHT = 600;

// Deklaracja zmiennych.
GLuint VAO, VBO, shader, uniformModel;
const float toRadians = 3.14159265f / 180.0f;

bool direction = true;
float triOffSet = 0.0f;
float triMaxOffSet = 0.7f;
float triIncrement = 0.005f;

float curAngle = 0.0f;

bool sizeDirection = true;
float curSize = 0.4f;
float maxSize = 0.8f;
float minSize = 0.1f;

// Vertex Shader
static const char* vShader = "														\n\
#version 330																		\n\
																					\n\
layout (location = 0) in vec3 pos;													\n\
																					\n\
uniform mat4 model;																	\n\
																					\n\
void main()																			\n\
{																					\n\
		gl_Position = model * vec4(pos, 1.0);									    \n\
}																					\n\
";

// Fragment Shader
static const char* fShader = "														\n\
#version 330																		\n\
																					\n\
out vec4 colour;																	\n\																					\n\
																					\n\
void main()																			\n\
{																					\n\
		colour = vec4(1.0, 0.0, 0.0, 1.0);										    \n\
}																					\n\
";

glm::mat4 model(1.0f);

void CreateTriangle()
{
	// 0. Utworzenie wierzcho�k�w tr�jk�ta.
	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	// 1. Utworzenie VAO.
	glGenVertexArrays(1, &VAO);

	// 2. Ustawienie VAO jako roboczego (binding).
	glBindVertexArray(VAO);

	// 3. Utworzenie VBO (tworzy VBO wewn�trz VAO).
	glGenBuffers(1, &VBO);

	/// 4. Ustawienie VBO jako roboczego (binding).
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// 5. Wlozenie danych wierzcho�k�w do buffora VBO.
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// 6. Okre�lenie atrybut�w wierzcho�ka.
	// [0] -> Id atrybutu.
	// [1] -> Ile wartosci ma wierzcho�ek (u nas s� 3).
	// [2] -> Jakiego typu s� warto�ci (u nas jest to float).
	// [3] -> Czy nale�y jes normalizowa� (u nas nie nale�y).
	// [4] -> Co ile wartosci skaka� (u nas jest to 0, bo nie skaczemy).
	// [5] -> Od kt�rego wierzcho�ka zacz�c (u nas jest to wierzcho�ek pierwszy).
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// 7. Aktywowanie atrybutu.
	glEnableVertexAttribArray(0);

	/// 8. Zdjecie VBO z pozycji roboczej (unbinding).
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// 9. Zdjecie VAO z pozycji roboczej (unbinding).
	glBindVertexArray(0);
}

void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType)
{
	// 1. Utworzenie pustego shader'a o okre�lonym typie oraz uzyskanie jego identyfikatora.
	GLuint theShader = glCreateShader(shaderType);

	// 2. Przypisanie kodu.
	const GLchar* theCode[1];
	theCode[0] = shaderCode;

	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);

	// 3. Za��czenie kodu.
	glShaderSource(theShader, 1, theCode, codeLength);

	// 4. Kompilacja shadera.
	glCompileShader(theShader);

	// 5. Sprawdzanie b��d�w.
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error compiling the %d shader: '%s' \n", shaderType, eLog);
		return;
	}

	// 5. Za��czenie shadera do programu.
	glAttachShader(theProgram, theShader);
}

void CompileShaders()
{
	// 1. Utworzenie pustego programu.
	shader = glCreateProgram();

	// 1.1 Sprawdzenie czy zosta� dobrze stworzony.
	if (!shader)
	{
		printf("Error creating shader program!\n");
		return;
	}

	// 2. Za��czenie Vertex Shader do programu.
	AddShader(shader, vShader, GL_VERTEX_SHADER);

	// 3. Za��czenie Fragment Shader do programu.
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);

	// 4. Powi�zanie ze sob� wszystkich shader�w oraz stworzenie z nich pliku wykonywalnego dla karty graficznej (poniewa� programy s� na karcie a my tylko zmieniamy ich tre��).
	glLinkProgram(shader);

	// 5. Sprawdzaczenie czy proces powi�zywania shader�w si� powi�d�.
	GLchar eLog[1024] = { 0 };
	GLint result = 0;
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error linking program: '%s' \n", eLog);
		return;
	}

	// 6. Walidacja programu czyli sprawdzanie czy utworzony program jest zgodny z wczesniej utworznym kontekstem.
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("Error validating program: '%s' \n", eLog);
		return;
	}

	/// * Uzyskanie lokalizacji uniformu zmiennej.
	uniformModel = glGetUniformLocation(shader, "model");
}

int main(void)
{
	/// 1. Inicjalizacja GLFW oraz sprawdzenie czy si� powiod�o.
	if (!glfwInit())
	{
		/// 1.1 Wydrukowanie komunikatu o niepowodzeniu.
		printf("GLFW initialization failed!");

		/// 1.2 Zwolnienie zainicjalizowanych zasob�w.
		glfwTerminate();

		/// 1.3 Zg�oszenie Erroru.
		return 1;
	}

	/// 2. Ustawienie parametr�w GLFW okna.
	/// 2.1 Wersja OpenGL.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	/// 2.2 Ustawienie kompatybilnosci z innymi wcze�niejszymi wersjami (BRAK).
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/// 2.3 Ustawienie kompatybilnosci z najnowszymi wersjami (JEST).
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	/// 3. Utworzenie okna.
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);

	/// 3.1 Sprawdzenie czy utworzenie okna sie powiodlo.
	if (!mainWindow)
	{
		/// 3.1.1 Wypisanie komunikatu o niepowodzeniu.
		printf("GLFW window creation failed!");

		/// 3.1.2 Zwrocenie zainicjalizowanych zasobow.
		glfwTerminate();

		/// 3.1.3 Zgloszenie bledu.
		return 1;
	}

	/// 4. Zdobycie informacji na temat rozmiaru buffora.
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	/// 5. Ustawienie kontekstu do u�ycia dla GLEW, zwiazanie kontekstu z tym utworznym oknem.
	glfwMakeContextCurrent(mainWindow);

	// 6. Pozwolenie na u�ycie nowoczesnych rozszerze�.
	glewExperimental = GL_TRUE;

	// 7. Inicjalizacja GLEW (biblioteki oraz wszystkich funkcji, kt�re tam s�).
	if (glewInit() != GLEW_OK)
	{
		// 7.1 Wypisanie komunikatu o niepowodzeniu.
		printf("GLEW initialization failed!");

		/// 7.2 Zniszczenie obecnego utworzonego wczesniej okna.
		glfwDestroyWindow(mainWindow);

		/// 7.3 Zwrocenie zainicjalizowanych wczesniej zasobow przez GLFW.
		glfwTerminate();

		/// 7.4 Zgloszenie bledu.
		return 1;
	}

	// 8. Ustawienie rozmiaru portu widoku (Viewport).
	glViewport(0, 0, bufferWidth, bufferHeight);

	/// * Utworzenie trojk�ta.
	CreateTriangle();

	/// * Kompilacja shaderow ~ utworzenie programu.
	CompileShaders();

	// 9. P�tla dzia�ania okna.
	while (!glfwWindowShouldClose(mainWindow))
	{
		// 9.1 Zdab�dz oraz obs�uz zdarzenia wykonywane przez u�ytkownika. (User Input Events)
		glfwPollEvents();

		/// Dodatek.
		if (direction)
		{
			triOffSet += triIncrement;
		}
		else
		{
			triOffSet -= triIncrement;
		}
		if (abs(triOffSet) >= triMaxOffSet)
		{
			direction = !direction;
		}

		curAngle += 0.7f;
		if (curAngle >= 360)
		{
			curAngle -= 360;
		}

		if (direction)
		{
			curSize += 0.005f;
		}
		else
		{
			curSize -= 0.005f;
		}

		if (curSize >= maxSize || curSize <= minSize)
		{
			sizeDirection = !sizeDirection;
		}

		// 9.2 Czyszczenie okna.
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/// ---------- Rysowanie ---------
		/// 1. Wybranie u�ywanego programu (Shader programu) czyli kaze znalezc karcie graficznej, zeby znalazla program o tym identyfikatorze oraz zeby go u�y�a.
		glUseProgram(shader);

		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(triOffSet, 0.0f, 0.0f));
		model = glm::rotate(model, curAngle * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

		/// 2. Wybranie VAO (to co chcemy narysowac).
		glBindVertexArray(VAO);

		/// 3. Rysowanie trojkata.
		glDrawArrays(GL_TRIANGLES, 0, 3);

		/// 4. Zwolnienie VAO.
		glBindVertexArray(0);

		/// 5. Zwolnienie programu.
		glUseProgram(0);

		/// ------------------------------

		// 9.3 Zamiana bufor�w (oryginalny na ten, na kt�ry widzi u�ytkownik).
		glfwSwapBuffers(mainWindow);
	}

	return 0;
}