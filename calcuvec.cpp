#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
void  menu ();
void leer_opcion(int &opt);
void printVector(int V[], int s);
void printVectorF(float V[], int s);
void scanVector(int V[], int s);
void suma(int v1[3],int v2[3],int *ptr);
void resta(int vector1[3],int v2[3],int *ptr);
void produccruz(int V[], int V2[],int *ptr);
int prodpunto(int V[], int V2[],int size);
float norma (int Vector[],int s);
void unitario(int vector1[3],float noor, float *ptr2);
int main(){
int opt,resu;
float nrm,res;
char rep;
  do{
int a[3];
int *ptra = &a[0];
int b[3];
int c[3];
float cf[3];
int *ptrC = &c[0];
float *ptrCf = &cf[0];
  		menu ();
		leer_opcion(opt);
switch(opt){
	case 1:
	scanVector(a,3);
	scanVector(b,3);
	printf("\n Vector 1\n");
	printVector(a,3);
	printf("\n Vector 2\n");
    printVector(b,3);
	suma(a,b,ptrC);
	printf("\n vector resultante\n");
    printVector(c,3);
    break;
	case 2:
	scanVector(a,3);
	scanVector(b,3);
	printf("\n Vector 1\n");
	printVector(a,3);
	printf("\n Vector 2\n");
    printVector(b,3);
	resta(a,b,ptrC);
	printf("\n vector resultante\n");
	printVector(c,3);
	break;
    case 3:
    scanVector(a,3);
	scanVector(b,3);
	printf("\n Vector 1\n");
	printVector(a,3);
	printf("\n Vector 2\n");
    printVector(b,3);
    printf("resultado\n");
    resu=prodpunto(a,b,3);
    printf(" \n %d ",resu);
    break;
    case 4:
    scanVector(a,3);
	scanVector(b,3);
	printf("\n Vector 1\n");
	printVector(a,3);
	printf("\n Vector 2\n");
    printVector(b,3);
    printf("resultado\n");
    produccruz(a,b,ptrC);
    printVector(c,3);

    break;
    case 5:
    scanVector(a,3);
    printf("\n Vector 1\n");
    printVector(a,3);
    res = norma(a,3);
    printf("resultado\n");
    printf(" \n %f ",res);
    break;
    case 6:
    scanVector(a,3);
    printf("\n Vector\n");
    printVector(a,3);
    res = norma(a,3);
    unitario(a,res,ptrCf);
    printVectorF(cf,3);
    break;
    default:
    printf("opcion invalida");
    break;
 }
 printf("\nDesea hacer otra operacion?\n");
 printf("S-Si\nN-No\n");
 rep = getch();
} while((rep=='S') || (rep=='s'));
}
void menu(){
 printf("1. suma\n");
 printf("2. resta\n");
 printf("3. producto punto\n");
 printf("4. producto escalar\n");
 printf("5. norma\n");
 printf("6. unitario\n");
 printf("\n");

 }
 void leer_opcion(int& opt){
 printf("seleccionar opcion\t"); scanf("%d",&opt);
 }


void printVector(int Vector[],int size){
    printf("\n");
    printf("las componentes del vector son;\t");
for (int i=0; i<size; i++){

	printf("[%d]\t",Vector[i]);
	}
	printf("\n");
}

void scanVector(int Vector[],int size){
for (int i=0; i<size; i++){
	printf("vector[%d]: \n",i);scanf("%d",&Vector[i]);
	}
}

void printVectorF(float myVector[],int size){
    printf("\n");
printf("\n vector unitario ahora es;\t ");
for (int i=0; i<size; i++){
	printf("[%.2f]\t",myVector[i]);
	}
}


void suma(int v1[3], int v2[3],int *ptr){
	for(int i = 0; i<3; i++){
		*(ptr+i) = v1[i] + v2[i];
	}
}


void resta(int v1[3], int v2[3],int *ptr){
	for(int i = 0; i<3; i++){
		*(ptr+i) = v1[i] - v2[i];
	}
}


float norma (int Vector[3],int size){
	float suma=0.0;
	for(int i = 0; i<size; i++){
		suma = suma +(Vector[i]*Vector[i]);

	}
	float b=sqrt(suma);
	return b;

}
int prodpunto(int V[], int V2[],int size){
    int suma=0;
    for(int i = 0; i<size; i++){
		suma =suma + (V[i]*V2[i]);

	}
	int b=suma;
	return b;
}
void produccruz(int V[], int V2[],int *ptr){
    *ptr=V[1]*V2[2]-V[2]*V2[1];
    *(ptr+1)=-V[0]*V2[2]+V[2]*V2[0];
    *(ptr+2)=V[0]*V2[2]-V[2]*V2[1];
}
void unitario(int vector1[3],float nor, float *ptr2){
    for(int i = 0; i<3; i++){
		*(ptr2+i) =vector1[i]/nor;
	}


}
