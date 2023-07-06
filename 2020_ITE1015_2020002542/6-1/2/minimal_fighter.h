//minimal_fighter.h
#ifndef __minimal_fighter__
#define __minimal_fighter__

#include <iostream>
using namespace std;

enum EFighterStatus
{
    Invalid=0,

    Alive,
    Dead,
};
typedef enum EFighterStatus FighterStatus;

class MinimalFighter
{
    private:
        int mHp; //Health Point
        int mPower; //Attack Power
        FighterStatus mStatus; //Invalid, Alive, Dead Status
    public:
        MinimalFighter();
        MinimalFighter(int _hp, int _power);

        int hp(); int power(); FighterStatus status();
        void setHp(int _hp);
        void hit(MinimalFighter* _enemy);    //run Hit command
        void attack(MinimalFighter* _enemy); //run Attack command
        void fight(MinimalFighter* _enemy);  //run FIght command
};

#endif

