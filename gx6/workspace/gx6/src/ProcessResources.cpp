/*
 * ProcessParams.cpp
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#include "ProcessResources.h"

#include <cassert>

ProcessResources::~ProcessResources() {
	// TODO Auto-generated destructor stub
}

ProcessResources::ProcessResources() {
	_socketPort = -1;
}


ProcessResources &ProcessResources::getInstance() {
	static ProcessResources instance;
	return instance;
}


void ProcessResources::addSocketPort(int socketPort) {
	assert(_socketPort == -1 && "never add more than 1 socket ports.");
	_socketPort = socketPort;
}


int ProcessResources::getAvailableSocketPort() {
	assert(_socketPort != -1 && "no socket ports");
	return _socketPort;
}
