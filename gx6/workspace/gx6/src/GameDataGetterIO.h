/*
 * GameDataGetterIO.h
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#ifndef GAMEDATAGETTERIO_H_
#define GAMEDATAGETTERIO_H_

class GameData;

class GameDataGetterIO {
private:
	GameDataGetterIO();
	~GameDataGetterIO();

public:
	static GameDataGetterIO &getInstance() {
		static GameDataGetterIO instance;
		return instance;
	}

	bool getNextGameData(GameData *gameData);

private:
	bool _socketInitialized;
	void initializeSocket();

	int _serverSocket;
};

#endif /* GAMEDATAGETTERIO_H_ */
