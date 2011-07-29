#ifndef RACER_H
#define RACER_H

#include <string>
#include <time.h>

#include "CheckPoints.h"

using namespace std;

class Racer
{
    public:
        /** Default constructor */
        Racer(string name, string aircraft, int laps, CheckPoints* cp);

        /** Access _name
         * \return The current value of _name
         */
        string name() { return _name; }

        /** Access _aircraft
         * \return The current value of _aircraft
         */
        string aircraft() { return _aircraft; }

        /** Access _lapNumber
         * \return The current value of _lapNumber
         */
        int lapNumber() { return _lapNumber; }

        /** Access _bestLap
         * \return The current value of _bestLap
         */
        double bestLap() { return _bestLap; }

        /** Access _laps
         * \return The current value of _laps
         */
        int laps() { return _laps; }

        /** Access _nextCP
         * \return The current value of _nextCP
         */
        int nextCP() { return _nextCP; }

        /** Access _previousInPoly
         * \return The current value of _previousInPoly
         */
        bool previousInPoly() { return _previousInPoly; }

        /** Access _previousSide
         * \return The current value of _previousInPoly
         */
        int previousSide() { return _previousSide; }

        /** Access _startLap
         * \return The current value of _startLap
         */
        clock_t startLap() { return _startLap; }

        /** Access _startRace
         * \return The current value of _startRace
         */
        clock_t startRace() { return _startRace; }

        /** Access _time
         * \return The current value of _time
         */
        double time() { return _time; }

        /** Access _topSpeed
         * \return The current value of _topSpeed
         */
        int topSpeed() { return _topSpeed; }

        /** Update the state of the racer : if it passed the checkpoint, ...
         * Assume that between two call of check, the distance between
         * the two positions of the player is inferior to 4*radius_of_the_poly
         * \param x position of the player
         * \param y position of the player
         * \param z position of the player
         * \param speed the speed of the player
         * \return -1 if failed to pass a check point
                    1 if passed a check point
                    2 if finished a lap
                    3 if finished the race
                    0 else
         */
        int check(double x, double y, double z, double speed, double time=0);

    protected:
    private:
        string  _name;           //!< Member variable "_name"
        string  _aircraft;       //!< Member variable "_aircraft"
        int     _lapNumber;      //!< Member variable "_lapNumber"
        int     _laps;           //!< Member variable "_laps
        double  _topSpeed;       //!< Member variable "_topSpeed"
        double  _bestLap;        //!< Member variable "_bestLap" duration of the best lap
        int     _nextCP;         //!< Member variable "_nextCP"
        clock_t _startRace;      //!< Member variable "_startRace"
        clock_t _startLap;       //!< Member variable "_startLap"
        double  _time;           //!< Member variable "_time" duration of the race
        int     _previousSide;   //!< Member variable "_previousSide"
        bool    _previousInPoly; //!< Member variable "_previousInPoly"
        bool    _finished;
        CheckPoints*  cp;
};

std::ostream& operator<< (std::ostream &os, Racer &racer);

#endif // RACER_H
