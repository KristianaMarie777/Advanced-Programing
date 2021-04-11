#pragma once
#ifndef _STORY_SCENE_H_
#define _STORY_SCENE_H_
#include "Scene.h"

class StoryScene : public Scene
{
public:
	StoryScene();
	~StoryScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
private:

};

#endif // !_STORY_SCENE_H_



