#include "TerrainObject.h"

TerrainObject::TerrainObject(Shader* shader, Model* model, Texture* texture)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
	_texture = texture;
}

void TerrainObject::loopObject(Camera* camera)
{
	_shader->useShader();
	_shader->modelToShader(_trans->getModel());
	_shader->projectionToShader(camera->getProjection());
	_shader->viewToShader(camera->getView());
	_texture->setTexture();
	_shader->textureToShader(_texture->getId());

	_model->modelInLoop();
	glDrawElements(GL_TRIANGLES, _model->getIndiciesCount(), GL_UNSIGNED_INT, NULL);
}
