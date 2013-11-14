#include <iostream>
#include <stddef.h>s
#include "tracking.h"

int main(int argc, char *argv[])
{
    for( int i = 0; i < 4; ++i )
    {
        int numSensors = trInitialize();
        //trSetNumPlayers(0, 1);

        if( numSensors > 0 )
        {
            trUpdate(0);
        }

        trShutdown();
    }
    return 0;
}
