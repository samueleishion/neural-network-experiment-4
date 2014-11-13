neunet: bio.h bio.cpp main.cpp utils.h utils.cpp
	g++ main.cpp bio.cpp utils.cpp -o main
	@./main 

clean: 
	rm -f main *.o *~ .gitignore~