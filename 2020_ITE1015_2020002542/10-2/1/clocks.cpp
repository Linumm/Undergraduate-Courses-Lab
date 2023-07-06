#include <iostream>
#include "clocks.h"
using namespace std;
//========================class <Clock>
Clock::Clock(int hour, int minute, int second, double driftPerSecond)
{
    _clockTime.setTime(hour, minute, second, 1);
    _driftPerSecond = driftPerSecond;
}

void Clock::reset()
{ _clockTime.reset(); }

void Clock::tick()
{
    _clockTime.increment(); //need to add more functionalities.
    _totalDrift += _driftPerSecond;
}

//========================class <NaturalClock>
NaturalClock::NaturalClock(int hour, int minute, int second, double driftPerSecond)
: Clock(hour, minute, second, driftPerSecond) {}


SundialClock::SundialClock(int hour, int minute, int second)
: NaturalClock( hour, minute, second, 0.0) {}

void SundialClock::displayTime()
{
    cout << "SundialClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

//=========================class <MechanicalClock>
MechanicalClock::MechanicalClock(int hour, int minute, int second, double driftPerSecond)
: Clock(hour, minute, second, driftPerSecond) {}


CuckooClock::CuckooClock(int hour, int minute, int second)
: MechanicalClock( hour, minute, second, 0.0) {}

void CuckooClock::displayTime()
{
    cout << "CuckooClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}


GrandFatherClock::GrandFatherClock(int hour, int minute, int second)
: MechanicalClock( hour, minute, second, 0.000694444) {}

void GrandFatherClock::displayTime()
{
    cout << "GrandFatherClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

//=========================class <DigitalClock>
DigitalClock::DigitalClock(int hour, int minute, int second, double driftPerSecond)
: Clock(hour, minute, second, driftPerSecond) {}


WristClock::WristClock(int hour, int minute, int second)
: DigitalClock( hour, minute, second, 0.000347222) {}

void WristClock::displayTime()
{
    cout << "WristClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}

//=========================class <QuantumClock>
QuantumClock::QuantumClock(int hour, int minute, int second, double driftPerSecond)
: Clock(hour, minute, second, driftPerSecond) {}


AtomicClock::AtomicClock(int hour, int minute, int second)
: QuantumClock( hour, minute, second, 0.000034722) {}

void AtomicClock::displayTime()
{
    cout << "AtomicClock ";
    _clockTime.display();
    cout << ", total drift: " << _totalDrift << endl;
}
