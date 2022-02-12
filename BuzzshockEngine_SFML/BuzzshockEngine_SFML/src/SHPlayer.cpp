#include "SHPlayer.h"

namespace buEngineSDK {
  void
  SHPlayer::init() {
    m_texture.loadFromFile("Data/Textures/Personaje05_Badgeron_Liberal.png");
    // Set role text
    if (m_role == PartyMembership::FASCIST || m_role == PartyMembership::HITLER) {
      m_roleText = "FASCIST";
    }
    else if (m_role == PartyMembership::LIBERAL) {
      m_roleText = "LIBERAL";
    }
  }

  void
  SHPlayer::render() {
    ImGui::Begin("Roberto Charreton");
    // Set image profile
    ImGui::Image(m_texture, sf::Vector2f(300, 350));
    ImGui::Separator();
    // Show Role description
    string role = "Role: " + m_roleText;
    ImGui::Text(role.c_str());
    ImGui::Separator();
    // Set votation
    ImGui::Text("                Votation");
    if (ImGui::Button("YES", ImVec2(135, 50))) {
    }
    ImGui::SameLine();
    if (ImGui::Button("NO", ImVec2(135, 50))) {
    }
    ImGui::End();
  }
  
  void 
  SHPlayer::setPartyMembership(PartyMembership _role) {
    m_role = _role;
  }
}
