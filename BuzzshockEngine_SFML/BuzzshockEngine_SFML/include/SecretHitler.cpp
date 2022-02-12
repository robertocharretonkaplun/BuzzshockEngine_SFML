#include "SecretHitler.h"

namespace buEngineSDK {
  void 
  SecretHitler::init() {
    // Get connected players -> Omniverse

    // Create players
    createPlayer();
    // Initialize Players
    initPlayers();
    // Set secret Role to each player
    setSecretRole();
    // Asign each player data to connected user -> Omniverse

  }
  
  void 
  SecretHitler::render() {
    m_player1.render();
  }

  void 
  SecretHitler::setSecretRole() {
    for (auto& player : m_players) {
      PartyMembership tmpRole;
      // Set random role index number
      int randomRoleIndex = rand() % m_connectedPlayers;
      tmpRole = (PartyMembership)randomRoleIndex;
      // Asigne role to player
      player.setPartyMembership(tmpRole);
    }
  }
  
  void 
  SecretHitler::createPlayer() {
    for (int i = 0; i < m_connectedPlayers; i++) {
      SHPlayer newPlayer;
      m_players.push_back(newPlayer);
    }
  }
  
  void 
  SecretHitler::initPlayers() {
    for (auto& player : m_players) {
      player.init();
    }
  }
}