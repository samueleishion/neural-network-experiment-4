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

typedef std::_Rb_tree_iterator<std::pair<const std::basic_string<char, std::char_traits<char>, std::allocator<char> >, Cognit> > entry; 


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

string Cognit::get_most_likely() {
	map<string, float> temp; 
	float highest = 0; 
	string likely; 
 
	for(map<string, int>::const_iterator it=destinations.begin(); it!=destinations.end(); ++it) {
		temp[it->first] = it->second * (random()%100)*0.01; 
		if(temp[it->first] > highest) {
			highest = temp[it->first]; 
			likely = it->first; 
		}
	}

	return likely; 
}


// ==============
// Neuron methods 
// ==============
void Neuron::connect(Neuron n) {
	axon.push_back(n); 
}

void Neuron::show_connections() {
	cout << "neuron " << id << " connections. " << endl << "\t"; 
	for(int i=0; i<axon.size(); i++) 
		cout << axon[i].id << ", "; 
	
	cout << endl; 
}

void Neuron::add_cognit(string in) {
	cout << "adding cognit " << in << "\n"; 

	if(!cognits.count(in)) {
		Cognit c(in); 

		// adding neurons in axon to possible cognit routes 
		// from the get-go. this model assumes no "physical" learning: 
		// meaning that the neural connections will not change. 
		for(vector<Neuron>::iterator i=axon.begin(); i!=axon.end(); ++i) {
			stringstream ss; 
			ss << ((Neuron) *i).id; 
			c.add_destination(ss.str(), 1); 
		}


		cognits.insert(outpair(in, c)); 
	} 
}

void Neuron::update_cognit(string in, string out, int value) {
	if(!cognits.count(in)) 
		add_cognit(in); 

	entry search = cognits.find(in); 
	if(search!=cognits.end()) 
		((Cognit) search->second).increment_destination(out); 
}

void Neuron::process(string cognit_trail, float input) { 
	float output = 0.0; 

	if(input>0) {
		subtotal += input*weight; 

		while(subtotal>threshold) {
			output = ((random()%3)+6)*0.1; // [0.6,0.8] 
			subtotal -= threshold; 
			send(cognit_trail, output); 
		}
	}
}

void Neuron::send(string cognit_trail, float output) {
	// cognits contains a map which keys are
	// a string corresponding to the cognit_trail 
	// and a value which is another map with keys 
	// output neuron and as value an int that 
	// corresponds to the amount of times 
	// this neuron has communicated with that neuron
	// (in the inner map key) given the cognit_trail. 
	
	stringstream ss; 
	ss << id; 
	string cognit_step = ss.str(); 

	if(!cognits.count(cognit_trail)) 
		add_cognit(cognit_trail); 
	
	entry search = cognits.find(cognit_trail); 
	string highest; 
	if(search!=cognits.end())
		highest = ((Cognit) search->second).get_most_likely(); 
	else return; 

	for(vector<Neuron>::iterator i=axon.begin(); i!=axon.end(); ++i) {
		stringstream ns; 
		ns << ((Neuron) *i).id; 
		if(ns.str()==highest) {
			ss << ns.str(); 
			((Neuron) *i).process(ss.str(), output); 
			break; 
		}
	}
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