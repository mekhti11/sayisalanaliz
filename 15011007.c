#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float fx(int,int,int,int,int,int);

int main() 
{
	float xL , xM , xR , yL , yM , yR , e;
	int a4 , a3 , a2 , a1 , a0 , maxi , cont_i , i;
	printf("a4 : ");
	scanf("%d",&a4);
	printf("a3 : ");
	scanf("%d",&a3);
	printf("a2 : ");
	scanf("%d",&a2);
	printf("a1 : ");
	scanf("%d",&a1);
	printf("a0 : ");
	scanf("%d",&a0);
	printf("xL (Baslangic noktasi) : ");
	scanf("%f",&xL);
	printf("xR (Bitis noktasi) : ");
	scanf("%f",&xR);
	printf("Epsilon degeri : ");
	scanf("%f",&e);
	printf("Maksimum iterasyon sayisi : ");
	scanf("%d",&maxi);
	yL = fx(a4,a3,a2,a1,a0,xL);
	yR = fx(a4,a3,a2,a1,a0,xR);
	if ((yL*yR)<0)
	{
		xM = (xL+xR)/2;
		yM = fx(a4,a3,a2,a1,a0,xM);
		cont_i = 1;
		printf("xL \t xR \t f(xL) \t f(xR) \t xM \t f(xM)");
		printf("%f \t %f \t %f \t %f \t %f \t %f" , xL , xR , yL , yR , xM , yM);
		while (fabs(yM)>e && (cont_i<maxi))
		{
			if ((yL*yM)<0)
			{
				yR = yM;
				xR = xM;
			}else{
				yL = yM;
				xL = xM;
			}
		xM = (xL+xR)/2;
		yM = fx(a4,a3,a2,a1,a0,xM);
		cont_i ++;
		printf("%f \t %f \t %f \t %f \t %f \t %f" , xL , xR , yL , yR , xM , yM);	
		}
		printf("Bu denklemin koku %f'dir." , xM);
	}else{
		printf("Bu denklemin koku yoktur.");
	}
	return 0;
}

float fx (int a4 , int a3 , int a2 , int a1 , int a0 , int b)
{
	int i , c;
	c = a0 + a1 * b;
	i = b * b ;
	c = c + a2 * i;
	i = i * b;
	c = c + a3 * i;
	i = i * b;
	c = c + a4 * i;
	return c;
}

