#include "StartScene.h"
#include "Game.h"

using namespace std;

StartScene::StartScene()
{
}

void StartScene::output()
{
	//outputs choices

	cout << "Welcome To My Game\n\n\n";
	cout << "A. Start game\nB. Change User/Add User\nC. Quit game\n\n";

	if (notAChar) { cout << "Not a letter. Try again.\n\n"; }
	if (notChoices) { cout << "Not one of the choices. Try again.\n\n"; }
}

void StartScene::update()
{
	// checks if input was a letter and outputs response
	if (!isalpha(choice[0])) { notAChar = true; }
	else
	{
		if (notAChar) { notAChar = false; }
		if (notChoices) { notChoices = false; }

		//checks the choice
		if (toupper(choice[0]) == 'A')
		{
			//if there a no current user
			if (Game::Instance()->getPlayer() == nullptr) { Game::Instance()->setPlayer(); }
		
			//if there are no saves loaded
			if(Game::Instance()->getPlayer()->getSeenStoryScene()) { Game::Instance()->changeSceneState(PLAY_SCENE); }
			else{ Game::Instance()->changeSceneState(STORY_SCENE); }
			
		}
		else if (toupper(choice[0]) == 'B') { Game::Instance()->setPlayer(); }
		else if (toupper(choice[0]) == 'C') { Game::Instance()->quit(); }
		else { notChoices = true; }

	}
}

void StartScene::input()
{
	cout << "Enter choice here: ";
	getline(cin, choice);
}
