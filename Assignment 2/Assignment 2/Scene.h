#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

class Scene
{
public:
	Scene();
	virtual ~Scene() = 0;
	virtual void output() = 0;
	virtual void update() = 0;
	virtual void input() = 0;
	virtual void save() = 0;
private:

};

#endif // !_SCENE_H_
