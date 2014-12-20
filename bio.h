/*
- @author: Samuel Acuna
- @date: 11/11/2014
- @project: Neural network experiment 4
			https://github.com/samueleishion/neural-network-experiment-4 
*/ 

#include <iostream> 
#include <string> 
#include <vector> 
#include <map>

using namespace std; 

#ifndef BIO_H_
#define BIO_H_ 

// bio constants
#define THRESHOLD 0.5 
#define LEARNING_RATE 0.2 
#define LIFE_SPAN 20 

#define SENSORY 0
#define TRANSMITTER 1
#define TERMINAL 2
#define MOTOR 3 


// bio classes 
class Cognit {
	public: 
		string source; 
		map<string, int> destinations; 

		Cognit(string name)
			: source(name) { } 

		void add_destination(string s, int i); 
		void increment_destination(string s); 
}; 


class Neuron {
	public: 
		int type; 
		int id; 
		int threshold; 
		int learning_rate; 
		float weight; 
		float subtotal; 
		int body; 
		vector<Neuron> axon; 
		map<string, Cognit> cognits; 

		Neuron() 
			: type(0), id(0), weight(0) { } 

		Neuron(int ntype, int nid, float nweight) 
			: type(ntype), id(nid), weight(nweight) { } 

		void connect(Neuron n); 
		void show_connections(); 
		void add_cognit(string in, string out, int value);
		void process(string cognit_trail, float input);  
		void send(string cognit_trail, float output); 
}; 


class Organ {
	public: 
		int id; 
		string name; 
		vector<Neuron> neurons; 

		Organ()
			: id(0), name("") { } 

		Organ(int oid, string oname)
			: id(oid), name(oname) { } 

		void add_neuron(Neuron n); 
		int neuron_count(); 
		void connect(Organ p); 
		void show_connections(); 
}; 


class Network {
	public:
		int id;
		vector<Organ> organs; 
			
		Network()
			: id(0) { }  

		Network(int nid) 
			: id(nid) { } 

		int organ_count(); 
		void add_organ(Organ o); 
}; 


typedef pair<string, int> inpair; 
typedef pair<string, Cognit> outpair; 

#endif