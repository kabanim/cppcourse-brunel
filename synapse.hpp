class Neuro;
#ifndef SYNAPSE_HPP
#define SYNAPSE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "constants.hpp"
#include "neuro.hpp"

//#include "simulation.hpp"
using namespace std;

class Synapse
{
	public:
	Synapse(Neuro,Neuro);

	Neuro getEmitterNeuron() const;
	Neuro getReceiverNeuron() const;
	//void add_target(Neuro n);

	//vector<Neuro> get_targets(Neuro n) const;

	//void receive(long time, double potential);

	~Synapse();

	
	private:
	/*Neuro n1; //this is the neuron that emits the signal
	Neuro n2 ; //this is the neuron that receives the signal*/

};
#endif 

