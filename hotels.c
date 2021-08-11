//programming assignemnt 3
//Andrew Cheng
//7/17/21
# include <stdio.h>

double getRoomRate(char TypeofBed){
//Price Per Night
double PN;
switch(TypeofBed){
	case'D':
		PN=59.99;
		break;
	case'Q':
		PN=69.99;
		break;
	case'K':
		PN=79.99;
		break;}
return (PN);
}

double calcReservation(double PricePerDay, int Nights){
// Total, Percent, Price before Percent, amount of discounts
double T, P, PBP, AD;
;
AD=Nights/2;
P=1-(AD*.15);
//printf("%lf\n", P); - I used this when testing the values of the percent.
PBP=PricePerDay*Nights;
T=PBP*P;
return (T);
}

int main(){
//variables, Sizes and nights, price per night, price per night, totals, 
char S1, S2;
int N1, N2;
double T1, T2, PN1, PN2;

printf("Making Reservations\nDescribe your stay\nTypes of beds: D Q K\n");
printf("Reservation 1 (#Nights Type): ");
scanf("%d %c", &N1, &S1);
printf("Reservation 2 (#Nights Type): ");
scanf("%d %c", &N2, &S2);

PN1= getRoomRate(S1);
PN2= getRoomRate(S2);

T1= calcReservation(PN1, N1);
T2= calcReservation(PN2, N2);

if (T1<T2){
	printf("The %c reservation for %d is the better deal: $%.2lf\n", S1, N1, T1);}
if (T2<T1){
	printf("The %c reservation for %d is the better deal: $%.2lf\n", S2, N2, T2);}
if (T1==T2) {
	printf("Both reservations are a great deal being the same price: $%.2lf\n", T1);}

return 0; 
}


