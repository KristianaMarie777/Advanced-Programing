#pragma once
#ifndef _ESCAPE_SCENE_H_
#define _ESCAPE_SCENE_H_

#include "Scene.h"
class EscapeScene : public Scene
{
public:
	EscapeScene();
	~EscapeScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
private:

};

#endif // !_ESCAPE_SCENE_H_
