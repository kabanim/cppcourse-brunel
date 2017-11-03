#include "neuro.hpp"

using namespace std;

Neuro::Neuro (double potential) //std::vector<unsigned short int> const& synapses)
:MembranePotential(potential), NumberOfSpikes(0),localTime(0),inputcurrent(0),state(false),focus(false)//,S(0)
{
	ring_buffer.resize(D/hequals+1);
	
}

Neuro::Neuro (const Neuro& neurone)
:MembranePotential(neurone.MembranePotential)
{
}

double Neuro::getMembranePotential() const
{
	return MembranePotential;
}


unsigned int Neuro::getNumberOfSpikes() const
{
	return NumberOfSpikes;
}

std::vector<unsigned int> Neuro::getTimeOfSPike() const
{
	return TimeOfSpike;
}

bool Neuro::isInRefractoryState()
{

	if(TimeOfSpike.empty()) return false;
	
	return ((getLocalTime()*hequals-(TimeOfSpike[TimeOfSpike.size()-1])*hequals)<refrac); 
}
void Neuro::updatepotential(long time,double Iext, double S)

{   //am i really giving to t+h potential t

	double potential(getMembranePotential());
	setMembranePotential(exp(-h*hequals/tau_excitation)*potential+getInputCurrent()*(membrane_resistance)*(1-exp(-h*hequals/tau_excitation))+S); ///S sum of spikes at time t of amplitude S);
		
}
bool Neuro::update(unsigned long h)

{  	double S(0);
    ofstream file("spikes.txt", std::ios_base::app);
   
	std::random_device dev;
	std::mt19937 generator(dev());
	std::poisson_distribution<> poisson(C_E*total*vext*h);

/*	for( int i(0); i<synapses.size();++i)
   {
		///setMembranePotential(synapses[i]->getMembranePotential());
	///	S+=synapses[i]->getMembranePotential();
		///getMembranePotential(); ///only neurones connected receive spikes
		S+=i;
	} */
	
	S+=ring_buffer[localTime]+J_E*poisson(generator);
	 //I CHANGED HERE
	
	 //am i really giving to t+h potential t
	assert(time>= 0);
	if (time==0) return false;
	
	bool spike(false);
	if (MembranePotential>Vth) ///neuron spikes
	{
		
	   spike=true;
		//++S;
	   t_spike=localTime;
	   TimeOfSpike.push_back(t_spike);
	   file<<localTime<<"\t";
	   file<<S<<"\n";
	   
		}
	
	if((localTime-t_spike)<refrac) ///neuron is refractory
	   setMembranePotential(0.0);
    else 
	{
	    updatepotential((localTime+h),0.0,S); ///was times*hequls
	    	    
	}
	ring_buffer[localTime%(int(D/hequals)+1)]=0;
	localTime=localTime+1;
	S=0;
	file.close();

	return spike;
}

void Neuro::setMembranePotential(double potential)
{
	MembranePotential=potential;
}
long Neuro::getLocalTime() const
{
	return localTime;
}
void Neuro::setInputCurrent(double in)
{
	inputcurrent=in;
}
double Neuro::getInputCurrent() const
{
	return inputcurrent;
}

void Neuro::add_time_of_spike(long time)
{
	TimeOfSpike.push_back(time);
}
void Neuro::setLocalTime(long time)
{
	localTime=time;
}
void::Neuro::setToRefactoryState()
{
	setMembranePotential(Vr);
	state=true; //isrefractory
}
void Neuro::receive(unsigned long arrival, double J_E)
{
	/*double potential(getMembranePotential());*/
	
	setMembranePotential(exp(-h/tau_excitation)*MembranePotential+getInputCurrent()*(membrane_resistance)*(1-exp(-h/tau_excitation))+J_E);
	const size_t idx=arrival%(int((D/hequals)+1)); ///D over hequals give us effectively the number of steps delayed
	assert(idx<ring_buffer.size());
	ring_buffer[idx]+=J_E;
	
}

bool Neuro::focusedon() const
{
	
	return focus;
}

void Neuro::settofocusedon(bool focusedon)
{
	focus=focusedon;
	
}

/*vector<Neuro*> Neuro::getNetwork(const& Network net) 
{ return net.NeuronesNetwork;
}*/
/*
void Neuro::add_synapse(Neuro* receiver)
{
	synapses.push_back(receiver);
}
* /
/*
Neuro Neuro::getsynapse(int i)
{
	return synapses[i];
}
*/
/*
vector<Neuro*> Neuro::getSynapses() const
{
	if (synapses.size()!=0)
	return synapses;
}
*/
Neuro::~Neuro() 
{
	
}
