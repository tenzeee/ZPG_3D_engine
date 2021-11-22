#include "ThirdScene.h"

ThirdScene::ThirdScene(GLFWwindow* window)
{
	_window = window;
	_objectManager = ObjectManager::getInstance();


	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	_shaderManager = ShaderManager::getInstance();

	Model* model0 = new Model("Textures/plane.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model0, _shaderManager->getShader(3)));
	_objectManager->getObject(0)->getTransformations()->scale(35.0f, 35.0f, 35.0f);

	Model* model1 = new Model("Textures/skydome.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model1, _shaderManager->getShader(0)));
	_objectManager->getObject(1)->getTransformations()->scale(5.0f, 5.0f, 5.0f);

	Model* model2 = new Model("Textures/building.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model2, _shaderManager->getShader(0)));
	_objectManager->getObject(2)->getTransformations()->translate(-15.0f, 0.0f, 5.0f);


	std::vector<Model*> trees;
	for (int i = 0; i < 5; i++)
	{
		Model* model = new Model("Textures/tree.obj");
		trees.push_back(model);
		_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model, _shaderManager->getShader(3)));
		_objectManager->getObject(i + 3)->getTransformations()->translate((1.0f + (i * 5)), 0.0f, 0.0f);
		_objectManager->getObject(i + 3)->getTransformations()->scale(0.2f, 0.2f, 0.2f);
	}

	_camera = Camera::getInstance(_window, glm::vec3(0.0f, 1.5f, 4.0f));
	_controller = Controller::getInstance(_camera);
	_lightPosition = glm::vec3(10.0f, 10.0f, 10.0f);

	//Texture textures;
	textures.loadTexture("Textures/building.png");
	textures.loadTexture("Textures/skydome.png");
	textures.loadTexture("Textures/tree.png");
	textures.loadTexture("Textures/test.png");
}

void ThirdScene::renderScene()
{
	_controller->checkInputs();
	_camera->lookAt();
	//_shaderManager->getShader(3)->cameraPosToShader(_camera->getPosition());
	_shaderManager->getShader(3)->update();
	_shaderManager->getShader(3)->lightPosToShader(_lightPosition);

	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		_objectManager->getObject(i)->loopObject(_camera);

		if (i == 1)
		{
			textures.setTexture(0);
			_shaderManager->getShader(0)->textureToShader(0);
		}
		else if (i == 2)
		{
			textures.setTexture(1);
			_shaderManager->getShader(0)->textureToShader(1);
		}
	}
}

