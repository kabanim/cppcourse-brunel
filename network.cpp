#include "network.hpp"

Network::Network(long t):numberOfNeurons(12500),globalsimulationclock(0) {

    for (int i(0); i<C_E*numberOfNeurons; ++i) {
		NeuronesNetwork.push_back(new Neuro(J_E));
	}

<<<<<<< HEAD
    for (int i(C_E*numberOfNeurons); i<numberOfNeurons; ++i) {
=======
    for (int i(C_E*numberOfNeurons); i<numberOfNeurons; ++i)	{
>>>>>>> e4f948a425391dec84f5b7e9c853f657d3883dd8
		NeuronesNetwork.push_back(new Neuro (J_I));	
	}

    cout<<NeuronesNetwork.size()<<endl;
}

void Network::initializeNetwork() {
	std::random_device dev;
	std::mt19937 generator(dev());
	std::uniform_int_distribution<> distribution(0,numberOfNeurons-1);

<<<<<<< HEAD
    for (auto& n: NeuronesNetwork) 	{
=======
	for (auto& n: NeuronesNetwork)
	{
>>>>>>> e4f948a425391dec84f5b7e9c853f657d3883dd8
         for (int i (0); i< 0.1*numberOfNeurons; ++i) {
             Neuro* neighbor = NeuronesNetwork[distribution(generator)];
             neighbor->synapses.push_back(n);
		 }
	}	 
}

void Network::simulation() {
<<<<<<< HEAD

    do {
        for( auto& n:NeuronesNetwork) {
            bool spike(n->update(1));
            if (spike) {
                for(unsigned int i(0); i<n->synapses.size();++i) {
                    n->synapses[i]->receive(globalsimulationclock+D/hequals, n->getMembranePotential());
                }
            }
        }
        globalsimulationclock=globalsimulationclock+1;
      } while(globalsimulationclock<10000);

    cout<<"Start writing the spikes"<<endl;
    ofstream file("spikes.txt");
    for(int i (0); i<numberOfNeurons; ++i) {
        //Write stuff at the end
        for(auto& t:NeuronesNetwork[i]->getTimeOfSPike()) {
           file<<t<<"\t"<<i<<"\n";
        }
    }
=======
   /* std::random_device dev;
    std::mt19937 generator(dev());
    std::poisson_distribution<> poisson(vext); //ici j'ai changé c'etait hequals *vext*/
    ofstream file("spikes.txt");

    do {
        double S(0);
        for( auto& n:NeuronesNetwork) {

           /* double external = poisson(generator);
           n->receive(globalsimulationclock +D/hequals, J_E * external);*/
          // S=J_E*external;

            bool spike(n->update(1));
            if (spike) {
                S++;
                for(unsigned int i(0); i<n->synapses.size();++i) {
                    n->synapses[i]->receive(globalsimulationclock+D/hequals, n->J);
                }
                n->setMembranePotential(0);
            }
        }
        file<<globalsimulationclock<<"\t"<<S<<"\n";
        globalsimulationclock=globalsimulationclock+1;

      } while(globalsimulationclock<1000);
>>>>>>> e4f948a425391dec84f5b7e9c853f657d3883dd8
    file.close();
}

void Network::reset() {
    for (auto& neuron : NeuronesNetwork){
		delete neuron;
		neuron = nullptr;
	 }
	NeuronesNetwork.clear();
}

Network::~Network(){
	reset();
	}
