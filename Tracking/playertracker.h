#ifndef PLAYERTRACKER_H
#define PLAYERTRACKER_H

#include <QVector3D>
#include <QApplication>
#include <QMap>
#include <QList>
#include "tracking_global.h"
#include "BlobDetector.h"
#include "imagedebugger.h"

class DebugWindow;
class Sensor;

enum TrackingParameter
{
    TP_UNKNOWN = 0,
    TP_DEPTH_THREASHOLD = 1,
    TP_ARM_SIZE = 2,
    TP_MIN_BLOB_SIZE = 3,
    TP_VEL_MIN = 4,
    TP_VEL_MAX = 5,
    TP_VEL_FACTOR = 6,
    TP_VEL_THREASHOLD = 7,
    TP_NEAR_CLIP = 8,
    TP_FAR_CLIP = 9
};

class PlayerTracker
{
public:
    PlayerTracker(Sensor *sensor);
    ~PlayerTracker();

    /**
     * @brief saveSettings Saves all parameters to a file for later use
     * @param fileName
     */
    void saveSettings(const QString& fileName);

    /**
     * @brief loadSettings Loads all parameters from a file previously saved using saveSettings()
     * @param fileName
     */
    void loadSettings(const QString& fileName);

    /**
     * @brief getNumPlayers
     * @return The number of players active on screen
     */
    uint getNumPlayers() const;

    /**
     * @brief setNumPlayers Sets the number of players and inits their positions
     * @param amount
     */
    void setNumPlayers(int amount);

    /**
     * @brief getPlayerPosition
     * @param player The player id from getPlayerId()
     * @return The nomrlaized vector for the player position
     */
    const QVector2D& getPlayerPosition(uint playerId) const;

    /**
     * @brief isPlayerThrowing
     * @param player The player id from 0 to getNumPlayers()
     * @return True if the player has thrown a ball since last update()
     */
    bool isPlayerThrowing(uint playerId) const;

    /**
     * @brief update Update the tracker system
     */
    void update();

    /**
     * @brief showDebugger Specifies if the tracking debugger window should be visible
     * @param visible
     */
    void showDebugger(bool visible);

    bool isDebuggerVisible() const;

    /**
     * @brief setParameter Sets a TrackingParameter for the tracking system
     * @param tp The TrackingParameter to set
     * @param value The parameter value to set it to
     */
    void setParameter(TrackingParameter tp, float value);

    /**
     * @brief getParameter Retrieves a TrackingParameter for the tracking system
     * @param tp The TrackingParameter to retrieve
     * @return The parameter's current value
     */
    float getParameter(TrackingParameter tp) const;

    /**
     * @brief getSensor
     * @return The kinect sensor used for this tracker
     */
    Sensor *getSensor();

    /**
     * @brief getBlobDetector
     * @return The blob-detector object used to do BLOB detection
     */
    BlobDetector *getBlobDetector();

    /**
     * @brief getPlayerDebugView
     * @return An image showing a top-view of player positions
     */
    const QImage& getPlayerDebugView() const;

private:
    /**
     * @brief syncUi Sets all UI sliders to the internal object values
     */
    void syncUi();

    /**
     * @brief blobsToPlayers Updates the player positions to the nearest BLOBs.
     * If a blob is not nearby, the player is considered as out. If there is more BLOBs
     * Than players, a new player is added for that BLOB.
     */
    void blobsToPlayers();

    /**
     * @brief makePlayerOverview Makes a map showing the player positions by coloured boxes
     * @param outputImage The image to store the overview image in
     */
    void makePlayerOverview(QImage *outputImage);

private:
    Sensor *sensor;
    BlobDetector blobDetector;
    QVector<QVector2D> players;
    QVector<bool> playersThrowing;
    QImage playerDebugView, binaryDepth, depthImage;
    DebugWindow *debugWindow;

    float minSize, armSize, depthThreashold;
};

#endif // PLAYERTRACKER_H
