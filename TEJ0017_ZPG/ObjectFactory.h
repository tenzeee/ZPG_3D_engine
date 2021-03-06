#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

#include "SphereObject.h"
#include "TreeObject.h"
#include "SuziFlatObject.h"
#include "SuziSmoothObject.h"
#include "GroundObject.h"
#include "PlainObject.h"
#include "UniversalTriangleObject.h"
#include "SkyboxObject.h"
#include "TerrainObject.h"

class ObjectFactory
{
public:
	static Object* initSphere(Model* model, Shader* shader);
	static Object* initSphere(Model* model, Shader* shader, glm::vec3 color);
	static Object* initTree(Model* model, Shader* shader);
	static Object* initSuziFlat(Model* model, Shader* shader);
	static Object* initSuziSmooth(Model* model, Shader* shader);
	static Object* initGround(Model* model, Shader* shader);
	static Object* initPlain(Model* model, Shader* shader);
	static Object* initUniversalTriangle(Model* model, Shader* shader, Texture* texture);
	static Object* initUniversalTriangle(Model* model, Shader* shader, Texture* texture, Texture* normalTexture);
	static Object* initUniversalTriangle(Model* model, Shader* shader, Texture* texture, Bezier* bezier);
	static Object* initTerrain(Model* model, Shader* shader, Texture* texture);
	static Object* initSkybox(Model* model, Shader* shader, Texture* texture);
};

