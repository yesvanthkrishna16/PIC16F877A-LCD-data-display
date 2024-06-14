#include<pic.h>
__CONFIG(0x3F3A);
//delay
void delay(unsigned int x)
{
while(x--);
}
//command
void cmd(char b)
{
RC0=0;//RS pin
RC1=0;//RW pin
RC2=1;//Enable pin
PORTD=b;
delay(65000);
RC2=0;//Enable pin
}
void data1(char c)
{
RC0=1;//RS pin
RC1=0;//RW pin
RC2=1;//Enable pin
PORTD=c;
delay(65000);
RC2=0;//Enable pin
}
void data(char *a)
{
RC0=1;
while(*a!='\0')
{
RC1=0;
RC2=1;
PORTD=*a;
delay(65000);
RC2=0;
a++;
}
}
void num(int m)
{
int a[10],i=0;
while(m>0)
{
a[i]=m%10;
m=m/10;
i++;
}
i--;
while(i>=0)
{
RC0=1;
RC1=0;
RC2=1;
PORTD=a[i]+0x30;
delay(65000);
RC2=0;
i--;
}
}
void main()
{
TRISC=0x00;
PORTC=0x07;
TRISD=0x00;
PORTD=0xFF;
cmd(0x38);
cmd(0x0F);
while(1)
{
cmd(0x80);
data("Yesvanth");
delay(65000);
cmd(0xC0);
data("Krishna");
delay(65000);
}
}