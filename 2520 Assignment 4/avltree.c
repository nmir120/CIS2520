/*
Numan Mir
1005381
CIS2520 A4
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
	char key[50];
	int frequency;
	int height;
	struct node *left;
	struct node *right;
}node;

void findAll(int frequency, node* tree);
node* findKey(char* key, node* tree);
node* insertKey(char* key, node* tree);
node* removeKey(char* key, node* tree);
void findAll(int num, node* tree);
int height(node* tree);
int max(int x, int y);
node* minNode(node* min);
int getBalance(node* tree);
node* singleRotateLeft(node* tree);
node* singleRotateRight(node* tree);
node* doubleRotateLeft(node* tree);
node* doubleRotateRight(node* tree);
int size(node* tree);

int main(){
	int numChoice = 0;
	char str[50];
	node *tree = NULL;
	node *keyFound = NULL;
	int frequency = 0;
	FILE* fp;
	char text[500]; /*represents each line in text file*/
	char *token;
	node *tokenNode = NULL;
	int length = 0;
	int totalFrequency = 0;

	while(numChoice != 7){
		printf("1. Initialization\n2. Find\n3. Insert\n4. Remove\n");
		printf("5. Check Height and Size\n6. Find All (above a given frequency)\n7. Exit\n");
		printf("Enter a code (1 - 7) and hit Return\navl/> ");
		scanf("%d", &numChoice);
		switch(numChoice){
			case 1:
				fp = fopen("A4_data_f18.txt", "r");
				if(fp == NULL){
					printf("Error: could not open file\n");
				}
				while(fgets(text, 500, fp) != NULL){
				token = strtok(text, " "); /*find first token (space)*/
					while(token != NULL){ /*walk through other tokens*/
						length = strlen(token);
						/*replace newline with null to restart on next line*/
						if(token[length-1] == '\n') token[length-1] = '\0'; 
						if(length > 1){ /*so no space is counted*/
							tokenNode = findKey(token, tree); 
							if(tokenNode == NULL){
								tree = insertKey(token, tree); /*if key doesnt exist, insert into tree*/
								totalFrequency++; 
							} 
							else{
								tokenNode->frequency++; /*increase frequency if key already exists*/
								totalFrequency++;
							} 
						}
					token = strtok(NULL, "\n "); /*null character and space*/
					}
				}
				fclose(fp);
				break;
			case 2:
				if(tree == NULL) printf("\nYou must initialize before selecting other options\n\n");
				else{
					printf("find key: ");
	            	scanf("%s", str);
	            	keyFound = findKey(str, tree);
	            	if(keyFound == NULL){
	            		printf("no_such_key\n"); 
	            	}
	            	else{
	                	printf("key: %s, frequency: %d\n", str, keyFound->frequency); 
	            	}
	            }
				break;
			case 3:
				if(tree == NULL) printf("\nYou must initialize before selecting other options\n\n");
				else{
					printf("insert key: ");
					scanf("%s", str);
					keyFound = findKey(str, tree);
					if(keyFound == NULL){
						tree = insertKey(str, tree);
						totalFrequency++;
					}
					else{
						keyFound->frequency++;
						totalFrequency++;
					}
					keyFound = findKey(str, tree);
					printf("key: %s, frequency: %d\n", str, keyFound->frequency);
				}
				break;
			case 4:
				if(tree == NULL) printf("\nYou must initialize before selecting other options\n\n");
				else{
					printf("remove key: ");
					scanf("%s", str);
					keyFound = findKey(str, tree);
					if(keyFound == NULL){
						printf("no_such_key\n");
					}
					else if(keyFound->frequency > 1){
						keyFound->frequency--;
						totalFrequency--;
						printf("key: %s, frequency: %d\n", str, keyFound->frequency);
					}
					else{
						tree = removeKey(str, tree);
						totalFrequency--;
						printf("key: %s, frequency: 0\n", str);
					}
				}
				break;
			case 5:
				if(tree == NULL) printf("\nYou must initialize before selecting other options\n\n");
				else{
					printf("height: %d, size: %d, total count: %d\n", height(tree), size(tree), totalFrequency);
				}
				break;
			case 6:
				if(tree == NULL) printf("\nYou must initialize before selecting other options\n\n");
				else{
					printf("frequency: ");
					scanf("%d", &frequency);
					findAll(frequency, tree);
				}
				break;
			case 7: 
				break;
			default:
				printf("\nError, number must be between 1-7\n\n");
				break;
		}

	}
	return 0;

}

node* findKey(char* key, node* tree){ /*referenced from zentut*/
	/*
	asks user for key
	if no key found print "No_such_key"
	if key found, display "key: (key), frequency: (count)"
	*/
	if(tree == NULL) return NULL;
   
    if(strcmp(key, tree->key)<0){  /*if user key is less than tree's key*/
        return findKey(key, tree->left);
    }
    else if(strcmp(key, tree->key)>0){/*if user key is greater than tree's key*/
        return findKey(key, tree->right);
    }
    else return tree;
}
node* insertKey(char* key, node* tree){ /*referenced from zentut and geeksforgeeks*/
	/*
	ask user for key
	search for the position where the key should be placed (separate function?)
	if key is already in the tree, increase the count
	if key is new, carry out actual insertion, set count to 1
	*/
	/*check if node is empty, insert here if it is*/
	if(tree == NULL){
		tree = (node*)malloc(sizeof(node));
		if (tree == NULL)
		{
			printf("Error: out of memory\n");
			return NULL;
		}
		
		tree->height = 1;	
		tree->frequency = 1;
		strcpy(tree->key, key);	
		tree->left = NULL;		
		tree->right = NULL;	
	}
	else if(strcmp(key, tree->key) < 0){/*if user key is less than key, insert left*/
		tree->left = insertKey(key, tree->left);
		if (height(tree->left) - height(tree->right) == 2){
			if(strcmp(key, tree->left->key) < 0){
				tree = singleRotateLeft(tree);
			}
			else{
				tree = doubleRotateLeft(tree);
			}
		}		
	}
	else if(strcmp(key, tree->key) > 0){/*if user key is greater than key, insert right*/
		tree->right = insertKey(key, tree->right);
		if (height(tree->right) - height(tree->left) == 2){
			if(strcmp(key, tree->right->key) > 0){
				tree = singleRotateRight(tree);
			}
			else{
				tree = doubleRotateRight(tree);
			}
		}	
	}
	/*else tree->frequency++; if key already exists, increase count*/
		
	tree->height = max(height(tree->left), height(tree->right))+1;
	return tree;
}
node* removeKey(char* key, node* tree){ /*referenced from geeksforgeeks*/
	/*
	ask user for key
	if key not found, print "No_such_key"
	if key has a count of 1, print "key: (key), frequency: 0"
	if key has a count >1, decrease count of node by 1, display the key and new count
	*/
	node* temp = NULL;
	int balance = 0;
	if(tree == NULL) return tree;
	if(strcmp(key, tree->key) < 0){
		tree->left = removeKey(key, tree->left);
	}
	else if(strcmp(key, tree->key) > 0){
		tree->right = removeKey(key, tree->right);
	}
	else{
		if((tree->left == NULL) || (tree->right == NULL)){
			temp = tree->left ? tree->left:
								tree->right;
			if(temp == NULL){
				temp = tree;
				tree = NULL;
			}
			else *tree = *temp;

			free(temp);
		}
		else{
			temp = minNode(tree->right);
			strcpy(temp->key, tree->key);
			tree->right = removeKey(temp->key, tree->right);
		}
	}
	if(tree == NULL) return tree; /*if tree only has one node*/
	tree->height = 1 + max(height(tree->left), height(tree->right));
	balance = getBalance(tree);
	if(balance > 1 && getBalance(tree->left) >= 0){
		return singleRotateRight(tree);
	}
	if(balance > 1 && getBalance(tree->left) < 0){
		tree->left = singleRotateLeft(tree->left);
		return singleRotateRight(tree);
	}
	if(balance < -1 &&getBalance(tree->right) <= 0){
		return singleRotateRight(tree);
	}
	if(balance < -1 && getBalance(tree->right) > 0){
		tree->right = singleRotateRight(tree->right);
		return singleRotateLeft(tree);
	}
	return tree;
}

int size(node* tree){ /*calculates total number of nodes*/
	if(tree == NULL) return 0;
	else{
		return(size(tree->left) + 1 + size(tree->right));
	}
}
void findAll(int frequency, node* node){ /*referenced from geeksforgeeks*/ 
    if(node == NULL) return; 
  	 /*preorder traversal, referenced from geeksforgeeks*/
     /* first recur on left subtree*/ 
    findAll(frequency, node->left); 
  
     /* then recur on right subtree*/
    findAll(frequency, node->right); 

    if(node->frequency >= frequency){
     	printf("key: %s, frequency %d\n", node->key, node->frequency); 
 	}
} 

int height(node* tree){
	if(tree == NULL) return -1;
	else return tree->height;
}

node* singleRotateLeft(node* tree){
	node *temp = NULL;

	temp = tree->left;
	tree->left = temp->right;
	temp->right = tree;

	/*restore the correct heights*/
	tree->height = (max(height(tree->left), height(tree->right)))+1;

	temp->height = (max(height(temp->left), height(temp->right)))+1;

	return temp; /*new root*/

}
node* singleRotateRight(node* tree){
	node *temp = NULL;

	temp = tree->right;
	tree->right = temp->left;
	temp->left = tree;

	/*restore the correct heights*/
	tree->height = (max(height(tree->left), height(tree->right)))+1;

	temp->height = (max(height(temp->left), height(temp->right)))+1;

	return temp; /*new root*/
}
/*rotate a node with it's left child*/
node* doubleRotateLeft(node* tree){
	tree->left = singleRotateRight(tree->left);
	return singleRotateLeft(tree);
}

node* doubleRotateRight(node* tree){
	tree->right = singleRotateLeft(tree->right);
	return singleRotateRight(tree);
}

int max(int x, int y){
	if(x > y) return x;
	else return y;
}

node* minNode(node* min){
	while(min->left != NULL){ /*loop down to find the lowest leaf*/
		min = min->left;
	}
	return min;
}

int getBalance(node* tree){
	if(tree == NULL) return 0;
	else{
	return (height(tree->left) - height(tree->right));
	}
}

