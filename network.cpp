#include "network.hpp"

double Network::vext_;

Network::Network(long t,double vext, double g)
:globalsimulationclock_(0),g_(g),J_I(-g_*J_E)
{
	vext_=vext;
	setNumberOfNeurons(12500);
   for (int i(0); i<C_E*numberOfNeurons_; ++i) {
		NeuronesNetwork.push_back(new Neuro(J_E));
	}

    for (int i(C_E*numberOfNeurons_); i<numberOfNeurons_; ++i) {
				
		NeuronesNetwork.push_back(new Neuro (J_I));	
	}

}

Network::Network(long t,double vext, double g, unsigned int number)
:globalsimulationclock_(0),g_(g),J_I(-g_*J_E)
{
	vext_=vext;
	setNumberOfNeurons(number);
   for (int i(0); i<C_E*numberOfNeurons_; ++i) {
		NeuronesNetwork.push_back(new Neuro(J_E));
	}

    for (int i(C_E*numberOfNeurons_); i<numberOfNeurons_; ++i) {
				
		NeuronesNetwork.push_back(new Neuro (J_I));	
	}

}
void Network::setNumberOfNeurons(unsigned int number)
{
	numberOfNeurons_=number;
	
}

void Network::initializeNetwork() {
	 static std::random_device dev;
	 static std::mt19937 generator(dev());
	 static std::uniform_int_distribution<> distribution(0,numberOfNeurons_-1);
	 
    for (auto& n: NeuronesNetwork) 	
    {

         for (int i (0); i< 0.1*numberOfNeurons_; ++i) 
         {
             Neuro* neighbor = NeuronesNetwork[distribution(generator)];
             neighbor->synapses.push_back(n);
		 }
	}	 
}

void Network::simulation() {

     do {
       
       for (size_t neuron_id(0);neuron_id<NeuronesNetwork.size();++neuron_id)
		{	
      bool spike(NeuronesNetwork[neuron_id]->update(1));
            if (spike) 
				{
					for(unsigned int i(0); i<NeuronesNetwork[neuron_id]->synapses.size();++i) 
                {
                    NeuronesNetwork[neuron_id]->synapses[i]->receive(globalsimulationclock_+ D/hequals, NeuronesNetwork[neuron_id]->getMembranePotential());
                }
                
            }
        }
         
      
        globalsimulationclock_=globalsimulationclock_+1;
      } while(globalsimulationclock_<10000);

    cout<<"Start writing the spikes"<<endl;
    ofstream file("../spikes.txt");
    for(int i (0); i<numberOfNeurons_; ++i) {
        for(auto& n:NeuronesNetwork[i]->getTimeOfSPike()) {
           file<<n<<"\t"<<i<<"\n";
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
