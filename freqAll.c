#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//a struct that hold a word in an array and its frequency
struct wordCount{

	char wrd[100];
	int freq;

	};

int wordCompare(const void *x, const void *y){
	//cast the pointer, telling it that we are dealing with structs
	struct wordCount *tempptr = (struct wordCount *) x;
	struct wordCount *tempptr2 = (struct wordCount *) y;

	//arrows are used to access the members of structures
	int freqSort = tempptr2 -> freq - tempptr -> freq;
	
	//if the frequency is equal, sort alphabetically
	if(freqSort == 0){
		return strcmp(tempptr -> wrd, tempptr2 -> wrd);
	}
	return freqSort;
}

int main(){
	//array of structs
	struct wordCount wordCountArray[200];
	int counter = 0;	

	while(1){
		//tempp array that holds the word
		char temp[100];
		
		//getting the string from the terminal
		scanf("%s\n", temp);
		
		//breaks out of the while loop if temp is equal to "zzzzz"
		int res = strcmp(temp, "zzzzz");
		if(res == 0){
			break;
		}

		//flag checking if a word already exist in a struct
		int found = 0;
		for( int i = 0; i < counter; i ++){
			if(strcmp(wordCountArray[i].wrd, temp) == 0){
				found = 1;
				wordCountArray[i].freq++;
				break;

			}
		}
		//if the word is not in any of the struct, creates a new struct
		if(found == 0){
				
				strcpy(wordCountArray[counter].wrd,temp);
				wordCountArray[counter].freq = 1;	
				counter++;
		}
	}
	//sorts the array of struct
	qsort(wordCountArray, counter,sizeof(struct wordCount),  &wordCompare);

	//prints the top 5 highest frequency of words in the string.
	printf("Count\tWord\n=====\t====\n");
	for( int j = 0; j < 5; j++){
		printf("%d\t%s\n", wordCountArray[j].freq, wordCountArray[j].wrd);
	}
	return(0);
}