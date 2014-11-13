#include <iostream> 
#include <string> 
#include <cstdlib> 
#include "utils.h" 
#include "bio.h"


// ==============
// Neuron methods 
// ==============
void Neuron::connect(Neuron n) {
	axon.push_back(n); 
}

void Neuron::show_connections() {
	cout << "neuron " << id << " connections. " << endl << "\t"; 
	for(int i=0; i<axon.size(); i++) {
		cout << axon[i].id << ", "; 
	}
	cout << endl; 
}

// =============
// Organ methods
// =============
void Organ::add_neuron(Neuron n) {
	neurons.push_back(n); 
}

int Organ::neuron_count() {
	return neurons.size(); 
}

void Organ::connect(Organ p) {
	for(int i=0; i<neurons.size(); i++) {
		for(int j=0; j<p.neurons.size(); j++) {
			int r = random()%10;
			if(r >= 4) {
				neurons[i].connect(p.neurons[j]); 
			}
		} 
	}
}

void Organ::show_connections() {
	for(int i=0; i<neurons.size(); i++) {
		neurons[i].show_connections(); 
	}
}


// ===============
// Network methods 
// ===============
int Network::organ_count() {
	return organs.size(); 
}

void Network::add_organ(Organ o) {
	organs.push_back(o); 
}