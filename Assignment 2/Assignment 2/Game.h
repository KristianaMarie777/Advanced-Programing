#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "StartScene.h"
#include "PlayScene.h"
#include "InventoryScene.h"
#include "EndingScene.h"
#include "User.h"

#include "SceneState.h"

#include <iostream>

class Game
{
public:

	static Game* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	// simply set the isRunning variable to true
	void init();
	
	// public life cycle functions
	void output() const;
	void update() const;
	void input();
	void start();
	void quit();

	bool isRunning() const;
	void changeSceneState(SceneState new_state);

	void setPlayer(string name = "") { player = new User(name); }
	User* getPlayer() { return player; }

private:
	Game();
	~Game();

	// game properties
	bool m_bRunning;

	// scene variables
	Scene* m_currentScene;
	SceneState m_currentSceneState;
	
	// storage structures
	static Game* s_pInstance;


	User* player;

};


#endif // !_GAME_H_


