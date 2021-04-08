#pragma once
#include "Scene.h"
class InventoryScene : public Scene
{
public:
	InventoryScene();
	~InventoryScene() = default;
	virtual void output() override;
	virtual void update() override;
	virtual void input() override;
	virtual void save() override;
private:

};

