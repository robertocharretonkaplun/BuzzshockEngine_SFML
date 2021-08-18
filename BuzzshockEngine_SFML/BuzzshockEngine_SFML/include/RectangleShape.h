#pragma once
#include <Prerequisites.h>
#include <Component.h>

namespace buEngineSDK {
	class Transform;
	class RectangleShape : public Component{
	public:
		RectangleShape()  = default;
		~RectangleShape() = default;

		void
		init() override;

		void
		update() override;

		void
		update(Transform * _transform);

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

		sf::RectangleShape&
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
		rectanlgeColorUI();
		
		void
		outlineColorUI();

		void
		textureUI();

	private:
		string m_name = "Rectanlge Shape";

		sf::RectangleShape m_shape;

		sf::Color m_color;

		sf::Color m_outlineColor;

		float* m_origin;

		float m_outlineThickness = 0.0f;

		sf::Texture m_texture;

		sf::Sprite m_sprite;


		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::RECTANGLE_SHAPE;
	};
}