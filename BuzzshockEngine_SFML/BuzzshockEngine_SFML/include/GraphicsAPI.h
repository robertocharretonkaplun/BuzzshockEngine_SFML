#pragma once
#include <Prerequisites.h>
// SFML Library
#include <SFML/Graphics.hpp>
namespace buEngineSDK {
	class GraphicsAPI {
	public:
		GraphicsAPI() = default;
		~GraphicsAPI() = default;

		void 
		CreateWindow();

		void
		setFrameLimit(int _limit);

		bool
		isWindowOpen();

		bool 
		poolOfEvent();

		void
		windowClose();

		void
		clear();

		void
		present();
	private:
		sf::RenderWindow m_window;
		sf::Event m_event;
	};
}