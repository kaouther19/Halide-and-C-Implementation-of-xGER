# Implementation of Ger Function in Halide 
Ger is a Blas function that calculates  A := alpha*x*y'+ A, where alpha is a scalar and x, y, are vectors and A is a matrix. 
This program is an  implementation of ger in Halide and C. 

## Requirements

To run  this project, you will need Halide :

* Download a binary release of Halide from: https://github.com/halide/Halide/releases
* If you would prefer to build Halide from source, see https://github.com/halide/Halide/blob/master/README.md  for instructions. Note that it might take up to a full night.

You can find an example of installation log in the file intallation-log.txt

## Usage

* First clone this repo : 
* cd Halide-and-C-Implementation-of-xGER
* give the script execute permission chmod +x script.sh
* run the script.sh $ ./script.sh -p path/to/halide/in/your/pc
* The script will compile and run both c and Halide implementations, data are readen from prams file and written in result file. 
* The script compare c and Halide results. 
* If everything is right you will get this output:
```
***** Compiling Halide implementation *****
***** Compiling C implementation *****
***** Runing halide *****
Halide implementation :  
Vectors initialized successfully... 
Ger function done...
Results recorded successfully.  
***** Runing c *****
C implementation : 
Vectors initialized successfully... 
Ger function done... 
Results recorded successfully.  
Checking Results differences... 
Results are the same :D
```
* if you get this message : "Something went wrong in the params file ", check params.txt. It must be as following :
```
n = 5
m = 3
a = 4
x = 1 4 7
y = 1 5 2 3 3
A =
5  6  5  8  5
1  2  3  4  5
1  5  9  2  6
```
You can change the values of parameters, but make sure that the  format still the same. 





