#pragma once
#ifndef _PLAY_SCENE_H_
#define _PLAY_SCENE_H_

#include "Scene.h"
#include <string>
#include <fstream>
#include "SearchNext.h"
#include <stack>
#include <list>
#include <queue>

using namespace std;

class PlayScene : public Scene
{
public:
	PlayScene(bool newGame = false);

	~PlayScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;

	void txtOutput();
	void bossFight();
	void autoSave();
	//void setValues();
private:
	bool seenComputer = false,seenPassword = false, gotCode = false, gotCrank = true, secondwindow = false, firstwindow = false,
		red = false,yellow = false, purple = false,black = false, white = false, green = false, opensafe = false, gotKey = true,
		doorIsOpen = true, endingStart = false, outOfBasement = false, lockedagain = false, textOnce = false;
	int direction, counter = 5;
	string directionName[4], type, action, roomName, finalGame = "H", bossRoom = " ", attack;
	ifstream gameText;
	stack<string> enemy;
	queue<string> follow;
	list<string> items;
	SearchAbleVector<string> interactableItems;
};
#endif // !_PLAY_SCENE_H_



