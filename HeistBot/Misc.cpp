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
    return (min - 1 < (int)_f) ? (((int)_f < max + 1) ? ((contains(sides, (int)_f)) ? getIndex(sides, (int)_f) / 6 : 0 ) : 1) : 0;
}

float Dice::quant (float _f)
{
    if (_f > max / 6) return max;
    else if (_f < min / 6) return 0;
    else return sides[(int)(_f * 6)];
}

float Distribution::RandomNumber ()
{
    float _f = randomFloat();
    return quant(_f);
}

float Distribution::RandomNumber (float _l, float _u)
{
    float _f = randomFloat(_l, _u);
    float _q = quant(_f);
    if (min < _q < max) return _q;
    else return (min >= _q) ? min : max;
}