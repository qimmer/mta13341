#ifndef BLOBDETECTOR_H
#define BLOBDETECTOR_H

#include <QImage>
#include <QVector2D>
#include "velocitymapper.h"
#include "tracking_global.h"

struct Blob
{
    /**
     * @brief isolateColor Isolates the image for a specific color and stores
     *        it in the isolatedImage field
     * @param blobImage Image cropped to the blob
     * @param blobColor The BLOB color to search for
     */
    void isolateColor(const QImage& blobImage, const QColor& blobColor);

    /**
     * @brief isolateVelocity Isolates the velocity image for the 2 hands (upper left and upper right)
     * @param velocity The global velocity image
     */
    void isolateVelocity(const QImage& velocity);

    /**
     * @brief calculatePosition Calculates the position of the player in a BLOB
     *        containing the player. It does so by finfing the center of
     *        the players torso, filtering out the arms and finding the average depth.
     * @param armSize The arm thickness in percentage of the blob image.
     */
    void calculatePosition(float armSize);

    /**
     * @brief boundingBox The BLOBs bounding box
     */
    QRectF boundingBox;

    /**
     * @brief isolatedImage The binary image containing only this BLOB
     */
    QImage isolatedImage, isolatedColor;

    /**
     * @brief position The current calculated position of this BLOB. Can be set using calculatePosition()
     */
    QVector2D position;

    /**
     * @brief size The normalized BLOB size (total pixels divided by pixels belonging to the BLOB)
     */
    float size;

    /**
     * @brief kinectResolutionWidth The resolution width of the kinect image (ex. 320).
     *                              Used for center calculation
     */
    int kinectResolutionWidth;

    /**
     * @brief velocityImage The left and right upper hand velocity image.
     */
    QImage velocityImage;

    /**
     * @brief isThrowing Is true when one of the hand velocity images are > 50% white
     */
    bool isThrowing;
};

class TRACKINGSHARED_EXPORT BlobDetector
{
public:
    BlobDetector();

    /**
     * @brief update Does blob detection
     * @param binaryImage The binary image to perform the detection on
     * @param depthValues The depth image
     * @param depthThreashold The threashold for separating BLOBs by depth
     * @param minSize The minimum size of a BLOB
     */
    void update(const QImage& binaryImage, const QImage& velocityImage, const float *depthValues, float depthThreashold, float minSize, float armSize);

    /**
     * @brief getNumBlobs
     * @return The amount of BLOBs currently detected
     */
    int getNumBlobs() const;

    /**
     * @brief getBlob Retrieves a specific BLOB
     * @param index
     * @return
     */
    const Blob *getBlob(int index) const;

    /**
     * @brief grassFire Performs a grassfire BLOB detection on image and
     *        outputs the BLOB to blobImg.
     * @param image The binary image to find the BLOB in
     * @param blobImg The output image containing coloured BLOBs
     * @param depthValues Depth image for depth pixel comparisons. Can be NULL
     * @param x BLOB start x
     * @param y BLOB start y
     * @param color The color of this BLOB
     * @param boundingBox Where to store the bounding box
     * @param avrDepth
     * @return The amount of pixels the blob contains
     */
    int grassFire(const QImage &image, QImage &blobImg, const float *depthValues, int x, int y, QColor color, QRect& boundingBox, float &avrDepth);

    /**
     * @brief testPixel Tests if the pixel is part of a BLOB
     * @param image The binary image
     * @param blobImg The output image containing the BLOBs
     * @param depthValues The depth image to test for. Can be NULL for no check
     * @param p The pixel coordinte to check
     * @return True if the pixel is part of the BLOB
     */
    bool testPixel(const QImage &image, QImage &blobImg, const float *depthValues, const QPoint& p);

private:
    QVector<Blob> blobs;
    float depthThreashold;
};

#endif // BLOBDETECTOR_H
