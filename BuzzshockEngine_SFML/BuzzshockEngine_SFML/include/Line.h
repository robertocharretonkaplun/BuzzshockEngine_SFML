#pragma once
#include <Prerequisites.h>
#include <Component.h>

namespace buEngineSDK {
	class Line : public Component {
	public:
		Line ()  = default;
		~Line () = default;

		void
		init() override;

		void
		update() override;

		void
		render() override;

		void
		render(sf::RenderWindow & _window);
		
		void
		ui() override;

		buEngineSDK::ComponentType::E
		getType() override;

	  string
		getName() override;

		vector<sf::Vertex> &
		getShape();
	private:
		void
		vector2UI(string label,
								float* values, 
                string _id0,
                string _id1,
								float resetValues = 0.0f, 
								float columnWidth = 100.0f);

		void
		lineColorUI();
	private:
		string m_name = "Line";

		float* m_initPos;
		float* m_finalPos;
		vector<sf::Vertex> m_line;

		sf::Color m_color;

		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::RECTANGLE_SHAPE;
	};
}
