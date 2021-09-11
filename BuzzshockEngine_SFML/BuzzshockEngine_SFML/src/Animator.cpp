#include "Animator.h"

namespace buEngineSDK {
  void 
  Animator::init() {
  }

  void 
  Animator::init(sf::Texture& _tex, sf::Vector2u _imgCount) {
    m_texture = _tex;
    //m_imageCount = _imgCount;
    //
    //m_totalTime = 0.0f;
    //m_currImage.x = 0;
    //
    //m_uvRect.width = _tex.getSize().x / float(m_imageCount.x);
    //m_uvRect.height = _tex.getSize().y / float(m_imageCount.y);
  }

  void 
  Animator::update() {
    if (m_isAnimating){
      m_t += 0.0000001f;
      m_currImage.y = m_row;
      m_totalTime += m_t;

      if (m_totalTime >= m_animationSpeed) {
        m_totalTime -= m_animationSpeed;
        m_currImage.x++;

        if (m_currImage.x >= m_imageCount.x){
          m_currImage.x = 0;
        }
      }

      m_uvRect.left = m_currImage.x * m_uvRect.width;
      m_uvRect.top = m_currImage.y * m_uvRect.height;
    }
  }
  
  void 
  Animator::render() {
  }

  void 
  Animator::render(sf::RenderWindow& _window) {
  }
  
  void 
  Animator::ui() {
    ImGui::Separator();
    if (ImGui::TreeNode(m_name.c_str())) {
      ImGui::Separator();
      
      ImGui::InputInt("W", &w, 0, 100);
      ImGui::InputInt("H", &h, 0, 100);
      if (ImGui::Button("Set Animation area")) {
        m_totalTime = 0.0f;
        m_currImage.x = 0;
        m_imageCount.x = w;
        m_imageCount.y = h;
        m_uvRect.width = m_texture.getSize().x / float(m_imageCount.x);
        m_uvRect.height = m_texture.getSize().y / float(m_imageCount.y);
        m_isAnimating = true;
      }
      ImGui::SliderInt("Animation", &m_row, 0, 100);
      ImGui::SliderFloat("Speed", &m_animationSpeed, 0.0f, 10.0f);
      ImGui::SliderFloat("time", &m_t, 0.0f, 1.0f);
      //
      ImGui::TreePop();
    }
  }
  
  buEngineSDK::ComponentType::E 
  Animator::getType() {
    return m_componentType;
  }
  
  string 
  Animator::getName() {
    return m_name;
  }
  
  sf::IntRect& 
  Animator::getuvRect() {
    return m_uvRect;
  }
}