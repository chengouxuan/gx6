/*
 * ProcessParams.h
 *
 *  Created on: 2013-5-11
 *      Author: Administrator
 */

#ifndef PROCESSPARAMS_H_
#define PROCESSPARAMS_H_

class ProcessResources {
private:
	~ProcessResources();
	ProcessResources();

public:
	static ProcessResources &getInstance();

	void addSocketPort(int socketPort);
	int getAvailableSocketPort();

private:
	int _socketPort;
};

#endif /* PROCESSPARAMS_H_ */
