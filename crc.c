#include <stdio.h>
#include<conio.h>
#include <string.h>
int main()
{ int i,j,keylen,mslen,flag=0;
	char input[100],key[30],temp[30],quo[100],rem[30],key1[30],temp1[20];
	
	printf("Enter data : ");
	scanf("%s",input);
	printf("Enter the key : ");
	scanf("%s",key);
	keylen = strlen(key);
	mslen = strlen(input);
	strcpy(key1,key);
	
	for(i=0;i<keylen-1;i++)
	{
		input[mslen+i]='0';
		}
	
	for(i=0;i<keylen;i++)
	{
		temp[i]=input[i];
	}
	
	for(i=0;i<mslen;i++)
	{quo[i]=temp[0];
		if(quo[i]=='0')
		{
			for(j=0;j<keylen;j++)
			{key[j]='0';
			}
		}
		else
		{ for(j=0;j<keylen;j++)
			{key[j]=key1[j];
			}
		} 
		
		for(j=keylen-1;j>0;j--)
		{ if(temp[j]==key[j])
			{
				rem[j-1]='0';
			}
			else{
				rem[j-1]='1';
			}
		}
		rem[keylen-1]=input[i+keylen];
		strcpy(temp,rem);
			
	}
	
	strcpy(rem,temp);
	
	printf("\n Quotient is : ");
	for(i=0;i<mslen;i++)
	{	
		printf("%c",quo[i]);
				
	}
	printf("\n Remainder is : ");
	for(i=0;i<keylen-1;i++)
		printf("%c",rem[i]);
		
		
	printf("\n Final data is:");
	for(i=0;i<mslen;i++)	
		printf("%c",input[i]);
	for(i=0;i<keylen-1;i++)
		printf("%c",rem[i]);

	
	
	printf("\n Enter recieved data:");
	scanf("%s",temp1);
	for(i=0;i<keylen;i++)
		temp[i]=temp1[i];
	for(i=0;i<mslen;i++){
		quo[i]=temp[0];
		if(quo[i]=='0')
			for(j=0;j<keylen;j++)key[j]='0';
		else
			for(j=0;j<keylen;j++)key[j]=key1[j];
		for(j=keylen-1;j>0;j--){
			if(temp[j]==key[j])
				rem[j-1]='0';
			else
				rem[j-1]='1';
				
		}
		rem[keylen-1]=temp1[keylen+i];
		strcpy(temp,rem);
			
	}
	strcpy(rem,temp);
	printf("\n Quotient is ");

	for(i=0;i<mslen;i++) printf("%c",quo[i]);
	printf("\n Reminder is ");
	for(i=0;i<keylen-1;i++)printf("%c",rem[i]);
	flag=0;
	
	
	for(i=0;i<keylen-1;i++)
	{
		if(rem[i]=='1'){
		flag=1;
		break;
		}
		else flag=0;
	}
	
	if(flag==0)printf("\n No error ");
	else printf("\n Error detected");
	return 0;
	
	
	
}

