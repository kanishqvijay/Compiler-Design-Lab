%{
#include<stdio.h>
#include<string.h>
int count = 0;
char w[] = "Apples";
%}

%%
[a-zA-Z]+ { if(strcmp(yytext, w)==0) count++; }
				
.|\n { }
%%


int yywrap()
{
	return 1;
}

int main()
{
	FILE *fp;
	char filename[50];
	printf("Enter the filename: \n");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	yyin = fp;
	yylex();
	printf("%d", count);
	
}
