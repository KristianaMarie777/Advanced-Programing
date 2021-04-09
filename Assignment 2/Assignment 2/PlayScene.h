#pragma once
#ifndef _PLAY_SCENE_H_
#define _PLAY_SCENE_H_

#include "Scene.h"
#include <string>
#include <fstream>
#include "SearchNext.h"
#include "LivingRoom.h"

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

	//void setValues();
private:
	bool livingRoom, kitchen, washRoomMid, workRoom, hallWay, bedRoom, washRoomTop, storageRoom, basement;
	int direction;
	string directionName[4], type, action;
	Room* currentRoom;
	ifstream gameText;
};
#endif // !_PLAY_SCENE_H_



