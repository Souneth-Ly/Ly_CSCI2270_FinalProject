#include "SolarSystem.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

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
    planetNode *cursor=NULL;
    string line;
    ifstream inputfile;
    inputfile.open("SolarSystemData.txt");
    if (!inputfile)
    {
        cout << "Could not open file\n";
        return;
    }
    string planetName;
    string color;
    string diameter;
    string type;
    string yearLength;
    string distFromSun;
    string temp;

    string inLine;
    while (getline(inputfile, line))
    {
        istringstream inLine(line);
        getline(inLine, planetName, ',');
        getline(inLine, color, ',');
        getline(inLine, diameter, ',');
        int diam= stoi(diameter);
        getline(inLine, type, ',');
        getline(inLine, yearLength, ',');
        int year= stoi(yearLength);
        getline(inLine, distFromSun, ',');
        int distSun= stoi(distFromSun);

        planetNode *newNode= new planetNode(planetName, color, diam, type, year, distSun);
        if(head==NULL)
        {
            head=newNode;
            cursor=head;
            cursor->previous=NULL;
            tail=head;
        }else{
            cursor->next=newNode;
            tail=newNode;
            tail->previous=cursor;
            cursor=newNode;
            cursor->next=NULL;

        }
    }
}

void SolarSystem::printSolarSystem()
{

    cout<<"===THE SOLAR SYSTEM==="<<endl;
    for(planetNode *cursor = head; cursor!= NULL; cursor=cursor->next)
    {
        cout<<cursor->planetName<<"->";
    }
    cout<<" NULL";
    cout<<endl;
}


int SolarSystem::randomFact(){
    planetNode *cursor= head;
    int random= rand()%5;
    int counter = 0;
    while(counter<random)
    {
        cursor=cursor->next;
    }
    cout<<cursor->planetName<<endl;

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

