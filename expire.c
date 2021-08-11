//Programming Assignment 2
//Andrew Cheng Jr
//7/15/21

#include <stdio.h>

int main(void){
//Variables!
int Td, Tm, Ty, Ed, Em, Ey, NDFMT, NDFME, Dm, D, Dl;
	NDFMT=0, NDFME=0;
	//Assigning Variables!
	printf("Please enter today's date(m/d/y):");
	scanf("%d/%d/%d", &Tm, &Td, &Ty);
	printf("Please enter the expiration date of the product(m/d/y):");
	scanf("%d/%d/%d", &Em, &Ed, &Ey);

if(Ty<=Ey){
	//days from remaining years 
	int Dy;
	Dy=365*(Ey-Ty);
	switch (Tm) {
		//Number of days in month(today)

		case 12: NDFMT=NDFMT+31;
		case 11: NDFMT=NDFMT+30;
		case 10: NDFMT=NDFMT+31;
		case 9: NDFMT=NDFMT+30;
		case 8: NDFMT=NDFMT+31;
		case 7: NDFMT=NDFMT+31;
		case 6: NDFMT=NDFMT+30;
		case 5: NDFMT=NDFMT+31;
		case 4: NDFMT=NDFMT+30;
		case 3: NDFMT=NDFMT+31;
		case 2: NDFMT=NDFMT+28;
		case 1: NDFMT=NDFMT+31;
		}

	switch (Em) {
		//Number of days in month(expiration date)

		case 12: NDFME=NDFME+31;
		case 11: NDFME=NDFME+30;
		case 10: NDFME=NDFME+31;
		case 9: NDFME=NDFME+30;
		case 8: NDFME=NDFME+31;
		case 7: NDFME=NDFME+31;
		case 6: NDFME=NDFME+30;
		case 5: NDFME=NDFME+31;
		case 4: NDFME=NDFME+30;
		case 3: NDFME=NDFME+31;
		case 2: NDFME=NDFME+28;
		case 1: NDFME=NDFME+31;}
	//E-expired, T-today(M,D)
	//E/E
	if(Tm<=Em&&Td<=Ed){
		Dm=NDFME-NDFMT;
		D=Ed-Td;
		Dl=Dy+Dm+D;}
	//E/T
	if(Tm<=Em&&Td>Ed){
		Dm=NDFME-NDFMT;
		D=Td-Ed;
		Dl=Dy+Dm-D;}
	//T/T
	if(Tm>Em&&Ey>Ty&&Td>Ed){
		Dm=NDFMT-NDFME;
		D=Td-Ed;
		Dl=Dy-Dm-D;}

	//T/E
	if(Tm>Em&&Ey>Ty&&Td<=Ed){
		Dm=NDFMT-NDFME;
		D=Ed-Td;
		Dl=Dy-Dm+D;}
	//For the printf statements, i didn't use the over-exaggerated messages
	printf("Days till you get a different message here:%d days\n", Dl);}
else
{	printf("NOOOOOOOO don't eat that thing! It's unfit for consumtion: it's EXPIRED! :(\n");}

return 0;
}
