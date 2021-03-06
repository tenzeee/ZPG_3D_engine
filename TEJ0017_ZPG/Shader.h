#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include "Camera.h"

class Camera;
class Shader
{
public:
	Shader(const char* vertex_shader_filename, const char* fragment_shader_filename);
	void useShader();
	void modelToShader(glm::mat4 model);
	void viewToShader(glm::mat4 view);
	void projectionToShader(glm::mat4 projection);
	void cameraPosToShader(glm::vec3 cameraPosition);
	void lightPosToShader(glm::vec3 lightPosition);
	void textureToShader(int id);
	void lightToShader(const char* varName, glm::vec3 value);
	void lightToShaderFloat(const char* varName, float value);
	void lightsCountToShader(int count);
	void colorToShader(glm::vec3 color);
	void normalTextureToShader(int id);
	void update();
private:
	const char* _vertex_shader;
	const char* _fragment_shader;
	GLuint _vertexShader;
	GLuint _fragmentShader;
	GLuint _shaderProgram;
	std::string getContentFromFile(const char* filename);
};

