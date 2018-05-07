#pragma once
#include "BaseComponent.h"
#include "Shader.h"

class CubeComponent : public BaseComponent
{
public:
	CubeComponent();
	CubeComponent(const std::string& texturePath);
	~CubeComponent();

	virtual void Update(double curFrame, double deltaFrame);

	virtual stringT GetTypeName();

	virtual void Render();

	virtual void Render(Shader shader);

public:
	void SetColor(const glm::vec3& color);

private:
	glm::vec3 m_Color;
	unsigned int m_VBO, m_VAO;
	unsigned int m_TextureID;
	Shader m_Shader;
	unsigned int m_Texture;
	bool m_UseTexture;
};

