/*
- @author: Samuel Acuna
- @date: 11/11/2014
- @project: Neural network experiment 4
			https://github.com/samueleishion/neural-network-experiment-4 
*/ 

#include <iostream> 
#include <string> 
#include <sstream>
#include <cstdlib> 
#include "utils.h" 
#include "bio.h"

// ==============
// Cognit methods 
// ==============
void Cognit::add_destination(string s, int i) {
	if(!destinations.count(s)) 
		destinations.insert(inpair(s,i)); 
}

void Cognit::increment_destination(string s) {
	if(destinations.count(s))
		destinations[s]++; 
}

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

void Neuron::add_cognit(string in, string out, int value) {
	if(!cognits.count(in)) {
		Cognit c(in); 
		c.add_destination(out, value); 
		cognits.insert(outpair(in, c)); 
	} 
}

void Neuron::process(string cognit_trail, float input) { 
	float output = 0.0; 

	if(input>0) {
		subtotal += input*weight; 

		while(subtotal>threshold) {
			output = ((random()%3)+6)%10; // [0.6,0.8] 
			subtotal -= threshold; 
			send(cognit_trail, output); 
		}
	}
}

void Neuron::send(string cognit_trail, float output) {
	stringstream ss; 
	ss << id; 
	string cognit_step = ss.str(); 
	if(cognits.count(cognit_trail)) {
		// insert trail in cognits 

	} 

	// pick pseudo random 

	add_cognit(cognit_trail, cognit_step, 1); 
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