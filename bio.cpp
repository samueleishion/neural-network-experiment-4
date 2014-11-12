#include "bio.h"


// ==============
// Neuron methods 
// ==============
void Neuron::connect(Neuron n) {
	axon.push_back(n); 
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
	// @TODO 
	return; 
}


// ===============
// Network methods 
// ===============
int Network::organ_count() {
	return organs.size(); 
}

void Network::add_organ(Organ o) {
	// @TODO 
	return; 
}