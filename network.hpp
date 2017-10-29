#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>
#include <iostream>
#include <random>
#include "neuro.hpp"

using namespace std;

class Network
{
	public:
	int tstop=10000;
	int tstart=0;
	int a=0;
	int b=4000;
	Network(long t);
	void updateneurons();
	void reset();
	void initializeNetwork();
	void random50neurons();
	void simulation();
	std::vector<Neuro*> NeuronesNetwork;
	~Network();
	
	private:
	
	
	unsigned int numberOfNeurons;
	long globalsimulationclock;

};
#endif 

