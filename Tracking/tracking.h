#ifndef TRACKING_H
#define TRACKING_H

#include "tracking_global.h"

TRACKINGSHARED_EXPORT int Initialize();
TRACKINGSHARED_EXPORT int Shutdown();
TRACKINGSHARED_EXPORT int CountSensors();
TRACKINGSHARED_EXPORT int CountPlayers(int sensor);
TRACKINGSHARED_EXPORT float GetPlayerPositionX(int sensor, int player);
TRACKINGSHARED_EXPORT float GetPlayerPositionY(int sensor, int player);
TRACKINGSHARED_EXPORT float GetPlayerPositionZ(int sensor, int player);
TRACKINGSHARED_EXPORT float GetPlayerThrowSpeed(int sensor, int player);

#endif // TRACKING_H
