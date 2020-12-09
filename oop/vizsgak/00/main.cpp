#include "soccer.h"

#include <iostream>
#include <math.h>
#include <vector>
#include <iterator>
#include <algorithm>

SoccerPlayer::SoccerPlayer(const std::string &name, short speed, short stamina) : name(name), speed(speed), stamina(stamina) {}

std::ostream &operator<<(std::ostream &os, const SoccerPlayer &sp)
{
    os << sp.getName() << " (" << sp.getOverall() << ")";
    return os;
}

class FieldPlayer : public SoccerPlayer
{
    short shooting;
    short passing;
    short tackling;

public:
    FieldPlayer(const std::string &name, short speed, short stamina, short shooting, short passing, short tackling) : SoccerPlayer(name, speed, stamina), shooting(shooting), passing(passing), tackling(tackling){};
    short getShooting() const
    {
        return shooting;
    }
    short getPassing() const
    {
        return passing;
    }
    short getTackling() const
    {
        return tackling;
    }
    short getOverall() const
    {
        return floor((getSpeed() + getStamina() + shooting + passing + tackling) / 5);
    }
};

class Goalkeeper : public SoccerPlayer
{
    short reflexes;
    short agility;

public:
    Goalkeeper(const std::string &name, short speed, short stamina, short reflexes, short agility) : SoccerPlayer(name, speed, stamina), reflexes(reflexes), agility(agility){};
    short getReflexes() const
    {
        return reflexes;
    }
    short getAgility() const
    {
        return agility;
    }
    short getOverall() const
    {
        return floor((getSpeed() + getStamina() + reflexes + agility) / 4);
    }
};

class SoccerTeam
{
private:
    std::vector<const SoccerPlayer *> team;

public:
    bool add(const SoccerPlayer *sp)
    {
        if (std::find(team.begin(), team.end(), sp) != team.end())
        {
            return false;
        }
        const Goalkeeper *gk = dynamic_cast<const Goalkeeper *>(sp);
        if (gk != nullptr)
        {
            auto it = std::find_if(team.begin(), team.end(), [](const SoccerPlayer *s) {
                return dynamic_cast<const Goalkeeper *>(s) != nullptr;
            });

            if (it != team.end())
            {
                return false;
            }
        }
        team.push_back(sp);
        return true;
    }
    int playerCount()
    {
        return team.size();
    }
    const SoccerPlayer *operator[](int index)
    {
        return team[index];
    }
    ~SoccerTeam()
    {
        for (auto sp : team)
        {
            delete sp;
        }
    }
};

int main()
{
    // main()-ben szereplo kod:
    using namespace std;

    SoccerTeam team;

    if (team.add(new FieldPlayer("C. Ronaldo", 90, 85, 95, 91, 76)))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add C. Ronaldo.\n";

    if (team.add(new FieldPlayer("L. Messi", 88, 93, 75, 88, 96)))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add L. Messi.\n";

    if (team.add(new Goalkeeper("M. Neuer", 89, 87, 94, 95)))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add M. Neuer.\n";

    if (team.add(team[0]))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add " << *team[0] << endl;

    if (team.add(team[1]))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add " << *team[1] << endl;

    if (team.add(team[2]))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add " << *team[2] << endl;

    Goalkeeper *gk2 = new Goalkeeper("H. Lloris", 85, 86, 92, 94);
    if (team.add(gk2))
        cout << "Player added: " << *team[team.playerCount() - 1] << endl;
    else
        cout << "Failed to add " << *gk2 << endl;
    delete gk2;

    for (size_t i = 0; i < (size_t)team.playerCount(); ++i)
    {
        cout << *team[i] << endl;
        cout << team[i]->getName() << endl;
        cout << team[i]->getSpeed() << endl;
        cout << team[i]->getStamina() << endl
             << endl;
    }
}