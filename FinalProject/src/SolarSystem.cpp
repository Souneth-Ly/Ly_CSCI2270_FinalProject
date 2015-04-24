#include "SolarSystem.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime> // to use the time function
#include <cstdlib>

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
    string randomFacts;

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
        getline(inLine, randomFacts,',');

        planetNode *newNode= new planetNode(planetName, color, diam, type, year, distSun, randomFacts);
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
    inputfile.close();
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
    srand(time(0));
    int n= rand() % 4;
    cout << n<<endl;

    int counter = 0;
    while(counter<n)
    {

        cursor=cursor->next;
        counter++;
    }
    cout<<cursor->randomFact<<endl;

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
            cout<<"Distance from the sun: "<<foundPlanet->distanceFromSun<<" km"<<endl;
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

//<<<<<<< HEAD
void SolarSystem::closestPlanet(string namePlanet){
    planetNode* Planet = new planetNode;
    planetNode * nearplanet;
    Planet = searchPlanet(namePlanet);
    int pre_dist;
    int next_dist;
    if(Planet != NULL){
        if(Planet->previous == NULL){
             nearplanet= Planet->next;
        }
        if (Planet->next == NULL){
            nearplanet = Planet->previous;
        }
        pre_dist = Planet->distanceFromSun - Planet->previous->distanceFromSun;
        next_dist = Planet->next->distanceFromSun - Planet->distanceFromSun;
        if(pre_dist > next_dist){
            nearplanet = Planet->next;
        }else
        nearplanet = Planet->previous;
    }
     if(nearplanet != NULL){

            cout<<"Planet Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Color: "<<nearplanet->color<<endl;
            cout<<"Title: "<<nearplanet->planetName<<endl;
            cout<<"Type: "<<nearplanet->type<<endl;
            cout<<"Distance from the sun: "<<nearplanet->distanceFromSun<<" km"<<endl;
    }

}

//=======
//>>>>>>> 545933c21198b3b3e37d32478065884331b71a80
