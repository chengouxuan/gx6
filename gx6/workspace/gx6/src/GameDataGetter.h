/*
 * GameDataGetter.h
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#ifndef GAMEDATAGETTER_H_
#define GAMEDATAGETTER_H_

class GameData;

class GameDataGetter {

public:
	GameDataGetter();
	~GameDataGetter();

	bool get(GameData *gameData);
};

#endif /* GAMEDATAGETTER_H_ */
