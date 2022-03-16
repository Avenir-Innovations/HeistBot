#pragma once
#include <iostream>
#include <list>
#include <math.h>
#include <stdlib.h>
#include <random>
#include "ListsExtensions.h"

using namespace std;

namespace Extras
{
    const double PI = std::atan(1.0) * 4;
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
        float _i;
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
            float min = 0;
            float max = 1;
            float pdf (float _f) { return _f; }
            float cdf (float _f) { return _f; }
            float cdf (float _u, float _l) { return cdf(_u) - cdf(_l); }
            float quant (float _f) { return _f; }
            float RandomNumber ();
            float RandomNumber (float _l, float _u);
    };

    class NormalDistribution : Distribution
    {
        public:
            float min = -3;
            float max = 3;
            float mean = 0;
            float SD = 1;
            float pdf (float _f);
            float cdf (float _f);
            float quant (float _f);
    };

    class Dice : Distribution
    {
        public:
            float min = 1;
            float max = 6;
            int sides[6] = {1,2,3,4,5,6};
            float pdf (float _f);
            float cdf (float _f);
            float quant (float _f);
    };

    int randomInt (int min, int max)
    {
        uniform_int_distribution _d = uniform_int_distribution(min, max);
        std::random_device rd;
        std::mt19937 gen(rd());
        float _f = _d(gen);
        return _f;
    }

    float randomFloat ()
    {
        uniform_real_distribution<float> _d = uniform_real_distribution<float>(0, 1);
        std::random_device rd;
        std::mt19937 gen(rd());
        float _f = _d(gen);
        return _f;
    }

    float randomFloat (float min, float max)
    {
        uniform_real_distribution<float> _d = uniform_real_distribution<float>(min, max);
        std::random_device rd;
        std::mt19937 gen(rd());
        float _f = _d(gen);
        return _f;
    }

    double randomDouble ()
    {
        uniform_real_distribution<double> _d = uniform_real_distribution<double>(0, 1);
        std::random_device rd;
        std::mt19937 gen(rd());
        float _f = _d(gen);
        return _f;
    }

    double randomDouble (double min, double max)
    {
        uniform_real_distribution<double> _d = uniform_real_distribution<double>(min, max);
        std::random_device rd;
        std::mt19937 gen(rd());
        float _f = _d(gen);
        return _f;
    }
}
