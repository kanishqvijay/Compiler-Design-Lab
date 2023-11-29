%{
%}

num [0-9]

%%

{num} {
	printf("'%s' is a digit\n",yytext);
}

. {
	printf("'%s' is not a digit\n",yytext);
}
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
