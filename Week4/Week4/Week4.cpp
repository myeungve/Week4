#include <glfw3.h>
#include <algorithm>
#include <math.h>

const int width = 1300;
const int height = 650;

float* pixels = new float[width*height * 3];

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{
	for (int i = i0; i <= i1; i++)
	{
		const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

		drawPixel(i, j, red, green, blue);
	}
}

void drawCircle(const int& i0, const int& j0, int r, const float& red, const float& green, const float& blue)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if ((i - i0) * (i - i0) + (j - j0) * (j - j0) - r * r < 0 && (i - i0) * (i - i0) + (j - j0) * (j - j0) - (r - 3) * (r - 3) > 0)
			{
				drawPixel(i, j, red, green, blue);
			}
		}
	}
}

bool InsideCircle(const int& i0, const int& j0, int r, double xpos, double ypos)
{
	double check = (xpos - (double)i0) * (xpos - (double)i0) + (ypos - (double)j0) * (ypos - (double)j0);

	if (check < (double)r * (double)r) return true;
	else return false;
}

void drawMyPainting()
{
	/* White background */
	std::fill_n(pixels, width*height * 3, 1.0f);

	//Slash
	drawCircle(150, 450, 100, 1.0f, 0.0f, 0.0f);
	drawLine(99, 400, 200, 501, 1.0f, 0.0f, 0.0f);
	drawLine(100, 401, 201, 501, 1.0f, 0.0f, 0.0f);
	drawLine(100, 401, 201, 500, 1.0f, 0.0f, 0.0f);
	drawLine(100, 400, 201, 500, 1.0f, 0.0f, 0.0f);

	//Doughnut Shape
	drawCircle(400, 450, 100, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= width; i++)
	{
		for (int j = 0; j <= height; j++)
		{
			if ((i - 400)*(i - 400) + (j - 450)*(j - 450) - 40 * 40 <= 0)
			{
				drawPixel(i, j, 1.0f, 0.0f, 0.0f);

				if ((i - 400)*(i - 400) + (j - 450)*(j - 450) - 30 * 30 <= 0)
				{
					drawPixel(i, j, 1.0f, 1.0f, 1.0f);
				}
			}
		}
	}

	//Empty Squre
	drawCircle(650, 450, 100, 1.0f, 0.0f, 0.0f);
	drawLine(600, 400, 700, 400, 1.0f, 0.0f, 0.0f);
	drawLine(600, 500, 700, 500, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 100; i++)
	{
		drawPixel(600, 400 + i, 1.0f, 0.0f, 0.0f);
		drawPixel(700, 400 + i, 1.0f, 0.0f, 0.0f);
	}

	//Cross Line
	drawCircle(900, 450, 100, 1.0f, 0.0f, 0.0f);
	drawLine(850, 400, 950, 500, 1.0f, 0.0f, 0.0f);
	drawLine(850, 500, 950, 400, 1.0f, 0.0f, 0.0f);

	//Down Arrow
	drawCircle(1150, 450, 100, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 100; i++)
	{
		drawPixel(1150, 400 + i, 1.0f, 0.0f, 0.0f);
	}
	drawLine(1120, 430, 1150, 400, 1.0f, 0.0f, 0.0f);
	drawLine(1150, 400, 1180, 430, 1.0f, 0.0f, 0.0f);

	//Right Arrow
	drawCircle(150, 200, 100, 1.0f, 0.0f, 0.0f);
	drawLine(100, 200, 200, 200, 1.0f, 0.0f, 0.0f);
	drawLine(170, 230, 200, 200, 1.0f, 0.0f, 0.0f);
	drawLine(170, 170, 200, 200, 1.0f, 0.0f, 0.0f);

	//'A'
	drawCircle(400, 200, 100, 1.0f, 0.0f, 0.0f);
	drawLine(350, 150, 400, 250, 1.0f, 0.0f, 0.0f);
	drawLine(351, 150, 401, 250, 1.0f, 0.0f, 0.0f);
	drawLine(400, 249, 450, 151, 1.0f, 0.0f, 0.0f);
	drawLine(401, 249, 451, 151, 1.0f, 0.0f, 0.0f);
	drawLine(375, 200, 425, 200, 1.0f, 0.0f, 0.0f);

	//Vertical Line
	drawCircle(650, 200, 100, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 100; i++)
	{
		drawPixel(650, 150 + i, 1.0f, 0.0f, 0.0f);
	}

	//Left Arrow
	drawCircle(900, 200, 100, 1.0f, 0.0f, 0.0f);
	drawLine(850, 200, 950, 200, 1.0f, 0.0f, 0.0f);
	drawLine(850, 200, 880, 230, 1.0f, 0.0f, 0.0f);
	drawLine(850, 200, 880, 170, 1.0f, 0.0f, 0.0f);

	//Up Arrow
	drawCircle(1150, 200, 100, 1.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 100; i++)
	{
		drawPixel(1150, 150 + i, 1.0f, 0.0f, 0.0f);
	}
	drawLine(1120, 220, 1150, 250, 1.0f, 0.0f, 0.0f);
	drawLine(1150, 250, 1180, 220, 1.0f, 0.0f, 0.0f);
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Myeong Bae Seung", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	double xpos, ypos;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* White background */
		std::fill_n(pixels, width*height * 3, 1.0f);

		glfwGetCursorPos(window, &xpos, &ypos);

		drawMyPainting();

		if (InsideCircle(150, 200, 100, xpos, ypos) == true)
		{
			drawCircle(150, 450, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(400, 200, 100, xpos, ypos) == true)
		{
			drawCircle(400, 450, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(650, 200, 100, xpos, ypos) == true)
		{
			drawCircle(650, 450, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(900, 200, 100, xpos, ypos) == true)
		{
			drawCircle(900, 450, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(1150, 200, 100, xpos, ypos) == true)
		{
			drawCircle(1150, 450, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(150, 450, 100, xpos, ypos) == true)
		{
			drawCircle(150, 200, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(400, 450, 100, xpos, ypos) == true)
		{
			drawCircle(400, 200, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(650, 450, 100, xpos, ypos) == true)
		{
			drawCircle(650, 200, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(900, 450, 100, xpos, ypos) == true)
		{
			drawCircle(900, 200, 100, 0.0f, 0.0f, 1.0f);
		}

		if (InsideCircle(1150, 450, 100, xpos, ypos) == true)
		{
			drawCircle(1150, 200, 100, 0.0f, 0.0f, 1.0f);
		}

		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	delete[] pixels;

	glfwTerminate();
	return 0;
}