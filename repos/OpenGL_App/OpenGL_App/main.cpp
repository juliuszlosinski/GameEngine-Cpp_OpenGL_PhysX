#include <stdio.h>

// Za��czenie pliku nag��wkowego z GLEW.
#include <GL/glew.h>

/// Za��czenie pliku nag��wkowego z GLFW.
#include <GLFW/glfw3.h>

// Ustawienie szeroko�ci oraz wysoko�ci okna.
const GLint WIDTH = 800, HEIGHT = 600;

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

	// 9. P�tla dzia�ania okna.
	while (!glfwWindowShouldClose(mainWindow))
	{
		// 9.1 Zdab�dz oraz obs�uz zdarzenia wykonywane przez u�ytkownika. (User Input Events)
		glfwPollEvents();

		// 9.2 Czyszczenie okna.
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// 9.3 Zamiana bufor�w (oryginalny na ten, na kt�ry widzi u�ytkownik).
		glfwSwapBuffers(mainWindow);
	}

	return 0;
}