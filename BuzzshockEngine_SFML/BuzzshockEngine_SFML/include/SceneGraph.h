#pragma once
#include <Prerequisites.h>
#include <Node.h>
namespace buEngineSDK {
  class Transform;
  class CircleShape;
  class SceneGraph {
  public:
    SceneGraph()  = default;
    ~SceneGraph() = default;

    void
    init();

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
    vector<Node> m_nodes;
    int m_currnode = 0;
    int m_tempComponentType;
  };
}