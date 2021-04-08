#include "StartScene.h"
#include "Game.h"

using namespace std;

StartScene::StartScene()
{
	user();


}

void StartScene::output()
{

}

void StartScene::update()
{

}

void StartScene::input()
{
	Game::Instance()->setPlayer();
}

void StartScene::save()
{
}

void StartScene::user()
{

}
