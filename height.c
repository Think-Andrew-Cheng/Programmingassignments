//programming asignment 5
//Andreww Cheng Jr
//7/21/21
// saying all the next comments are essentially troubleshooting and trying to find problems at the source, in the scanfs there is a space after most of the first " since i found that resulted in the input getting saved, not an enter. 

#include <stdio.h>

#define FILE_NAME "heights.txt"

int getMenuChoice();
void calcHeightDifference(int, int, int, int, int*, int*);
void saveHeights(FILE*);


int main(){
	int userChoice;
	FILE* filePtr;
	userChoice = getMenuChoice();
	//printf("%d",userChoice);

	 switch(userChoice){
                case 1:filePtr = fopen(FILE_NAME, "r");
                        if(filePtr == NULL){
                                printf("File could not be opened.\n");
                        }
                        else{
                                char Namex, Namey;
                                int feetx, inchesx, feety, inchesy, feetr, inchesr;
                                if(fscanf(filePtr, "%c %d\'%d\" %c %d\'%d\"", &Namex, &feetx, &inchesx, &Namey, &feety, &inchesy) == 6){
					//printf("%d%d%d%d", feetx, inchesx, feety, inchesy);
                               		calcHeightDifference(feetx, inchesx, feety, inchesy, &feetr, &inchesr);
                                	fclose(filePtr);

                                        if(feetx>feety){
                                                printf("%c is taller by %d'%d\"\n", Namex, feetr, inchesr);}
                                        if(feety>feetx){
                                                printf("%c is taller by %d'%d\"\n", Namey, feetr, inchesr);}
                                        if(feetx==feety&inchesx>inchesy){
                                                printf("%c is taller by %d'%d\"\n", Namex, feetr, inchesr);}
                                        if(feetx==feety&inchesy>inchesx){
                                                printf("%c is taller by %d'%d\"\n", Namey, feetr, inchesr);}
                        		if(feetx==feety&inchesx==inchesy){
						printf("%c and %c are the same height\n", Namex, Namey);}
					}
                        break;
			}
		case 2:
                        filePtr = fopen(FILE_NAME, "w");
                        if(filePtr == NULL){
                                printf("File could not be opened.\n");
                                }
                        else{
                                saveHeights(filePtr);
                                fclose(filePtr);
				}
                        break;


                default:printf("VALID(V-A-L-I-D) option please\n");}
	return 0;}

int getMenuChoice(){
	int menuChoice;

	printf("***HEIGHT SYSTEM***\n");
	printf("1 - Who's tallest?\n2 - Save new Heights\n");
	scanf("%d", &menuChoice);

	return menuChoice;
}

void calcHeightDifference(int feetx, int inchesx, int feety, int inchesy, int*feetr, int*inchesr){
	int feets, inchess;
	if(feetx>=feety&inchesx>=inchesy){
		feets=feetx-feety, inchess=inchesx-inchesy;
		//printf("A");
		//printf("%d,%d,%d,%d", feetx, inchesx, feety, inchesy);
		}
	if(feetx<feety&inchesx>inchesy){
                feets=feety-feetx-1, inchess=inchesy-inchesx+12;
		//printf("B");
		//printf("%d,%d,%d,%d", feetx, inchesx, feety, inchesy);
		}
	if(feetx>feety&inchesx<inchesy){
		feets=feetx-feety-1, inchess=inchesx-inchesy+12;
		//printf("C");
		//printf("%d,%d,%d,%d", feetx, inchesx, feety, inchesy);
		}
	if(feetx<feety&inchesx<inchesy){
		feets=feety-feetx,inchess=inchesy-inchesx;
		//printf("D");
		//printf("%d,%d,%d,%d", feetx, inchesx, feety, inchesy);
		}
	*feetr=feets;
	*inchesr=inchess;


	//printf("Feet, Inches :%d'%d\"\n", feets, inchess);
	//printf("f, i: %d'%d\"\n", *feetr, *inchesr);
}
void saveHeights(FILE* fptr){
        char Nh1;
	char Nh2;
        int Nf1, Ni1;
	int Nf2, Ni2;

        printf("Please enter initial and height 1 ($ ##'##\"):");
        scanf(" %c %d\'%d\"", &Nh1, &Nf1, &Ni1);
        //printf("%c %d\'%d\"\n", Nh1, Nf1, Ni1);

        printf("Please enter initial and height 2 ($ ##'##\"):");
        scanf(" %c %d\'%d\"", &Nh2, &Nf2, &Ni2);
        //printf("%c %d\'%d\"\n", Nh2, Nf2, Ni2);

	fprintf(fptr, "%c %d\'%d\"\n", Nh1, Nf1, Ni1);
	fprintf(fptr, "%c %d\'%d\"\n", Nh2, Nf2, Ni2);
}
