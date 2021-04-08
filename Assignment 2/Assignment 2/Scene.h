#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;
	virtual void output() = 0;
	virtual void update() = 0;
	virtual void input() = 0;
	virtual void save() = 0;
	//virtual void start() = 0;
private:

};

#endif // !_SCENE_H_
