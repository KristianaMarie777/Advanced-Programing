#include "StoryScene.h"
#include <string>
#include <iostream>
#include <Windows.h>
#include "Game.h"

using namespace std;

StoryScene::StoryScene()
= default;

void StoryScene::output()
{
	string text[] = { "Welcome Player...\n\n",
						""};

	for ( int i = 0; i < 2; i++)
	{
		for (int a = 0; a < text[i].size(); a++)
		{
			cout << text[i][a];
			Sleep(500);
		}
		system("pause");
	}
}

void StoryScene::update()
{
	Game::Instance()->changeSceneState(PLAY_SCENE);
}

void StoryScene::input()
{
}

void StoryScene::save()
{
}
