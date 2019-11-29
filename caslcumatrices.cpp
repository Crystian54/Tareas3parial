#include<stdio.h>
#include<conio.h>
void Meter_val(int v[100][100], int f, int c);
void printMatrix(int v[100][100],int f, int c);
void printMatrixf(int *ptr,int f, int c);
void Traspuesta(int *ptr, int f, int c);
void suma(int va[100][100], int vb[100][100], int *ptrc,int f,int c,int n);
void resta(int va[100][100], int vb[100][100], int *ptrc,int f,int c,int n);
void Mult(int va[100][100],int vb[100][100],int f,int c,int n);
void menu();
void opcion(int& op);
void repe();
void lrepe(char& o);
int main (void){
    int a,b,op;
    float c;
    char o;
    do{
    int f,c,f2,c2;
    int mata[100][100];
    int matb [100][100];
    int *ptromma=&mata[0][0];
    int *ptrommb=&matb[0][0];
    int matc [100][100];
    int *ptrommc=&matc[0][0];

    menu();
    opcion(op);
    switch (op){
        case 1:
        printf("Dame el no. de filas y columnas de la b \t");
        scanf("%d %d", & f, &c);
        printf("Dame el no. de filas y columnas de la a\t");
        scanf("%d %d", & f2, &c2);
        Meter_val(mata, f, c);
        printf("\n");
        Meter_val(matb, f2, c2);
        printf("\n");
        printMatrix(mata, f, c);
        printf("\n");
        printMatrix(matb, f2, c2);
        printf("\n");
        if(f==f2 && c==c2){
        suma(mata, matb, ptrommc, c, f2, f);
        printMatrixf(ptrommc,c,f);
        printf("\n");
        }
        else{
            printf("No se puede realizar esta operacion");

        }
        break;
        case 2:
        printf("Dame el no. de filas y columnas de la b \t");
        scanf("%d %d", & f, &c);
        printf("Dame el no. de filas y columnas de la a\t");
        scanf("%d %d", & f2, &c2);
        Meter_val(mata, f, c);
        printf("\n");
        Meter_val(matb, f2, c2);
        printf("\n");
        printMatrix(mata, f, c);
        printf("\n");
        printMatrix(matb, f2, c2);
        printf("\n");
         if(f==f2 && c==c2){
        resta(mata, matb,ptrommc, c, f2, f);
        printMatrixf(ptrommc,c,f);
        printf("\n");
        }
        else{
            printf("No se puede realizar esta operacion");
        }
        break;
        case 3:
        printf("Dame el no. de filas y columnas de la b \t");
        scanf("%d %d", & f, &c);
        printf("Dame el no. de filas y columnas de la a\t");
        scanf("%d %d", & f2, &c2);
        Meter_val(mata, f, c);
        printf("\n");
        Meter_val(matb, f2, c2);
        printf("\n");
        printMatrix(mata, f, c);
        printf("\n");
        printMatrix(matb, f2, c2);
        printf("\n");
        if(c==f2)
        {
        Mult(mata,matb,f,c2,f2);
        printf("\n");
        }
        else
        {
      printf("No se puede realizar esta operacion");
    }

        break;
        default:
        break;

    }
    repe();
    lrepe(o);
    o=getch();
    }while(o=='S'||o=='s');
    printf("\n");
}
void menu(){
    printf("\tCalculadora de Matrices\n");
    printf("\n\t\t1-SUMA \n\n\t\t2-RESTA\n\n\t\t3-MULTIPLICACION\n\n");
}
void opcion(int& op){
    printf("\n\tDame la opcion (1-3)"); scanf("%d",&op);
}
void repe(){
    printf("\ndeseas efectuar otra operacion?\t");
}
void lrepe(char& o){
    printf("\nS-si\nN-no\t"); scanf("%c",&o);
}
void Meter_val (int v[100][100], int f, int c)
{
    for(int i=0; i<f; i++)
        {
          for(int j=0; j<c; j++)
          {
               printf("Dame el valor en [%d , %d]", i, j);
               scanf("%d", & v[i][j]);
          }
        }
}
void printMatrix(int v[100][100],int f, int c)
{
	for(int i = 0; i < f ; i++){
		for(int j = 0; j < c ; j++){
			printf("\t%d  ",v[i][j]);
		}
		printf("\n");
	}
}
void printMatrixf(int *ptr,int f, int c)
{
	for(int i = 0; i < f ; i++){
		for(int j = 0; j < c ; j++){
			printf("\t%d  ",*(ptr+j+(i*f)));
		}
		printf("\n");
	}
}

void suma(int va[100][100], int vb[100][100], int *ptrc,int f,int c,int n)
{
    for(int i=0; i<f; i++){
			for(int j=0; j<c; j++)
                {

              *(ptrc+j+(i*f))=va[i][j]+vb[i][j];

               }
                         }
}
void resta(int va[100][100], int vb[100][100], int *ptrc,int f,int c,int n)
{
    for(int i=0; i<f; i++){
			for(int j=0; j<c; j++)
                {

              *(ptrc+j+(i*f))=va[i][j]-vb[i][j];

               }
                         }
}
void Mult(int va[100][100],int vb[100][100],int f,int c,int n)
{
    int b[100][100];
    for(int i=0; i<f; i++)
    {
			for(int j=0; j<c; j++)
                {
                    int cont1=0;
			   for(int k=0; k<n; k++)
              {
                cont1=cont1+(va[i][k]*vb[k][j]);
              }
              b[i][j]=cont1;
              printf("%d\t", b[i][j]);

               }
            printf("\n");
    }
}
