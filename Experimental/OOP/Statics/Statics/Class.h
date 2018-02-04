#pragma once
#include <iostream>

using namespace std;

class Player {
private:
	char name[16];
	int strenght;
	int intelegent;
	int player_id;
	static int id;
public:
	Player() {
		cout << "Enter your name ";
		cin >> name;
		cout << "Enter your str and int ";
		cin >> strenght;
		cin >> intelegent;
		player_id = give_id();
	}
	~Player() {
		cout << "Hana mne posani" << endl;
	}

	static int give_id() {
		id++;
		return id;
	}

	int get_id() {
		return player_id;
	}
};
int Player::id = 0;