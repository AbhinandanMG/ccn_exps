#include <stdio.h>	
 void main()
{
int d[10],i,c,c1,c2,c3;
int rec[10];

printf("enter 4 bits of data one by one\n");
scanf("%d %d %d %d",&d[3],&d[5],&d[6],&d[7]);
d[1]=d[3]^d[5]^d[7];
printf("parity bit at p1 %d\n",d[1]);
d[2]=d[3]^d[6]^d[7];
printf("parity bit at p2 %d\n",d[2]);
d[4]=d[5]^d[6]^d[7];
printf("parity bit at p4 %d\n",d[4]);
printf("\n encoded data is\n");
for(i=7;i>0;i--){

printf("%d",d[i]);
//printf("\n");
}
printf("\nenter the received data bits one by one : \n");
for(i=0;i<7;i++)
scanf("%d",&rec[i]);

	c1 = rec[6]^rec[4]^rec[2]^rec[0];
	c2 = rec[5]^rec[4]^rec[1]^rec[0];
	c3 = rec[3]^rec[2]^rec[1]^rec[0];
	c = c3*4+ c2*2+c1;
	if(c==0)
{
printf("no error while transmission of data \n");
}
else
{
printf("error on position %d",c);
}
printf("\n data received : ");
for(i=0;i<7;i++)
printf("%d",rec[i]);

printf("\ncorrect message is : ");
if(rec[7-c]==0)
rec[7-c]=1;

else
rec[7-c]=0;

for(i=0;i<7;i++)
printf("%d",rec[i]);
}
