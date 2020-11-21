#include "registry.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>

void Voter::print()
{
    std::cout << name << " - " << state << " - " << age << " - " << id << std::endl;
}

void Registry::addVoter(const std::string &name, const std::string &state, unsigned int age, unsigned int id)
{
    int count = std::count_if(voters.begin(), voters.end(), [id](Voter *voter) {
        return voter->isEquals(id);
    });
    if (count > 0)
    {
        std::cout << "Could not add voter: " << id << ": " << name << " -- " << age << " years old -- " << state << std::endl;
        return;
    }
    voters.push_back(new Voter(name, state, age, id));
}

void Registry::printVoters()
{
    for (Voter *voter : voters)
    {
        voter->print();
    }
}

MailInBallot *Election::getMailInBallot(unsigned int id)
{
    std::vector<Voter *>::iterator it = std::find_if(registry.getVoters().begin(), registry.getVoters().end(), [id](Voter *voter) {
        return voter->isEquals(id);
    });
    if (*it != nullptr)
    {
        MailInBallot *ballot = new MailInBallot(*it);
        ballots.push_back(ballot);
        return ballot;
    }
    return nullptr;
}

InPersonBallot *Election::getInPersonBallot(unsigned int id)
{
    std::vector<Voter *>::iterator it = std::find_if(registry.getVoters().begin(), registry.getVoters().end(), [id](Voter *voter) {
        return voter->isEquals(id);
    });
    if (*it != nullptr)
    {
        std::vector<Ballot *>::iterator ballotIt = std::find_if(ballots.begin(), ballots.end(), [it](Ballot *ballot) {
            InPersonBallot *inPerson = dynamic_cast<InPersonBallot *>(ballot);
            return ballot->getVoter() == *it && inPerson != nullptr;
        });

        if (*ballotIt == nullptr)
        {
            InPersonBallot *ballot = new InPersonBallot(*it);
            ballots.push_back(ballot);
            return ballot;
        }
        return nullptr;
    }
    return nullptr;
}

void MailInBallot::cast(unsigned int candidate)
{
    vote = candidate;
}

void InPersonBallot::cast(unsigned int candidate)
{
    vote = candidate;
}

void Election::processResults()
{
    std::map<Voter *, Ballot *> map;

    for (auto ballot : ballots)
    {
        if (map.find(ballot->voter) != map.end())
        {
            InPersonBallot *inPerson = dynamic_cast<InPersonBallot *>(ballot);
            if (inPerson != nullptr)
            {
                std::cout << "mail ballot rejected for voter " << ballot->voter->getName() << std::endl;
                map[ballot->voter] = ballot;
            }
            else
            {
                std::cout << "mail ballot rejected for voter " << ballot->voter->getName() << std::endl;
            }
        }
        else
        {
            map.insert({ballot->voter, ballot});
        }
    }

    int votes[candidates];
    for (int i = 0; i < candidates; i++)
    {
        votes[i] = 0;
    }

    for (auto ballot : map)
    {
        if (ballot.second->vote > candidates || ballot.second->vote < 1)
        {
            std::cout << "Invalid vote" << std::endl;
        }
        else
        {
            votes[ballot.second->vote - 1]++;
        }
    }

    std::cout << "Results for election " << name << std::endl;
    for (int i = 1; i <= candidates; i++)
    {
        std::cout << "Candidate " << i << " : " << votes[i - 1] << " votes" << std::endl;
    }
}