#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 
#include "bio.h" 
#include "map.h" 

// Boolean make_network() {
	// float r = (float) drand48(); 
	// neuron *n = neuron_create(type, nid++, r); 
	// return n!=NULL; 

	// network *n = network_create(); 
	// return n!=NULL; 
// }


int main(int argc, char **argv) {
	srand(time(NULL));
	printf("MAIN\n"); 

	network *n = network_create(); 
	if(n!=NULL) printf("Network created successfully! (%d organs)\n", n->organ_count);
	else printf("Error creating network.\n"); 

	organ *o = organ_create("right hand"); 
	organ *p = organ_create("left hand"); 

	neuron *k = neuron_create(1,1,0.5); 

	organ_add_neuron(o,k); 
	organ_add_neuron(o,k); 
	organ_add_neuron(p,k); 

	network_add_organ(n, o); 
	network_add_organ(n, p); 

	organ_connect(o, p); 

	return 0; 
}
