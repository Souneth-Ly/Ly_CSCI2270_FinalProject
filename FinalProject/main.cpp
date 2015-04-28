#include <iostream>
#include <string>
#include "SolarSystem.h"

using namespace std;

int main(){
    SolarSystem *System = new SolarSystem;


    //inputfile.close();

    while(1){

        char selection[2];
        cout<<"======Main Menu====="<<endl;
        cout<<"1.Build the solar system"<<endl;
        cout<<"2.Print the solar system"<<endl;
        cout<<"3.Find Planet"<<endl;
        cout<<"4.Print Random Fact"<<endl;
        cout<<"5.Find a planet close your Favorite planet"<<endl;
        cout<<"6.Distance between planets"<<endl;
        cout<<"7.Print the Biggest Planet to the Smallest"<<endl;
        cout<<"8.Add our own planet"<<endl;
        cout<<"9.Convert a planet's year length from Earth days to Earth years"<<endl;
        cout<<"10.Quit"<<endl;
        cin>>selection;
        cin.ignore(1, '\n');
        if(selection[0]=='1'){
            System->buildSystem();
            System->printSolarSystem();
        }
        if(selection[0]=='2'){
            System->printSolarSystem();

        }
        if(selection[0]=='3'){
            string namePlanet;
            cout<<"Enter Name of the Planet"<<endl;
            getline(cin, namePlanet);
            System->findPlanet(namePlanet);

        }
        if(selection[0]=='4'){
           System->randomFact();

        }
        if (selection[0]=='5'){
            string Nameplanet;
            cout<<"Enter your favorite Planet"<<endl;
            getline(cin, Nameplanet);
            System->closestPlanet(Nameplanet);

        }
        if(selection[0]=='6')
        {
            string nameP1;
            string nameP2;
            cout<<"Enter name of the first planet:"<<endl;
            getline(cin,nameP1);
            cout<<"Enter name of the second planet:"<<endl;
            getline(cin,nameP2);
            System->distanceBetweenPlanets(nameP1, nameP2);
        }
        if(selection[0]== '7'){
            System->PrintPlanetbiggesttosmallest();
            //System->BiggestandSmallestplanet();
            //System->Test();
        }
        if(selection[0]== '8'){
            string creator;
            string distance;
            string nextName;
            cout<<"Please enter your name:"<<endl;
            getline(cin,creator);
            cout<<"Enter the new planet name:"<<endl;
            getline(cin, nextName);
            cout<<"Enter how far this planet is to the sun: it has to be a distance in the millions"<<endl;
            getline(cin, distance);

            System->addPlanet(nextName,stoll(distance),creator);
        }
        if(selection[0]=='9')
        {
            string planetName;
            cout<<"Enter a planet name to see its length in Earth years:"<<endl;
            getline(cin, planetName);
            System->convertFromDaysToYears(planetName);
        }
        if(selection[0]== '10'){

            cout<<"Goodbye!"<<endl;
            //delete;
            break;
        }

        }
        return 0;

}
