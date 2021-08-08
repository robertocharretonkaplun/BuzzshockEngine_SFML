#pragma once
#include <Prerequisites.h>
#include <Node.h>
namespace buEngineSDK {
  class Transform;
  class SceneGraph {
  public:
    SceneGraph()  = default;
    ~SceneGraph() = default;

    void
    init();

    void 
    update();

    void
    render();

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
  private:
    vector<Node> m_nodes;
    int m_currnode = 0;
    int m_tempComponentType;
  };
}