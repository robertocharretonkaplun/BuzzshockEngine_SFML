// Ref: https://www.youtube.com/watch?v=-SlhLuyHWy0
#pragma once
#include "Prerequisites.h"
#include "SHPlayer.h"
#include "SHCommons.h"
namespace buEngineSDK {
  class SecretHitler {
  public:
    SecretHitler() = default;
    ~SecretHitler() = default;

    void
    init();

    void
    update();

    void
    render();

    void
    destroy();
  private:
    /* @brief: Method in charge of setting the secret role to each character
    */
    void
    setSecretRole();

    /**
    * @brief Give a card from the deck to a player
    */
    void
    StealCardFromDeck();

    void
    createPlayer();

    void
    initPlayers();
  private:
    vector<SHPlayer> m_players;
    SHPlayer m_player1;
    int m_playerTurn = 0;
    int m_connectedPlayers = 0;
  };
}
