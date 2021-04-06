#pragma once
#ifndef _DEATH_SCENE_H_
#define _DEATH_SCENE_H_

#include "Scene.h"
class DeathScene : public Scene
{
public:
	DeathScene();
	~DeathScene();
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
private:

};

#endif // !_DEATH_SCENE_H_

