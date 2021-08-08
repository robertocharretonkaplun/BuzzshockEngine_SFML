#include "Transform.h"

namespace buEngineSDK {
  void 
  Transform::init() {
    m_pos= new float[2];
    m_scal = new float[2];
    m_rot = new float[2];

    m_pos[0] = 0.0f;
    m_pos[1] = 0.0f;
    m_scal[0] = 100.0f;
    m_scal[1] = 0.0f;
    m_rot[0] = 0.0f;
    m_rot[1] = 0.0f;
  }

  void 
  Transform::update() {
  }

  void 
  Transform::render() {
  }

  void 
  Transform::ui() {
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      vector2UI("Position", m_pos, "##X0", "##Y0");
      vector2UI("Rotation", m_rot, "##X1", "##Y1");
      vector2UI("Scale", m_scal  , "##X2", "##Y2");

      ImGui::Separator();

      ImGui::TreePop();
    }
  }

  buEngineSDK::ComponentType::E 
  Transform::getType() {
    return m_componentType;
  }

  string 
  Transform::getName() {
    return m_name;
  }

  void 
  Transform::vector2UI(string label, float* values, string _id0, string _id1,
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