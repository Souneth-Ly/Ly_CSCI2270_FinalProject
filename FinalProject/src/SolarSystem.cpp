#include "SolarSystem.h"
#include <iostream>
#include <string>

using namespace std;

SolarSystem::SolarSystem()
{
    //ctor
}

SolarSystem::~SolarSystem()
{
    //dtor
}

void SolarSystem::buildSystem(){

}

int SolarSystem::randomFact(int x){

}

planetNode* SolarSystem::searchPlanet(std:: string namePlanet){
    planetNode * searchNode = new planetNode;
    searchNode = head;
    while(searchNode != NULL){
        if(searchNode->planetName == namePlanet){
            return searchNode;
    }
        searchNode = searchNode->next;
    }
    return NULL;
}

