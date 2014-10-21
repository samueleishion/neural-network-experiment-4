/*
 -	@author: Samuel Acuna 
 -	@date: 10/20/2014 
 -	@project: Neural Network Experiment 4 
*/
#include "utils.h" 

#ifndef BIO_H_
#define BIO_H_ 

#define THRESHOLD 0.5 
#define LEARNING_RATE 0.2 
#define LIFE_SPAN 20 

#define SENSORY 0
#define TRANSMITTER 1
#define TERMINAL 2 
#define MOTOR 3 

int nid = 0; 

// ==================
// 		NEURON   
// ==================
typedef struct neuron neuron; 
struct neuron { 
	int type; 
	int id; 
	int th; // threshold 
	int lr; // learning rate 
	float weight; // weight value axon 
	neuron *axon[2000]; // connection to other neurons 
	float sub; // subtotal value of sensor and weight 
	int body; 
}; 

neuron *neuron_create(int type, int id, float weight) { 
	struct neuron *n = TYPED_MALLOC(neuron); 
	n->type = type; 
	n->id = id; 
	n->weight = weight; 
	n->th = THRESHOLD; 
	n->lr = LEARNING_RATE; 
	n->sub = 0.0; 
	return n; 
} 


// ==================
// 		ORGAN  
// ==================
typedef struct organ organ; 
struct organ { 
	int id; 
	neuron *neurons[2000]; // set of neurons 
	int neuron_count; 
	string name; 
}; 

organ *organ_create() {
	organ *o = TYPED_MALLOC(organ); 
	return o; 
} 

void organ_add_neuron(organ *o, neuron *n) {
	o->neurons[o->neuron_count++] = n; 
}


// ==================
// 		NETWORK   
// ==================
typedef struct network network; 
struct network { 
	int id; 
	organ *organs[2000]; // set of organs 
	int organ_count; 
}; 

network *network_create() {
	network *n = TYPED_MALLOC(network); 
	n->organ_count = 0; 
	return n; 
} 

void network_add_organ(network *n, organ *o) {
	n->organs[n->organ_count++] = o; 
}

#endif