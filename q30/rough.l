%{
%}

word [a-zA-Z]+

number (-)?[0-9]+

%%

{word} {
	printf("%s is a word\n",yytext);
}

{number} {
	printf("%s is a number\n",yytext);
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
