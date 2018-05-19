#pragma once
#include "Scene.h"
#include "CameraComponent.h"

class RenderContext {
public:
	glm::mat4 MatWorld;
	glm::mat4 MatView;
	glm::mat4 MatProj;
	glm::vec3 ViewPos;

	void GetParamsFromCamera(CameraComponent* camera);
	void UpdateTransform();
};

class BaseRenderer
{
public:
	BaseRenderer(int width, int height);
	~BaseRenderer();

	virtual void Initialize() = 0;

	virtual void Render(Scene* scene, RenderContext* context) = 0;

	virtual void Resize(int width, int height) = 0;

protected:
	int m_Width;
	int m_Height;
};
