#include "SolarSystem.h"
#include <iostream>
#include <string>
#include <sstream>

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

        }else{
            cursor->next=newNode;
            cursor->previous=cursor;
            cursor=newNode;

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

void SolarSystem::findPlanet(string namePlanet){
    //string namePlanet;
    planetNode* foundPlanet;
    foundPlanet = searchPlanet(namePlanet);
    if(foundPlanet != NULL){

            cout<<"Planet Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Color: "<<foundPlanet->color<<endl;
            cout<<"Title: "<<foundPlanet->planetName<<endl;
            cout<<"Type: "<<foundPlanet->type<<endl;
            cout<<"Distance from the sun: "<<foundPlanet->distanceFromSun<<endl;
    }
}

int SolarSystem::distanceBetweenPlanets(string name, string name2)
{
    planetNode *planetOne=new planetNode;
    planetNode *planetTwo=new planetNode;
    planetOne=searchPlanet(name);
    planetTwo=searchPlanet(name2);
    int distance=0;
    if(planetOne->planetName==planetTwo->planetName)
    {
        cout<<"This is the same planet"<<endl;
        return 0;
    }else{
        if(planetOne->distanceFromSun>planetTwo->distanceFromSun)
        {
            distance=planetOne->distanceFromSun-planetTwo->distanceFromSun;
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
        if(planetTwo->distanceFromSun>planetOne->distanceFromSun)
        {
            distance=planetTwo->distanceFromSun-planetOne->distanceFromSun;
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
    }

}

void SolarSystem::closestPlanettoearth(int Distance){

}

