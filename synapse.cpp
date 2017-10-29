#include "synapse.hpp"


Synapse::Synapse(Neuro n1, Neuro n2)
{
	
	/*for (auto n:targets)
	
		{
			add_target(n);
		}*/
	//n2.setMembranePotential(exp(-h/tau_excitation)*n2.potential+n2.getInputCurrent()*(membrane_resistance)*(1-exp(-h/tau_excitation))+J);
}
/*
void Synapse::add_target(Neuro n)
{

 targets.push_back(n);

}
vector<Neuro> Synapse::get_targets(Neuro n) const
{
	return targets;
	
}
*/
/*
Neuro Synapse::getEmitterNeuron() const
{
	return n1;
}
Neuro Synapse::getReceiverNeuron() const
{
	return n2;
}
* */
/*
void Synapse::receive(long time, double )
{
	for(auto n :targets)
	{
		double potential(n.getMembranePotential());
	n.setMembranePotential(exp(-h/tau_excitation)*potential+n.getInputCurrent()*(membrane_resistance)*(1-exp(-h/tau_excitation))+J_E);
	}	
}
 */
Synapse::~Synapse()
{}
