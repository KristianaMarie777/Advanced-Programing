#pragma once
#ifndef _ENDING_SCENE_H_
#define _ENDING_SCENE_H_

#include "Scene.h"
#include <fstream>

using namespace std;

class EndingScene : public Scene
{
public:
	EndingScene(int);
	~EndingScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
private:
	int endingVer;
	ifstream openFile;
	string choice;
};

#endif // !_DEATH_SCENE_H_

