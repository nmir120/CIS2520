/*
Numan Mir
1005381
CIS2520 A3 Question 2
November 5, 2018
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int row = 20;
	int column = 10;
	int array[row][column];
	
	int i = 0;
	int j = 0;
	FILE* fp = fopen("f.dat", "r");
	
	/*read file into array*/
	for(i = 0; i < row; i++)
	{
	    for(j = 0; j < column; j++)
	    {
	        fscanf(fp, "%d", &array[i][j]);
	    }
	}
	/* printing the original file contents*/
	for(i = 0; i < row; i++) 
	{
	    for(j = 0; j < column; j++)
	    {	
	    	if(array[i][j] < 10){
	    		printf("0%d ", array[i][j]);
	    	}
	    	else{
	        	printf("%d ", array[i][j]);
	    	}
	    }
	    printf("\n");
	}

	fclose(fp); 
	return 0;
}
