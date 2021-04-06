#pragma once
#ifndef _PLAY_SCENE_H_
#define _PLAY_SCENE_H_

#include "Scene.h"

class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene();
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
private:

};
#endif // !_PLAY_SCENE_H_



