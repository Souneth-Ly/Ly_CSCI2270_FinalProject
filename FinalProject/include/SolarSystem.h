#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <string>
#include <fstream>
#include <iostream>

struct planetNode{
    std::string planetName;
    int tempature;
    //planetNode* next;
    //planetNode* previous;
    std::string type;
    std::string color;
    int diameter;
    int lengthOfYear;
    int distanceFromSun;
    planetNode *next;
    planetNode *previous;

    planetNode(){};
    planetNode(std::string in_planetName, std::string in_color, int in_diameter, std::string in_type, int in_lengthOfYear, int in_distFromSun)
    {
        planetName=in_planetName;
        color=in_color;
        diameter=in_diameter;
        type=in_type;
        lengthOfYear=in_lengthOfYear;
        distanceFromSun=in_distFromSun;
    }

};


class SolarSystem
{
    public:
        SolarSystem();
        virtual ~SolarSystem();
        void buildSystem();
        int randomFact(int x);
        void closestplanettoearth(std::string sizeplanet, std::string tempature);
        void printSolarSystem();
        void findPlanet(std::string Planet);

    protected:
    private:
        planetNode* searchPlanet(std::string Planet);
        planetNode* head;
        planetNode* tail;
};

#endif // SOLARSYSTEM_H
