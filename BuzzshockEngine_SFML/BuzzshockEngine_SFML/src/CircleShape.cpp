#include "CircleShape.h"
#include "Transform.h"
namespace buEngineSDK {
  void
  CircleShape::init() {
    m_shape.setRadius(10.0f);
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.rotate(100);
    m_shape.setPosition(500, 500);
  }

  void CircleShape::update()
  {
  }

  void 
  CircleShape::update(Transform* _transform) {
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.setPosition(_transform->m_pos[0], _transform->m_pos[1]);
    m_shape.setRotation(_transform->m_rot[0]);
    m_shape.setRadius(_transform->m_scal[0]);
  }

  void 
  CircleShape::render() {
  }

  void 
  CircleShape::render(sf::RenderWindow& _window) {
    _window.draw(m_shape);
  }

  void 
  CircleShape::ui() {
    ImGui::Separator();
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      ImGui::TreePop();
    }
  }

  buEngineSDK::ComponentType::E 
  CircleShape::getType() {
    return m_componentType;
  }

  string 
  CircleShape::getName() {
    return m_name;
  }
  
  sf::CircleShape& 
  CircleShape::getShape() {
    return m_shape;
  }
}