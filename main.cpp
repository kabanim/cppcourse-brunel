#include "neuro.hpp"
#include "network.hpp"
#include <fstream>
using namespace std;
int main() {
	
    int a(0),b(4000);
    double Iext(1.01);
    double PotentialThreshold(20);
    int tstart(0);
    int tstop(10);

    Network N(0);

    N.initializeNetwork();
    cout<<"i am here 1"<<std::endl;
    N.simulation();
    cout<<"i am here 2"<<std::endl;

    return 0;

} 
