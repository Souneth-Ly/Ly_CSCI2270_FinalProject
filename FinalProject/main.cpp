#include <iostream>
#include <string>
#include "SolarSystem.h"

using namespace std;
void displayMenu();
int main(){
    SolarSystem *System = new SolarSystem;
    int input;
    bool quit=false;


    //inputfile.close();
    string namePlanet;
    string namePlanet2;
    string userName;
    string distance;

    while(quit!=true){

        displayMenu();
        cin>>input;
        cin.clear();
        cin.ignore(10000, '\n');
        switch(input)
        {
            case 1:
                System->buildSystem();
                System->printSolarSystem();
                break;

            case 2:
                System->printSolarSystem();
                break;

            case 3:
                cout<<"Enter Name of the Planet"<<endl;
                getline(cin, namePlanet);
                System->findPlanet(namePlanet);
                break;

            case 4:
                System->randomFact();
                break;

            case 5:
                cout<<"Enter your favorite Planet"<<endl;
                getline(cin, namePlanet);
                System->closestPlanet(namePlanet);
                break;

            case 6:
                cout<<"Enter name of the first planet:"<<endl;
                getline(cin,namePlanet);
                cout<<"Enter name of the second planet:"<<endl;
                getline(cin,namePlanet2);
                System->distanceBetweenPlanets(namePlanet, namePlanet2);
                break;

            case 7:
                System->printPlanetsBiggestToSmallest();
                break;

            case 8:
                cout<<"Please enter your name:"<<endl;
                getline(cin,userName);
                cout<<"Enter the new planet name:"<<endl;
                getline(cin, namePlanet);
                cout<<"Enter how far this planet is to the sun: it has to be a distance in the millions"<<endl;
                getline(cin, distance);

                System->addPlanet(namePlanet,stoll(distance),userName);
                break;

            case 9:
                cout<<"Enter a planet name to see its length in Earth years:"<<endl;
                getline(cin, namePlanet);
                System->convertFromDaysToYears(namePlanet);
                break;

            case 10:
                cout<<"Goodbye!"<<endl;
                quit = true;
                break;

            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    delete System;
    return 0;
}
void displayMenu()
{
    cout<<"======Main Menu====="<<endl;
    cout<<"1.Build the solar system"<<endl;
    cout<<"2.Print the solar system"<<endl;
    cout<<"3.Find Planet"<<endl;
    cout<<"4.Print Random Fact"<<endl;
    cout<<"5.Find a planet close your Favorite planet"<<endl;
    cout<<"6.Distance between planets"<<endl;
    cout<<"7.Print the Biggest Planet to the Smallest"<<endl;
    cout<<"8.Add your own planet"<<endl;
    cout<<"9.Convert a planet's year length from Earth days to Earth years"<<endl;
    cout<<"10.Quit"<<endl;
    return;
}
