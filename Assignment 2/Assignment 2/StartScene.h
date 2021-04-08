#pragma once
#ifndef _START_SCENE_H_
#define _START_SCENE_H_

#include "Scene.h"
#include "DynTempQueue.h"
#include <list>

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
	void user();
private:
	DynTempQueue<string> userNames;
	string choice;
	bool notAChar = false, notChoices = false;
};

#endif // !_START_SCENE_H_



