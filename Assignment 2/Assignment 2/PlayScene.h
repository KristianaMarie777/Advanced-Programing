#pragma once
#ifndef _PLAY_SCENE_H_
#define _PLAY_SCENE_H_

#include "Scene.h"
#include <string>
#include <fstream>
#include "SearchNext.h"

using namespace std;

class PlayScene : public Scene
{
public:
	PlayScene();

	~PlayScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;

	void txtOutput();
	//void setValues();
private:
	bool seenComputer = false,seenPassword = false, gotCode = false, gotCrank = false;
	int direction;
	string directionName[4], type, action;
	ifstream gameText;
	string roomName;
	SearchAbleVector<string> interactableItems;
};
#endif // !_PLAY_SCENE_H_



