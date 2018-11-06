#include "MeshRenderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

#include <iostream>

using namespace Disc_Engine;

void MeshRenderer::OnInit()
{
	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->Add(glm::vec3( 0.0f,  0.5f, 0.0f));
	positions->Add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->Add(glm::vec3( 0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	colors->Add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->Add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colors->Add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	m_shape = std::make_shared<VertexArray>();
	m_shape->SetBuffer("in_Position", positions);
	m_shape->SetBuffer("in_Color", colors);

	m_shader = std::make_shared<Shader>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
}


void MeshRenderer::OnDisplay()
{
	m_shader->SetUniform("in_Model", glm::mat4(1.0f));
	m_shader->SetUniform("in_Projection", glm::mat4(1.0f));
	m_shader->Draw(*m_shape);

	//std::cout << "drawn" << std::endl;
}
