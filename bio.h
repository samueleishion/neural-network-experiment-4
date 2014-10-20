/*
 -	@author: Samuel Acuna 
 -	@date: 10/20/2014 
 -	@project: Neural Network Experiment 4 
*/


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

void neuron_create() {
	return; 
}


// ==================
// 		ORGAN  
// ==================
typedef struct organ organ; 
struct organ { 
	int id; 
	neuron *neurons[2000]; // set of neurons 
}; 

void organ_create() {
	return; 
} 


// ==================
// 		NETWORK   
// ==================
typedef struct network network; 
struct network { 
	int id; 
	organ *organs[2000]; // set of neurons 
}; 

void network_create() {
	return; 
} 

void network_add_organ(organ o) {
	return; 
}
