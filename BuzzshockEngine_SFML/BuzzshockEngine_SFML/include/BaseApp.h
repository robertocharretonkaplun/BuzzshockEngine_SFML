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
	private:
    SceneGraph m_graphman;
    float * m_position;
    float * m_rotation;
    float * m_scale;
	};
}