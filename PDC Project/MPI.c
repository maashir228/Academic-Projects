#include <stdio.h>
#include <math.h>
#include <./sequential.c>
#include <time.h>
#include <mpi.h>
#include <stdlib.h>
#define size 20


float determinant(float [][size], int);
void cofactor(float [][size], int);
void transpose(float [][size], float [][size], int);

int world_size;
int world_rank;

int main(int argc, char*argv[])
{
      float Matrix[size][size], OrderOfMatrix, DeterminantOfInputMatrix;
      int i, j;
	double timetaken=0;      

      	MPI_Init(&argc, &argv);
      	
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	// Get the rank of the process
	
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	if(world_rank==0)
	{
		printf("Enter the order of the Matrix : ");
      		scanf("%f", &OrderOfMatrix);
      
      		printf("Enter the elements of %.0f X %.0f Matrix : \n", OrderOfMatrix, OrderOfMatrix);
      	
		      for (i = 0;i < OrderOfMatrix; i++)
		      {	
				for (j = 0;j < OrderOfMatrix; j++)
			   	{
			    		Matrix[i][j]= rand()%25;
			    	}
		      }
		DeterminantOfInputMatrix = determinant(Matrix, OrderOfMatrix);	      
		MPI_Send(Matrix, size, MPI_INT, 1, 1, MPI_COMM_WORLD);
      	}	
      	if (DeterminantOfInputMatrix == 0)
       	{
       	printf("\nInverse of Entered Matrix is not possible\n");
       	MPI_Finalize();
       	return 0;
       	}
      	else
      	{
      			//printf("\nDeterminant of Input: %f\n", DeterminantOfInputMatrix);
      		if(world_rank==1)
      		{
      			clock_t begin= clock();
			MPI_Recv(Matrix, size, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
       		cofactor(Matrix, OrderOfMatrix);			
			clock_t end= clock();		
			timetaken = (double)(end-begin) / CLOCKS_PER_SEC;
			printf("\nTime for execution in MPI: %lf seconds by rank %d\n", timetaken, world_rank);
		}
		MPI_Barrier(MPI_COMM_WORLD);
			
	}
		MPI_Finalize();
}
    

float determinant(float InputMatrix[size][size], int OrderOfMatrix)
{
      float s = 1, det = 0, PassingMatrix[size][size];
      int i, j, m, n, c;
      
	if (OrderOfMatrix == 1)
	{
	//	printf("\n%d times returning from base case\n", 1);
         	return (InputMatrix[0][0]);
	}
      	else
	{
         	det = 0;
         	
         	for (c = 0; c < OrderOfMatrix; c++)
           	{
		    m = 0;
		    n = 0;
		    	for (i = 0;i < OrderOfMatrix; i++)
              		{
		       	for (j = 0 ;j < OrderOfMatrix; j++)
		          	{
					PassingMatrix[i][j] = 0;
				    	if (i != 0 && j != c)
				     	{
				       	PassingMatrix[m][n] = InputMatrix[i][j];
				       	if (n < (OrderOfMatrix - 2))
				        		n++;
				       	else
						{
							 n = 0;
							 m++;
						}
		               	}	
		           	}
                 	}
              
              	det = det + s * (InputMatrix[0][c] * determinant(PassingMatrix, OrderOfMatrix - 1));
              	s = -1 * s;
              }
              
        }
        return (det);       
}

void cofactor(float num[size][size], int f)
{
     float b[size][size], fac[size][size];
     int p, q, m, n, i, j;
     //printf("\nFinding cofactor");
     for (q = 0;q < f; q++)
     {//printf("\nFor 1 cofactor");
       	for (p = 0;p < f; p++)
        	{//printf("\nFor 2 cofactor");
         		m = 0;
         		n = 0;
         		for (i = 0;i < f; i++)
         		{//printf("\nFor 3 cofactor");
           			for (j = 0;j < f; j++)
            			{//printf("\nFor 4 cofactor");
				      if (i != q && j != p)
				      {
					 b[m][n] = num[i][j];
						if (n < (f - 2))
					 		n++;
						else
					 	{
					   		n = 0;
					   		m++;
					   	}
                			}
            			}
          		}
          		
          		fac[q][p] = (pow(-1, (q + p))) * determinant(b, f - 1);
        	}
      }
      
      transpose(num, fac, f);
      
}


void transpose(float num[size][size], float fac[size][size], int r)
{
      	int i, j;
      	float b[size][size], inverse[size][size], d;
     
      	for (i = 0;i < r; i++)
        {
         	for (j = 0;j < r; j++)
           	{
             		b[i][j] = fac[j][i];
            	}
        }
        
      	d = determinant(num, r);
	
	for (i = 0;i < r; i++)
	{
         	for (j = 0;j < r; j++)
           	{
            		inverse[i][j] = b[i][j] / d;
            	}
	}       
       
       printf("\n\nThe inverse of matrix is : \n");
    
       for (i = 0;i < r; i++)
       {
       	for (j = 0;j < r; j++)
         	{
             		printf("\t%f", inverse[i][j]);
         	}	
        	printf("\n");
        
       }
}
