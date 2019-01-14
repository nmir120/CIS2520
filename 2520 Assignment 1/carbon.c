//Numan Mir
//1005381
//CIS2520 Assignment 1
//Monday September 24th, 2018
//code structure and idea from 
//https://www.robertcina.com/2015/02/19/an-exercise-in-permutations-using-java/
#include <stdio.h>
#include <string.h>

int carbonMain(){
	char string[] = {'c', 'a', 'r', 'b', 'o', 'n'};
	int strlength = 6;
	int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0; //integers representing each character position
	for(i = 0; i < strlength; ++i){ //nested for loops for each character position
		for(j = 0; j < strlength; ++j){ //each position can be 6 different characters 
			for(k = 0; k < strlength; ++k){ 
				for(l = 0; l < strlength; ++l){ 
					for(m = 0; m < strlength; ++m){ 
						for(n = 0; n < strlength; ++n){ 
							//if no characters are the same, print result (6! = 720 total)
							if(i != j && i != k && i != l && i != m && i != n && j!= k && j != l && j != m && j != n && k != l && k != m && k != n && l != m && l != n && m != n){
								printf("%c%c%c%c%c%c\n", string[i], string[j], string[k], string[l], string[m], string[n]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

