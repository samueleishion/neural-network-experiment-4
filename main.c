#include <stdio.h> 
#include <stdlib.h> 
#include <inttypes.h> 
#include "bio.h" 

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
	if(n!=NULL) printf("Network created successfully! (%d organs)\n", network_organ_count(n));
	else printf("Error creating network.\n"); 

	organ *o = organ_create("right hand"); 
	organ *p = organ_create("left hand"); 
	organ *e = organ_create("eye"); 

	neuron *k = neuron_create(1,1,0.5); 
	neuron *l = neuron_create(2,2,0.4); 
	neuron *m = neuron_create(3,3,0.7); 

	organ_add_neuron(o,k); 
	organ_add_neuron(o,l); 
	organ_add_neuron(o,m); 
	printf("neurons added successfully! (%d organs)\n", organ_neuron_count(o));
	organ_add_neuron(p,l); 
	organ_add_neuron(p,m); 
	printf("neurons added successfully! (%d organs)\n", organ_neuron_count(p));
	organ_add_neuron(e,k); 
	printf("neurons added successfully! (%d organs)\n", organ_neuron_count(e));

	network_add_organ(n, o); 
	network_add_organ(n, p); 
	printf("organs added successfully! (%d organs)\n", network_organ_count(n));

	// organ_connect(o, p); 
	// organ_connect(e, o); 

	return 0; 
}
