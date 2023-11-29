%{
%}

vowel [aeiouAEIOU][A-Za-z]*

%%

{vowel} { printf("%s is accepted\n",yytext);}

[a-zA-Z]+ { printf("%s is not accepted\n",yytext); }
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
