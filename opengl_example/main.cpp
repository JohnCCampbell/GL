#pragma warning(disable:4996)
#pragma comment(linker,"/subsystem:console")

//LOAD LIBRARIES
#pragma comment(lib,"SDL2-2.0.9\\lib\\x86\\SDL2.lib")
#pragma comment(lib,"SDL2-2.0.9\\lib\\x86\\SDL2main.lib")

#pragma comment(lib,"glew-2.1.0\\lib\\Release\\Win32\\glew32.lib")
#pragma comment(lib,"opengl32.lib")

//INCLUDE HEADERS
#include "glew-2.1.0\include\GL\glew.h"
#include "SDL2-2.0.9\include\SDL.h"
#include "SDL2-2.0.9\include\SDL_opengl.h"


#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

/////

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <gl/GL.h>


//https://github.com/glfw/glfw
//https://github.com/opengl-tutorials/ogl


using namespace glm;

int main(void)
{
	glewExperimental = true; // Needed for core profile
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	// Open a window and create its OpenGL context
	GLFWwindow* window; // (In the accompanying source code, this variable is global for simplicity)
	window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}


}


























//unsigned int vertex_buffer_object = 0;
//unsigned int index_buffer_object = 0;
//unsigned int bitmap_buffer_object = 0;
//
//SDL_Window *window = NULL;
//int wiggle_id = 0;
//int tint_id = 0;
//int size_id = 0;
//
//int load(char *buffer,int buffer_size, const char *filename)
//{
//	FILE *f = fopen(filename, "rb");
//	fseek(f, 0, SEEK_END);
//	int size = ftell(f);
//	if (size > buffer_size) size = buffer_size;
//	fseek(f, 0, SEEK_SET);
//	fread(buffer, 1, size, f);
//	buffer[size] = 0;
//	fclose(f);
//	return size;
//}
//
//void init_OpenGL()
//{
//	const int buffer_size = 4096 * 4;
//	const char *buffer = (char*)malloc(buffer_size);
//
//	printf("%s\n", glGetString(GL_VERSION));
//
//	int program_id = glCreateProgram();
//	int compile_status = 0;
//	//////////////
//	//unsigned int vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
//	//load((char*)buffer, buffer_size, "vertex.glsl");
//	//glShaderSource(vertex_shader_id, 1, &buffer, NULL);
//	//glCompileShader(vertex_shader_id);
//	//glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &compile_status);
//	//if (compile_status == 0)
//	//{
//	//	static char info[1024];
//	//	glGetShaderInfoLog(vertex_shader_id, 1024, NULL, info);
//	//	printf("vertex shader compiler error: %s\n", info);
//	//}
//	//glAttachShader(program_id, vertex_shader_id);
//	////////////////
//	unsigned int vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
//	load((char*)buffer, buffer_size, "vertex.glsl");
//	glShaderSource(vertex_shader_id, 1, &buffer, NULL);
//	glCompileShader(vertex_shader_id);
//	glGetShaderiv(vertex_shader_id, GL_COMPILE_STATUS, &compile_status);
//	if (compile_status == 0)
//	{ 
//		static char info[1024];
//		glGetShaderInfoLog(vertex_shader_id, 1024, NULL, info);
//		printf("vertex shader compiler error: %s\n", info);
//	}  
//	glAttachShader(program_id, vertex_shader_id);
//
//	unsigned int fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
//	load((char*)buffer, buffer_size, "fragment.glsl");
//	glShaderSource(fragment_shader_id, 1, &buffer, NULL);
//	glCompileShader(fragment_shader_id);
//	glGetShaderiv(fragment_shader_id, GL_COMPILE_STATUS, &compile_status);
//	if (compile_status == 0)
//	{
//		static char info[1024];
//		glGetShaderInfoLog(fragment_shader_id, 1024, NULL, info);
//		printf("fragment shader compiler error: %s\n", info);
//	}
//	glAttachShader(program_id, fragment_shader_id);
//
//	glLinkProgram(program_id);
//
//	glUseProgram(program_id);
//
//	float vertex_data[] = 
//	{
//		-0.5, -0.25, 0.0,
//		0.5, -0.5, 0.0,
//		0.5, 0.5, 0.0,
//		-0.5, 0.5, 0.0,
//		//0.5, 0.25, 0.0,
//		//-0.5, 0.5, 0.0,
//		//0.25, 0.5, 0.1,
//		//-0.25, 1, 0.1
//	};
//
//	unsigned int index_data[] =
//	{
//		0, 1, 2, 3
//	};
//
//	glGenBuffers(1, &vertex_buffer_object);
//	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
//	glBufferData(GL_ARRAY_BUFFER, 3 * 4 * sizeof(float), vertex_data, GL_STATIC_DRAW);
//	
//	glGenBuffers(1, &index_buffer_object);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(unsigned int), index_data, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, 0, sizeof(float) * 3, NULL);
//	glEnableVertexAttribArray(0);
//
//	wiggle_id = glGetUniformLocation(program_id, "wiggle");
//	tint_id = glGetUniformLocation(program_id, "tint");
//	size_id = glGetUniformLocation(program_id, "size");
//}
//
//void init()
//{
//	SDL_Init(SDL_INIT_VIDEO);
//
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
//	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//
//	window = SDL_CreateWindow("opengl", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
//
//	SDL_GLContext context = SDL_GL_CreateContext(window);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	init_OpenGL();
//}
//
//
//int main(int argc, char **argv)
//{
//	init();
//
//	bool done = false;
//	while (!done)
//	{
//		SDL_Event event;
//		while (SDL_PollEvent(&event))
//		{
//			if (event.type == SDL_QUIT)
//			{
//				done = true;
//			}
//		}
//
//
//		//render
//		glClearColor(0.5, 0.5, 0.5, 1.0);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUniform2f(size_id,.5, .5);
//		glUniform3f(wiggle_id,
//			0.01*(1.0 - 2.0*rand() / RAND_MAX),
//			0, 0);
//
//		glUniform4f(tint_id,
//			.7,.2,.5,
//			1.0);
//		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
//		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_object);
//		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, NULL);
//
//
//		glRotatef(.01, .01, .01, 1);
//
//		SDL_GL_SwapWindow(window);
//	}
//
//
//	return 0;
//}

//(1.0*rand() / RAND_MAX),
//(1.0*rand() / RAND_MAX),
//(1.0*rand() / RAND_MAX),