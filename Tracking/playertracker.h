#ifndef PLAYERTRACKER_H
#define PLAYERTRACKER_H

#include <QVector3D>
#include "tracking_global.h"

/**
 * @brief trackPlayer Does the BLOB detection on the input depth
 *        image to track up to 2 players.
 * @param depthImage
 */
TRACKINGSHARED_EXPORT void track(const QImage& depthImage);

/**
 * @brief getNumPlayers
 * @return The number of active players
 */
TRACKINGSHARED_EXPORT int getNumPlayers();

/**
 * @brief getPlayerPosition
 * @param player
 * @return A vector containing the specific player's tracked
 *         position in world space
 */
TRACKINGSHARED_EXPORT const QVector3D& getPlayerPosition(int player);

/**
 * @brief getPlayerScreenPosition
 * @param player
 * @return The current screen position of a player in screen pixels
 */
TRACKINGSHARED_EXPORT const QVector2D& getPlayerScreenPosition(int player);

#endif // PLAYERTRACKER_H
