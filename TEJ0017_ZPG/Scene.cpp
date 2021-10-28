#include "Scene.h"

Scene::Scene(GLFWwindow* window)
{
	_window = window;
	_objectManager = new ObjectManager();
	
	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	ShaderManager shaderManager;

	Model* model0 = new Model(ground, sizeof(ground));
	_objectManager->insertObject(ObjectFactory::initGround(model0, shaderManager.getShader(1)));

	Model* model1 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model1, shaderManager.getShader(2)));
	_objectManager->getObject(1)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(1)->getTransformations()->translate(-1.5f, 0.0f, 0.0f);

	Model* model2 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model2, shaderManager.getShader(2)));
	_objectManager->getObject(2)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(2)->getTransformations()->translate(0.0f, 0.0f, -1.5f);

	Model* model3 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model3, shaderManager.getShader(2)));
	_objectManager->getObject(3)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(3)->getTransformations()->translate(1.5f, 0.0f, 0.0f);

	Model* model4 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model4, shaderManager.getShader(2)));
	_objectManager->getObject(4)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(4)->getTransformations()->translate(0.0f, 0.0f, 1.5f);

	Model* model5 = new Model(tree, sizeof(tree));
	_objectManager->insertObject(ObjectFactory::initTree(model5, shaderManager.getShader(1)));
	_objectManager->getObject(5)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(5)->getTransformations()->translate(5.5f, 0.0f, 0.0f);

	Model* model6 = new Model(suziFlat, sizeof(suziFlat));
	_objectManager->insertObject(ObjectFactory::initSuziFlat(model6, shaderManager.getShader(1)));
	_objectManager->getObject(6)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(6)->getTransformations()->translate(5.5f, 0.0f, 3.0f);

	Model* model7 = new Model(suziSmooth, sizeof(suziSmooth));
	_objectManager->insertObject(ObjectFactory::initSuziSmooth(model7, shaderManager.getShader(1)));
	_objectManager->getObject(7)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(7)->getTransformations()->translate(2.5f, 0.0f, 5.0f);

	_camera = new Camera(_window, glm::vec3(0.0f, 0.0f, 2.0f));
}

void Scene::renderScene()
{
	_camera->Controller();
	_camera->lookAt();

	_objectManager->getObject(5)->getTransformations()->rotate(0.0f, 1.0f, 0.0f);
	_objectManager->getObject(6)->getTransformations()->rotate(0.0f, 1.0f, 0.0f);

	for (int i = 0; i < 8; i++)
	{
		_objectManager->getObject(i)->loopObject(_camera);
	}
}
