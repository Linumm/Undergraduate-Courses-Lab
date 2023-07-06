#include "minimal_fighter.h"
#include <iostream>
using namespace std;

MinimalFighter::MinimalFighter() { mHp=0; mPower=0; mStatus=Invalid; }

MinimalFighter::MinimalFighter(int _hp, int _power)
{
    mHp=_hp; mPower=_power;
}

int MinimalFighter::hp() { return mHp; }
int MinimalFighter::power() { return mPower; }
FighterStatus MinimalFighter::status()
{
    if (hp()<=0)
        return Dead;
    else
        return Alive;
}

void MinimalFighter::setHp(int _hp)
{
    mHp-=_hp;
}
void MinimalFighter::hit(MinimalFighter* _enemy)
{
    mHp-=_enemy->power();
    _enemy->setHp(mPower);
}

void MinimalFighter::attack(MinimalFighter* _enemy)
{
    _enemy->setHp(power());
    mPower=0;
}

void MinimalFighter::fight(MinimalFighter* _enemy)
{
    while(true) {
        if (hp()<=0 ||( _enemy->hp())<=0)
            break;
        mHp-=_enemy->power();
        _enemy->setHp(mPower);
    }
}
