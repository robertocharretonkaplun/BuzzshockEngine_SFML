#pragma once
#include "Prerequisites.h"
class VotationEngine
{
public:
	VotationEngine() = default;
	~VotationEngine() = default;

	// vote = 1 Positive, 0 Negative
	void 
	getVotePresident(int _vote, int _playerID, int _playerIndex) {
		// Check if player already vote
		for (auto& player : votedPlayers) {
			if (player == _playerID) {
				cout << "Player with ID: " << _playerID << ", already voted" << endl;
			}
			else {
				votedPlayers.push_back(_playerID);
				
				// store votation
				if (_playerIndex == 0) {
					player0Votes = _vote;
				}
				if (_playerIndex == 1) {
					player1Votes = _vote;
				}
				if (_playerIndex == 2) {
					player2Votes = _vote;
				}
				if (_playerIndex == 3) {
					player3Votes = _vote;
				}
				if (_playerIndex == 4) {
					player4Votes = _vote;
				}
				if (_playerIndex == 5) {
					player5Votes = _vote;
				}
			}
		}

	};

	void
	setWinner() {

	};

private:
	int positiveVotes = 0;
	int negativeVotes = 0;

	int player0Votes = 0;
	int player1Votes = 0;
	int player2Votes = 0;
	int player3Votes = 0;
	int player4Votes = 0;
	int player5Votes = 0;

	vector<int> votedPlayers;
};
