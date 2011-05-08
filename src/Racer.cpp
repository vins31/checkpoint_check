#include "Racer.h"

Racer::Racer()
{
     _lapNumber      = 1;
     _topSpeed       = 0;
     _bestLap        = 0;
     _nextCP         = 0;
     _startRace      = 0;
     _startLap       = 0;
     _previousSide   = 0;
     _previousInPoly = true;
}

int Racer::check(double x, double y, double z, double speed)
{
    int ret = 0;
    Vec pt(x, y, z);
    if (speed>_topSpeed)
    {
        _topSpeed = speed;
    }
    if (cp->in_area(pt, _nextCP) ==0)
    {
        bool inPoly = cp->in_poly_area(pt, _nextCP);
        int  side   = cp->side(pt, _nextCP);
        if (side+_previousSide == 0)
        {
            if (inPoly && _previousInPoly)
            {
                _nextCP = (_nextCP+1)%cp->nbPolys();
                ret = 1;
                if (_nextCP == 0)
                {
                    ret = 2;
                    if (_lapNumber == _laps)
                    {
                        ret = 3;
                    }
                    _lapNumber ++;
                }
            }
            else
            {
                ret = -1;
            }

        }
        _previousInPoly = inPoly;
        _previousSide   = side;
    }
    return ret;
}
