#ifndef RACER_H
#define RACER_H

#include "CheckPoints.h"

class Racer
{
    public:
        /** Default constructor */
        Racer();

        /** Access _name
         * \return The current value of _name
         */
        char* name() { return _name; }

        /** Access _aircraft
         * \return The current value of _aircraft
         */
        char* aircraft() { return _aircraft; }

        /** Access _lapNumber
         * \return The current value of _lapNumber
         */
        int lapNumber() { return _lapNumber; }

        /** Update the state of the racer : if it passed the checkpoint, ...
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
        int check(double x, double y, double z, double speed);

    protected:
    private:
        char*  _name;           //!< Member variable "_name"
        char*  _aircraft;       //!< Member variable "_aircraft"
        int    _lapNumber;      //!< Member variable "_lapNumber"
        int    _laps;           //!< Member variable "_laps
        double _topSpeed;       //!< Member variable "_topSpeed"
        double _bestLap;        //!< Member variable "_bestLap"
        int    _nextCP;         //!< Member variable "_nextCP"
        double _startRace;      //!< Member variable "_startRace"
        double _startLap;       //!< Member variable "_startLap"
        int    _previousSide;   //!< Member variable "_previousSide"
        bool   _previousInPoly; //!< Member variable "_previousInPoly"
        CheckPoints*  cp;
};

#endif // RACER_H
