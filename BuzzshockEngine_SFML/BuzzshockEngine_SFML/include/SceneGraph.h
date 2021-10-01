#pragma once
#include <Prerequisites.h>
#include <Node.h>
namespace buEngineSDK {
  class Transform;
  class CircleShape;
  class RectangleShape;
  class Animator;
  class SceneGraph {
  public:
    SceneGraph()  = default;
    ~SceneGraph() = default;

    void
    init(float _w, float _h);

    void 
    update();

    void
    render(sf::RenderWindow& _window);

    void
    destroy();

    void
    ui();

    void
    basicsUI();

    void
    worldOutlinerUI();

    void
    propertiesUI();
    
    vector<Node> &
    getNodes();

  private:
    void
    createEmptyActor();

    void
    createCircleShapeActor();
    
    void
    createRectangleShapeActor();
  private:
    vector<Node> m_nodes;
    int m_currnode = 0;
    int m_tempComponentType;
    sf::RenderTexture m_scene;
    sf::Texture m_texture;
    bool m_debugMode;
  };
}