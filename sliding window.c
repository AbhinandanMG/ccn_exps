#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <dos.h>
int n,r;
struct frame{
	char ack;
	int data;
	
}frm[10];
int sender(void);
void rec_vack(void);
void resend_sr(void);
void resend_gb(void);
void goback(void);
void selective(void);
int main(){
	int c;
	do{
		printf("\n\n1-Selective repeat ARQ\n 2-Goback ARQ\n 3- Exit");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		switch(c){
			case 1: selective(); break;
			case 2: goback(); break;
			case 3: exit(0); break;
		}
	}
	while(c>=4) ;
}

void goback(){
	sender();
	rec_vack();
	resend_gb();
	printf("\nAll frames sent succesfully\n");
}

void selective(){
	sender();
	rec_vack();
	resend_sr();
	printf("\nAll frames sent succesfully");
}
	
	int sender(){
		int i;
		printf("\n Enter teh no. of frames to be sent:");
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			printf("\nEnter data for frames[%d]",i);
			scanf("%d",&frm[i].data);
			frm[i].ack='y';
		}
		return 0;
	}
	
	void rec_vack(){
		int i;
		rand();
		r=rand()%n;
		frm[r].ack='n';
		for(i=1;i<=n;i++){
			if (frm[i].ack == 'n') printf("\nThe frame no. %d is not received\n",r);
		}
	}
	
	void resend_sr(){
		printf("\nResending frame %d",r);
		sleep(2);
		frm[r].ack = 'y';
		printf("\nThe received frame is %d",frm[r].data);
	}
	
	void resend_gb(){
		int i;
		printf("\n Resending from frame %d",r);
		for (i=r;i<=n;i++){
			sleep(2);
			frm[i].ack='y';
			printf("\nReceived data of frame %d is %d",i,frm[i].data);
		}
	}
	
