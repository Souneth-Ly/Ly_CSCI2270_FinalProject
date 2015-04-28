#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include <string>
#include <fstream>
#include <iostream>

struct planetNode{
    std::string planetName;
    int tempature;
    std::string type;
    std::string color;
    std::string randomFact;
    int diameter;
    int lengthOfYear;
    long long distanceFromSun;
    planetNode *next;
    planetNode *previous;

    planetNode(){};
    planetNode(std::string in_planetName, std::string in_color, int in_diameter, std::string in_type, int in_lengthOfYear, long long in_distFromSun, std::string in_fact)
    {
        planetName=in_planetName;
        color=in_color;
        diameter=in_diameter;
        type=in_type;
        lengthOfYear=in_lengthOfYear;
        distanceFromSun=in_distFromSun;
        randomFact=in_fact;
    }

};


class SolarSystem
{
    public:
        SolarSystem();
        virtual ~SolarSystem();
        void buildSystem();
        int randomFact(int x);
        void closestPlanet(std:: string namePlanet);
        int randomFact();
        void closestplanettoearth(std::string sizeplanet, std::string tempature);
        void printSolarSystem();
        void findPlanet(std::string Planet);
        int distanceBetweenPlanets(std::string name, std::string name2);
        void PrintPlanetbiggesttosmallest();
        planetNode *addPlanet(std::string name,long long dist,std::string user);
        int convertFromDaysToYears(std::string name);


    protected:
    private:
        planetNode* searchPlanet(std::string Planet);
        planetNode* deleteNode(planetNode* head, std::string name2);
        void Bubblesort(int *array, int sizeArray);
        planetNode* head;
        planetNode* tail;
};

#endif // SOLARSYSTEM_H
