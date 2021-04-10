#pragma once
#ifndef _DEATH_SCENE_H_
#define _DEATH_SCENE_H_

#include "Scene.h"
#include <fstream>

using namespace std;

class DeathScene : public Scene
{
public:
	DeathScene(int);
	~DeathScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
private:
	int endingVer;
	ifstream openFile;
	string choice;
};

#endif // !_DEATH_SCENE_H_

