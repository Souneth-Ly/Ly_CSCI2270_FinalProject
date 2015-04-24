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
        cout<<"5.Which planet is the most similar to earth"<<endl;
        cout<<"6.Distance between planets"<<endl;
        cout<<"7.Quit"<<endl;
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
            cout<<"Enter Name of the Planet"<<endl;
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

            cout<<"Goodbye!"<<endl;
            //delete;
            break;
        }

        }
        return 0;

}
