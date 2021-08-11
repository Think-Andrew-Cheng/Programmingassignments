//programming assignment 4
//Andrew Cheng Jr
//7/20/21
//Did off Raspberry Pi(not π)

#include <stdio.h>

int getMenuChoice();
void getTime(int*, int*, int*, int*);
void addTime( int, int, int, int, int*, int*);
void subtractTime(int, int, int, int, int*, int*);

int main(){
	// if the letter part of the variable is followed by a x or y, x means the first time, and y means the second, and the number(1,2) specifies if it is the hours or min (1-hours, 2- min) 
	int option, timex1, timex2, timey1, timey2, total1, total2;

	printf("***Time Calculator**\n");

	option=getMenuChoice();
	getTime(&timex1, &timex2, &timey1, &timey2);
	if(option==1){
		addTime(timex1, timex2, timey1, timey2, &total1, &total2);
		}
	if(option==2){
		subtractTime(timex1, timex2, timey1, timey2, &total1, &total2);
		//using ifs to make sure the correct amount of time is displayed if the minutes on the first is less than the minutes on the second or if the hours on the first is less than the hours on the second or a combination of both of these casses
		if(total1<0 & total2>0){
		total1=total1+24;}
		if(total1<0 & total2<0){
		total1=total1+23, total2=total2+60;}
		if(total1>0 & total2<0){
		total1=total1-1, total2=total2+60;}
		}
	printf("*RESULT*\n");
	total1=total1+total2/60;
	total2=total2%60;
	printf("The total is: %d:%d\n", total1, total2);

return 0;

}
int getMenuChoice(){
	int optionx;
	printf("1 - addition\n");
	printf("2 - subtraction\n");
	scanf("%d", &optionx);
	return(optionx);}

void getTime(int*timex1, int*timex2, int*timey1, int*timey2){
	printf("Enter a military time ##:##\n");
	scanf("%d:%d",timex1, timex2);
	printf("Enter a military time ##:##\n");
        scanf("%d:%d",timey1, timey2);
}

void addTime(int timex1, int timex2, int timey1, int timey2, int*total1, int*total2){

	*total1=timex1+timey1;
	*total2=timex2+timey2;
	//printf("%ls:%ls", total1, total2);
}
void subtractTime(int timex1, int timex2, int timey1, int timey2, int*total1, int*total2){

        *total1=timex1-timey1;
        *total2=timex2-timey2;
	//printf("%ls:%ls", total1, total2);
}
