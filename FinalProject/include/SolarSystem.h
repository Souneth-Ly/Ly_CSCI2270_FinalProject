#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <string>
#include <fstream>
#include <iostream>

struct planetNode{
    std::string planetName;
    int tempature;
    planetNode* next;
    planetNode* previous;
};


class SolarSystem
{
    public:
        SolarSystem();
        virtual ~SolarSystem();
        void buildSystem();
        int randomFact(int x);
        void closestplanettoearth(std::string sizeplanet, std::string tempature);

    protected:
    private:
        planetNode* searchPlanet(std::string Planet);
        planetNode* head;
        planetNode* tail;
};

#endif // SOLARSYSTEM_H
