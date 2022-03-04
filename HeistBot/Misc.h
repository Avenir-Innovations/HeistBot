#pragma once
#include <iostream>
#include <list>
#include <math.h>

using namespace std;

const float PI = std::atan(1.0) * 4;
const float E = std::exp(1);

float erfInv(float x){
   float tt1, tt2, lnx, sgn;
   sgn = (x < 0) ? -1.0f : 1.0f;

   x = (1 - x)*(1 + x);        // x = 1 - x*x;
   lnx = logf(x);

   tt1 = 2/(PI*0.147) + 0.5f * lnx;
   tt2 = 1/(0.147) * lnx;

   return(sgn*sqrtf(-tt1 + sqrtf(tt1*tt1 - tt2)));
};

bool tryParse(string s)
{
	int _i;
    if (s == "") return false;
    try
    {
        _i = std::stoi(s);
    }
    catch (invalid_argument inva) { return false; }
    return true;
}

bool tryParse(string s, int *i) //do &int
{
	int _i = *i;
    if (s == "") return false;
    try
    {
        _i = std::stoi(s);
    }
    catch (invalid_argument inva) { return false; }
	*i = _i;
    return true;
}

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

int pushToInt (float _f)
{
	string _s = to_string(_f);
	int _h = (int)_f;
	replace(_s, ".", "");
	tryParse(_s, &_h);
	return _h;
};

class Distribution
{
	public:
		float pdf (float _f) { return _f; }
		float cdf (float _f) { return _f; }
		float cdf (float _u, float _l) { return cdf(_u) - cdf(_l); }
		float quant (float _f) { return _f; }
};

class NormalDistribution : Distribution
{
	public:
		float mean = 0;
		float SD = 1;
		float pdf (float _f);
		float cdf (float _f);
		float quant (float _f);
};

class Dice : Distribution
{
	public:
		int sides[6] = {1,2,3,4,5,6};
        void setSides (int _i);
		float pdf (float _f);
		float cdf (float _f);
		float quant (float _f);
};

float RandomNumber ();

