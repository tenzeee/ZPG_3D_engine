#include "Shader.h"

Shader::Shader(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
	std::string vertexFileOutput = getContentFromFile(vertexShaderFilename);
	std::string fragmentFileOutput = getContentFromFile(fragmentShaderFilename);

	_vertex_shader = vertexFileOutput.c_str();
	_fragment_shader = fragmentFileOutput.c_str();

	_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_vertexShader, 1, &_vertex_shader, NULL);
	glCompileShader(_vertexShader);
	_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_fragmentShader, 1, &_fragment_shader, NULL);
	glCompileShader(_fragmentShader);

	char log[1024];
	glGetShaderInfoLog(_vertexShader, 1024, nullptr, log);
	if (strlen(log) > 0)
		fprintf(stderr, "Vertex shader error:\n%s\n", log);

	char log2[1024];
	glGetShaderInfoLog(_fragmentShader, 1024, nullptr, log2);
	if(strlen(log2) > 0)
		fprintf(stderr, "Fragment shader error:\n%s\n", log2);

	_shaderProgram = glCreateProgram();
	glAttachShader(_shaderProgram, _fragmentShader);
	glAttachShader(_shaderProgram, _vertexShader);
	glLinkProgram(_shaderProgram);
}

void Shader::useShader()
{
	glUseProgram(_shaderProgram);
}

void Shader::modelToShader(glm::mat4 model)
{
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
}

void Shader::viewToShader(glm::mat4 view)
{
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
}

void Shader::projectionToShader(glm::mat4 projection)
{
	glUniformMatrix4fv(glGetUniformLocation(_shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}

void Shader::cameraPosToShader(glm::vec3 cameraPosition)
{
	glUniform3f(glGetUniformLocation(_shaderProgram, "cameraPosition"), cameraPosition.x, cameraPosition.y, cameraPosition.z);
}

void Shader::lightPosToShader(glm::vec3 lightPosition)
{
	glUniform3f(glGetUniformLocation(_shaderProgram, "lightPosition"), lightPosition.x, lightPosition.y, lightPosition.z);
}

void Shader::textureToShader(int id)
{
	GLint uniformID = glGetUniformLocation(_shaderProgram, "textureUnitID");
	glUniform1i(uniformID, id);
}

void Shader::lightToShader(const char* varName, glm::vec3 value)
{
	glUniform3f(glGetUniformLocation(_shaderProgram, varName), value.x, value.y, value.z);
}

void Shader::lightToShaderFloat(const char* varName, float value)
{
	glUniform1f(glGetUniformLocation(_shaderProgram, varName), value);
}

void Shader::lightsCountToShader(int count)
{
	glUniform1i(glGetUniformLocation(_shaderProgram, "lightsCount"), count);
}

void Shader::colorToShader(glm::vec3 color)
{
	glUniform3f(glGetUniformLocation(_shaderProgram, "lightColor"), color.x, color.y, color.z);
}

void Shader::normalTextureToShader(int id)
{
	GLint uniformID = glGetUniformLocation(_shaderProgram, "normalTextureUnitID");
	glUniform1i(uniformID, id);
}

void Shader::update()
{
	Camera *cam = Camera::getInstance();
	glUniform3f(glGetUniformLocation(_shaderProgram, "cameraPosition"), cam->_position.x, cam->_position.y, cam->_position.z);
}

std::string Shader::getContentFromFile(const char* filename)
{
	std::string fileContent;
	std::ifstream fileStream(filename, std::ios::in);

	if (fileStream.is_open())
	{
		std::string line = "";
		while (!fileStream.eof())
		{
			std::getline(fileStream, line);
			fileContent.append(line + "\n");
		}
		fileStream.close();
		return fileContent;
	}
	else
	{
		return "";
	}
}
