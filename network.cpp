#include "network.hpp"

Network::Network(long t):numberOfNeurons(12500),globalsimulationclock(0) {

    for (int i(0); i<C_E*numberOfNeurons; ++i) {
		NeuronesNetwork.push_back(new Neuro(J_E));
	}

    for (int i(C_E*numberOfNeurons); i<numberOfNeurons; ++i) {
				
		NeuronesNetwork.push_back(new Neuro (J_I));	
	}

}

void Network::initializeNetwork() {
	std::random_device dev;
	std::mt19937 generator(dev());
	std::uniform_int_distribution<> distribution(0,numberOfNeurons-1);

    for (auto& n: NeuronesNetwork) 	{

         for (int i (0); i< 0.1*numberOfNeurons; ++i) {
             Neuro* neighbor = NeuronesNetwork[distribution(generator)];
             neighbor->synapses.push_back(n);
		 }
	}	 
}

void Network::simulation() {

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
