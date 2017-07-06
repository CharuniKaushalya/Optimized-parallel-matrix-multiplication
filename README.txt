*** Compile sequential program ***
in terminal run command 
	g++ -fopenmp -o serial.out sequential.cpp

*** Execute sequential program ***
in terminal run command, Give value for n(n is the size of the square matrices)
./serial.out n 

*** Compile parallel program ***
in terminal run command 
g++ -fopenmp -o parallel.out parallel.cpp

***** Execute parallel program *****
after compiling, run command , Give value for n(n is the size of the square matrices)
./parallel.out n

*** Compile potimised parallel program ***
in terminal run command 
g++ -fopenmp -o optimized.out optimized.cpp

***** Execute optimized parallel program *****
after compiling, run command , Give value for n(n is the size of the square matrices)
./optimized.out n