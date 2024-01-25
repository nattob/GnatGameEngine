#include <math.h>

float dBToVolume( float db )
{
    return powf( 10.0f, 0.05f * db );
}

float volumeToDb( float volume )
{
    return 20.0f * log10f( volume );
}