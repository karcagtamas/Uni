#pragma once
#include <string>

class SoccerPlayer
{
    const std::string name;
    short speed;
    short stamina;

public:
    SoccerPlayer(const std::string &name, short speed, short stamina); //TODO
    virtual ~SoccerPlayer() = default;
    const std::string &getName() const { return name; }
    short getSpeed() const { return speed; }
    short getStamina() const { return stamina; }
    virtual short getOverall() const = 0;
};