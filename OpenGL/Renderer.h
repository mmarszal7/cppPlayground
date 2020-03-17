#include <glad\glad.h>
#ifndef RENDERER_H
#define RENDERER_H

class Renderer
{
public:
	Renderer()
	{
	}

	void LoadCube()
	{
		float vertices[] = {
			// positions          // colors           // texture coords
			 0.5f,  0.5f, -0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
			 0.5f, -0.5f, -0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
			-0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
			-0.5f,  0.5f, -0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // top left 

			 0.5f,  0.5f, 0.5f,   1.0f, 0.0f, 0.0f,   1.0f, 0.0f, // top right
			 0.5f, -0.5f, 0.5f,   0.0f, 1.0f, 0.0f,   1.0f, 1.0f, // bottom right
			-0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 1.0f,   0.0f, 1.0f, // bottom left
			-0.5f,  0.5f, 0.5f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f  // top left 
		};
		unsigned int indices[] = {
			0, 1, 3, 1, 2, 3, // bottom
			4, 5, 6, 6, 7, 4, // top
			0, 1, 5, 5, 4, 0, // right
			2, 3, 6, 6, 7, 3, // left
			0, 3, 7, 7, 4, 0, // back
			1, 2, 6, 6, 1, 5  // front
		};

		// Buffers
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		unsigned int VBO;
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		unsigned int EBO;
		glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(2);
	}

	void Draw()
	{
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}

private:
	unsigned int VAO;

};
#endif