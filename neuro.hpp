 //class Synapse;
class Network; ///prdeclartion of class
#ifndef NEURO_HPP
#define NEURO_HPP
#include <iostream>
#include <vector>
#include <cmath>
#include "constants.hpp"
#include <cassert>
#include <random>



using namespace std;
class Neuro
{
	public:
	
	Neuro(double MembranePotential);/*, std::vector<unsigned short int> const& synapses/*std::vector<unsigned int>const& synapses*///)
	Neuro(const Neuro&);
	double getMembranePotential() const;
	unsigned int getNumberOfSpikes() const;
	std::vector<unsigned int> getTimeOfSPike() const;
	bool isInRefractoryState();
	void setToRefactoryState();
	bool update(unsigned long);
	void updatepotential(long time,double Iext, double S);
	void setMembranePotential(double);
	long getLocalTime() const;
	void setInputCurrent(double);
	double getInputCurrent() const;
	void add_time_of_spike(long);
	void setLocalTime(long);
	void receive(unsigned long arrival, double potential);
	//vector<Neuro*> getNetwork(const& Network) ;
	//void add_synapse(Neuro*);
	/*Neuro getsynapse(int i); */
	//vector<Neuro*> getSynapses() const;
	bool state;
	/*! \brief Getter for whether the neuron is chosen*/
	bool focusedon() const;

	/*! \brief Setter for whether the neuron is observed */
	void settofocusedon(bool focusedon);
	vector<Neuro*> synapses;
	//std::vector<unsigned short int> synapses;
	~Neuro();
	
	private:
	//vector<Neuro> synapses;
	double MembranePotential;
	unsigned int NumberOfSpikes;
	std::vector<double> ring_buffer;
	
	
	/// we use a vector where we stock each value of "pas de temps" where a recorded a spike 
	std::vector<unsigned int> TimeOfSpike;
	long localTime;
	bool focus;
	double inputcurrent;
	double t_spike;
	double S; ///sum of spikes at time t
	///false i.e is not in refractory state 
	
	
};
#endif 
