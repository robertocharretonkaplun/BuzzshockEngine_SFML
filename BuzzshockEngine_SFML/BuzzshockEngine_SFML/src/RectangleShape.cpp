#include "RectangleShape.h"
#include "Transform.h"

namespace buEngineSDK {
  void
  RectangleShape::init() {
    m_shape.setSize(sf::Vector2(10.0f, 10.0f));
    m_shape.setFillColor(sf::Color::Yellow);
    m_shape.rotate(100);
    m_shape.setPosition(500, 500);
    m_color = sf::Color::White;
    m_origin = new float[2];
    m_tmpScale = new float[2];
    m_origin[0] = 0.0f;
    m_origin[1] = 0.0f;
    m_tmpScale[0] = 0.0f;
    m_tmpScale[1] = 0.0f;
  }

  void RectangleShape::update()
  {
  }

  void 
  RectangleShape::update(Transform* _transform) {
    m_shape.setFillColor(m_color);
    m_shape.setPosition(_transform->m_pos[0], _transform->m_pos[1]);
    m_shape.setRotation(_transform->m_rot[0]);
    m_shape.setSize(sf::Vector2(_transform->m_scal[0], _transform->m_scal[1]));
    m_tmpScale = _transform->m_scal;
    m_shape.setOrigin(m_origin[0], m_origin[1]);
    m_shape.setOutlineThickness(m_outlineThickness);
    m_shape.setOutlineColor(m_outlineColor);
  }

  void 
  RectangleShape::render() {
  }

  void 
  RectangleShape::render(sf::RenderTexture& _scene) {
    
    _scene.draw(m_shape);
    //_window.draw(m_sprite);
    
  }

  void 
  RectangleShape::ui() {
    ImGui::Separator();
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      // Origin
      if (ImGui::TreeNode("Origin")) {
        ImGui::Separator();
        vector2UI("Origin", m_origin, "##O0", "##O1");
        if (ImGui::Button("Center Origin")) {
          m_origin[0] = m_tmpScale[0] / 2;
          m_origin[1] = m_tmpScale[1] / 2;
        }
        ImGui::TreePop();
      }
      ImGui::Separator();
      // Shape color
      if (ImGui::TreeNode("Shape Color")) {
        ImGui::Separator();
        rectanlgeColorUI();
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
  RectangleShape::getType() {
    return m_componentType;
  }

  string 
  RectangleShape::getName() {
    return m_name;
  }
  
  sf::RectangleShape& 
  RectangleShape::getShape() {
    return m_shape;
  }

  sf::Texture& 
  RectangleShape::getTexture() {
    return m_texture;
  }
  
  void 
  RectangleShape::vector2UI(string label, float* values, string _id0, 
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
  RectangleShape::rectanlgeColorUI() {
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
  RectangleShape::outlineColorUI() {
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
  RectangleShape::textureUI() {
    static char str1[128] = "";
    string name;
    ImGui::Text(m_texPath.c_str());
    ImGui::Image(m_texture, sf::Vector2f(50.0f, 50.0f));
    ImGui::InputText("Texture Name", str1, IM_ARRAYSIZE(str1));
    if (ImGui::Button("Set texture")) {
      ImGui::SameLine();
      name = str1;
      string texPath = "Data/Textures/" + name;
      m_texPath = texPath;
      if (m_texture.loadFromFile(texPath.c_str())) {
        cout << "Texture load with path found in : " << m_texPath << endl;
        m_shape.setTexture(&m_texture);
      }
      else {
        cout << "Texture not found : " << texPath << endl;
        string texPath = "Data/Textures/DefaultTexture.png";
        m_texPath = texPath;
        cout << "Texture load with default path found in : " << texPath << endl;
        m_texture.loadFromFile(texPath.c_str());
        m_shape.setTexture(&m_texture);
      }
    }
  }
}