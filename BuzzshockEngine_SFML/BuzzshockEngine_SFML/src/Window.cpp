#include "Window.h"

namespace buEngineSDK {
  void 
  Window::init(string _windowName, int _w, int _h) {
    m_window.create(sf::VideoMode(_w, _h), _windowName);
  }

  void 
  Window::update() {
  }

  void 
  Window::render() {
  }

  void 
  Window::destroy() {
  }
  
  sf::RenderWindow& 
  Window::getWindow() {
    return m_window;
  }
}
