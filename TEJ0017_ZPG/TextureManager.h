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

//Include SOIL
#include <SOIL.h>

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>

//My classes
#include "Texture.h"

class TextureManager
{
public:
	static TextureManager* getInstance();
	static TextureManager* getInstanceValue();
	Texture* getTexture(int id);
private:
	TextureManager();
	static TextureManager* _instance;
	std::vector<Texture>* _textures;
};

