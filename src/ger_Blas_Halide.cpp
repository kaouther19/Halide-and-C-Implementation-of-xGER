#include "Halide.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace Halide;
int main(int argc, char * argv[] )
{
    printf("Halide implementation :  \n");
    // defining the maximum Demension of vectors
    const int maxSize= 10;
    int n,m,alpha;
    // declaration of the vectors x, y and the matrix A
    int y[1][maxSize],x[maxSize][1],A[maxSize][maxSize];
    // opennig the file params to intialize m,n,alpha, x, y and A 
    ifstream params("./files/params.txt");
	if (!params)
    {
	    printf("Error! file can not be opened");
	    exit(2);
	}
    char cursor;

    // reading demensions of vectors and  matrix from params file 
    // reading n
    params >> cursor;

    if (cursor=='n')
    {
        params >> cursor >>n; 

    }
    else
    {
        printf("Something went wrong in the params file  \n");
        exit(1);
    }
    // reading m
    params >> cursor;
    if (cursor=='m')
    {
        params >> cursor >>m;

    }
    else
    {
        printf("Something went wrong in the params file \n");
        exit(1);
    }

    // reading the alpha
    params >> cursor;
    if (cursor=='a')
    {
        params >> cursor >>alpha;

    }
    else
    {
        printf("Something went wrong in the params file \n");
        exit(1);
    }
    int i=0,j=0;
    // reading the vector x
    params >> cursor;
    if(cursor=='x')
    {
        params >> cursor;
        for (i = 0; i < m; i++)
        {
            
            params >> x[i][0];
            
        }
        
    }
    else
    {
        printf("Something went wrong in the params file \n");
        exit(1);
    }
    // reading the vector y
    // while reading y we can define it with 1 row and n colomns, so we can skip calculating the transpose 
    params >> cursor;
    if(cursor=='y')
    {
        params >> cursor;
        for (i = 0; i < n; i++)
        {
           params >> y[0][i];
        }
        
    }
    else
    {
        printf("Something went wrong in the params file \n");
        exit(1);
    }
    // reading the matrix A
    params >> cursor;
    if(cursor=='A')
    {
        params >> cursor;
        for ( i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                params>>A[i][j];
            }
            
        }
        
    }
    else
    {
        printf("Something went wrong in the params file \n");
        exit(1);
    }
    params.close();
    printf("Vectors initialized successfully... \n");
    // declaring a Halide function*/
    Func ger; 
    // Declaring three buffers to store the two vectors and the matrix 
    Buffer<int> matrixA(A);
    Buffer<int> vectorX(x);
    Buffer<int> vectorY(y);
    // declaring two halide variables that are going to be used as indices in the ger function
    Var w, z;
	// defining a reduction to use it in the sum reduction
    RDom r (0,1);
	// Definig the function ger
    ger(w,z)=alpha*sum(vectorX(r,z)* vectorY(w, r))+matrixA(w,z);
    matrixA= ger.realize(n,m);
    printf("Ger function done...\n");
      // we write the result in a file 
    ofstream result("./files/result.txt");
	for (j = 0; j < matrixA.height(); j++) 
    {
		for ( i = 0; i < matrixA.width(); i++) 
        {
		    result << matrixA(i, j) << "  ";
		}
        result << "\n";
            
	}
	printf("Results recorded successfully.  \n");
	result.close();
}