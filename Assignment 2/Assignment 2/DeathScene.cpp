#include "DeathScene.h"
#include <string>
#include <iostream>
#include "Game.h"
#include <Windows.h>

DeathScene::DeathScene(int endings= 0)
{
	endingVer = endings;
}

void DeathScene::output()
{
	openFile.open("gameText.txt");

	string getText;

	while (getText != "DEATH") { getline(openFile, getText); }
	while (getText != to_string(endingVer)) { getline(openFile, getText); }
	while (getText != "END")
	{
		getline(openFile, getText);
		if (getText != "-")
		{
			if (getText != "END")
			{
				for (int i = 0; i < getText.size(); i++)
				{
					cout << getText[i];
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

	openFile.close();

}

void DeathScene::update()
{
	switch (choice[0])
	{
	case 'A':
		Game::Instance()->changeSceneState(PLAY_SCENE);
		break;
	case 'B':
		Game::Instance()->changeSceneState(PLAY_SCENE_0);
		break;
	case 'C':

		break;
	default:
		break;
	}


}

void DeathScene::input()
{
	cout << "\n\nA.Reset to previous save.\nB.Restart the entire game.\nC.Quit Game.\n\nEnter choice here: ";
	getline(cin, choice);

	choice[0] = toupper(choice[0]);
}

void DeathScene::save()
{
}
