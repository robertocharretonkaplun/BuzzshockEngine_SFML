#pragma once
#include <Prerequisites.h>
#include <SceneGraph.h>
namespace buEngineSDK {
	class BaseApp {
	public:
		BaseApp() = default;
		~BaseApp() = default;

    int
    run();

		void
    init();

    void 
    update();

    void
    render();

    void
    destroy();
    
    void 
    style();

    void
    MainMenu();

    void
		vec3Control(string label,
								float* values, 
                string _id0,
                string _id1,
								float resetValues = 0.0f, 
								float columnWidth = 100.0f);

    void
    properties();
	private:
    SceneGraph m_graphman;
    float * m_position;
    float * m_rotation;
    float * m_scale;
	};
}