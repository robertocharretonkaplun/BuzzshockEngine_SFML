#include "GraphicsAPI.h"

namespace buEngineSDK {
  void 
  GraphicsAPI::createWindow() {
    m_window.create(sf::VideoMode(640, 480), "Buzzshock Engine SFML");
  }

  void GraphicsAPI::setFrameLimit(int _limit) {
    m_window.setFramerateLimit(60);
  }
  
  bool 
  GraphicsAPI::isWindowOpen() {
    return m_window.isOpen();
  }
  bool GraphicsAPI::poolOfEvent()
  {
    return m_window.pollEvent(m_event);
  }
  void GraphicsAPI::windowClose() {
    m_window.close();
  }
  void GraphicsAPI::clear()
  {
    m_window.clear();
  }

  void GraphicsAPI::present()
  {
    m_window.display();
  }
}