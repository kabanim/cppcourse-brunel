#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

///tau=RC in ms
double const tau_excitation = 20;
///V threshold
double const Vth=20;
///tau decharge in ms
double const tau_rp=2;
///V resetpotentiel de la membrane in mV
double const Vr=0;
///firing threshold in mV
double const teta=20;
///membrane resistance
double const membrane_resistance=20;
///relative strength of the inhibitory synapses
double const g=5; // J_E/J_I
///the connection probability in the network of neurons
double const connectionProbability=0.1;
/*///the frequency of the external input in mV
double const vext=1;
*/
///refractory time of one 1 ms
int const refrac=2;
///the EPSP amplitude in mV
//double const J_E=10;  //EXCITATORY
//double const J_I=2;  //INHIBITORY
///the post synaptic potential
double const J_E=0.1;
///the post synaptic potential
double const J_I=0.5;
///the delay of transmission in ms
double const D=1.5;
///the number of recurrent excitatory connections (equals also the number of connections from outside the network
double const C_E=0.8; 
///Proportion of inhibitory neurons
double const C_I=0.2;
///firing rate poisson lamba
int const vext=2;
///total number of neurons
int const total=12500;

/// simulation step
long const h=1; 
///h equals 0,1ms
double const hequals=0.1;

#endif 
