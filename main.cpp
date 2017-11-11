#include "neuro.hpp"
#include "network.hpp"
#include <fstream>
using namespace std;
char c;


int main() 
{
	
	do 
	{
	   
	   cout<<"Which Brunel network do you want to simulate A,B,C or D (as specified in figure 8"<<endl;
	   cin>> c;
	}	
   while((c<'A' or c>'D') ); 
   
     
     switch (c)
     {
		case 'A':
		{
			cout<<"Running A..."<<endl;
			
			
	   Network net(0,2,3);
       net.initializeNetwork();
       net.simulation();
       cout<<"Simulation completed"<<endl;

       
		break;
		}
		case 'B':
		{
		cout<<"Running B..."<<endl;
	   Network net(0,4,6);
       net.initializeNetwork();
       net.simulation();
       cout<<"Simulation completed"<<endl;

		break;	
		}
		case 'C':
		{
		cout<<"Running C..."<<endl;
	   Network net(0,2,5);
       net.initializeNetwork();
       net.simulation();
       cout<<"Simulation completed"<<endl;

		break;			
		}
		case 'D': 
		{
		cout<<"Running D..."<<endl;
	   Network net(0,0.9,4.5);
       net.initializeNetwork();
       net.simulation();
       cout<<"Simulation completed"<<endl;

		break;			
		}
		 
		 
	 }
   
    

    return 0;

} 
