#pragma once
#include "Prerequisites.h"
#include "SHCommons.h"
namespace buEngineSDK {
  class SHPlayer {
  public:
    SHPlayer() = default;
    ~SHPlayer() = default;


    void
    init();

    void
    render();
    
    void
    setPartyMembership(PartyMembership _role);

    bool
    vote();
  private:
    unsigned int m_id = 0;
    string m_publicName = "Peter";
    PartyMembership m_role;
    bool m_isPresident = false;
    sf::Texture m_texture;
    int m_turn = 0;
    string m_roleText;
  };
}