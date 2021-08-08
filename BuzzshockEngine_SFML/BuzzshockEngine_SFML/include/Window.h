#pragma once
#include <Prerequisites.h>

namespace buEngineSDK {
  class Window
  {
  public:
    Window() = default;
    ~Window() = default;

    void
    init(string _windowName, int _w, int _h);

    void 
    update();

    void
    render();

    void
    destroy();

    sf::RenderWindow & 
    getWindow();
  private:
    sf::RenderWindow m_window;
  };
}
