//programming assignment 8
//andrew cheng jr
//7/28/21, 7/29/21

#include <stdio.h>
#define WORD_LENGTH 100

_Bool isPalindrome(char[]);
_Bool isSameString(char[], char[]);
void reverseCopy(char[], char[]);
int stringLength(char[]);

int main(){

char possiblepalindrome1[WORD_LENGTH+1], possiblepalindrome2[WORD_LENGTH+1];
_Bool palindrome1, palindrome2, wordsaresame = 0;
int stringlength1, stringlenght2;

	printf("Enter your first word: ");
	scanf("%s", possiblepalindrome1);
	printf("Enter your second word: ");
        scanf("%s", possiblepalindrome2);

	palindrome1 = isPalindrome(possiblepalindrome1);
	palindrome2 = isPalindrome(possiblepalindrome2);

	for(int index = 0; possiblepalindrome1[index] != '\0'||possiblepalindrome2[index] != '\0'; index++){
		if(possiblepalindrome1[index] == possiblepalindrome2[index]){
			wordsaresame = 1;
		}
		else{
			wordsaresame = 0;
		}
	}
	if(wordsaresame == 1){
		printf("You entered the same words!\n");
		if(palindrome1 == 1){
			printf("'%s' is a palindrome!", possiblepalindrome1);
		}
		else{
			printf("'%s' is not palindrome.", possiblepalindrome1);
		}
		printf("\n");
	}
	else{
		if(palindrome1 == 1){
			printf("'%s' is a palindrome!", possiblepalindrome1);
		}
		else{
			printf("'%s' is not palindrome.", possiblepalindrome1);
		}
		printf("\n");
		if(palindrome2 == 1){
                	printf("'%s' is a palindrome!", possiblepalindrome2);
		}
        	else{
                	printf("'%s' is not palindrome.", possiblepalindrome2);
       		}
		printf("\n");
	}

return 0;
}
//Is PaLiNdRoMe
_Bool isPalindrome(char stringpalindrome[]){
	char reversestringpalindrome[WORD_LENGTH+1];
	_Bool ispalindrome;

	reverseCopy(stringpalindrome, reversestringpalindrome);


	ispalindrome = isSameString(stringpalindrome, reversestringpalindrome);
return ispalindrome;
}
//ReVeRsE cOpY
void reverseCopy(char palindrome[], char reversepalindrome[]){
	int lengthpalindrome;
	lengthpalindrome = stringLength(palindrome);

	for(int index=0; index<lengthpalindrome; index++){
		reversepalindrome[index] = palindrome[lengthpalindrome-index-1];
	}
	reversepalindrome[lengthpalindrome] = '\0';

}
//StRiNg LeNgTh
int stringLength(char palindrome[]){
	int count = 0;

	for(int ind = 0; palindrome[ind] != '\0'; ind++){
		count++;
	}
	return count;
}
//Is SaMe StRiNg
_Bool isSameString(char palindrome[], char reversepalindrome[]){

	_Bool issame = 0;
	for(int index = 0; palindrome[index]!='\0'; index++){
		if(palindrome[index] == reversepalindrome[index]){
		issame = 1;
		}
		else{
		issame = 0;
		}
	}
	return issame;
}
