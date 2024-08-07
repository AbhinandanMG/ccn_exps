#include <stdio.h>	
 void main()
{
int d[8],i,c,c1,c2,c3;
int rec[8];

printf("enter 4 bits of data one by one\n");
scanf("%d %d %d %d",&d[3],&d[5],&d[6],&d[7]);
d[1]=d[3]^d[5]^d[7];
printf("parity bit at p1 %d\n",d[1]);
d[2]=d[3]^d[6]^d[7];
printf("parity bit at p2 %d\n",d[2]);
d[4]=d[5]^d[6]^d[7];
printf("parity bit at p4 %d\n",d[4]);
printf("\n encoded data is\n");

for(i=1;i<=7;i++){

printf("%d",d[i]);

}
printf("\nenter the received data bits one by one : \n");
for(i=1;i<=7;i++)
scanf("%d",&rec[i]);

	c1 = rec[4]^rec[5]^rec[6]^rec[7];
	c2 = rec[2]^rec[3]^rec[6]^rec[7];
	c3 = rec[1]^rec[3]^rec[5]^rec[7];
	c = c1*4+ c2*2+c3;
	if(c==0)
{
printf("no error while transmission of data \n");
}
else
{
printf("error on position %d",c);
}
printf("\n data received : ");
for(i=1;i<=7;i++)
printf("%d",rec[i]);

printf("\ncorrect message is : ");
rec[c] = !(rec[c]);

for(i=1;i<=7;i++)
printf("%d",rec[i]);
}
