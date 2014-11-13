/*
- @author: Samuel Acuna
- @date: 11/11/2014
- @project: Neural network experiment 4
			https://github.com/samueleishion/neural-network-experiment-4 
*/ 

#include <iostream> 

long random() {
	static unsigned int nSeed = time(NULL); 
	nSeed = (8253729 * nSeed +2396403); 
	return (long) nSeed % 32763; 
}