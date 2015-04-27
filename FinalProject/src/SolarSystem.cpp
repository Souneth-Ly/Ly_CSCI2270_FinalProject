#include "SolarSystem.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime> // to use the time function
#include <cstdlib>

using namespace std;
//Uranus,Blue-green,51118,Ice Giant,30687,3006318143,Uranus hits the coldest temperatures of any planet reaching temperature of -224°C
//Neptune,Bright Blue,49528,Ice Giant,60190,4537039826,Neptune has a very active climate. Large storms whirl through its upper atmosphere, and high-speed winds track around the planet at up 600 meters per second.

SolarSystem::SolarSystem()
{
    //ctor
}

SolarSystem::~SolarSystem()
{
    //dtor
}

//The build function will build the solar system from the SolarSystemData.txt as a doubly linked list
//it will get the planet name,color,diameter, type of planet, length of year in days, distance from the sun, a random fact about the planet

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
        long long distSun= stoll(distFromSun);
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
//The build function will out put a linked list of the planets: The Sun->Mercury->Venus and so on until it hits NULL

//Print out the the Solar System in order
void SolarSystem::printSolarSystem()
{

    cout<<"===THE SOLAR SYSTEM==="<<endl;
    for(planetNode *cursor = head; cursor!= NULL; cursor=cursor->next)
    {
        cout<<cursor->planetName<<"->";
    }
    cout<<" NULL";
    cout<<endl;
}//output the solar system


//the randomFact function is a function that randomly picks one of the nodes in the linked list and prints out the random fact about the planet, stored in the node
int SolarSystem::randomFact(){
    planetNode *cursor= head;
    int counter=0;//to store the number of nodes
    for(cursor=head;cursor!=NULL;cursor=cursor->next) //for loop to count how many nodes are in the list
    {
        counter++;
    }

    srand(time(0));
    int n= rand() %counter; //random function that generates a random number. then gets divided by the number of nodes to get the remainder

    planetNode *cursor2=new planetNode; //new node to travel through the list
    cursor2=head;
    int counter2 = 0;// counter to find which node to get the fact from
    while(counter2<n)
    {
        cursor2=cursor2->next;
        counter2++;
    }
    cout<<cursor2->randomFact<<endl;
    return 0;
}//this function will output the random fact that is stored in a node;


//Search for any planet in the solar system
planetNode* SolarSystem::searchPlanet(std:: string namePlanet){
    planetNode * searchNode = new planetNode;
    searchNode = head;
    while(searchNode != NULL){
        if(searchNode->planetName == namePlanet){
            return searchNode;
        }
        searchNode = searchNode->next;
    }
    if(searchNode==NULL)
    {
        cout<<"This planet is not in our Solar System"<<endl;
        return NULL;
    }

}//Output the name of a planet

//Find a planet in the linked list
void SolarSystem::findPlanet(string namePlanet){
    planetNode* foundPlanet;
    foundPlanet = searchPlanet(namePlanet);
    if(foundPlanet != NULL){

            cout<<"Planet Info:"<<endl;
            cout<<"==========="<<endl;
            cout<<"Name: "<<foundPlanet->planetName<<endl;
            cout<<"Color: "<<foundPlanet->color<<endl;
            cout<<"Type: "<<foundPlanet->type<<endl;
            cout<<"Distance from the sun: "<<foundPlanet->distanceFromSun<<" km"<<endl;
    }
}//output the name of the planet and the information about the planet:Color, Type of the planet, and Distance from the sun


//This function find the distance between two planets, by subtracting the nodes "distances from the sun" from each other to get the distance between them
//the function takes in two strings of planet names that will be inputed by the user
int SolarSystem::distanceBetweenPlanets(string name, string name2)
{
    planetNode *planetOne=new planetNode;//declaring nodes
    planetNode *planetTwo=new planetNode;
    planetOne=searchPlanet(name);//putting planet information into the nodes by using the searchPlanet function
    planetTwo=searchPlanet(name2);
    int distance=0;
    if(planetOne==NULL || planetTwo==NULL)//if on of the planets doesn't exist return a 0
    {
        return 0;
    }
    if(planetOne->planetName==planetTwo->planetName)//if the user inputs the same name for both parameters tell the user that it is the same planet
    {
        cout<<"This is the same planet"<<endl;
        return 0;
    }else{
        if(planetOne->distanceFromSun>planetTwo->distanceFromSun)//if the fist planet is bigger than the second
        {
            distance=planetOne->distanceFromSun-planetTwo->distanceFromSun;//then subtract the second from the first to not get a negative number
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
        if(planetTwo->distanceFromSun>planetOne->distanceFromSun)//if the second is bigger than the first
        {
            distance=planetTwo->distanceFromSun-planetOne->distanceFromSun;//then subtract the first from the second
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
    }

}
//once this function is complete and it was a valid input, it should output the the name of the planets and the distance between them

//Find the closest planet to the user's planet
void SolarSystem::closestPlanet(string namePlanet){
    planetNode* Planet = new planetNode;
    planetNode * nearplanet;
    Planet = searchPlanet(namePlanet);
    int pre_dist;
    int next_dist;
    if(Planet != NULL){
        if(Planet->previous == NULL){
             nearplanet= Planet->next;
        }else{
        if(Planet->next == NULL){
            nearplanet = Planet->previous;
        }else{
            pre_dist = Planet->distanceFromSun - Planet->previous->distanceFromSun;
            next_dist = Planet->next->distanceFromSun - Planet->distanceFromSun;
        }

        if(pre_dist > next_dist){
            nearplanet = Planet->next;
        }else
        nearplanet = Planet->previous;
    }
    }
     if(nearplanet != NULL){

            cout<<"Planet Close to:"<<" "<<Planet->planetName<<endl;
            cout<<"==========="<<endl;
            cout<<"Name: "<<nearplanet->planetName<<endl;
            cout<<"Color: "<<nearplanet->color<<endl;
            cout<<"Type: "<<nearplanet->type<<endl;
            cout<<"Distance from the sun: "<<nearplanet->distanceFromSun<<" km"<<endl;
    }

}//output the closest planet with its information

//delete a node from the linked list
planetNode* SolarSystem::deleteNode(planetNode* head, string name2){
    planetNode *cursor;
    //planetNode *cursorPrevious;
    //string name2;
    cursor=head;
    if(head->planetName == name2)
    {
        head=head->next;
        delete cursor;
        return head;
    }

    for(cursor = head; cursor!= NULL; cursor=cursor->next)
    {


        if(cursor->planetName==name2)
        {
            cursor->previous->next=cursor->next;
            delete cursor;
            break;
        }
        cursor->previous=cursor;
    }
    return head;
}//delete a planet from the solar system

void SolarSystem::PrintPlanetbiggesttosmallest(){
    /*
    int arraySize;

    planetNode* Diameter = new planetNode[arraySize];
    planetNode * cursor;
    int newDiameter = Diameter->diameter;
    for(int i = 0 ; i < arraySize; i++){
        Diameter[i];
    }
    planetNode* temp = head;
    string nameplanet;
    planetNode* largest;
    int cur_diameter;
    int largest_diameter = temp->diameter;
    int x = 1;
    while(x > 0){
        if(temp->next != NULL){
            if(temp->diameter >= largest_diameter){
                largest_diameter = temp->diameter;
                largest = temp;
            //}
            //cout<<largest->planetName<<"->";
            //deleteNode(largest, largest->planetName);
            temp = temp->next;
            largest_diameter = temp->diameter;
        }
        }
        //cout<<largest->planetName<<endl;
        if(temp->diameter > largest_diameter){
            largest_diameter = temp->diameter;
            largest = temp;
            //cout<<largest->planetName<<endl;
        }
        if((temp->next == NULL) && (temp->previous == NULL)){
            //cout<<temp->planetName<<"->";
    }
        //cout<<temp->planetName<<"->";
        //cout<<" NULL";
        //cout<<" "<<endl;
        x = -1;


    }
    //cout<<largest->planetName<<endl;
    */
    cout<<"We are sorry, this option is not working at the moment. Please continue on"<<endl;
    }
//add a planet to the solar system including the information of the planet.
planetNode* SolarSystem::addPlanet(string name, long long dist,string creator){
    planetNode *cursor=new planetNode;
    planetNode *newPlanet=new planetNode;
    string coolFact= name+" was created by the great and powerful "+creator;
    cursor=head;
    while(dist>cursor->distanceFromSun)
    {
        cursor=cursor->next;
    }
    if(cursor->distanceFromSun-dist<2500000)
    {
        string newDistance;
        cout<<"Your planet will be too close to "<<cursor->planetName<<endl;
        cout<<"please choose a new distance thats a million or two Km less than your current distance:"<<endl;
        getline(cin, newDistance);
        dist=stoll(newDistance);
    }
    else if(dist-cursor->previous->distanceFromSun<2500000)
    {
        string newDistance;
        cout<<"Your planet will be too close to "<<cursor->previous->planetName<<endl;
        cout<<"please choose a new distance thats a million or two Km greater than your old distance:"<<endl;
        getline(cin, newDistance);
        dist=stoi(newDistance);
    }
    planetNode *temp=cursor->previous;
    planetNode *temp2=cursor->previous->next;
    cursor->previous->next=newPlanet;
    cursor->previous=newPlanet;
    newPlanet->previous=temp;
    newPlanet->next=temp2;
    newPlanet->planetName=name;
    newPlanet->distanceFromSun=dist;
    newPlanet->randomFact=coolFact;
    string color;
    cout<<"What color do you want your planet?"<<endl;
    getline(cin, color);
    newPlanet->color=color;
    if(dist<450000000)
    {
        newPlanet->type="Terrestrial planet";
        cout<<newPlanet->planetName<<" will be a Terrestrial planet because you put it before the asteroid belt"<<endl;
    }else if(45000000<dist && dist<1700000000){
        newPlanet->type="Gas Giant";
        cout<<newPlanet->planetName<<" will be a Gas Giant because you put it after the asteroid belt"<<endl;
    }else {
        newPlanet->type="Ice Giant";
        cout<<newPlanet->planetName<<" will be an Ice Giant because you put it after the asteroid belt and after Saturn"<<endl;
    }
    return head;
}//after you put in your planet into the solar system, you can print the solar system and see your planet there

//The purpose of the function sort the diameter of the planet
void SolarSystem::Bubblesort(int * array, int sizeArray){
    int swap;
    for(int c = 0; c < sizeArray - 1; c++){
        for(int d = 0; d < sizeArray - c - 1; d++){
            if(array[d] > array[d+1]){
                swap = array[d];
                array[d] = array[d+1];
                array[d+1] = swap;
            }
        }
    }
    cout<<"sorted list, ascending order:"<<endl;
    for(int c = 0; c < sizeArray; c++){
       cout<<array[c]<<endl;
    }
}//output the order of some number
