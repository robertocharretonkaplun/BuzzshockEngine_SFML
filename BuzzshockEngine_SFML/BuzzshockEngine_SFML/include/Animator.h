/**
 * @brief This class is in charge of animating the texture of circle and rectangle shapes.
 * Ref: https://www.youtube.com/watch?v=Aa8bXSq5LDE
 */
#pragma once
#include <Prerequisites.h>
#include <Component.h>

namespace buEngineSDK {
	class Animator : public Component	{
	public:
		Animator() = default;
		~Animator() = default;

		void
		init() override;

		void
		init(sf::Texture& _tex, sf::Vector2u _imgCount);

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

		sf::IntRect & 
		getuvRect();

	private:
		string m_name = "Animator";

		sf::IntRect m_uvRect;

		sf::Vector2u m_imageCount;

		sf::Vector2u m_currImage;

		float m_totalTime = 0.0f;

		float m_animationSpeed = 0.0f;
		float m_t = 0.0f;

		int m_row = 0;

		sf::Texture m_texture;

		int w = 0;

		int h = 0;

		bool m_isAnimating = false;

		// componentType: This object store the type of component that is the class.
		buEngineSDK::ComponentType::E m_componentType = buEngineSDK::ComponentType::E::ANIMATOR;


	};
}
