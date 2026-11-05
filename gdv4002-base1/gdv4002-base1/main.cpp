#include "Engine.h"


// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
// Global Variables
bool spacePressed = false;

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		fprintf(stderr, "Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	
	addObject("player", glm::vec2(0.0f, 0.0f), glm::radians(0.0f), glm::vec2(0.4f, 0.4f), "Resources\\textures\\player1_ship.png");
	
	setUpdateFunction(myUpdate);
	setKeyboardHandler(myKeyboardHandler); 
		const float pi = 3.141593f;
	// addObject("test", glm::vec2(1.0f, 1.0f), 45.0f * pi / 180.0f);
	

	//
	// Set callback functions
	//
	

	// Enter main loop - this handles update and render calls
	engineMainLoop();

	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}

void myUpdate(GLFWwindow* window, double tDelta) {


	GameObject2D* player = getObject("player");
	if (player != nullptr) {

		static float playerMass = 1.0f;
		static glm::vec2 playerVelocity = glm::vec2(0.0f, 0.0f);
		const float thrust = 2.0f;

			glm::vec2 f = glm::vec2(0.0f, 0.0f);

		f += glm::vec2(0.0f, -1.0f);


		glm::vec2(0.0f, -1.0f);
			if (spacePressed) {
				f += glm::vec2(0.0f, 2.0f);
			}

		// 1. accumulate forces


		glm::vec2 a = f / playerMass;
		playerVelocity = playerVelocity + a * (float)tDelta;
		player->position = player->position + playerVelocity * (float)tDelta;
	}
}
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods) //NEW START
{
	// Check if the key was just pressed
	if (action == GLFW_PRESS) {

		// now check which key was pressed...
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_SPACE:
			spacePressed = true;
			break;

		}
	}
	// If not pressed, check the key has just been released
	else if (action == GLFW_RELEASE) {
		switch (key)
		{
		case GLFW_KEY_ESCAPE:
			// If escape is pressed tell GLFW we want to close the window(and quit)
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_SPACE:
			spacePressed = false;
			break;
			// handle key release events
		}
	}
}
