/*C-DECLARATIONS*/
%{ 
    /*INCLUDE STATEMENTS*/
    #include <stdlib.h> 
    #include <string.h>
    #include "header.h" 
    #include "y.tab.h" 

    //FUNCTION DECLARATIONS.
    int lno=0;                  /*LINE NUMBER COUNT*/
    void yyerror(char *);       /*FUNCTION TO PRINT ERRORS*/
    long long hash(char* str);  /*HASH FUNCTION TO HASH ID(IDENTIFIERS) TO INTEGERS*/
%}

/*DECLARATIONS FOR USING THEM IN REGULAR EXPRESSIONS*/
alpha [a-zA-Z]
digit [0-9]

/*RULES FOR TOKENS - REGULAR EXPRESSIONS*/
%% 
"<*"                        {   //MULTI LINE COMMENT-SKIP IT!!
                                char ch = input();
                                while(ch != '*' 
                                || input() != '>'){
                                    ch = input();
                                }                       
                            }                      
"<<"                        {   //SINGLE LINE COMMENT-SKIP THE LINE FROM HERE!!
                                char ch = input();
                                while(ch != '\n'){
                                    ch = input();
                                }
                            }   
"___"                       {   //RECOGNIZE END OF CLASS IN INPUT FILE.
                                return CLSEND;        
                            }   
"..."                       {   //RECOGNIZE END OF SEPARATE FUNCTIONS DECLARATIONS IN INPUT.
                                return FUNEND;        
                            }   
"main"                      {   //RECOGNIZE THE "main" AND RETURN "MAIN" TOKEN : USED IN MAIN FUNCTION.
                                return MAIN;          
                            }   
"return"                    {   //RECOGNIZE "return" AND RETURN THE "RETURN" TOKEN : USED TO RETURN VALUES IN FUNCTIONS.                         
                                return RETURN;        
                            }   
"new"                       {   //RECOGNIZE "new" AND RETURN "CLSCONSTR" TOKEN : USED IN OBJECT CREATION STATEMENTS.
                                return CLSCONSTR;           
                            }   
"@"                         {   //RECOGNIZE "AT The Rate" SYMBOL : USED IN FUNCTION DECLARATIONS.
                                return FUNCALL;           
                            }   
">="                        {   //RECOGNIZE ">=" AS 'GREATER THAN OR EQUAL TO' OPERATOR AND RETURN THE "GE" TOKEN.
                                return GE;            
                            }   
"<="                        {   //RECOGNIZE "<=" AS 'LESS THAN OR EQUAL TO' OPERATOR AND RETURN THE "LE" TOKEN.
                                return LE;            
                            }   
"=="                        {   //RECOGNIZE "==" AS 'IS EQUAL TO' OPERATOR AND RETURN THE "EQ" TOKEN.
                                return EQ;            
                            }   
"!="                        {   //RECOGNIZE "!=" AS 'IS NOT EQUAL TO' OPERATOR AND RETURN THE "NE" TOKEN.
                                return NE;            
                            }   
"++"                        {   //RECOGNIZE "++" AS 'UNARY INCREMENT' OPERATOR AND RETURN THE "UP" TOKEN.
                                return UP;            
                            }   
"--"                        {   //RECOGNIZE "--" AS 'UNARY DECREMENT' OPERATOR AND RETURN THE "UM" TOKEN.
                                return UM;            
                            }   
"+="                        {   //RECOGNIZE "/=" AS 'ADD & ASSIGN' OPERATOR AND RETURN THE "EP" TOKEN.
                                return EP;            
                            }   
"-="                        {   //RECOGNIZE "/=" AS 'SUBTRACT & ASSIGN' OPERATOR AND RETURN THE "EM" TOKEN.
                                return EM;           
                            }   
"*="                        {   //RECOGNIZE "/=" AS 'MULTIPLY & ASSIGN' OPERATOR AND RETURN THE "EMUL" TOKEN.
                                return EMUL;          
                            }   
"/="                        {   //RECOGNIZE "/=" AS 'DIVIDE & ASSIGN' OPERATOR AND RETURN THE "EDIV" TOKEN.
                                return EDIV;          
                            }   
"&"                         {   //RECOGNIZE "&" AS 'AND' OPERATOR AND RETURN THE "AND" TOKEN.
                                return AND;          
                            }   
"|"                         {   //RECOGNIZE "|" AS 'OR' OPERATOR AND RETURN THE "OR" TOKEN.
                                return OR;          
                            }   
"int"                       {   //RECOGNIZE "int" AS DECLARATION AND RETURN THE "INT" TOKEN.
                                return INT;          
                            }   
"double"                    {   //RECOGNIZE "double" AS DECLARATION AND RETURN THE "FLOAT" TOKEN.
                                return FLOAT;          
                            }   
"until"                     {   //RECOGNIZE "until" AND RETURN THE "UNTIL" TOKEN == WHILE LOOP IN C++.
                                return UNTIL;          
                            }   
"loop"                      {   //RECOGNIZE "loop" AND RETURN THE "LOOP" TOKEN == FOR LOOP IN C++.
                                return LOOP;          
                            }   
"check"                     {   //RECOGNIZE "check" AND RETURN THE "CHECK" TOKEN == IF STATEMENT IN C++.
                                return CHECK;          
                            }   
"otherwise"                 {   //RECOGNIZE "otherwise" AND RETURN THE "OTHERWISE" TOKEN == ELSE STATEMENT IN C++.
                                return OTHERWISE;          
                            }
"printf"                    {   //RECOGNIZE "printf" AND RETURN THE "PRINTF" TOKEN : FOR PRINTING A STRING AND AN EXPRESSION.  
                                return PRINTF;          
                            }      
"write"                     {   //RECOGNIZE "write" AND RETURN THE "WRITE" TOKEN : FOR PRINTING ANY INDIVIDUAL VARIABLES.
                                return WRITE;          
                            }   
"cout"                      {   //RECOGNIZE "cout" AND RETURN THE "PRINT" TOKEN : FOR PRINTING ANY # OF EXPRESSIONS.
                                return PRINT;          
                            }   
"cin"                       {   //RECOGNIZE "return" AND RETURN THE "RETURN" TOKEN : USED TO RETURN VALUES IN FUNCTIONS.  
                                return INPUT;         
                            }   
[-()<>=+*/;{}.$,]           {   //RECOGNIZE THESE CHARACTERS AND RETURN THEM TO PARSER AS IT IS.  
                                return *yytext;          
                            }   
["].*["]                    {   //RECOGNIZE THE "String" AND RETURN THE STRING TOKEN WITH STRING VALUE OF IT.
                                char str[1000];
                                int sz = strlen(yytext);
                                for(int i=0; i< sz-2; i++){
                                    str[i] = *(yytext+i+1);
                                } 
                                for(int i=sz-2; i< 1000; i++){
                                    str[i] = '\0';
                                } 
                                yylval.strVal = str;
                                return STRING;
                            }     
{alpha}({alpha}|{digit})*   {   //RECOGNIZE THE "Identifier" AND RETURN ID TOKEN WITH HASHED VALUE OF THE IDENTIFIER.
                                yylval.symInd =  hash(yytext); 
                                return ID;
                            }   
[-]?[0-9]+[.][0-9]+         {   //RECOGNIZE THE NUMBER AS 'Double Value' AND RETURN "DOUBLE" TOKEN WITH IT'S VALUE.
                                yylval.dVal =  atof(yytext); return DOUBLE;
                            }   
0                           {   //RECOGNIZE THE NUMBER AS 0 AND RETURN "INTEGER" TOKEN WITH IT'S VALUE.
                                yylval.iVal = atoi(yytext); return INTEGER;
                            }   
[1-9][0-9]*                 {   //RECOGNIZE THE NUMBER AS 'Integer Value' AND RETURN "INTEGER" TOKEN WITH IT'S VALUE.
                                yylval.iVal = atoi(yytext); return INTEGER;
                            }   
[\n]                        {   //RECOGNIZE '\n' AS NEWLINE AND INCREASE LINENO(lno).
                                lno++;
                            }   
[\t ]                       {   //RECOGNIZE '\t' AND ' ' AND IGNORE THEM.
                                ;
                            }   
.                           {   //IF UNKNOWN CHARACTER RETURN ERROR.
                                yyerror("Unknown character");
                            }   

%% 

/*SUBROUTINES FOR LEX FILE*/

/*HASH FUNCTION WHICH TAKES IDENTIDIER AS STRING INPUT 
  AND PRODUCES INTEGER OUTPUT WHICH IS USED FOR INDEXING IN SYMBOL TABLE FOR THAT VARIABLE*/
long long hash(char* str){
    long long x = 28;
    long long ans = 0;
    for(int i=0; i< yyleng; i++){
        ans += ((str[i]-'a'+1)*x)%100;
        x++;
    }
    return ans;
}

/*YYWRAP FUNCTION*/
int yywrap(void) { 
    return 1; 
}       