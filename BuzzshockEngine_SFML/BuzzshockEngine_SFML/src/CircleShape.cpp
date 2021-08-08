#include "CircleShape.h"
#include "Transform.h"
namespace buEngineSDK {
  void
  CircleShape::init() {
    m_shape.setRadius(10.0f);
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.rotate(100);
    m_shape.setPosition(500, 500);
    m_color = sf::Color::White;
  }

  void CircleShape::update()
  {
  }

  void 
  CircleShape::update(Transform* _transform) {
    m_shape.setFillColor(m_color);
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
      const char* items[] = { "Red", "Green", "Blue", "White", "Yellow" };
      static const char* current_item = NULL;

      if (ImGui::BeginCombo("Shape color", current_item)) {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++) {

          bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
          if (ImGui::Selectable(items[n], is_selected)) {
            current_item = items[n];

            if (n == 0) {
              m_color = sf::Color::Red;
            }
            if (n == 1) {
              m_color = sf::Color::Green;
            }
            if (n == 2) {
              m_color = sf::Color::Blue;
            }
            if (n == 3) {
              m_color = sf::Color::White;
            }
            if (n == 4) {
              m_color = sf::Color::Yellow;
            }
          }
          if (is_selected)
            ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
        }
        ImGui::EndCombo();
      }
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