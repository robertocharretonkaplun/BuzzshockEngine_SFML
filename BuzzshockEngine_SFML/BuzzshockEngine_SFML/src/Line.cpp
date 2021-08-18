#include "Line.h"

namespace buEngineSDK {
  void 
  Line::init() {
    m_initPos = new float[2];
    m_finalPos = new float[2];

    m_initPos[0] = 10;
    m_initPos[1] = 10;
    m_finalPos[0] = 150;
    m_finalPos[1] = 0;

    m_line.push_back(sf::Vertex(sf::Vector2f(m_initPos[0], m_initPos[1])));
    m_line.push_back(sf::Vertex(sf::Vector2f(m_finalPos[0], m_finalPos[1])));
  }
  
  void 
  Line::update() {
    m_line[0].position.x = m_initPos[0];
    m_line[0].position.y = m_initPos[1];
    m_line[0].position.x = m_finalPos[0];
    m_line[1].position.y = m_finalPos[1];
  }

  void 
  Line::render() {
  }

  void 
  Line::render(sf::RenderWindow& _window) {
    _window.draw(m_line.data(), m_line.size(), sf::Lines);
  }

  void 
  Line::ui() {
    ImGui::Separator();
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      vector2UI("Initial Position", m_initPos, "##I0", "##I1");
      vector2UI("Final Position", m_finalPos, "##F0", "##F1");
    }
  }

  buEngineSDK::ComponentType::E 
  Line::getType() {
    return m_componentType;
  }

  string 
  Line::getName() {
    return m_name;
  }

  vector<sf::Vertex>& 
  Line::getShape() {
    return m_line;
  }

  void 
  Line::vector2UI(string label, float* values, string _id0, string _id1, 
                  float resetValues, float columnWidth) {
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

}