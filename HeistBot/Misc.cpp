#include "Misc.h"

float NormalDistribution::pdf (float _f)
{
    return ( ( 1 / ( SD * sqrt(2 * PI) ) ) * exp( -0.5 * pow( ( _f - mean ) / 2 , 2) ) );
}

float NormalDistribution::cdf (float _f)
{
    return .5 * ( 1 + erf( ( _f - mean ) / ( SD * sqrt( 2 ) ) ) );
}

float NormalDistribution::quant (float _f)
{
    return mean + ( SD * sqrt( 2 ) * erfInv( _f * 2 - 1 ) );
}

float Dice::pdf (float _f)
{
    return 
}

float Dice::cdf (float _f)
{
    return 
}

float Dice::quant (float _f)
{
    return 
}
