#include <stdio.h>
#include <math.h>
#include <time.h>
#define size 20


float determinant(float [][size], int);
void cofactor(float [][size], int);
void transpose(float [][size], float [][size], int);


int main()
{
      float a[size][size], OrderOfMatrix, d;
      int i, j;
      
      printf("Enter the order of the Matrix : ");
      scanf("%f", &OrderOfMatrix);
      
      printf("Enter the elements of %.0f X %.0f Matrix : \n", OrderOfMatrix, OrderOfMatrix);
      
      for (i = 0;i < OrderOfMatrix; i++)
      {	
		for (j = 0;j < OrderOfMatrix; j++)
           	{
            		scanf("%f", &a[i][j]);
            	}
      }
      
      d = determinant(a, OrderOfMatrix);
      
      if (d == 0)
       	printf("\nInverse of Entered Matrix is not possible\n");
      else
      	{
      		clock_t begin= clock();	
       	cofactor(a, OrderOfMatrix);
       	clock_t end= clock();
       	
       	double time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
       	printf("\nTime for execution in Sequential: %lf seconds", time_spent);
	}
}
    

float determinant(float a[size][size], int OrderOfMatrix)
{
      float s = 1, det = 0, b[size][size];
      int i, j, m, n, c;
      
	if (OrderOfMatrix == 1)
	{
         	return (a[0][0]);
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
					b[i][j] = 0;
				    	if (i != 0 && j != c)
				     	{
				       	b[m][n] = a[i][j];
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
              
              	det = det + s * (a[0][c] * determinant(b, OrderOfMatrix - 1));
              	s = -1 * s;
              }
        }
        return (det);
        
}

void cofactor(float num[size][size], int f)
{
     float b[size][size], fac[size][size];
     int p, q, m, n, i, j;
     
     for (q = 0;q < f; q++)
     {
       	for (p = 0;p < f; p++)
        	{
         		m = 0;
         		n = 0;
         		for (i = 0;i < f; i++)
         		{
           			for (j = 0;j < f; j++)
            			{
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
       
       printf("\n\n\nThe inverse of matrix is : \n");
    
       for (i = 0;i < r; i++)
       {
       	for (j = 0;j < r; j++)
         	{
             		printf("\t%f", inverse[i][j]);
         	}	
        	printf("\n");
       }
}
