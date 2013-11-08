#ifndef PLAYER_H
#define PLAYER_H

class BlobDetector;

class Player
{
public:
    Player(float initX, float initY);

    void update(BlobDetector *blobDetector);

private:
    float px, py, pz;
};

#endif // PLAYER_H
