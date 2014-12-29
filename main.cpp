/*
- @author: Samuel Acuna
- @date: 11/11/2014
- @project: Neural network experiment 4
			https://github.com/samueleishion/neural-network-experiment-4 
*/ 

#include <iostream> 
#include <string> 
#include "bio.h"
#include "utils.h"

using namespace std; 

int main() {

	Network n(1); 

	Organ o(1, "right_hand"); 
	Organ p(2, "left_hand"); 

	Neuron a(SENSORY, 1, 0.25);
	Neuron b(SENSORY, 2, 0.45);  
	Neuron c(SENSORY, 3, 0.65); 
	Neuron d(SENSORY, 4, 0.75); 
	Neuron e(TERMINAL, 5, 0); 
	Neuron f(TERMINAL, 6, 0); 

	n.add_organ(o); 
	n.add_organ(p); 

	o.add_neuron(a); 
	o.add_neuron(b); 
	o.add_neuron(e); 

	p.add_neuron(c); 
	p.add_neuron(d); 
	p.add_neuron(f); 

	o.connect(p); 

	a.add_cognit("asdf"); 
	a.update_cognit("asdf","3",1); 
	a.add_cognit("asdf"); 
	a.update_cognit("asdf","3",1); 
	// a.add_cognit("asdf","3",1); 
	// a.add_cognit("asdf","3",1); 

	cout << "hello brain with " << n.organ_count() << " organs!" << endl; 
	cout << "  " << o.name << " has " << o.neuron_count() << " neurons." << endl; 
	cout << "  " << p.name << " has " << p.neuron_count() << " neurons." << endl; 

	o.show_connections(); 
}