//Programming assignment 7
//Andrew Cheng Jr
//7/26/21, 7/27/21

# include <stdio.h>
#define SIZE 50
#define COLUMNS 5
#define FILE_NAME "heights.txt"

int getMenuChoice();
void saveHeights(FILE*);
int loadHeightData(FILE*, int columns, char[], double[][columns]);
void displayHeightData(int, int columns, char[], double[][columns]);
double calcAverageHeight(int columns, double[]);


int main(){
	FILE* filePtr;
	int userInput, numData, row;
	char initialArray[SIZE];
	double heights2DArray[SIZE][COLUMNS], averageheight;
	_Bool fileopen;

	do
	{
		userInput = getMenuChoice();

		filePtr = fopen(FILE_NAME, "r");
		if(filePtr != NULL){
                	numData = loadHeightData(filePtr, COLUMNS, initialArray, heights2DArray);
			fileopen = 1;
			}
		else{
			fileopen = 0;
			}
		switch(userInput){
			case 1:
				if(fileopen == 0){
                                        printf("File could not be opened.\n");
					}
				else{
					displayHeightData(numData, COLUMNS, initialArray, heights2DArray);
					}
				break;
			case 2:
				if(fileopen == 0){
                                        printf("File could not be opened.\n");
                                        }
				else{
						displayHeightData(numData, COLUMNS, initialArray, heights2DArray);
						printf("Which row do you want to calculate for? ");
						scanf("%d", &row);
						averageheight = calcAverageHeight(COLUMNS, heights2DArray[row-1]);
						printf("%c's average height:%5.2lf\n", initialArray[row-1], averageheight);
					}
				break;
			case 3:
				filePtr = fopen(FILE_NAME, "a");

                                if(filePtr == NULL){
                                        printf("File could not be opened.\n");
                                }
                                else{
                                        saveHeights(filePtr);
                                        fclose(filePtr);
                                }
				break;
			case 0:
				break;
			default:
				printf("Please enter a valid option!\n");
		}
	}
		while (userInput != 0);
		return 0;


return 0;
}

int getMenuChoice(){
	int menuChoice;

	printf("***HEIGHT SYSTEM***\n");
	printf("1. Display Heights\n");
	printf("2. Calculate Average Height\n");
	printf("3. Save New Heights\n");
	printf("0. EXIT\n");
	printf("Enter your choice: ");
	scanf("%d", &menuChoice);

	return menuChoice;
}

int loadHeightData(FILE* inFile, int columns, char initial[], double height[][columns]){
	int dataI = 0;

	while(fscanf(inFile, " %c: ", &initial[dataI]) == 1){
		//printf("%c: ", initial[dataI]);
		for(int colI = 0; colI< columns; colI++){
			fscanf(inFile, " %lf", &height[dataI][colI]);
			//printf("%6.2lf", height[dataI][colI]);
		}
		dataI++;
	}
	return dataI;
}

void displayHeightData(int rows, int columns, char initialarray[], double heightarray[][columns]){
	for(int row = 0; row < rows; row++){
		printf("%d.%4c:", row+1, initialarray[row]);

		for(int col = 0; col < columns; col++){
			printf("%7.2lf", heightarray[row][col]);
		}
		printf("\n");
	}
}

double calcAverageHeight(int columns, double heights[]){
	double sumheights = 0;
	for(int index = 0; index < columns; index++){
		sumheights += heights[index];
	}
	return sumheights / columns;
}
void saveHeights(FILE* fptr){
	int totaladddatarows, value;
	char initial;
	double height1, height2, height3, height4, height5;
	printf("How many data rows are you adding? ");
        scanf(" %d", &totaladddatarows);
	for(value = 1; value <= totaladddatarows; value++){
		// The last letter of heights is capitilized just like the example!
		printf("Please enter initial and 5 heightS %d:", value);
		scanf(" %c %lf %lf %lf %lf %lf", &initial, &height1, &height2, &height3, &height4, &height5);
		fprintf(fptr, "%c: %.2lf %.2lf %.2lf %.2lf %.2lf\n", initial, height1, height2, height3, height4, height5);
	}
}
