//Programming Assignment 1
//Andrew Cheng Jr
//7/14/21

#include <stdio.h>

int main(void) {
/*=======================================*/
	//creating the variables
	//Order 1
	int combo1;	
	float price1;
	char size1;
	//Order 2
	int combo2;
	float price2;
	char size2;
	//Order 3
	int combo3;
	float price3;
	char size3;
	//Order 4
	int combo4;
	float price4;
	char size4;
/*=======================================*/
	printf("Welcome to McKeith's! May I take your order, we offer 9 combo choices and 3 sizes for each.\n");

	//Order 1
	printf("Order 1 (Combo# Size Price):");
	scanf("%d %c%f/n", &combo1,  &size1, &price1);
	//Order 2
	printf("Order 2 (Combo# Size Price):");
	scanf("%d %c%f/n", &combo2,  &size2, &price2);
	//Order 3
	printf("Order 3 (Combo# Size Price):");
	scanf("%d %c%f/n", &combo3,  &size3, &price3);
	//Order 4
	printf("Order 4 (Combo# Size Price):");
	scanf("%d %c%f/n", &combo4,  &size4, &price4);
float total;
total=price1+price2+price3+price4;
/*=======================================*/
	//Table
	printf("===================================================\n");
	printf("||Combo Size   |   Combo Number   |   Combo Price||\n"); 
	printf("===================================================\n");
	printf("||%6c       |%9d         |%8.2f      ||\n", size1, combo1, price1);
	printf("||-------------|------------------|--------------||\n");
	printf("||%6c       |%9d         |%8.2f      ||\n", size2, combo2, price2);
	printf("||-------------|------------------|--------------||\n");
	printf("||%6c       |%9d         |%8.2f      ||\n", size3, combo3, price3);
	printf("||-------------|------------------|--------------||\n");
	printf("||%6c       |%9d         |%8.2f      ||\n", size4, combo4, price4);
	printf("||--------------------------------|--------------||\n");
	printf("|| Subtotal			  |%9.2f     ||\n", total);
	printf("||================================|==============||\n");
	printf("|| TOTAL			  |%9.2f     ||\n", total*1.0827); 
	printf("===================================================\n");
/*=======================================*/
return 0;

}
