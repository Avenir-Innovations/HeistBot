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
    float __f = sqrt( 2 ) * erfInv( _f * 2 - 1 );
    if (__f > 3) __f = 3;
    else if (__f < -3) __f = -3;
    return mean + ( SD * __f);
}

float Dice::pdf (float _f)
{
    bool _b = false;
    for(int i = 0; i < 6; i++){
        if(sides[i] == (int)_f){
            _b = true;
            break;
        }
    }
    if (_b) return 1 / 6;
    else return 0; 
}

float Dice::cdf (float _f)
{
    return (0 < (int)_f) ? (((int)_f < 7) ? ((int)_f) / 6 : 1) : 0;
}

float Dice::quant (float _f)
{
    if (_f > 1) return 6;
    else if (_f < 1 / 6) return 0;
    else return (int)(_f * 6);
}
