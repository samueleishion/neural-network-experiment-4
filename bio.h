/*
 -	@author: Samuel Acuna 
 -	@date: 10/20/2014 
 -	@project: Neural Network Experiment 4 
*/
#include "utils.h" 
#include "arraylist.h"
#include "map.h" 

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
	arraylist *neurons; // connection to other neurons 
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
	arraylist *neurons; // set of neurons 
	string name; 
}; 

organ *organ_create(string name) {
	organ *o = TYPED_MALLOC(organ); 
	o->neurons = TYPED_MALLOC(arraylist); 
	o->name = name; 
	return o; 
} 

void organ_add_neuron(organ *o, neuron *n) {
	// printf("Adding neuron id %d to %s\n", n->id, o->name); 
	// o->neurons[o->neuron_count++] = n; 
	arraylist_add(o->neurons, n); 
}

int organ_neuron_count(organ *o) {
	return arraylist_get_size(*o->neurons); 
}

void organ_connect(organ *o, organ *p) {
	// neuron *n_o; 
	// neuron *n_p; 
	// int *current_o = *o->neurons; 
	// int *current_p = *p->neurons; 

	// int count_o = 0; 
	// int count_p = 0; 
	
	// printf("\n%s\n", o->name); 
	// while(*current_o!=NULL) {
	// 	n_o = *current_o; 
	// 	printf("%d, ", &n_o->id); 
	// 	current_o++; 
	// 	count_o++; 
	// }

	// printf("\n"); 

	// printf("\n%s\n", p->name); 
	// while(*current_p!=NULL) {
	// 	n_p = *current_p; 
	// 	printf("%d, ", &n_p->id); 
	// 	current_p++; 
	// 	count_p++; 
	// }

	// printf("\n"); 

	// printf("count of o: %d\n", count_o); 
	// printf("count of p: %d\n", count_p); 
}

// ==================
// 		NETWORK   
// ==================
typedef struct network network; 
struct network { 
	int id; 
	arraylist *organs; // set of organs 
}; 

network *network_create() {
	network *n = TYPED_MALLOC(network); 
	n->organs = TYPED_MALLOC(arraylist); 
	arraylist_initial(n->organs); 
	return n; 
} 

int network_organ_count(network *n) {
	return arraylist_get_size(*n->organs); 
}

void network_add_organ(network *n, organ *o) {
	arraylist_add(n->organs, o); 
}



#endif