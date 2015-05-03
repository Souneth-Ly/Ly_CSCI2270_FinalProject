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

//The build function will build the solar system from the SolarSystemData.txt as a doubly linked list
//it will get the planet name,color,diameter, type of planet, length of year in days, distance from the sun, a random fact about the planet

void SolarSystem::buildSystem(){
	if(built == false)
	{
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
		built = true;
		inputfile.close();
	}
	else
		cout << "System already built." << endl;

}
//The build function will out put a linked list of the planets: The Sun->Mercury->Venus and so on until it hits NULL

//Print out the the Solar System in order
void SolarSystem::printSolarSystem()
{

    cout<<"===THE SOLAR SYSTEM==="<<endl;
    for(planetNode *cursor = head; cursor!= NULL; cursor=cursor->next)
    {
        cout<<cursor->planetName<<"\n";
    }
    cout<<"The Heliosphere and beyond!";
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
    cout<<"Random Fact About: " << cursor2 -> planetName<< endl;
    cout<<cursor2->randomFact<<endl;
    return 0;
}//this function will output the random fact that is stored in a node;


//Search for any planet in the solar system
planetNode* SolarSystem::searchPlanet(std:: string namePlanet){
    planetNode * searchNode = new planetNode;
    searchNode = head;
    while(searchNode != NULL){
        if(searchNode->planetName == namePlanet){//if the Linked List is not empty, it will search for the planet
            return searchNode;
        }
        searchNode = searchNode->next;
    }
    if(searchNode==NULL)//check if the user enter a correct name of the planet in the solar system
    {
        cout<<"This planet is not in our Solar System"<<endl;
        return NULL;
    }

}//Output the name of a planet

//Find a planet in the linked list
void SolarSystem::findPlanet(string namePlanet){
    planetNode* foundPlanet;
    foundPlanet = searchPlanet(namePlanet);//search for the planet the user input
    if(foundPlanet != NULL){//output the information the user planet
			cout<<endl; //added by jogo9225
            cout<<"Planet Info:"<<endl;
            cout<<"============"<<endl;
            cout<<"Name: "<<foundPlanet->planetName<<endl;
            cout<<"Color: "<<foundPlanet->color<<endl;
            cout<<"Type: "<<foundPlanet->type<<endl;
            cout<<"Distance from the sun: "<<foundPlanet->distanceFromSun<<" Km"<<endl;
            cout<<"Length of year: "<<foundPlanet->lengthOfYear<<" Earth days"<<endl;
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
		cout <<"\n";
        cout<<"This is the same planet"<<endl;
        return 0;
    }else{
        if(planetOne->distanceFromSun>planetTwo->distanceFromSun)//if the fist planet is bigger than the second
        {
            distance=planetOne->distanceFromSun-planetTwo->distanceFromSun;//then subtract the second from the first to not get a negative number
            cout<<"\n";
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
        if(planetTwo->distanceFromSun>planetOne->distanceFromSun)//if the second is bigger than the first
        {
            distance=planetTwo->distanceFromSun-planetOne->distanceFromSun;//then subtract the first from the second
            cout<<"\n";
            cout<<"The distance between "<<planetOne->planetName<<" and "<<planetTwo->planetName<<" is "<<distance<<" Km"<<endl;
            return distance;
        }
    }

}
//once this function is complete and it was a valid input, it should output the the name of the planets and the distance between them

//Find the closest planet to the user's planet
planetNode* SolarSystem::closestPlanet(string namePlanet){
    planetNode* Planet = new planetNode;
    planetNode * nearplanet;
    Planet = searchPlanet(namePlanet);
    int pre_dist;
    int next_dist;
    if(Planet != NULL){
        if(Planet->previous == NULL){
             nearplanet= Planet->next;//check if the planet the user looking for is the Beginning of the Linked list
        }else{
        if(Planet->next == NULL){//check if the planet the user looking for is the end of the the Linked List
            nearplanet = Planet->previous;
        }else{
            pre_dist = Planet->distanceFromSun - Planet->previous->distanceFromSun;//using the distance from the sun to determine the closest planet
            next_dist = Planet->next->distanceFromSun - Planet->distanceFromSun;
        }

        if(pre_dist > next_dist){
            nearplanet = Planet->next;
        }else
        nearplanet = Planet->previous;
    }
    }
     if(Planet == NULL){
        cout<<"Please try again"<<endl;
        return NULL;
    }
     if(nearplanet != NULL){//output the information of the closest planet
			cout<<"\n";
            cout<<"Planet Closeest to:"<<" "<<Planet->planetName<<endl; //reformatted by jogo9225
            cout<<"=================="<<endl;
            cout<<"Name: "<<nearplanet->planetName<<endl;
            cout<<"Color: "<<nearplanet->color<<endl;
            cout<<"Type: "<<nearplanet->type<<endl;
            cout<<"Distance from the sun: "<<nearplanet->distanceFromSun<<" Km"<<endl;
    }

}//output the closest planet with its information

//delete a node from the linked list
planetNode* SolarSystem::deleteNode(planetNode* head, string name2){
    planetNode *cursor;
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


//prints planets from biggest to smallest in terms of diameter length
void SolarSystem::printPlanetsBiggestToSmallest(){
    cout<<"Planets and Sun diameters listed \nfrom largest to smallest."<<endl; //removed "comapring planets..."
   // cout <<"Body  -     Diameter:"<< endl;
	cout.width(10);
	cout<<"Body"<<"   "<<"Diameter"<<"\n";
    //create a cursor node to traverse through list
    planetNode *cursor= new planetNode;

    //create a counter to count how many nodes are in the linked list
    int counter=0;
    for(cursor=head;cursor!=NULL;cursor=cursor->next)
    {
        counter++;
    }

    //create an Array with a size of the list
    int diameterArray[counter];

    //planetDiameter variable
    int planetDiameter=0;

    //make cursor be at the head of the list again
    cursor=head;
    //for loop to loop through the array
    for(int i=0; i<counter;i++)
    {
        //set planetDiameter equal to the diameter of the node
        planetDiameter=cursor->diameter;
        //put the diameter into the array
        diameterArray[i]=planetDiameter;
        //got to next node
        cursor=cursor->next;
    }
    //call the bubble sort function to sort the array from biggest to smallest
    Bubblesort(diameterArray,counter);

    //set cursor at the beginning of the list again
    cursor=head;
    //for loop to loop through array
    for(int j=0; j<counter;j++)
    {
        //for loop to loop through list
        for(cursor=head;cursor!=NULL;cursor=cursor->next)
        {
            //if diameter in node equals to diameter in Array print out the planet name and the diameter
            if(cursor->diameter==diameterArray[j] && cursor -> planetName != " ")
            {
				cout.width(10);
				cout<<cursor->planetName<<left<<"   " <<cursor->diameter<<" Km"<<"\n";

            }
        }
    }
    //std::cout.width(6); std::cout << std::right << n << '\n';

}//output the order of the planets from biggest to smallest in terms of diameter
//the function will out put the biggest to smallest planet like so: The Sun(diameter)->Jupiter(diameter) and so on until it hits Null

//add a planet to the solar system including the information of the planet.
planetNode* SolarSystem::addPlanet(string name, long long dist,string creator){
    //declaring a cursor traverse through the list
    planetNode *cursor=new planetNode;

    //declaring a new node to put the information of the new planet in
    planetNode *newPlanet=new planetNode;

    //coolFact to put in as a random fact for the new planet
    string coolFact= name+" was created by the great and powerful "+creator;
    cursor=head;
    //While distance the user inputed is less than the nodes distance from the sun
    //keep going until the user's distance is less than the nodes and thats where you will put the node
    while(dist>cursor->distanceFromSun)
    {
        cursor=cursor->next;
    }

    //the new planet is too close to another planet then ask the user for a new distance
    if(cursor->distanceFromSun-dist<2500000)
    {
        string newDistance;
        cout<<"Your planet will be too close to "<<cursor->planetName<<endl;
        cout<<"please choose a new distance thats a couple million few kilometers than your current distance:"<<endl; //jogo9225 changed wording for clarity
        getline(cin, newDistance);
        dist=stoll(newDistance);
    }
    else if(dist-cursor->previous->distanceFromSun<2500000)
    {
        string newDistance;
        cout<<"Your planet will be too close to "<<cursor->previous->planetName<<endl;
        cout<<"please choose a new distance thats a few million kilometers farther than that distance:"<<endl; //ibid
        getline(cin, newDistance);
        dist=stoll(newDistance);
    }

    //insert new node into its position
    planetNode *temp=cursor->previous;
    planetNode *temp2=cursor->previous->next;
    cursor->previous->next=newPlanet;
    cursor->previous=newPlanet;
    newPlanet->previous=temp;
    newPlanet->next=temp2;
    newPlanet->planetName=name; //insert planet name
    newPlanet->distanceFromSun=dist;//insert the new planets distance from the sun
    newPlanet->randomFact=coolFact;//insert random fact

    //Ask the user what color they want the planet to be
    string color;
    cout<<"What color do you want your planet?"<<endl;
    getline(cin, color);
    newPlanet->color=color;//insert color.

    //ask user how big the planet's diameter is going to be
    string diameter;
    cout<<"How big do you want you planet's diameter to be?"<<endl;
    getline(cin,diameter);
    newPlanet->diameter=stoi(diameter);//insert new planet's diameter

    //Calculating the average year length of the planet's that come before and after the new planet
    int avgYearLength= ((newPlanet->previous->lengthOfYear)+(newPlanet->next->lengthOfYear))/2;
    newPlanet->lengthOfYear=avgYearLength;//inserting the year length of the new planet

    //if the distance is less than the distance of the asteroid belt then the planet will be a terrestrial planet
    if(dist<450000000)
    {
        newPlanet->type="Terrestrial planet";//insert new planet's type
        cout<<newPlanet->planetName<<" will be a Terrestrial planet because you put it before the asteroid belt"<<endl;
    }else if(45000000<dist && dist<1700000000){//if new planet's distance is greater than the asteroid belt  but less than the of  Saturn then it will be a Gas giant
        newPlanet->type="Gas Giant";
        cout<<newPlanet->planetName<<" will be a Gas Giant because you put it after the asteroid belt"<<endl;
    }else {//else its greater than Saturn distance from the sun and it will be a Gas Giant
        newPlanet->type="Ice Giant";
        cout<<newPlanet->planetName<<" will be an Ice Giant because you put it after the asteroid belt and after Saturn"<<endl;
    }
    return head;
}//after you put in your planet into the solar system, you can print the solar system and see your planet there

//The purpose of the function sort the diameter array of the planets
void SolarSystem::Bubblesort(int * array, int sizeArray){
    int swap;
    for(int c = 0; c < sizeArray - 1; c++){
        for(int d = 0; d < sizeArray - c - 1; d++){
            if(array[d] < array[d+1]){
                swap = array[d];
                array[d] = array[d+1];
                array[d+1] = swap;
            }
        }
    }
    //cout<<"sorted list, ascending order:"<<endl;
    for(int c = 0; c < sizeArray; c++){
       //cout<<array[c]<<endl; //removed by jogo9225
    }
}//output the order of some number


//function to convert the length of they year of a planet from Earth days to Earth years
int SolarSystem::convertFromDaysToYears(string name)
{
    planetNode *foundPlanet=new planetNode;
    foundPlanet=searchPlanet(name);
    if(foundPlanet == NULL){
        cout<<"Please try again"<<endl;
        return 0; //changed from NULL to 0 by jogo9225
    }
    double earthDays=foundPlanet->lengthOfYear;
    double earthYears=earthDays/365;
    cout<<foundPlanet->planetName<<"'s year length is: "<<earthYears<<" Earth years."<<endl;
    return 0;
}
//The output should be the year length of a planet in Earth years
