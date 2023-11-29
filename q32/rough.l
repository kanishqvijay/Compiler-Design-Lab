%{
%}

url ("http"[s]?)"://"([a-z0-9]+\.)+[a-z]{2,}

%%

{url} {
	printf("'%s' is a url\n",yytext);
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
