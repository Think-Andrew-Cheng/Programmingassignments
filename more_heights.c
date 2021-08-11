//programming assignment6
//Andrew cheng jr
//7/22/21

#include <stdio.h>

#define FILE_NAME "heights.txt"

int getMenuChoice();
void displayHeights(FILE*);
void calcAverageHeight(FILE*,int*, int*);
void saveHeights(FILE*);
int main()
{
	int userchoice;
	FILE*filePtr;

	do{
		userchoice = getMenuChoice();
		switch(userchoice){
			case 1:
				filePtr = fopen(FILE_NAME, "r");

				if(filePtr == NULL){
					printf("File could not be opened.\n");
				}
				else{
					displayHeights(filePtr);
					fclose(filePtr);
				}
				break;
			case 2:
				filePtr = fopen(FILE_NAME, "r");

				if(filePtr == NULL){
                                        printf("File could not be opened.\n");
                                }
                                else{
					int averagefeet, averageinches;
					calcAverageHeight(filePtr, &averagefeet, &averageinches);
					fclose(filePtr);
					printf("Average Height: %d\'%d\"\n", averagefeet, averageinches);

				}
				break;
			case 3:
				filePtr = fopen(FILE_NAME, "w");

				if(filePtr == NULL){
                                        printf("File could not be opened.\n");
                                }
				else{
					saveHeights(filePtr);
					fclose(filePtr);
				}
		}
	}
	while (userchoice != 0);

return 0;}


int getMenuChoice(){
	int userchoice;
	printf("***HEIGHT SYSTEM***\n");
        printf("1. Display Heights\n");
        printf("2. Calculate Average Height\n");
        printf("3. Save New Heights\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &userchoice);

	return userchoice;
}

void displayHeights(FILE* fptr){

	char name;
	int feet, inches;
	while(fscanf(fptr, "%c %d\'%d\"\n", &name, &feet, &inches) == 3){
		printf("%c %d\'%d\"\n", name, feet, inches);
		}
	}

void calcAverageHeight(FILE* fptr, int*averagefeet, int*averageinches){
	//create 2 variables -  count and sumofheights
	char name;
	int feet, inches, inches2, averageinches2, count, averageinches3;
	while(fscanf(fptr, " %c %d\'%d\"\n", &name, &feet, &inches) == 3){
		//*averagefeet += feet;
		//*averageinches +=inches;
		//printf("%d\'%d\"\n", feet, inches);
		inches2=feet*12;
		inches2 += inches;
		//printf("%d\n", inches2);
		averageinches2 += inches2;
		//printf("%d\n", averageinches2);
		count += 1;
		//printf("%d\n", count);

		}
	averageinches3=averageinches2/count;
	//printf("%d\n", averageinches3);
	*averagefeet = averageinches3/12;
	*averageinches = averageinches3%12;
	}

void saveHeights(FILE* fptr){
	char initial;
	int totaladd, feet, inches, value;
	printf("How many heights are you adding? ");
	scanf("%d", &totaladd);
	for (value = 1; value <= totaladd; value++){
		printf("Please enter initial and height1 ($ ##\'##\"): ");
		scanf(" %c %d\'%d\"", &initial, &feet, &inches);

		fprintf(fptr, "%c %d\'%d\"", initial, feet, inches);
		}
}
