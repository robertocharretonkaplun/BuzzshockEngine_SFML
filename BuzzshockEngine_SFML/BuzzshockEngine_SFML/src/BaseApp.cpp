#include "BaseApp.h"

namespace buEngineSDK {

  int 
  BaseApp::run() {
    init();
		sf::RenderWindow window(sf::VideoMode(1600, 900), "Buzzshock Engine SFML");
		window.setFramerateLimit(60);
		ImGui::SFML::Init(window);
		style();
		//sf::CircleShape shape(100.f);
    
		//shape.setFillColor(sf::Color::Yellow);
		//shape.rotate(100);
		//shape.setPosition(500, 500);
    
		sf::Clock deltaClock;
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				ImGui::SFML::ProcessEvent(event);
				ImGuiIO& io = ImGui::GetIO();
				if (io.WantCaptureMouse)
				{

				}
				if (event.type == sf::Event::Closed) {
					window.close();
				}
				//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
				//{
				//	exit(1);
				//}
			}
			ImGui::SFML::Update(window, deltaClock.restart());
			MainMenu();
      properties();
      m_graphman.ui();
      m_graphman.update();
      //shape.setPosition(m_position[0], m_position[1]);
      //shape.setRotation(m_rotation[0]);
      //shape.setRadius(m_scale[0]);

			window.clear();
      m_graphman.render(window);
			//window.draw(shape);
			ImGui::SFML::Render(window);
			window.display();
		}

		ImGui::SFML::Shutdown();
		return 0;
  }

  void 
  BaseApp::init() {
    m_position = new float[2];
    m_scale = new float[2];
    m_rotation = new float[2];
    m_position[0] = 0.0f;
    m_position[1] = 0.0f;
    m_scale[0] = 100.0f;
    m_scale[1] = 0.0f;
    m_rotation[0] = 0.0f;
    m_rotation[1] = 0.0f;
  }

  void 
  BaseApp::update() {
  }

  void 
  BaseApp::render() {
  }

  void  
  BaseApp::destroy() {
  }
	
	void 
  BaseApp::style() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.08f, 0.50f, 0.72f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.22f, 0.22f, 0.22f, 1.00f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.67f, 0.67f, 0.67f, 0.39f);
    style.Colors[ImGuiCol_Separator] = style.Colors[ImGuiCol_Border];
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.41f, 0.42f, 0.44f, 1.00f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.29f, 0.30f, 0.31f, 0.67f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.08f, 0.08f, 0.09f, 0.83f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.33f, 0.34f, 0.36f, 0.83f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.23f, 0.24f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.09f, 1.00f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.14f, 0.15f, 1.00f);
    //style.Colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
    //style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.11f, 0.64f, 0.92f, 1.00f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
    style.GrabRounding = style.FrameRounding = 2.3f;
    style.WindowRounding = 0.0f;
	}
  
  void 
  BaseApp::MainMenu() {
    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Load...", "CTRL+O")) {
        }
        if (ImGui::MenuItem("Save...", "CTRL+S")) {
        }
        ImGui::Separator();

        if (ImGui::MenuItem("Exit", "CTRL+F4")) {
          exit(1);
        }

        ImGui::EndMenu();
      }
      if (ImGui::BeginMenu("Edit")) {
        if (ImGui::MenuItem("Animator...")) {
          //m_showAnimator = true;
        }
        if (ImGui::BeginMenu("Script")) {
          if (ImGui::MenuItem("Script Editor...")) {
            //m_isScriptEditorOpen = true;
          }
          ImGui::EndMenu();
        }
        ImGui::EndMenu();
      }

      ImGui::EndMainMenuBar();
    }
  }
  
  void 
  BaseApp::vec3Control(string label, float* values, string _id0, string _id1, float resetValues, float columnWidth) {

    ImGui::Text(label.c_str());
    ImGui::SameLine();
    ImVec2 buttonSize = { 18 + 3.0f, 18};

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
    if (ImGui::Button("X", buttonSize)) {
      values[0] = resetValues;
    }
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    // slider will be 65% of the window width (this is the default)
    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

    // slider will always be 400 pixel wide
    ImGui::PushItemWidth(50);

    // slider will fill the space and leave 100 pixels for the label
    ImGui::PushItemWidth(-200);
    ImGui::DragFloat(_id0.c_str(), &values[0], 0.1f);
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
    if (ImGui::Button("Y", buttonSize)) {
      values[1] = resetValues;
    }
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    // slider will be 65% of the window width (this is the default)
    ImGui::PushItemWidth(ImGui::GetWindowWidth() * 0.65f);

    // slider will always be 400 pixel wide
    ImGui::PushItemWidth(50);

    // slider will fill the space and leave 100 pixels for the label
    ImGui::PushItemWidth(-100);
    ImGui::DragFloat(_id1.c_str(), &values[1], 0.1f);
    //ImGui::PopID();
  }
  
  void 
  BaseApp::properties() {
    ImGui::Begin("Properties2");
    vec3Control("Position", m_position, "##X0", "##Y0");
    vec3Control("Rotation", m_rotation, "##X1", "##Y1");
    vec3Control("Scale   ", m_scale,    "##X2", "##Y2");
    ImGui::End();
  }
}