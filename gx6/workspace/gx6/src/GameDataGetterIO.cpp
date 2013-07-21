/*
 * GameDataGetterIO.cpp
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#include "GameDataGetterIO.h"
#include "GameData.h"
#include "ProcessResources.h"

#include <winsock2.h>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include "SearchDataDef.h"

using namespace GX6SearchData;

#define oops(st)										\
	do {												\
		std::cerr << (st) << "\n";						\
		exit(1);										\
	} while (0)


GameDataGetterIO::GameDataGetterIO()
	: _socketInitialized(false)
	, _serverSocket(0) {
}

GameDataGetterIO::~GameDataGetterIO() {
	// TODO Auto-generated destructor stub
}


bool GameDataGetterIO::getNextGameData(GameData *gameData) {

	assert(gameData && "empty GameData pointer");

	if (! _socketInitialized) {
		this->initializeSocket();
	}

	if (! _socketInitialized) {
		oops("socket initialization failed.");
	}

	do {
		SOCKADDR_IN addrClient;
		int len = sizeof(addrClient);
		int sockConn;
		if ((sockConn = accept(_serverSocket, (SOCKADDR *)(&addrClient), &len)) < 0) {
			break;
		}

		RequestData req;
		size_t totalRecvLen = 0;
		do {
			int newRecvLen = recv(sockConn, (char *)(&req) + totalRecvLen, sizeof(RequestData) - totalRecvLen, 0);
			if (newRecvLen < 0) {
				break;
			}
			totalRecvLen += newRecvLen;
		} while (totalRecvLen < sizeof(RequestData));

		if (totalRecvLen < sizeof(RequestData)) {
			break;
		}

		if (req._type != RequestData::TYPE_SEARCH) {
			std::cerr << "unhandled request: type = " << (int)req._type << "\n";
			break;
		}

		assert(req._type == RequestData::TYPE_SEARCH && "bad request type.");

		for (int row=0; row<GameData::ROWS; ++row) {
			for (int column=0; column<GameData::COLUMNS; ++column) {
				if (req._data._searchData._board[row][column] == CELL_TYPE_WHITE) {
					gameData->cellType[row][column] = GameData::CellType::WHITE;
				} else if (req._data._searchData._board[row][column] == CELL_TYPE_BLACK) {
					gameData->cellType[row][column] = GameData::CellType::BLACK;
				} else {
					assert(req._data._searchData._board[row][column] == CELL_TYPE_EMPTY && "bad request data.");
					gameData->cellType[row][column] = GameData::CellType::EMPTY;
				}
			}
		}

		return true;

	} while (0);

	return false;
}

void GameDataGetterIO::initializeSocket() {

    WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested = MAKEWORD(1, 1);
    if (WSAStartup(wVersionRequested, &wsaData) != 0) {
        oops("socket startup failed.");
    }

    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
    	oops("socket version error.");
    }

    SOCKET sockSrv;
    if ((sockSrv = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    	oops("socket creation error.");
    }

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons((u_short)ProcessResources::getInstance().getAvailableSocketPort());

    if (bind(sockSrv, (SOCKADDR *)(&addrSrv), sizeof(SOCKADDR)) < 0) {
    	oops("socket binding error.");
    }

    if (listen(sockSrv, 10) < 0) {
    	oops("socket listening error.");
    }

    _socketInitialized = true;
}
