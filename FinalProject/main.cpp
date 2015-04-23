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
        cout<<"6.Quit"<<endl;
        cin>>selection;
        cin.ignore(1, '\n');
        if(selection[0]=='1'){

        }
        if(selection[0]=='2'){


        }
        if(selection[0]=='3'){

        }
        if(selection[0]=='4'){


        }
        if (selection[0]=='5'){

        }
        if(selection[0]== '6'){

            cout<<"Goodbye!"<<endl;
            //delete;
            break;
        }

        }
        return 0;

}
