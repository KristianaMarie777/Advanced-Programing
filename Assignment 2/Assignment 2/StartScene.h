#pragma once
#ifndef _START_SCENE_H_
#define _START_SCENE_H_

#include "Scene.h"
#include "LinkedList.h"

class StartScene : public Scene
{
public:
	StartScene();
	~StartScene();
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
	void user();
private:
	LinkedList<string> userNames;
};

#endif // !_START_SCENE_H_



