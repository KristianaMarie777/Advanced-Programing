#pragma once
#ifndef _PLAY_SCENE_H_
#define _PLAY_SCENE_H_

#include "Scene.h"
#include <string>

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
	bool livingRoom, kitchen, washRoomMid, workRoom, hallWay, bedRoom, washRommTop, storageRoom, basement;
	int direction;
	string directionName[4], type, action;
};
#endif // !_PLAY_SCENE_H_



