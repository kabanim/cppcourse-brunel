/*! \class Neuro
 *
 *  \brief The class Neuro receives input from other neurons in the network, it stores the neurones it has a connection with
 *
 *  \details Neuro calculates its potential according to the equations presented by the Brunel paper (2000).
 *  \details Neuro has a method receive that saves the potential received from the neurons in the network/the background noise
 *  \details Neuro stores the time of the spikes occured in a vector, it also stores the potential in a buffer until they are received after a delay D
 * 
 */
class Network; ///prdeclartion of class for circular dependance


#ifndef NEURO_HPP
#define NEURO_HPP
				#ifdef TEST
				#include <gtest/gtest.h>
				#endif
#include <iostream>
#include <vector>
#include <cmath>
#include "constants.hpp"
#include <cassert>
#include <random>
#include <fstream>


using namespace std;
class Neuro
{
	public:
	 #ifdef TEST
		FRIEND_TEST(neuronetest, activate_neuron);
	  #endif

	

		/*! \brief Constructor
		 *  \details Initializes a Neuron.
		 */
    Neuro(double MembranePotential);

    /*! \brief Constructor of copy
     * 
     */
	Neuro(const Neuro&);
	
	/*! \brief Destructor */
	~Neuro();
   /*! \brief Returns the potentiel a given neuron 
    * @return double
    */
	double getMembranePotential() const;
	/*! \brief Returns the number of spikes a given neuron 
	 * @return unsigned int
	 */
	unsigned int getNumberOfSpikes() const;
	
	/*! \brief Returns the spikes times a given neuron 
	 * @return vector of unsigned int
	 */
	 
	std::vector<unsigned int> getTimeOfSPike() const;
	
	/*! \brief checks whether a given neuron is in refractory period
	 * @return bool
	 */
	 
	bool isInRefractoryState();
	
	/*! \brief sets a given neuron to refractory
	 *
	 */
	void setToRefactoryState();
	
	/*! \brief updates a given neuron in the simulation
		 * 	\details if the potential of a given neuron is superior to the threshold it spikes
		 *   if the last time of spike is more recent than the refractory time the neuron potential is set to zero
		 *   if it is not the case we update the potential of the given tohold and reset value in the ring buffer at that time to zero
		 *  @param unsigned long the time step of the simulation
		 *  @return bool: neuron spiked or not 
		 */
	 
	bool update(unsigned long);
	
	/*! \brief updates the potential a given neuron in the simulation
		 *  @param long: time of the simulation, double: exterior current which zero in the case of a network, double: S which is the sum of spikes
		 * 
		 */
	void updatepotential(long time,double Iext, double S);
	
	/*! \brief sets the potential a given neuron in the simulation
		 *  @param double: the potential value to set to 
		 */
	void setMembranePotential(double);
	/*! \brief gets the local time of a given neuron in the simulation
		 *  @return long
		 */
	long getLocalTime() const;
	
		/*! \brief gets the local time of a given neuron in the simulation
		 *  @return long
		 */
	void setLocalTime(long);

	/*! \brief sets the local time to t of a given neuron in the simulation
	 *  @param long
	 */
	 
	void setInputCurrent(double);
	
	/*! \brief gets the input current a given neuron in the simulation
	 *   \details irrelevent in a neural netwok i ext always zero
	 *  @return double 
	 */
	double getInputCurrent() const;

	
	/*! \brief stockes the potential and the time of arrival of spike to a given neuron
	 *  @return unsigned long, double 
	 */
	void receive(unsigned long arrival, double potential);
	
	/*! \brief state is not refractory by default
	 */
	bool state;
	/*! \brief Getter for whether the neuron is chosen*/
	bool focusedon() const;
	/*! \brief Setter for whether the neuron is observed 
	 * @param :bool 
	 */
	
	void settofocusedon(bool focusedon);
	
	/*! \brief vector of pointers on neurons 
	 *  \details the neurons to which a given neuron are connected are stocked here
	 */
	vector<Neuro*> synapses;


	
	private:
	/*! \brief the potential of a given neuron
	 */
	double MembranePotential;
	/*! \brief the number of spikes of a given neuron
	 */
	unsigned int NumberOfSpikes;
	
	/*! \brief buffer where the spikes are stocked until received by the given neuron
	 */
	std::vector<double> ring_buffer;
	
	/*! \brief a vector where we stock all the spikes times of a given neuron
	 */
	std::vector<unsigned int> TimeOfSpike;
	/*! \brief long local time of a given neuron
	 */
	long localTime;
	/*! \brief poisson distribution
	 */
	std::poisson_distribution<> poisson;
	bool focus;
	/*! \brief input current of a given neuron
	 *  \details irrelavent in a neural simulation
	 */
	double inputcurrent;
	
	/*! \brief last time of spike
	 */
	double t_spike;
	
	
};
#endif 
