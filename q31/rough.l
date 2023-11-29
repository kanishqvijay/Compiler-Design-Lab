%{
%}

nnum "-"[0-9]+(\.[0-9]+)?

pnum (\+)?[0-9]+(\.[0-9]+)?

%%

{nnum} {
	printf("'%s' is a negative number\n",yytext);
}

{pnum} {
	printf("'%s' is a positive number\n",yytext);
}

.|\n { }
%%


int yywrap(){
	return 1;
}

int main(){
	FILE *fp;
	char filename[50];
	printf("Enter the filename: \n");
	scanf("%s",filename);
	fp = fopen(filename,"r");
	yyin = fp;
	yylex();
	return 0;
}
