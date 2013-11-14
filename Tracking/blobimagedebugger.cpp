#include "blobimagedebugger.h"
#include "ui_blobimagedebugger.h"
#include "BlobDetector.h"

BlobImageDebugger::BlobImageDebugger(BlobDetector *blobDetector, int imageType, QWidget *parent) :
    ImageDebugger(parent),
    blob_ui(new Ui::BlobImageDebugger)
{
    qDeleteAll(children());
    blob_ui->setupUi(this);
    this->blobDetector = blobDetector;
    this->imageType = imageType;

    if( this->imageType == 0 )
        this->setWindowTitle("Blob Binary Images");

    if( this->imageType == 2 )
        this->setWindowTitle("Blob Coloured Images");

    if( this->imageType == 1 )
        this->setWindowTitle("Blob Velocities");
}

BlobImageDebugger::~BlobImageDebugger()
{
    delete blob_ui;
}

void BlobImageDebugger::update()
{
    if( blobDetector->getNumBlobs() > 0 )
    {
        if( this->imageType == 0 )
            this->blob_ui->lblBlob1->setPixmap(QPixmap::fromImage(blobDetector->getBlob(0)->isolatedImage));

        if( this->imageType == 1 )
            this->blob_ui->lblBlob1->setPixmap(QPixmap::fromImage(blobDetector->getBlob(0)->velocityImage));

        if( this->imageType == 2 )
            this->blob_ui->lblBlob1->setPixmap(QPixmap::fromImage(blobDetector->getBlob(0)->isolatedColor));
    }
    else
        this->blob_ui->lblBlob1->setPixmap(QPixmap());

    if( blobDetector->getNumBlobs() > 1 )
    {
        if( this->imageType == 0 )
            this->blob_ui->lblBlob2->setPixmap(QPixmap::fromImage(blobDetector->getBlob(1)->isolatedImage));

        if( this->imageType == 1 )
            this->blob_ui->lblBlob2->setPixmap(QPixmap::fromImage(blobDetector->getBlob(1)->velocityImage));

        if( this->imageType == 2 )
            this->blob_ui->lblBlob2->setPixmap(QPixmap::fromImage(blobDetector->getBlob(1)->isolatedColor));
    }
    else
        this->blob_ui->lblBlob2->setPixmap(QPixmap());

    if( blobDetector->getNumBlobs() > 2 )
    {
        if( this->imageType == 0 )
            this->blob_ui->lblBlob3->setPixmap(QPixmap::fromImage(blobDetector->getBlob(2)->isolatedImage));

        if( this->imageType == 1 )
            this->blob_ui->lblBlob3->setPixmap(QPixmap::fromImage(blobDetector->getBlob(2)->velocityImage));

        if( this->imageType == 2 )
            this->blob_ui->lblBlob3->setPixmap(QPixmap::fromImage(blobDetector->getBlob(2)->isolatedColor));
    }
    else
        this->blob_ui->lblBlob3->setPixmap(QPixmap());
}
