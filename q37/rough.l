%{
int highest = 0;
%}

word [A-Za-z]+

%%

{word} {
	if (yyleng > highest){
		highest = yyleng;
	}
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
	printf("Highest lenght is: %d",highest);
	return 0;
}
