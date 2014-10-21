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

	organ *o = organ_create(); 
	if(o!=NULL) printf("Organ created successfully\n"); 
	else printf("Error creating organ.\n"); 

	network_add_organ(n, o); 

	if(n->organ_count==1) printf("Successfully added organ! (%d organs)\n", n->organ_count); 
	else printf("Error adding organ.\n"); 

	return 0; 
}
