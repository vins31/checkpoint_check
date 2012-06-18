#include "checkpoint_check/Racer.h"

#include <iostream> // debug
using namespace std;

Racer::Racer(string name, string aircraft, int laps, CheckPoints*  cp)
{
    cout << "Racer start" << endl;
     _lapNumber      = 1;
     _topSpeed       = 0;
     _bestLap        =-1;
     _time           =-1;
     _nextCP         = 0;
     _startRace      = 0;
     _startLap       = 0;
     _previousSide   = 0;
     _previousInPoly = true;
     _finished       = false;
     cout << "Racer middle" << endl;
     _startRace      = clock();
     _startLap       = clock();
     this->_name     = name;
     this->_aircraft = aircraft;
     this->_laps     = laps;
     this->cp        = cp;
     cout << "Racer end" << endl;
}

int Racer::check(double x, double y, double z, double speed, double time)
{
    int ret = 0;
    if (! _finished)
    {
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
		                clock_t endLap = time;//clock(); // restart the clock for start_lap
		                double lapTime = ((double)(endLap - _startLap)) / CLOCKS_PER_SEC;
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
		                    _time = endLap - _startRace;
		                    //_time = ((double)endLap - _startRace) / CLOCKS_PER_SEC;
		                    _finished = true;
		                }
		                _lapNumber ++;
		            }
		            else if (_nextCP ==1)
		            {
		                _startLap = time;//clock();
		                if (_lapNumber == 1)
		                {
		                    _startRace = time;//clock();
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
	}
    return ret;
}

std::ostream& operator<< (std::ostream &os, Racer &racer)
{
    os << racer.name() << " flying a " << racer.aircraft() << " finished in: " << racer.time()
       << "s ;  top speed: " << racer.topSpeed() << " ; best lap: " << racer.bestLap() << "s";
    return os;
}
