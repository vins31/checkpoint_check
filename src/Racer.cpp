#include "Racer.h"

Racer::Racer(string name, string aircraft, int laps, CheckPoints*  cp)
{
     _lapNumber      = 1;
     _topSpeed       = 0;
     _bestLap        =-1;
     _time           =-1;
     _nextCP         = 0;
     _startRace      = 0;
     _startLap       = 0;
     _previousSide   = 0;
     _previousInPoly = true;
     _startRace      = clock();
     _startLap       = clock();
     this->_name     = name;
     this->_aircraft = aircraft;
     this->_laps     = laps;
     this->cp        = cp;
}

int Racer::check(double x, double y, double z, double speed)
{
    int ret = 0;
    Vec pt(x, y, z);
    if (speed>_topSpeed)
    {
        _topSpeed = speed;
    }
    if (cp->in_area(pt, _nextCP))
    {
        bool inPoly = cp->in_poly_area(pt, _nextCP);
        int  side   = cp->side(pt, _nextCP);
        if (side+_previousSide == 0)
        {
            if (inPoly && _previousInPoly)
            {
                _nextCP = (_nextCP+1)%cp->nbPolys();
                side *= -1; // we changed of check_point so we switched of side
                inPoly = false; // changing of checkpoint
                ret = 1;
                if (_nextCP == 0)
                {
                    ret = 2;
                    clock_t endLap = clock();
                    double lapTime = ((double)endLap - _startLap) / CLOCKS_PER_SEC;
                    if (_bestLap == -1)
                    {
                        _bestLap = lapTime;
                    }
                    else if (lapTime < _bestLap)
                    {
                        _bestLap = lapTime;
                    }
                    if (_lapNumber == _laps)
                    {
                        ret = 3;
                        clock_t endRace = clock();
                        _time = ((double)endRace - _startRace) / CLOCKS_PER_SEC;
                    }
                    _lapNumber ++;
                }
                else if (_nextCP ==1)
                {
                    _startLap = clock();
                    if (_lapNumber == 1)
                    {
                        _startRace = clock();
                    }
                }
            }
            else
            {
                ret = -1;
                inPoly = false; // the player has to come back
                side  *= -1;
            }

        }
        _previousInPoly = inPoly;
        _previousSide   = side;
    }
    else
    {
        _previousInPoly = false;
        _previousSide   = 0;
    }
    return ret;
}

std::ostream& operator<< (std::ostream &os, Racer &racer)
{
    os << racer.name() << " flying a " << racer.aircraft() << " finished in: " << racer.time()
       << "s ;  top speed: " << racer.topSpeed() << " ; best lap: " << racer.bestLap() << "s";
    return os;
}
