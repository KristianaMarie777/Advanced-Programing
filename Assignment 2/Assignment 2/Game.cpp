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
	changeSceneState(PLAY_SCENE);
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
		system("CLS");

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
		case ESCAPE_SCENE:
			m_currentScene = new EscapeScene();
			std::cout << "escape scene activated" << std::endl;
			break;
		case DEATH_SCENE:
			m_currentScene = new DeathScene();
			std::cout << "death scene activated" << std::endl;
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
