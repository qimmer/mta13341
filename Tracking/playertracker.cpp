#include "playertracker.h"
#include "sensor.h"
#include "debugWindow.h"
#include "ui_debugWindow.h"
#include <QVector2D>
#include <QPainter>
#include <QFile>
#include "utility.h"

PlayerTracker::PlayerTracker(Sensor *sensor)
{
    this->depthThreashold = 0.1f;
    this->armSize = 0.2f;
    this->minSize = 0.2f;
    this->sensor = sensor;
    this->sensor->setNearClip(0);
    this->sensor->setFarClip(1);
    this->debugWindow = new DebugWindow(this);
    this->debugWindow->show();

    setNumPlayers(1);

    depthImage = QImage(sensor->getDepthImage().size(), sensor->getDepthImage().format());
    binaryDepth = QImage(sensor->getDepthImage().size(), sensor->getDepthImage().format());
    playerDebugView = QImage(300, 300, QImage::Format_ARGB32);

    syncUi();
}

PlayerTracker::~PlayerTracker()
{
    this->debugWindow->close();
    delete this->debugWindow;
}

void PlayerTracker::saveSettings(const QString &fileName)
{
    QFile file(fileName);

    file.open(QFile::WriteOnly);
    QDataStream stream(&file);

    for( uint i = TP_DEPTH_THREASHOLD; i <= TP_FAR_CLIP; ++i )
    {
        stream << this->getParameter((TrackingParameter)i);
    }

    file.close();
}

void PlayerTracker::loadSettings(const QString &fileName)
{
    QFile file(fileName);
    if( file.exists() )
    {
        file.open(QFile::ReadOnly);
        QDataStream stream(&file);

        for( uint i = TP_DEPTH_THREASHOLD; i <= TP_FAR_CLIP; ++i )
        {
            float value;
            stream >> value;
            this->setParameter((TrackingParameter)i, value);
        }

        file.close();
    }

    // Update debug UI sliders
    syncUi();
}

uint PlayerTracker::getNumPlayers() const
{
    return players.size();
}

void PlayerTracker::setNumPlayers(int amount)
{
    this->players.clear();
    this->playersThrowing.clear();

    for( int i = 0; i < amount; ++i )
    {
        this->players.push_back(QVector2D(((float)i / amount), 0.5f));

        this->playersThrowing.push_back(false);
    }
}

const QVector2D &PlayerTracker::getPlayerPosition(uint playerId) const
{
    return players[playerId];
}

bool PlayerTracker::isPlayerThrowing(uint playerId) const
{
    return false;
}

void PlayerTracker::update()
{
    //QApplication::processEvents();

    if( this->sensor->update() )
    {
        Utility::depthToImage(sensor->getDepthData(), &depthImage);
        Utility::depthToBinary(sensor->getDepthData(), &binaryDepth);

        blobDetector.update(
                    binaryDepth,
                    sensor->getVelocityMapper()->getBinaryImage(),
                    sensor->getDepthData(),
                    this->depthThreashold,
                    this->minSize,
                    this->armSize);

        // Update player positions, and remove players who left and add new players.
        blobsToPlayers();

        // Make an overview image for debugging purposes
        makePlayerOverview(&this->playerDebugView);
    }
}

void PlayerTracker::showDebugger(bool visible)
{
    debugWindow->setVisible(visible);
}

bool PlayerTracker::isDebuggerVisible() const
{
    return debugWindow->isVisible();
}

void PlayerTracker::setParameter(TrackingParameter tp, float value)
{
    switch( tp )
    {
    case TP_ARM_SIZE:
        this->armSize = value;
        break;

    case TP_MIN_BLOB_SIZE:
        this->minSize = value;
        break;

    case TP_DEPTH_THREASHOLD:
        this->depthThreashold = value;
        break;

    case TP_NEAR_CLIP:
        this->sensor->setNearClip((double)value * USHRT_MAX);
        break;

    case TP_FAR_CLIP:
        this->sensor->setFarClip((double)value * USHRT_MAX);
        break;

    case TP_VEL_MIN:
        this->sensor->getVelocityMapper()->setMinima(value);
        break;

    case TP_VEL_MAX:
        this->sensor->getVelocityMapper()->setMaxima(value);
        break;

    case TP_VEL_FACTOR:
        this->sensor->getVelocityMapper()->setFactor(value);
        break;

    case TP_VEL_THREASHOLD:
        this->sensor->getVelocityMapper()->setThreashold(value);
        break;
    }
}

float PlayerTracker::getParameter(TrackingParameter tp) const
{
    switch( tp )
    {
    case TP_ARM_SIZE:
        return this->armSize;
        break;

    case TP_MIN_BLOB_SIZE:
        return this->minSize;
        break;

    case TP_DEPTH_THREASHOLD:
        return this->depthThreashold;
        break;

    case TP_NEAR_CLIP:
        return (double)this->sensor->getNearClip() / USHRT_MAX;
        break;

    case TP_FAR_CLIP:
        return (double)this->sensor->getFarClip() / USHRT_MAX;
        break;

    case TP_VEL_MIN:
        return this->sensor->getVelocityMapper()->getMinima();
        break;

    case TP_VEL_MAX:
        return this->sensor->getVelocityMapper()->getMaxima();
        break;

    case TP_VEL_FACTOR:
        return this->sensor->getVelocityMapper()->getFactor();
        break;

    case TP_VEL_THREASHOLD:
        return this->sensor->getVelocityMapper()->getThreashold();
        break;
    }

    return 0.0f;
}

Sensor *PlayerTracker::getSensor()
{
    return sensor;
}

BlobDetector *PlayerTracker::getBlobDetector()
{
    return &blobDetector;
}

const QImage &PlayerTracker::getPlayerDebugView() const
{
    return playerDebugView;
}

void PlayerTracker::syncUi()
{
    debugWindow->ui->sliArmSize->setValue(getParameter(TP_ARM_SIZE) * 1000);
    debugWindow->ui->sliMinSize->setValue(getParameter(TP_MIN_BLOB_SIZE) * 1000);
    debugWindow->ui->sliNear->setValue(getParameter(TP_NEAR_CLIP) * 1000);
    debugWindow->ui->sliFar->setValue(getParameter(TP_FAR_CLIP) * 1000);
    debugWindow->ui->sliDepthThreashold->setValue(getParameter(TP_DEPTH_THREASHOLD) * 1000);
    debugWindow->ui->sliMinima->setValue(getParameter(TP_VEL_MIN) * 1000);
    debugWindow->ui->sliMaxima->setValue(getParameter(TP_VEL_MAX) * 1000);
    debugWindow->ui->sliFactor->setValue(getParameter(TP_VEL_FACTOR) * 1000);
    debugWindow->ui->sliThreashold->setValue(getParameter(TP_VEL_THREASHOLD) * 1000);
}

void PlayerTracker::blobsToPlayers()
{
    // Our "update list" to tell which BLOB fits the individual player
    QVector<const Blob*> playerBlobMap;

    if( this->blobDetector.getNumBlobs() != getNumPlayers() )
        return;

    // Find which BLOBs that are nearest to the players
    for( uint i = 0; i < getNumPlayers(); ++i )
    {
        playerBlobMap.push_back(0);

        for( int j = 0; j < blobDetector.getNumBlobs(); ++j )
        {
            const Blob* blob = blobDetector.getBlob(j);

            if( !playerBlobMap.contains(blob) )
            {
                if( playerBlobMap[i] == 0 )
                    playerBlobMap[i] = blob;

                if( (getPlayerPosition(i) - blob->position).length() <
                        (getPlayerPosition(i) - playerBlobMap[i]->position).length() )
                    playerBlobMap[i] = blob;
            }
        }


    }

    // Set the new player positions from the appropriate BLOBs found in the "update list"
    for( int i = 0; i < players.size(); ++i )
    {
        if( playerBlobMap[i] != 0 )
        {
            players[i] = playerBlobMap[i]->position;
            playersThrowing[i] = playerBlobMap[i]->isThrowing;
        }
    }
}

void PlayerTracker::makePlayerOverview(QImage *outputImage)
{
    QPainter painter;
    painter.begin(outputImage);
    painter.fillRect(outputImage->rect(), QColor(0,0,0));

    for( int i = 0; i < players.size(); ++i )
    {
        QColor colors[] = {QColor(Qt::red),
                          QColor(Qt::green),
                          QColor(Qt::blue),
                          QColor(Qt::yellow),
                          QColor(Qt::magenta)};

        QColor& color = colors[i % 5];
        QPointF rectCenter = QPointF(
                    (players[i].x() + 1.0f)/2.0f * outputImage->width(),
                     players[i].y() * outputImage->height());

        painter.fillRect(rectCenter.x() - 5, rectCenter.y() - 5, 10, 10, color);
        painter.setPen(color);

        if( playersThrowing[i] )
            painter.drawEllipse(rectCenter.x() - 10, rectCenter.y() - 10, 20, 20);
    }

    painter.end();
}
