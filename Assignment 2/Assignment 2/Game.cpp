#include "Game.h"

Game* Game::s_pInstance = nullptr;

Game::Game() : 
	m_bRunning(true),m_currentScene(nullptr), m_currentSceneState(NO_SCENE)
{
	srand(unsigned(time(nullptr)));  // random seed
}

Game::~Game()
= default;

void Game::init()
{
	m_bRunning = true;

	start();
}

void Game::output() const
{
	system("CLS");
	m_currentScene->output();
}

void Game::update() const
{
	m_currentScene->update();
}

void Game::input()
{
	m_currentScene->input();

}

void Game::start()
{
	m_currentSceneState = NO_SCENE;

	//changeSceneState(m_currentSceneState);
	changeSceneState(START_SCENE);
}

void Game::quit()
{
	m_bRunning = false;
	//m_currentScene->save();
}

bool Game::isRunning() const
{
	return m_bRunning;
}

void Game::changeSceneState(SceneState new_state)
{
	if (new_state != m_currentSceneState)
	{
		// scene clean up

		m_currentScene = nullptr;

		m_currentSceneState = new_state;

		switch (m_currentSceneState)
		{
		case START_SCENE:
			m_currentScene = new StartScene();
			std::cout << "start scene activated" << std::endl;
			break;
		case PLAY_SCENE:
			m_currentScene = new PlayScene();
			std::cout << "play scene activated" << std::endl;
			break;
		case ESCAPE_SCENE_VER1:
			m_currentScene = new EndingScene(3);
			std::cout << "escape scene activated" << std::endl;
			break;
		case ESCAPE_SCENE_VER2:
			m_currentScene = new EndingScene(4);
			std::cout << "escape scene activated" << std::endl;
			break;
		case ESCAPE_SCENE_VER3:
			m_currentScene = new EndingScene(5);
			std::cout << "escape scene activated" << std::endl;
			break;
		case DEATH_SCENE_VER1:
			m_currentScene = new EndingScene(0);
			std::cout << "death scene ver1 activated" << std::endl;
			break;
		case DEATH_SCENE_VER2:
			m_currentScene = new EndingScene(1);
			std::cout << "death scene ver2 activated" << std::endl;
			break;
		case DEATH_SCENE_VER3:
			m_currentScene = new EndingScene(2);
			std::cout << "death scene ver3 activated" << std::endl;
			break;
		case INVENTROY_SCENE:
			m_currentScene = new InventoryScene();
			std::cout << "inventory scene activated" << std::endl;
			break;
		default:
			std::cout << "default case activated" << std::endl;
			break;
		}
	}
}
