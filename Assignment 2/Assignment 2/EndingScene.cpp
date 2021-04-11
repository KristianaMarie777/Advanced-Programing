#include "EndingScene.h"
#include <string>
#include <iostream>
#include "Game.h"
#include <Windows.h>

EndingScene::EndingScene(int endings = 0) { endingVer = endings; }

void EndingScene::output()
{
	openFile.open("gameText.txt");

	string getText;

	while (getText != "ENDING") { getline(openFile, getText); }
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

void EndingScene::update()
{
	switch (choice[0])
	{
	case 'A':
		Game::Instance()->getPlayer()->Loadsave();
		Game::Instance()->changeSceneState(PLAY_SCENE);
		break;
	case 'B':
		Game::Instance()->getPlayer()->NewGame();
		Game::Instance()->getPlayer()->Loadsave();
		Game::Instance()->changeSceneState(PLAY_SCENE);
		break;
	case 'C':
		Game::Instance()->changeSceneState(START_SCENE);
		break;
	case 'D':
		exit(1);
		break;
	default:
		break;
	}
}

void EndingScene::input()
{
	cout << "\n\nA.Reset to previous save.\nB.Restart the entire game.\nC. Go to start\nD.Quit Game.\n\nEnter choice here: ";
	cin >> ws;
	getline(cin, choice);

	choice[0] = toupper(choice[0]);
}
