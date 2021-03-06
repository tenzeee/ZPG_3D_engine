#include "ObjectFactory.h"

Object* ObjectFactory::initSphere(Model* model, Shader* shader)
{
    Object* object = new SphereObject(shader, model);
    return object;
}

Object* ObjectFactory::initSphere(Model* model, Shader* shader, glm::vec3 color)
{
    Object* object = new SphereObject(shader, model, color);
    return object;
}

Object* ObjectFactory::initTree(Model* model, Shader* shader)
{
    Object* object = new TreeObject(shader, model);
    return object;
}

Object* ObjectFactory::initSuziFlat(Model* model, Shader* shader)
{
    Object* object = new SuziFlatObject(shader, model);
    return object;
}

Object* ObjectFactory::initSuziSmooth(Model* model, Shader* shader)
{
    Object* object = new TreeObject(shader, model);
    return object;
}

Object* ObjectFactory::initGround(Model* model, Shader* shader)
{
    Object* object = new GroundObject(shader, model);
    return object;
}

Object* ObjectFactory::initPlain(Model* model, Shader* shader)
{
    Object* object = new PlainObject(shader, model);
    return object;
}

Object* ObjectFactory::initUniversalTriangle(Model* model, Shader* shader, Texture* texture)
{
    Object* object = new UniversalTriangleObject(shader, model, texture);
    return object;
}

Object* ObjectFactory::initUniversalTriangle(Model* model, Shader* shader, Texture* texture, Texture* normalTexture)
{
    Object* object = new UniversalTriangleObject(shader, model, texture, normalTexture);
    return object;
}

Object* ObjectFactory::initUniversalTriangle(Model* model, Shader* shader, Texture* texture, Bezier* bezier)
{
    Object* object = new UniversalTriangleObject(shader, model, texture, bezier);
    return object;
}

Object* ObjectFactory::initTerrain(Model* model, Shader* shader, Texture* texture)
{
    Object* object = new TerrainObject(shader, model, texture);
    return object;
}

Object* ObjectFactory::initSkybox(Model* model, Shader* shader, Texture* texture)
{
    Object* object = new SkyboxObject(shader, model, texture);
    return object;
}
