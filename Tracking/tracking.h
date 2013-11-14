#ifndef TRACKING_H
#define TRACKING_H

#include "tracking_global.h"

extern "C" int TRACKINGSHARED_EXPORT trInitialize();
extern "C" int TRACKINGSHARED_EXPORT trShutdown();
extern "C" unsigned int TRACKINGSHARED_EXPORT trGetNumSensors();
extern "C" unsigned int TRACKINGSHARED_EXPORT trGetNumPlayers(unsigned int sensor);
extern "C" void TRACKINGSHARED_EXPORT trSetNumPlayers(unsigned int sensor, unsigned int players);
extern "C" float TRACKINGSHARED_EXPORT trGetPlayerPositionX(unsigned int sensor, unsigned int playerId);
extern "C" float TRACKINGSHARED_EXPORT trGetPlayerPositionZ(unsigned int sensor, unsigned int playerId);
extern "C" int TRACKINGSHARED_EXPORT trIsPlayerThrowing(unsigned int sensor, unsigned int playerId);
extern "C" void TRACKINGSHARED_EXPORT trUpdate(unsigned int sensor);
extern "C" void TRACKINGSHARED_EXPORT trShowDebugger(unsigned int sensor, int show);
extern "C" int TRACKINGSHARED_EXPORT trIsDebuggerVisible(unsigned int sensor);

#endif // TRACKING_H
