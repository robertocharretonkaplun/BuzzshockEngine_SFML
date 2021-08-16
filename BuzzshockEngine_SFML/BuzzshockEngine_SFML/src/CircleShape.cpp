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
    m_origin = new float[2];
    m_origin[0] = 0.0f;
    m_origin[1] = 0.0f;
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
    m_shape.setOrigin(m_origin[0], m_origin[1]);
    m_shape.setOutlineThickness(m_outlineThickness);
    m_shape.setOutlineColor(m_outlineColor);
  }

  void 
  CircleShape::render() {
  }

  void 
  CircleShape::render(sf::RenderWindow& _window) {
    _window.draw(m_shape);
    //_window.draw(m_sprite);
  }

  void 
  CircleShape::ui() {
    ImGui::Separator();
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      // Origin
      if (ImGui::TreeNode("Origin")) {
        ImGui::Separator();
        vector2UI("Origin", m_origin, "##O0", "##O1");
        ImGui::TreePop();
      }
      ImGui::Separator();
      // Shape color
      if (ImGui::TreeNode("Shape Color")) {
        ImGui::Separator();
        circleColorUI();
        ImGui::TreePop();
      }
      ImGui::Separator();
      // Outline
      if (ImGui::TreeNode("Outline Thickness")) {
        ImGui::Separator();
        outlineColorUI();
        ImGui::SliderFloat("Outline Thickness", &m_outlineThickness, 0.0f, 10.0f);
        ImGui::TreePop();
      }
      ImGui::Separator();
      // Texture
      if (ImGui::TreeNode("Texture")) {
        ImGui::Separator();
        textureUI();
        ImGui::TreePop();
      }
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
  
  void 
  CircleShape::vector2UI(string label, float* values, string _id0, 
                         string _id1, float resetValues, float columnWidth) {
    ImGui::Text(label.c_str());
    ImGui::SameLine();
    ImVec2 buttonSize = { 18 + 3.0f, 18 };

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    if (ImGui::Button("X", buttonSize)) {
      values[0] = resetValues;
    }
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    // slider will be 65% of the window width (this is the default)
    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

    // slider will always be 400 pixel wide
    ImGui::PushItemWidth(50);

    // slider will fill the space and leave 100 pixels for the label
    ImGui::PushItemWidth(-200);
    ImGui::DragFloat(_id0.c_str(), &values[0], 0.1f);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    if (ImGui::Button("Y", buttonSize)) {
      values[1] = resetValues;
    }
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    // slider will be 65% of the window width (this is the default)
    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

    // slider will always be 400 pixel wide
    ImGui::PushItemWidth(50);

    // slider will fill the space and leave 100 pixels for the label
    ImGui::PushItemWidth(-100);
    ImGui::DragFloat(_id1.c_str(), &values[1], 0.1f);
  }
  
  void 
  CircleShape::circleColorUI() {
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
  }

  void 
  CircleShape::outlineColorUI() {
    const char* items[] = { "Red", "Green", "Blue", "White", "Yellow" };
    static const char* current_item = NULL;

    if (ImGui::BeginCombo("Outline color", current_item)) {
      for (int n = 0; n < IM_ARRAYSIZE(items); n++) {

        bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
        if (ImGui::Selectable(items[n], is_selected)) {
          current_item = items[n];

          if (n == 0) {
            m_outlineColor = sf::Color::Red;
          }
          if (n == 1) {
            m_outlineColor = sf::Color::Green;
          }
          if (n == 2) {
            m_outlineColor = sf::Color::Blue;
          }
          if (n == 3) {
            m_outlineColor = sf::Color::White;
          }
          if (n == 4) {
            m_outlineColor = sf::Color::Yellow;
          }
        }
        if (is_selected)
          ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
      }
      ImGui::EndCombo();
    }
  }
  
  void 
  CircleShape::textureUI() {
    static char str1[128] = "";
    ImGui::InputText("Texture Name", str1, IM_ARRAYSIZE(str1));
    if (ImGui::Button("Set texture")) {
      ImGui::SameLine();
      string name = str1;
      string texPath = "Data/Textures/" + name;
      if (m_texture.loadFromFile(texPath.c_str())) {
        m_shape.setTexture(&m_texture);
      }
      else {
        cout << "Texture not found : " << endl;
      }
    }
  }
}