#include "neuro.hpp"
<<<<<<< HEAD
#include "network.hpp"
#include <fstream>
using namespace std;
int main() {
	
    int a(0),b(4000);
    double Iext(1.01);
    double PotentialThreshold(20);
    int tstart(0);
    int tstop(10);

    Network N(0);

    N.initializeNetwork();
    cout<<"i am here 1"<<std::endl;
    N.simulation();
    cout<<"i am here 2"<<std::endl;

    return 0;
=======
#include "synapse.hpp"
#include "network.hpp"
#include <fstream>
using namespace std;
int main()
{
	
int a(0),b(4000);
double Iext(1.01);
double PotentialThreshold(20);
int tstart(0);
int tstop(10);


Network N(0);
N.initializeNetwork();
cout<<"i am here 1"<<std::endl;

N.simulation();

cout<<"i am here 2"<<std::endl;
/*
bool spike(false);
		
		long simtime(tstart);
		/*Neuro* neurone1= new Neuro();
		Neuro* neurone2=new Neuro();
		//vector<Neuro*> neurones{neurone1,neurone2};
		neurone1->add_synapse(neurone2);*/
	/*	ofstream file1,file2;
        file1.open ("MembranePotential.txt");
        file2.open ("MembranePotential2.txt");
		

 do
	{      /*  neurone1->setLocalTime(simtime);
			 neurone2->setLocalTime(simtime);
				//SIMULATION LOOP FOR ONE NEURON
				file1 << neurone1->getMembranePotential();
					file1<<" ";
					neurone1->setInputCurrent(Iext);
					if (neurone1->getMembranePotential()> PotentialThreshold)
						 {
							 neurone1->add_time_of_spike(simtime);
							 neurone1->setToRefactoryState();
						 }
					if (neurone1->isInRefractoryState())
					{
						neurone1->setMembranePotential(0.0);
					}
						else 
					if (simtime>=a and simtime<=b)	
					 spike=neurone1->update(simtime);
					else 
					   { neurone1->setInputCurrent(0.0);
						 neurone1->update(simtime);
							}*/
				//SIMULATION LOOP FOR THE POSTSYNP NEURONS		
				//APRES JE DOIS FAIRE POUR N NEURONES ICI Q UN SEUL EMETTEUR DE SIG 
			/*	for(auto& newconnection: neurone1->getSynapses())
				{
					// spike=neurone1.update(simtime);
					 if (spike==true)
					 {
						  newconnection->receive(simtime+D,J_E);
						  file2<< newconnection->getMembranePotential();
						  file2<<" ";
						}
					}
					simtime=simtime+h;
		} while (simtime<tstop);
		file1.close();
		file2.close();
			
cout<<"spike times for neurone 1"<<endl;
for (auto t: neurone1->getTimeOfSPike())
{
	cout<<t*hequals<<endl;
} 

cout<<"spike times for neurone 2"<<endl;

for (auto t: neurone2->getTimeOfSPike())
{
	cout<<t*hequals<<endl;
} 
*/

 return 0;
>>>>>>> e4f948a425391dec84f5b7e9c853f657d3883dd8
}
