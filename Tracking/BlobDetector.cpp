#include "BlobDetector.h"

BlobDetector::BlobDetector()
{
}

void BlobDetector::update(const QImage &binaryImage)
{
    // Empty the blob container
    this->blobs.clear();

    /* Add found blobs to the container here.
     * Example: Adding a blob to the container
     * GOD ARBEJDSLYST! :-D

    Blob tempBlob;
    tempBlob.boundingBox = QSize(100, 150);
    tempBlob.center = QPoint(154, 120);
    tempBlob.circularity = 0.56f; // 56 %
    tempBlob.isolatedImage = imageWithOnlyTheBlobInside;

    this->blobs.push_back(tempBlob);
    */

    //Makes an empty blobImg, same size and format as the binaryImage
    QImage blobImg(binaryImage.size(), binaryImage.format());
    blobImg.fill(Qt::black);


    QColor colors[] = {QColor(Qt::blue),
                       QColor(Qt::green),
                       QColor(Qt::magenta),
                       QColor(Qt::red),
                       QColor(Qt::yellow)};

    int blobId = 0;

    for(int y = 0; y < binaryImage.size().height(); y++){
        for(int x = 0; x < binaryImage.size().width(); x++){

            //Grassfire algorithm to find BLOB.
            if ((qGray(binaryImage.pixel(x, y)) == 255) && (qGray(blobImg.pixel(x, y)) == 0)){
                QImage tmpImg = blobImg;
                Blob tmpBlob;

                int size = 0;
                grassFire(binaryImage, blobImg, x, y, colors[blobId % 5], size);

                if (size < 100 || size > 300){ //Size of BLOB has to be between:
                    blobImg = tmpImg;
                }
                else{
                    blobId++;
                    tmpBlob.pixelCount = size;
                    this -> blobs.push_back(tmpBlob);
                }
            }


            //Area


            //Circularity - remove BLOB's which do not have a circle on top


            //Bounding box for ROI


        }
    }
    return;
}



int BlobDetector::getNumBlobs() const
{
    return this->blobs.size();
}

const Blob &BlobDetector::getBlob(int index) const
{
    Q_ASSERT(index < this->blobs.size());

    return this->blobs.at(index);
}

Blob grassFire(QImage &image, QImage &blobImg, int x, int y, QColor color, int &size){
    size++;

    //Burn pixel in both images
    image.setPixel(x, y, color.rgb());
    blobImg.setPixel(x, y, color.rgb());

    //Kernal 4-connectivity
    //1
    if ((qGray(image.pixel(x+1, y)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x+1, y, color, size);
    }
    //2
    if ((qGray(image.pixel(x, y+1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x, y+1, color, size);
    }
    //3
    if ((qGray(image.pixel(x-1, y)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x-1, y, color, size);
    }
    //4
    if ((qGray(image.pixel(x, y-1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x, y-1, color, size);
    }

    return;

    /*
    //Kernal 8-connectivity
    //1
    if ((qGray(image.pixel(x+1, y)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x+1, y, color, size);
    }
    //2
    if((qGray(image.pixel(x+1, y+1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x+1, y+1, color, size);
    }
    //3
    if ((qGray(image.pixel(x, y+1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x, y+1, color, size);
    }
    //4
    if ((qGray(image.pixel(x-1, y+1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x-1, y+1, color, size);
    }
    //5
    if ((qGray(image.pixel(x-1, y)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x-1, y, color, size);
    }
    //6
    if ((qGray(image.pixel(x-1, y-1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x-1, y-1, color, size);
    }
    //7
    if ((qGray(image.pixel(x, y-1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x, y-1, color, size);
    }

    //8
    if ((qGray(image.pixel(x+1, y-1)) == 255) && ((x >= 0 && x <= image.size().width()) && (y >= 0 && y <= image.size().height()))){
        grassFire(image, blobImg, x+1, y-1, color, size);
    }

    return;
    */
}

