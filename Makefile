neunet: bio.h bio.cpp main.cpp utils.h
	g++ main.cpp bio.h bio.cpp utils.h -o main
	@./main 

clean: 
	rm -f main *.o *~ .gitignore~