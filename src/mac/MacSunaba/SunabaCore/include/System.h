﻿#ifndef INCLUDED_SUNABA_SYSTEM_H
#define INCLUDED_SUNABA_SYSTEM_H

#include <sstream>

namespace Sunaba{
class Graphics;
class Machine;
class NetworkManager;
class Connection;
class Server;
class Sound;
template<class T> class Array;

class System{
public:
	System(void* windowHandle);
	~System();
	void setPictureBoxHandle(void* pictureBoxHandle, int pictureBoxWidth, int pictureBoxHeight);
	bool restartGraphics();
	bool bootProgram(const unsigned char* objectCode, int objectCodeSize); //コンパイル済み
	bool bootProgram(const wchar_t* filename); //内部コンパイル
	void update(Array<unsigned char>* messageOut, int pointerX, int pointerY, const char* keys);
	int screenWidth() const;
	int screenHeight() const;
	int framePerSecond() const;
	int calculationTimePercent() const;
	void requestAutoSync(bool);
	bool requestAutoSyncFinished() const;
	bool autoSync() const;
	void requestMemoryWrite(int address, int value);
	bool requestMemoryFinished() const;

	int memoryValue(int address) const;
private:

	Graphics* mGraphics;
	Machine* mMachine;
	void* mWindowHandle;
	void* mPictureBoxHandle;
	int mPictureBoxWidth;
	int mPictureBoxHeight;
	std::wostringstream mMessageStream;
	bool mError;
	bool mTerminationMessageDrawn;
	int mFramePerSecond;
	int mCalculationTimePercent;
	//自動お手紙
	int mMemoryRequestAddress;
	int mMemoryRequestValue;
	int mMemoryRequestState;

	Sound* mSound;
};

};

#include "inc/System.inc.h"


#endif
