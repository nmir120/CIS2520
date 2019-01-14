/*
Numan Mir
1005381
CIS2520 A3 Question 1
November 5, 2018
*/

#include <stdio.h>
#include <string.h>
void preorder(char []);
void inorder(char []);
void postorder(char []);

int main(int argc, char *argv[]){
	char originalString[100];
	char resultString[100];
	int userChoice = 0;
	if(argc == 1){ /*if no command line argument input, send error message*/
		printf("Error, no input.\n");
		return 1;
	}
	
	strcpy(originalString, argv[1]); 
	strcpy(resultString, originalString);

	while(userChoice != 7){
		printf("Choose one of the following options (enter the corresponding number):\n");
		printf("1. Display\n2. Preorder\n3. Inorder\n4. Postorder\n");
		printf("5. Update\n6. Caculate\n7. Exit\n");
		scanf("%d", &userChoice);
		if(userChoice == 1){
			printf("Binary tree display:\n");
		}
		else if(userChoice == 2){
			strcpy(resultString, originalString);
			printf("Preorder traversal expression:\n");
			preorder(resultString);
		}
		else if(userChoice == 3){
			strcpy(resultString, originalString);
			printf("Inorder traversal expression:\n");
			inorder(resultString);
		}
		else if(userChoice == 4){
			strcpy(resultString, originalString);
			printf("Postorder traversal expression:\n");
			postorder(resultString);
		}
		else if(userChoice == 5){
			printf("What variable value would you like to change?\n");
			printf("What would you like to change the value to?\n");
		}
		else if(userChoice == 6){
			printf("The calculation result is:\n");
			/*check if divided by 0*/
		}
		else if(userChoice != 7){
			printf("Invalid number, please try again or enter 7 to exit:\n");
		}
	}
	return 0;
}
/*prints expression in preorder travsersal form*/
void preorder(char resultString[]){
	int i = 0;
	int lastOBrace = 0; /*variable for last opening brace*/
	int j = 0;
	int stringLength = 0;
	char currentOperator = ' ';
	stringLength = strlen(resultString);
	for(i = 0; i < stringLength; ++i){ /*goes through entire string*/
		if(resultString[i] == '+' || resultString[i] == '-' || resultString[i] == '/' || resultString[i] == '*'){ /*checks for operators*/
			currentOperator = resultString[i]; /*currentOperator variable used for readability*/
			for(j = i; j >= 0; --j){ /*count back from currentOperator position to check for last opening brace*/
				if(resultString[j] == '('){
					lastOBrace = j; /*lastBrace variable used for readability*/
					resultString[lastOBrace] = currentOperator; /*replace the last opening brace with the operator*/
					resultString[i] = ' '; /*replace the currentOperator's position with a space*/
					break; /*break out of loop to prevent multiple replacements of opening braces*/
				}
			}
			
		}
	}
	for(i = 0; i < strlen(resultString); ++i){ /*for loop to replace closing braces with spaces*/
		if(resultString[i] == ')'){
			resultString[i] = ' ';
		}
	}
	printf("%s\n", resultString);
}
/*prints expression in inorder traversal form*/
void inorder(char resultString[]){
	printf("%s\n", resultString); /*original input is already inorder, fully parenthesized*/
}
/*prints expression in postorder traversal form*/
void postorder(char resultString[]){
	int i = 0;
	int lastCBrace = 0; /*variable for last closing brace position*/
	int j = 0;
	char currentOperator = ' ';
	int stringLength = 0;
	char *strPtr; 
	stringLength = strlen(resultString);
	for(i = stringLength - 1; i >= 0; --i){ /*goes through entire string*/
		if(resultString[i] == '+' || resultString[i] == '-' || resultString[i] == '/' || resultString[i] == '*'){ /*checks for operators*/
			currentOperator = resultString[i]; /*currentOperator variable used for readability*/
			for(j = i; j < stringLength; ++j){ /*count back from currentOperator position to check for last opening brace*/
				if(resultString[j] == ')'){
					lastCBrace = j; /*lastCBrace variable used for readability*/
					resultString[lastCBrace] = currentOperator; /*replace the last closing brace with the operator*/
					resultString[i] = ' '; /*replace the currentOperator's position with a space*/
					break; /*break out of loop to prevent multiple replacements of closing braces*/
				}
			}
			
		}
	}
	for(i = 0; i < strlen(resultString); ++i){ /*for loop to replace opening braces with spaces*/
		if(resultString[i] == '('){
			resultString[i] = ' ';
		}
	}

	/*removing spaces from beginning of string to make output a little more visually appealing*/
	/*referenced from stackoverflow website, full link in readme.txt*/
   	strPtr = resultString;  
    while(*strPtr == ' '){
    	strPtr++;  
    }
    if(strPtr != resultString){
    	memmove(resultString, strPtr, strlen(strPtr)+1); 
    }

	printf("%s\n", resultString);
}
