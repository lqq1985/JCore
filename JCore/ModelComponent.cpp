#include "stdafx.h"
#include "Node.h"
#include "ModelComponent.h"
#include "ResourceManager.h"
#include "World.h"

ModelComponent::ModelComponent(const std::string& path)
{
	m_Model.LoadModel(path.c_str());
}

ModelComponent::~ModelComponent()
{
}

stringT ModelComponent::GetTypeName()
{
	return _T("ModelComponent");
}

void ModelComponent::Update(double curFrame, double deltaFrame)
{
	m_Model.SetWorldTransform(GetOwner()->GetWorldTransform());
	m_Model.SetHighLight(GetOwner()->GetHighLight());
	m_Model.SetHighLightColor(GetOwner()->GetHighLightColor());
	m_Model.SetID(GetOwner()->GetID());
	m_Model.SetColor(GetOwner()->GetColor());
	m_Model.SetCurrentAnimation(GetOwner()->GetCurrentAnimation());

	if (m_Model.GetSupportAnimation()) {
		m_Model.UpdateBoneTransform(curFrame);
	}
}

void ModelComponent::OnAddToWorld(World* world)
{
	if (m_Model.GetSupportAnimation()) {
		world->GetScene()->GetAnimationModels().push_back(&m_Model);
	}
	else {
		world->GetScene()->GetModels().push_back(&m_Model);
	}
}

void ModelComponent::OnRemoveFromWorld(World* world)
{
	auto it = std::find(world->GetScene()->GetModels().begin(), world->GetScene()->GetModels().end(), &m_Model);
	if (it != world->GetScene()->GetModels().end()) {
		world->GetScene()->GetModels().erase(it);
	}

	it = std::find(world->GetScene()->GetAnimationModels().begin(), world->GetScene()->GetAnimationModels().end(), &m_Model);
	if (it != world->GetScene()->GetAnimationModels().end()) {
		world->GetScene()->GetAnimationModels().erase(it);
	}
}
