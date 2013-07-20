/*
 * GameData.h
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#ifndef GAMEDATA_H_
#define GAMEDATA_H_


struct GameData {

	struct CellType {
		enum CellType_ { EMPTY, WHITE, BLACK };
	};

	enum {
		ROWS = 19,
		COLUMNS = 19
	};

	struct ToGo {
		enum { WHITE, BLACK };
	};

	CellType::CellType_ cellType[19][19];
	ToGo toGo;
};


#endif /* GAMEDATA_H_ */
