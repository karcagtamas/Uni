#pragma once

#include <string>
#include <vector>

class Voter
{
    std::string name;
    std::string state;
    unsigned int age;
    unsigned int id;

public:
    Voter(const std::string &name, const std::string &state, unsigned int age, unsigned int id) : name(name), state(state), age(age), id(id){};
    void print();
    bool isEquals(unsigned int id)
    {
        return this->id == id;
    };
    std::string &getName()
    {
        return name;
    };
};

class Registry
{
private:
    std::vector<Voter *> voters;

public:
    void addVoter(const std::string &name, const std::string &state, unsigned int age, unsigned int id);
    void printVoters();
    std::vector<Voter *> &getVoters()
    {
        return voters;
    };
    ~Registry()
    {
        for (auto voter : voters)
        {
            delete voter;
        }
    };
};

class Election;

class Ballot
{
protected:
    Voter *voter;
    unsigned int vote;

public:
    virtual void cast(unsigned int candidate) = 0;
    Ballot(Voter *voter) : voter(voter){};
    Voter *getVoter() const { return voter; };
    friend Election;
};

class InPersonBallot : public Ballot
{
private:
    InPersonBallot(Voter *voter) : Ballot(voter){};

public:
    void cast(unsigned int candidate) override;
    friend Election;
};

class MailInBallot : public Ballot
{
private:
    MailInBallot(Voter *voter) : Ballot(voter){};

public:
    void cast(unsigned int candidate) override;
    friend Election;
};

class Election
{
private:
    std::string name;
    unsigned int candidates;
    Registry &registry;
    std::vector<Ballot *> ballots;

public:
    Election(const std::string &name, unsigned int candidates, Registry &registry) : name(name), candidates(candidates), registry(registry){};
    MailInBallot *getMailInBallot(unsigned int id);
    InPersonBallot *getInPersonBallot(unsigned int id);
    void processResults();
    ~Election()
    {
        // delete &registry;
        for (auto ballot : ballots)
        {
            delete ballot;
        }
    };
};