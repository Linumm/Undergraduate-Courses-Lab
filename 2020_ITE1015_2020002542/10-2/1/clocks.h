//clocks.h
#include "clock_time.h"
class Clock
{
    public:
        Clock(int hour, int minute, int second, double driftPerSecond);
        void reset();
        void tick();
        virtual void displayTime() = 0;

    protected:
        ClockTime _clockTime;
        double _driftPerSecond;
        double _totalDrift;
};

//=================================class <Natural>
class NaturalClock: public Clock
{
    public:
        NaturalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class SundialClock: public NaturalClock
{
    public:
        SundialClock(int hour, int minute, int second);
        virtual void displayTime();
};

//=================================class <Mechanical>
class MechanicalClock: public Clock
{
    public:
        MechanicalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class CuckooClock: public MechanicalClock
{
    public:
        CuckooClock(int hour, int minute, int second);
        virtual void displayTime();
};

class GrandFatherClock: public MechanicalClock
{
    public:
        GrandFatherClock(int hour, int minute, int second);
        virtual void displayTime();
};

//=================================class <Digital>
class DigitalClock: public Clock
{
    public:
        DigitalClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class WristClock: public DigitalClock
{
    public:
        WristClock(int hour, int minute, int second);
        virtual void displayTime();
};

//=================================class <Quantum>
class QuantumClock: public Clock
{
    public:
        QuantumClock(int hour, int minute, int second, double driftPerSecond);
        virtual void displayTime() = 0;
};

class AtomicClock: public QuantumClock
{
    public:
        AtomicClock(int hour, int minute, int second);
        virtual void displayTime();
};
