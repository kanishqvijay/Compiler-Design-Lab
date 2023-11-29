%{
%}

date (([0-2][0-9])|(3[0-1]))"/"([0-1][0-2])"/"[0-9]{4}

%%

{date} {
	printf("'%s' is a date\n",yytext);
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
