
#include<stdio.h>
#include<math.h>
#include<string.h>

char findxor(char data,char crc)
{
	
		if(data==crc)
		return '0';
		else
		return '1';
		
	
}

int main()
{
char data[50],crc[50],crc1[50],d[50],d1[50];
char c;
int a1=0,b1=0,c1=0,i;
int len,len1;
printf("enter the data : ");
scanf("%s",data);
len=strlen(data);
do{
strcpy(crc,"");
printf("enter the crc genarator (firstbit=1) and length < %d : ",len);
scanf("%s",crc);
c=crc[0];

len1=strlen(crc);

}while(c!='1' || len1>=len);
for(i=0;i<len1;i++)
{
crc1[i]='0';}

for(i=0;i<len1-1;i++)
{
data[len+i]='0';}

data[len+i]='\0';
printf("%s\n",crc);
printf("%s ",data);
for(i=0;i<len1;i++)
{
	d[i]=data[i];
}
d[i]='\0';
printf("\n***********SENDER SIDE***************\n");
while(strlen(d)!=(strlen(crc)-1))
{
b1=0;
if(d[0]=='1')
{

for(i=0;i<len1;i++)
{
	
	d[i]=findxor(d[i],crc[b1]);
	b1++;
}}

else
{
	for(i=0;i<len1;i++)
{
	
	d[i]=findxor(d[i],crc1[b1]);
	b1++;
}

}

d[i]=data[len1+a1];
a1++;

for(i=0;i<len1;i++)
{
	d[i]=d[i+1];
	
}
d[i]='\0';

}

memcpy(data+len,d,strlen(d));

printf("ENCODED DATA :%s ",data);

printf("\n*************RECEIVER END****************\n");
a1=0;

for(i=0;i<len1;i++)
{
	d1[i]=data[i];
}
d1[i]='\0';


while(strlen(d1)!=(strlen(crc)-1))
{
b1=0;
if(d1[0]=='1')
{

for(i=0;i<len1;i++)
{
	
	d1[i]=findxor(d1[i],crc[b1]);
	b1++;
}

}

else
{
	for(i=0;i<len1;i++)
{
	
	d1[i]=findxor(d1[i],crc1[b1]);
	b1++;
	
}

}

d1[i]=data[len1+a1];
a1++;


for(i=0;i<len1;i++)
{
	d1[i]=d1[i+1];
}
d1[i]='\0';

}

memcpy(data+len,d1,strlen(d1));

printf("DECODED DATA :%s ",data);
return 0;}


