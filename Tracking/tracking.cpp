#include "tracking.h"
#include "playertracker.h"
#include "sensor.h"
#include <QApplication>
#include "NuiApi.h"

QApplication *app = 0;
QList<PlayerTracker*> trackers;
QList<Sensor*> sensors;

int trInitialize()
{
    int argc = 0;
    char** argv = 0;
    app = new QApplication(argc, argv);

    int sensorCount;
    NuiGetSensorCount(&sensorCount);

    for( int i = 0; i < sensorCount; ++i )
    {
        Sensor *sensor = new Sensor;
        if( !sensor->initialize(i, Medium) )
        {
            return -1;
        }

        PlayerTracker *tracker = new PlayerTracker(sensor);
        tracker->loadSettings("tracker" + QString::number(i) + ".dat");

        sensors.push_back(sensor);
        trackers.push_back(tracker);
    }

    return sensorCount;
}


int trShutdown()
{
    int i = 0;
    Q_FOREACH(PlayerTracker *tracker, trackers)
    {
        tracker->saveSettings("tracker" + QString::number(i) + ".dat");
        ++i;
    }

    qDeleteAll(trackers);
    qDeleteAll(sensors);
    trackers.clear();
    sensors.clear();

    delete app;

    return 0;
}


unsigned int trGetNumSensors()
{
    return sensors.size();
}


unsigned int trGetNumPlayers(int sensor)
{
    return trackers.at(sensor)->getNumPlayers();
}

float trGetPlayerPositionX(unsigned int sensor, unsigned int playerId)
{
    return trackers.at(sensor)->getPlayerPosition(playerId).x();
}


float trGetPlayerPositionZ(unsigned int sensor, unsigned int playerId)
{
    return trackers.at(sensor)->getPlayerPosition(playerId).y();
}

int trIsPlayerThrowing(unsigned int sensor, unsigned int playerId)
{
    return trackers.at(sensor)->isPlayerThrowing(playerId);
}


void trUpdate(unsigned int sensor)
{
    trackers.at(sensor)->update();
}


void trShowDebugger(unsigned int sensor, int show)
{
    trackers.at(sensor)->showDebugger(show != 0);
}


int trIsDebuggerVisible(unsigned int sensor)
{
    return trackers.at(sensor)->isDebuggerVisible() ? 1 : 0;
}


void trSetNumPlayers(unsigned int sensor, unsigned int players)
{
    trackers.at(sensor)->setNumPlayers(players);
}
