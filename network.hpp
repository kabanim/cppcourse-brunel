
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
		FRIEND_TEST(networktest, NeuronsType);

		#endif
	

	
	/*! \brief Constructor
	 *  \details Initializes the network.
	 * @param long time
	 */
	Network(long t);//,double,double);
	
	
	
	
   /*! \brief initializes the network of neurons
	*  \details creates the neurons with the constants we have i.e 20% inhibitory and 80% excitatory
	* it also generates the connetion between neurons according to uniform random distribution
	*/

static double Noise() {
	static std::random_device dev;
	static std::mt19937 generator(dev());
	static std::poisson_distribution<> poisson(vext);
	int spikes_number=poisson(generator);
	return J_E*spikes_number;
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

	unsigned int numberOfNeurons_;
	
	/*! \brief global time of the simulation */

	long globalsimulationclock_;
	
	///*!firing rate of the poisson distribution lamba */
	//static double vext_;

	/*!relative strength of the inhibitory synapses*/
	//double g_;
	
	/*!the post synaptic potential of inhibitory */
  //  double J_I=- g_*J_E;

};
#endif 
