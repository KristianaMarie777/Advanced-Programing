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

	string text;
	ifstream gameText("gameText.txt");
	while (text != "STORY") { getline(gameText, text); }

	while (text != "STOP")
	{
		while (text != "END")
		{
			getline(gameText, text);
			if (text == "STOP") { break; }
			if (text != "-")
			{
				if (text != "END")
				{
					for (int i = 0; i < text.size(); i++)
					{
						cout << text[i];
						Sleep(15);
					}
				}

			}
			else
			{
				Sleep(500);
			}
			cout << endl;
			
		}
		getline(gameText, text);
		system("pause");
		system("CLS");
	}
	gameText.close();
}

void StoryScene::update()
{
	Game::Instance()->getPlayer()->setSeenStoryScene(true);
	Game::Instance()->changeSceneState(PLAY_SCENE);
}

void StoryScene::input()
{
}

void StoryScene::save()
{
}
