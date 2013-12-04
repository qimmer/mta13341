#include <iostream>
#include <stddef.h>s
#include "tracking.h"

int main(int argc, char *argv[])
{

    int numSensors = trInitialize();
    trSetNumPlayers(0, 1);

    while(true)
    {
    if( numSensors > 0 )
    {
        trUpdate(0);
    }
    }

    trShutdown();

    return 0;
}
