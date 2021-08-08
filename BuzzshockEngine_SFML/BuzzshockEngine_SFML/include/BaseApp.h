#pragma once
#include <Prerequisites.h>

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
								float resetValues = 0.0f, 
								float columnWidth = 100.0f);

    void
    properties();
	private:
    float * m_position;
	};
}