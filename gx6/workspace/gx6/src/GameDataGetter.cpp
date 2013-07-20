/*
 * GameDataGetter.cpp
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#include "GameDataGetter.h"
#include "GameDataGetterIO.h"
#include <cassert>
#include <cstddef>

GameDataGetter::GameDataGetter() {
	// TODO Auto-generated constructor stub

}


GameDataGetter::~GameDataGetter() {
	// TODO Auto-generated destructor stub
}


bool GameDataGetter::get(GameData *gameData) {
	assert(gameData != NULL);
	bool success = GameDataGetterIO::getInstance().getNextGameData(gameData);
	return success;
}
