
/*! \class Network
 * 	\brief The class Network contains a neuronal network that consists of indivuals of the class Neuro.
 * 	\details Netwrok initializes the network and the connections between individual neurons.
 *  \details Network starts the simulation
*/



#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>
#include <iostream>
#include <random>
#include <map>
#include "neuro.hpp"


using namespace std;

class Network
{
	public:
		#ifdef TEST
		FRIEND_TEST(Network_test, initializeNetwork);
		FRIEND_TEST(networktest, reset);
		FRIEND_TEST(networktest, numberOfConnections);


		#endif
	
	int tstop=10000;
	int tstart=0;
	int a=0;
	int b=4000;
	/*! \brief Constructor
	 *  \details Initializes the network.
	 * @param long time
	 */
	Network(long t);
	
	/*! \brief initializes the network of neurons
	 *  \details creates the neurons with the constants we have i.e 20% inhibitory and 80% excitatory
	 * it also generates the connetion between neurons according to uniform random distribution
	 */
	 
	 
<<<<<<< HEAD
	 static double Noise() {
        std::random_device dev;
        std::mt19937 generator(dev());

        std::poisson_distribution<> poisson(vext);
        int spikes_number=poisson(generator);
        return J_E*spikes_number;
=======
	 static double Noise() 
	 {
    std::random_device dev;
    std::mt19937 generator(dev());
    std::poisson_distribution<> poisson(vext);
	int spikes_number=poisson(generator);
	return J_E*spikes_number;
	
>>>>>>> e4f948a425391dec84f5b7e9c853f657d3883dd8
	 }
	
	void initializeNetwork();
	
	/*! \brief starts the simulation of the network of neurons
	 */
	
	void simulation();
	 /*! \brief resets the network of neurons
	 *  \details deletes the neurons and desallocates the memory
	 */
	 
	void reset();
	
	 /*! \brief neurons in the network */
    std::vector<Neuro*> NeuronesNetwork;
	
	/*! \brief Destructor */
	~Network();
	
	private:
	
	/*! \brief mumber of neurons in the network */

	unsigned int numberOfNeurons;
	
	/*! \brief global time of the simulation */

	long globalsimulationclock;

};
#endif 

