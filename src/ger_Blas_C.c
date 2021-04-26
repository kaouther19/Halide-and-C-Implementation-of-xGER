#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    In this program, initialisation of vectors x, y and the matrix A will be done from file params.txt.
    Then calculation 1-rank update of A, A=alpha*X*Y'+A.
    The result will be saved in result_c.txt file.
    */
   printf("C implementation : \n");
   FILE *params;
   FILE *result;
   int n,m,alpha;
   if ((params = fopen("./files/params.txt","r")) == NULL)
   {
       printf("Error! opening file");
       exit(2);
   }
   result= fopen("./files/result_c.txt","w");
   char cursor;
    // Read m and n and alpha
    fscanf(params,"%c",&cursor);
    if(cursor=='n')
    {
        fseek(params, 3, SEEK_CUR );
        fscanf(params,"%d\n", &n);
    }
    fscanf(params,"%c",&cursor);
    if(cursor=='m')
    {
        fseek(params, 3, SEEK_CUR );
        fscanf(params,"%d\n", &m);
    }
    fscanf(params,"%c",&cursor);
    if(cursor=='a')
    {
        fseek(params, 3, SEEK_CUR );
        fscanf(params,"%d\n", &alpha);
 
    }
    int x[m];
    int y[n];
    int A[m][n];
    fscanf(params,"%c",&cursor);
    int i=0,j=0;
    if(cursor=='x')
    {
        fseek(params, 3, SEEK_CUR );
        for ( i = 0; i < m; i++)
        {
            fscanf(params,"%d",&x[i]);
        }
    }
    else 
    { 
        printf("Something went wrong in the params file  \n");
        exit(1);
    }
    fscanf(params,"\n%c",&cursor);
    if(cursor=='y')
    {
        fseek(params, 3, SEEK_CUR );
        for ( i = 0; i < n; i++)
        {
            fscanf(params,"%d",&y[i]);
        }
    }
    else 
    { 
        printf("Something went wrong in the params file  \n");
        exit(1);
    }
    fscanf(params,"\n%c",&cursor);
    if(cursor=='A')
    {
        fseek(params,2,SEEK_CUR);
        for ( i = 0; i < m; i++)
        {
            
            for ( j = 0; j < n; j++)
            {
                fscanf(params,"%d",&A[i][j]);
                fseek(params,2,SEEK_CUR);
            }
            fseek(params,-1,SEEK_CUR);
        }
    }
    else 
    { 
        printf("Something went wrong in the params file  \n");
        exit(1);
    }
    printf("Vectors initialized successfully... \n");
    fclose(params);
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            A[i][j]=A[i][j]+alpha*x[i]*y[j];
            fprintf(result,"%d  ",A[i][j]);
        }
        fprintf(result,"\n");
    }
    printf("Ger function done... \n");
    printf("Results recorded successfully.  \n");
    fclose(result);

}