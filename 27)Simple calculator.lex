%{
#include<stdio.h>
float op1=6,op2=7;
%}
%%
"+" {printf("sum =%f",op1+op2);}
"-" {printf("diff=%f",op1-op2);}
"*" {printf("mul=%f",op1*op2);}
"/" {printf("div=%f",op1/op2);}
%%
int yywrap(){}
int main()
{
printf("enter proper operator.");
yylex();
}
