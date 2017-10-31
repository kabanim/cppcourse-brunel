#include "network.hpp"

Network::Network(long t)
:numberOfNeurons(12500),globalsimulationclock(0)
{
	for (int i(0);i<C_E*numberOfNeurons;++i)
	{
		NeuronesNetwork.push_back(new Neuro(J_E));
		
	}
	for (int i(C_E*numberOfNeurons);i<numberOfNeurons;++i)
	{
		NeuronesNetwork.push_back(new Neuro (J_I));	
	}
	/*for(const auto& pair :mynetwork)
	
	{  pair.second=NeuronesNetwork;
			
		}*/

}

void Network::initializeNetwork()
{
	///maybe add an assertion here to check the initialization

	///Here, we initialize the network by initializing the inihibitory neurons 
	/// then we initialize the excitatory neurons and finally the random background noise
	

	//std::vector<unsigned short int> connections;
	std::random_device dev;
	std::mt19937 generator(dev());
	///To generate the connections we need unifromly distributed random numbers
	std::uniform_int_distribution<> distribution(0,numberOfNeurons-1);
	///assert();
/*	std::uniform_int_distribution<> p(0,100); ///when p is 10 it is 0,1 probability
	std::uniform_int_distribution<> p_CI(0, 0.1*numberOfNeurons * C_I);
	std::uniform_int_distribution<> p_CE(0, 0.1*numberOfNeurons * C_E); */

	for (auto& n: NeuronesNetwork)
	{
		 std::vector<Neuro*> synapses;
		 for (int i (0); i< 0.1*numberOfNeurons; ++i)
		 {
			 synapses.push_back(NeuronesNetwork[distribution(generator)]);
		 }
		n->synapses=synapses;	
	
	}
			 

/*
	
	unsigned int numberInhibitory(numberOfNeurons * C_I);
	
	for ( unsigned int i(0); i < numberInhibitory; ++i)
	 {

		for (unsigned int j(0); j < numberOfNeurons ; ++j) {
			

			if (p(generator)==10) ///and (j != i)) { /// A neuron does not create a connection with itself
				connections.push_back(j);
			}
		}

		NeuronesNetwork.push_back(new Neuro(J_I,connections));

		connections.clear();
	}
	
	

	/// STEP 2: INITIALIZATION OF EXCITATORY NEURONS
	
    unsigned int numberExcitatory(numberOfNeurons * C_E);

	for (unsigned int i(0) ; i < numberExcitatory ; ++i) {

		for(unsigned int j(0); j < numberOfNeurons ; ++j) {

			if (distribution(generator) and (j != i)) { /// A neuron does not create a connection with itself
				connections.push_back(j);
			}
		}

		NeuronesNetwork.push_back(new Neuro(J_E, connections));

		connections.clear();
		
	}
*/
	
}
void Network::simulation()
{  
	
	do {
		
	 for( auto& n:NeuronesNetwork)
		{
			bool spike(n->update(1));

			if (spike)
			{
				for(unsigned int i(0); i<n->synapses.size();++i)
				{
					
					n->synapses[i]->receive(globalsimulationclock+D,NeuronesNetwork[i]->getMembranePotential()); ///only neurones connected receive spikes
				}
				
			}
		}
	    globalsimulationclock=globalsimulationclock+1;
	    
	  
	    /*
	    for (unsigned int i (0);i< NeuronesNetwork.size();++i)
	    {
			bool spike(NeuronesNetwork[i]->update(1));

			if (spike)
			{
				
				
				switch i:
				{
					NeuronesNetwork[i]->synapses[i]->receive(globalsimulationclock+D,J_E);
					
				}
					else 
					{
					NeuronesNetwork[i]->synapses[i]->receive(globalsimulationclock+D,J_I);
					cout<<"segfault";
						}	
				}
		
		}
		globalsimulationclock=globalsimulationclock+1;
		*/
		} while(globalsimulationclock<20) ;
	
	
}

/*
void Network::random50neurons() {
	
	
	int count(0);
	int n(0);
	/// choose 50 random neurons and let them know they are observed
	do{
		count = distribution(generator);
		if (!NeuronesNetwork[count]->focusedon()){
				neurons_[count]->settofocusedon(true);cd
				++n;
		}

	} while (n < 50);
}*/
///delete the Network

void Network::reset()
{

	for (auto& neuron : NeuronesNetwork) 
	{
		delete neuron;
		neuron = nullptr;
	 }
	NeuronesNetwork.clear();
}

Network::~Network()
{}
