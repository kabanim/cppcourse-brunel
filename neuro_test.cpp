#include <vector>
#include <iostream>

#include "gtest/include/gtest/gtest.h"
#include "../network.hpp"
#include "../neuro.hpp"
#include "../constants.hpp"






TEST(networktest, initializeNetwork) {
	Network n(0,2,3);
	EXPECT_EQ(12500,n.NeuronesNetwork.size());
	
}

TEST(networktest, NeuronsType) {
	Network n(0,2,3);
	size_t j(0), k(0);
	for(size_t i(0); i < total; ++i) 
	{
		
		if (n.NeuronesNetwork[i]->getMembranePotential()> 0.0) ++j;
		if (n.NeuronesNetwork[i]->getMembranePotential()< 0.0) ++k;
	}
		
		EXPECT_EQ(10000,j);
		EXPECT_EQ(2500,k);
	}


TEST(networktest, reset) {
	Network n(0,2,3);
	n.reset();
	EXPECT_EQ(0, n.NeuronesNetwork.size());
}



TEST(neuronetest, refactory) {
	Neuro n1(0);
	n1.setMembranePotential(20.1);
	n1.update(1);
	EXPECT_EQ(n1.isInRefractoryState(),true);
	
}
TEST(neuronetest, activateNeuron) {
	
	Neuro neuron(0);	
	neuron.MembranePotential = 20.0;
	EXPECT_EQ(neuron.MembranePotential, Vth);
	
	neuron.MembranePotential = 19.9999;
	EXPECT_LT(neuron.MembranePotential, Vth);
	
	neuron.MembranePotential = -1.00;
	EXPECT_LT(neuron.MembranePotential, Vth);
	
	neuron.MembranePotential = 100.00;
	EXPECT_GT (neuron.MembranePotential, Vth);
	
}
TEST(neuronetest, update) {
	Neuro n1(0);
	n1.setMembranePotential(20.1);
	EXPECT_EQ(n1.update(1),true);
	
}

TEST(networktest, numberOfConnections)
{

	Network n(0,2,3,100);
	n.initializeNetwork();
	std::vector <unsigned int> connections (100,0);
	for (unsigned int i(0); i<connectionProbability*100;++i) ///we test with 100 neurons
	{
		for (unsigned j(0); j< n.NeuronesNetwork[i]->synapses.size();++j)
		{
			
			++connections[j];
		}
	}
	
	EXPECT_EQ(connections[0],10);
}


int main(int argc, char **argv) { 
	
	

	
	::testing::InitGoogleTest(&argc, argv); 
	return RUN_ALL_TESTS();
}


