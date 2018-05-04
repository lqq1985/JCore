#pragma once
#include <vector>
#include <map>
#include "Node.h"
#include "Text.h"
#include "PostProcessor.h"
#include "FreeCameraComponent.h"
#include "FollowCameraComponent.h"

//����������
class Scene
{
public:
	Scene(int windowWidth, int windowHeight);
	~Scene();

	void Initialize();

	void Update(double curFrame, double deltaFrame);

	void Render();

	//�����нڵ��name�����ظ�����IDΨһ
	Node* AddNode(const stringT& name);

	//ɾ���ڵ㣬�Ƚ��ڵ㼰���ӽڵ��ƶ���m_NodesToDestroy������һ֡ͳһɾ��
	bool RemoveNode(Node* node);

	//������ɾ��һ���ڵ�
	bool RemoveNode(unsigned long id);

	//�ҵ������е�һ������ƥ��Ľڵ�
	Node* FindNode(const stringT& name);

	//��ó������ڵ�
	Node* GetRootNode();

	//UI�¼�
	void OnMouseMove(double xPos, double yPos);

	void OnMouseDown();

	void OnMouseUp();

	void OnKeyboard(int key);

	void OnMouseScroll(double xOffset, double yOffset);

	void ToFree(const glm::vec3& position);

	void ToFollow(Node* node);

	CameraComponent* GetActiveCamera();

private:
	std::map<unsigned long, Node*> m_Nodes;//���������еĽڵ㣬ʹ��map���ڲ�ѯ
	std::vector<Node*> m_NodesToDestroy;//��Ҫɾ���Ľڵ㣬һ������һ֡ɾ��
	Node* m_RootNode;//�������ڵ�
	unsigned long m_CurNodeID;//�����ڵ�id
	FreeCameraComponent* m_FreeCamera;
	FollowCameraComponent* m_FollowCamera;
	int m_WindowWidth;
	int m_WindowHeight;

	Text* m_TextRender;

	PostProcessor* m_Effects;
};
