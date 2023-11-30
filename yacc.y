/*C-DECLARATIONS*/
%{ 
   /*INCLUDE STATEMENTS*/
   #include <stdio.h> 
   #include <stdlib.h> 
   #include <string.h> 
   #include <stdarg.h> 
   #include "header.h" 

   /*FUNCTION DECLARATIONS*/
   parseNode *createOpNode(int optr, int nops, ...); 
   parseNode *createOpNode2(int optr, int typ1, int nops, ...);
   parseNode *createVarNode(int i); 
   parseNode  createVarNode2(int i, int typ); 
   parseNode *createConNode(double i);
   parseNode *createConStrNode(char* i);

   void putFunc(int index, parseNode *start);
   void getArguments(parseNode *p);
   void addClsData(int index, parseNode *ptr);
   void addClsMethod(int index, parseNode *ptr);
   void addMethPara(int index, int methodindex, parseNode *ptr);
   void copyObj(int objindex, int clsindex);
   void clsDataInitialize(int objindex, int clsindex, parseNode *ptr);

   void printTheList(parseNode *ptr);

   void cleanSpace(parseNode *ptr);

   double executeTheNode(parseNode *ptr);

   int yylex(void); 
   void yyerror(char *s); 


   /*TABLES & CNT, INDEX VARIABLES*/
   int symTabList_index = 0;                 //INDEX IN LIST OF SYMBOLTABLES(FUNCTION LEVEL SYMBOL TABLE). 
   tabNode sym_Tab[100][1000];               //LIST OF SYMBOL TABLES.

   classNode class_Tab[100];                 //LIST OF CLASSES, EACH HAVING THEIR OWN OBJECTS STORED.
   objNode tempClsStruct[100];               //TEMP STORAGE OF CLASS STRUCTURES.

   int tpl_index = 0;                        //INDEX IN TEMP FUNCTION'S PARAMETER STORAGE..
   parseNode tempParaList[20];               //TEMPORARY FUNCTION'S PARAMETER STORAGE.
   funcNode func_Table[1000];                //FUNCTION TABLE TO STORE FUNCTIONS.

   int arg_cnt = 0;                          //MAINTAINING ARGUMENT CNT OF FUNCTION CALL.
   int tal_index;	                           //INDEX IN FUNCTION'S ARGUMENT LIST IN 'tempArgList'.
   double tempArgList[10];                   //STORING FUNCTION ARGUMENTS TEMPORARITLY.
   
   int itr = 0;                              //
%} 

/*DECLARATIONS IN YACC*/

                                             //TOKEN CAN HAVE YYLVAL AS AN ATTRIBUTE.
%union {                                     //"YYLVAL" CAN BE ONE OF THESE.
   int iVal; 
   char* strVal;
   double dVal;
   
   int symInd;
   parseNode *nPtr; 
};

/*TOKEN DECLARATIONS*/
%token <iVal> INTEGER
%token <dVal> DOUBLE
%token <strVal> STRING
%token INT FLOAT 

%token <symInd> ID  
%token UNTIL LOOP
%token CHECK 
%token PRINT PRINTF WRITE
%token CLSEND FUNEND MAIN RETURN FUNCALL CLSCONSTR CLSDATA CLSDATAINI OBJFUNCALL INPUT 

%type <nPtr> program main funclist func paralist classlist class datalist methodlist method methparalist  
%type <nPtr> body stmt stmts expr num funccall arglist printlist1 printlist inilist inilist1 inputlist return

%nonassoc CHECKX 
%nonassoc OTHERWISE 
%left GE LE EQ NE '>' '<' AND OR
%token EP EM EMUL EDIV
%left '+' '-' 
%left '*' '/' 
%token UP UM
%nonassoc UMINUS 

/*RULES OF THE PROGRAM STRUCTURE - CONTEXT FREE GRAMMAR*/
%% 

program: 
 classlist CLSEND funclist FUNEND {symTabList_index = 0;} main   { ;}        
 ;

main:
 MAIN '(' ')' '{' body return '}'                  { executeTheNode($5); cleanSpace($5); }
 ;

funclist :
 func funclist                                     { ;}
 | func                                            { ;}
 ;

func:
 ID FUNCALL paralist '{' body return '}'           { $$ = createOpNode(';', 2, $5, $6); putFunc($1, $$); }
 |                                                 { ;}
 ;
 
paralist:
 paralist ',' INT ID                               { tempParaList[tpl_index] = createVarNode2($4, 0); tpl_index++; }
 | paralist ',' FLOAT ID                           { tempParaList[tpl_index] = createVarNode2($4, 1); tpl_index++; }
 | INT ID                                          { tempParaList[tpl_index] = createVarNode2($2, 0); tpl_index++; }
 | FLOAT ID                                        { tempParaList[tpl_index] = createVarNode2($2, 1); tpl_index++; }
 |                                                 { ;}
 ;

 classlist:
 class classlist                                   { ;}
 | class                                           { ;}
 ; 

 class:
 ID '{' datalist  methodlist '}' '$'               { itr = 0; addClsData($1, $3); addClsMethod($1, $4); }
 |                                                 { $$= NULL;}
 ;

 datalist:
 datalist  INT ID ';'                              { $$ = createOpNode2('^', 0, 2, $1, createVarNode($3)); }
 | datalist  FLOAT ID ';'                          { $$ = createOpNode2('^', 1, 2, $1, createVarNode($3)); }
 | INT ID ';'                                      { $$ = createOpNode2('^', 0, 2, NULL, createVarNode($2)); }
 | FLOAT ID ';'                                    { $$ = createOpNode2('^', 1, 2, NULL, createVarNode($2)); }
 |                                                 { ;}
 ;

 methodlist:
 methodlist method                                 { $$ = createOpNode('^', 2, $1, $2); }
 | method                                          { $$ = $1; }
 ;

method:
 ID FUNCALL methparalist '{' body return '}' ';'   { $$ = createOpNode(';', 4, createVarNode($1), $3, $5, $6); }
 |                                                 { $$ =  NULL; }
 ; 

methparalist:
 methparalist ',' INT ID                           { $$ = createOpNode2('!', 0, 2, $1, createVarNode($4)); }
 | methparalist ',' FLOAT ID                       { $$ = createOpNode2('!', 1, 2, $1, createVarNode($4)); }
 | INT ID                                          { $$ = createOpNode2('!', 0, 2, NULL, createVarNode($2)); }
 | FLOAT ID                                        { $$ = createOpNode2('!', 1, 2, NULL, createVarNode($2)); }
 |                                                 { $$ = NULL; }
 ;

body: 
 body stmt                                         { $$ = createOpNode(';', 2, $1, $2); }                      
 |                                                 { $$ = NULL; }
 ;


stmt: 
 ';'                                               { $$ = createOpNode(';', 2, NULL, NULL); } 
 | expr ';'                                        { $$ = $1; }  
 | INT ID '=' expr ';'                             { $$ = createOpNode2('=', 0, 2, createVarNode($2), $4); } 
 | FLOAT ID '=' expr ';'                           { $$ = createOpNode2('=', 1, 2, createVarNode($2), $4); } 
 | INT ID ';'                                      { $$ = createOpNode2('=', 0, 1, createVarNode($2)); }
 | FLOAT ID ';'                                    { $$ = createOpNode2('=', 1, 1, createVarNode($2)); }
 | ID '=' expr ';'                                 { $$ = createOpNode('=', 3, createVarNode($1), $3); }
 | ID EP expr ';'                                  { $$ = createOpNode(EP, 2, createVarNode($1), $3); }
 | ID EM expr ';'                                  { $$ = createOpNode(EM, 2, createVarNode($1), $3); }
 | ID EMUL expr ';'                                { $$ = createOpNode(EMUL, 2, createVarNode($1), $3); }
 | ID EDIV expr ';'                                { $$ = createOpNode(EDIV, 2, createVarNode($1), $3); }
 | UNTIL '(' expr ')' stmt                         { $$ = createOpNode(UNTIL, 2, $3, $5); } 
 | LOOP '(' stmt stmt expr ')' stmt                { $$ = createOpNode(LOOP, 4, $3, $4, $5, $7); }
 | CHECK '(' expr ')' stmt %prec CHECKX            { $$ = createOpNode(CHECK, 2, $3, $5); } 
 | CHECK '(' expr ')' stmt OTHERWISE stmt          { $$ = createOpNode(CHECK, 3, $3, $5, $7); }  
 | WRITE '(' ID ')' ';'                            { $$ = createOpNode(WRITE, 1, createVarNode($3)); }
 | WRITE ID ';'                                    { $$ = createOpNode(WRITE, 1, createVarNode($2)); }
 | PRINT printlist1 ';'                            { $$ = createOpNode(PRINT, 1, $2); }
 | PRINTF '(' STRING ',' expr ')' ';'              { $$ = createOpNode(PRINTF, 2, createConStrNode($3), $5);}
 | ID '=' CLSCONSTR ID '(' inilist1 ')' ';'        { $$ = createOpNode(CLSCONSTR, 3, createVarNode($1), createVarNode($4), $6); copyObj($1, $4); }
 | ID '.' ID '.' ID '=' expr ';'                   { $$ = createOpNode(CLSDATAINI, 4, createVarNode($1),createVarNode($3),createVarNode($5),$7); }
 | INPUT  inputlist ';'                            { $$ = $2; }
 | '{' stmts '}'                                   { $$ = $2; }
 ; 

stmts: 
 stmt                                              { $$ = $1; } 
 | stmts stmt                                      { $$ = createOpNode(';', 2, $1, $2); } 
 ; 

expr: 
 num                                               { $$ = $1;}
 | ID                                              { $$ = createVarNode($1); } 
 | ID '.' ID '.' ID                                { $$ = createOpNode(CLSDATA, 3, createVarNode($1), createVarNode($3), createVarNode($5)); }
 | '-' expr %prec UMINUS                           { $$ = createOpNode(UMINUS, 1, $2); } 
 | expr '+' expr                                   { $$ = createOpNode('+', 2, $1, $3); } 
 | expr '-' expr                                   { $$ = createOpNode('-', 2, $1, $3); } 
 | expr '*' expr                                   { $$ = createOpNode('*', 2, $1, $3); } 
 | expr '/' expr                                   { $$ = createOpNode('/', 2, $1, $3); } 
 | expr '<' expr                                   { $$ = createOpNode('<', 2, $1, $3); } 
 | expr '>' expr                                   { $$ = createOpNode('>', 2, $1, $3); } 
 | expr GE expr                                    { $$ = createOpNode(GE, 2, $1, $3); } 
 | expr LE expr                                    { $$ = createOpNode(LE, 2, $1, $3); } 
 | expr NE expr                                    { $$ = createOpNode(NE, 2, $1, $3); } 
 | expr EQ expr                                    { $$ = createOpNode(EQ, 2, $1, $3); }
 | expr AND expr                                   { $$ = createOpNode(AND, 2, $1, $3); }
 | expr OR expr                                    { $$ = createOpNode(OR, 2, $1, $3); } 
 | '(' expr ')'                                    { $$ = $2; } 
 | ID UP                                           { $$ = createOpNode(UP,1, createVarNode($1)); }
 | ID UM                                           { $$ = createOpNode(UM,1, createVarNode($1)); } 
 | UP ID                                           { $$ = createOpNode(UP,1, createVarNode($2)); }
 | UM ID                                           { $$ = createOpNode(UM,1, createVarNode($2)); } 
 | funccall                                        { ;}
 | ID '.' ID '.' ID '(' {arg_cnt=0;} arglist ')'   { $$ = createOpNode(OBJFUNCALL, 4, createVarNode($1), createVarNode($3), createVarNode($5), $8); }
 ; 

num:
 INTEGER                                           { $$ = createConNode($1); } 
 | DOUBLE                                          { $$ = createConNode($1); } 
 ;

funccall : 
 ID '(' { arg_cnt=0;} arglist  ')'                 { $$ = createOpNode(FUNCALL, 2, createVarNode($1), $4); }
 ;

arglist : 
 expr ',' arglist                                  { arg_cnt++; $$ = createOpNode(';', 2, $1, $3); }
 | expr                                            { arg_cnt++; $$ = $1; }
 |                                                 { ;}
 ;

printlist1:
 printlist                                         { $$ = $1; }
 | '(' printlist ')'                               { $$ = $2; }
 ;

printlist:
 printlist ',' expr                                { $$ = createOpNode(';', 2, $1, $3); }
 | expr                                            { $$ = createOpNode(';', 2, NULL, $1); }
 | printlist ',' STRING                            { $$ = createOpNode(';', 2, $1, createConStrNode($3)); }
 | STRING                                          { $$ = createOpNode(';', 2, NULL,createConStrNode($1)); }

inilist1:
 inilist                                           { $$ = $1; }
 |                                                 { $$ = NULL; }
 ;

inilist:
 inilist ',' ID '=' num                            { $$ = createOpNode(';', 3, $1, createVarNode($3), $5); }
 | inilist ',' ID '=' ID                           { $$ = createOpNode(';', 3, $1, createVarNode($3), createVarNode($5)); }
 | ID '=' num                                      { $$ = createOpNode(';', 3, NULL, createVarNode($1), $3); }
 | ID '=' ID                                       { $$ = createOpNode(';', 3, NULL, createVarNode($1), createVarNode($3)); }
 ;

inputlist:
 '(' inputlist ')'                                 { $$ = $2; }
 | inputlist ',' ID                                { $$ = createOpNode(INPUT, 2, $1, createVarNode($3)); }
 | ID                                              { $$ = createOpNode(INPUT, 2, NULL, createVarNode($1)); }
 ;

return:
 RETURN expr ';'                                   { $$ = createOpNode(RETURN, 1, $2); }
 ;

%%

/*SUBROUTINES FOR YACC FILE*/

/*CREATE A PARSE NODE OF TYPE 'OPERATION', SAVE THE OPERATOR & OPERANDS AND RETURN THE POINTER*/
parseNode *createOpNode(int oper, int nops, ...) { 
   va_list ap; 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); ptr->opr.operands = malloc(nops * sizeof(parseNode)); 

   ptr->type = oprType;          //NODE TYPE: OPERATION.
   ptr->opr.optr = oper;         //OPERATOR TYPE.
   ptr->opr.nops = nops;         //# OF OPERANDS.

   //STORE THE OPERANDS.
   va_start(ap, nops); 
   for (int i = 0; i < nops; i++) {
      ptr->opr.operands[i] = va_arg(ap, parseNode*); 
   }
   va_end(ap);

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'OPERATION', SAVE THE OPERATOR & OPERANDS AND RETURN THE POINTER*/
parseNode *createOpNode2(int oper,int typ1, int nops, ...) { 
   va_list ap; 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); ptr->opr.operands = malloc(nops * sizeof(parseNode)); 

   ptr->type = oprType;          //NODE TYPE IS OPERATION.
   ptr->opr.optr = oper;         //OPERATOR TYPE.
   ptr->opr.nops = nops;         //# OF OPERANDS.
   ptr->opr.type = typ1; 

   //STORE THE OPERANDS.
   va_start(ap, nops); 
   for (int i = 0; i < nops; i++) {
      ptr->opr.operands[i] = va_arg(ap, parseNode*); 
   }
   va_end(ap);

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'VARIABLE', SAVE THE INDEX OF THE VARIABLE AND RETURN THE POINTER*/
parseNode *createVarNode(int i) { 
   parseNode *ptr; 

   ptr = malloc(sizeof(parseNode)); 

   ptr->type = varType;          //NODE TYPE: VARIABLE.
   ptr->var.index = i;           //INDEX OF THE VARIABLE IN SYMBOL TABLE.

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'VARIABLE' AND SAVE THE CONTENT*/
parseNode createVarNode2(int i, int typ) { 
   parseNode ptr; 
   ptr.type = (typ==0)?conintTyp: condoubleTyp; 
   ptr.var.index = i; 

   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'CONSTANT NUMBER', SAVE THE NUMBER AND RETURN THE POINTER*/
parseNode *createConNode(double i) { 
   parseNode *ptr; 
   ptr = malloc(sizeof(parseNode)); 
   ptr->type = connumType;       //NODE TYPE: CONSTANT.
   ptr->constNum.value = i;      //CONSTANT VALUE.
   return ptr; 
}

/*CREATE A PARSE NODE OF TYPE 'STRING', SAVE THE STRING AND RETURN THE POINTER*/
parseNode *createConStrNode(char* i) { 
   parseNode *ptr; 
   ptr = malloc(sizeof(parseNode)); 
   ptr->type = constringType;    //NODE TYPE: STRING.
   ptr->constString.svalue = i;  //STRING.
   return ptr; 
}

/*PUT THE # OF PARAMETERS, PARAMETERS, ROOT NODE OF THE FUNCTION INTO FUNCTION TABLE*/
void putFunc(int index, parseNode *start){
         
			func_Table[index].numPara = tpl_index;
			for(int i=0; i<tpl_index; i++){
				func_Table[index].para[i] = tempParaList[i];
			}
			tpl_index=0;

			func_Table[index].start = start;
}

/*GET THE ARGUMENTS INTO TEMPORARY LIST OF ARGUMENTS FOR FUNCTIONS AND CLASS MEMBER METHODS*/
void getArguments(parseNode *p){
    if (!p) return ;
    switch(p->type) {
        case connumType: 
            tempArgList[tal_index] = p->constNum.value; tal_index++; return;    
        case varType:
            tempArgList[tal_index] = sym_Tab[symTabList_index][p->var.index].value; tal_index++; return;
        case oprType:
            switch(p->opr.optr){
               case ';': 
                  {
                     getArguments(p->opr.operands[0]); getArguments(p->opr.operands[1]); return;
                  }
               case UMINUS: 
                  tempArgList[tal_index] = -executeTheNode(p->opr.operands[0]); tal_index++;return;

               case '+': 
                  tempArgList[tal_index] =  executeTheNode(p->opr.operands[0]) + executeTheNode(p->opr.operands[1]); tal_index++;return;

               case '-': 
                  tempArgList[tal_index] =  executeTheNode(p->opr.operands[0]) - executeTheNode(p->opr.operands[1]);tal_index++;return;

               case '*': 
                  tempArgList[tal_index] = executeTheNode(p->opr.operands[0]) * executeTheNode(p->opr.operands[1]); tal_index++;return;
               
               case '/': 
                  if(executeTheNode(p->opr.operands[1]) == 0){
                     yyerror("Divide by zero error."); 
                     tempArgList[tal_index] = 0;tal_index++;return;
                  }else{
                     tempArgList[tal_index] = executeTheNode(p->opr.operands[0]) / executeTheNode(p->opr.operands[1]);tal_index++;return; 
                  }
            }
    }
}

/*ADD THE MEMBER VARIABLES OF THE CLASS INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addClsData(int index, parseNode *ptr){
   if(!ptr){
      tempClsStruct[index].nodp = itr;
      return;
   } 
   switch(ptr->opr.optr){
      case '^':
         {  
            itr++;
            addClsData(index, ptr->opr.operands[0]);
            itr--;
            tempClsStruct[index].data[ptr->opr.operands[1]->var.index].type = (ptr->opr.type == 1)?doubleType:intType; 
            tempClsStruct[index].inUse[itr] = ptr->opr.operands[1]->var.index;
         }
   }
}

/*ADD THE CLASS METHODS INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addClsMethod(int index, parseNode *ptr){
   if(!ptr) return;

   switch(ptr->type){
      case oprType:
         {
            switch(ptr->opr.optr){
               case '^':
                  {
                     addClsMethod(index,ptr->opr.operands[0]);
                     addClsMethod(index,ptr->opr.operands[1]);
                  }

               case ';':
                  {
                     int methodindex =  ptr->opr.operands[0]->var.index;
                     tempClsStruct[index].methTable[methodindex].numPara = 0;
                     addMethPara(index, methodindex, ptr->opr.operands[1]);

                     parseNode *p = createOpNode(';', 2, ptr->opr.operands[2], ptr->opr.operands[3]);
                     tempClsStruct[index].methTable[methodindex].start = p;
                  }
            }
         }
   }
}

/*ADD THE PARAMETERS OF THE CLASS'S METHOD INTO THE TEMPORARY CLASS STRUCTURE - 'tempClsStruct'*/
void addMethPara(int index, int methodindex, parseNode *ptr){
if(!ptr) return;

   switch(ptr->type){
      case oprType:
         {
            switch(ptr->opr.optr){
               case '!':
                  {
                     addMethPara(index, methodindex, ptr->opr.operands[0]);
                     tempClsStruct[index].methTable[methodindex].para[tempClsStruct[index].methTable[methodindex].numPara] = createVarNode2(ptr->opr.operands[1]->var.index,ptr->opr.type);
                     tempClsStruct[index].methTable[methodindex].numPara = tempClsStruct[index].methTable[methodindex].numPara +1;
                     
                  }
            }
         }
   }
}

/*COPY THE STRUCTURE OF THE CLASS WHICH IS TEMPORARILY STORED IN 'tempClsStruct' 
  INTO THE OBJECT CREATED OF THAT CLASS*/
void copyObj(int objindex, int clsindex){
   class_Tab[clsindex].obj[objindex] = tempClsStruct[clsindex];
}

/*INITIALIZE THE CLASS MEMBER VARIABLES WHILE CREATING OBJECTS = CONSTRUCTOR IMPLEMENTATION.*/
void clsDataInitialize(int objindex, int clsindex, parseNode *ptr){
   if(!ptr)return;

   switch(ptr->type){
         case oprType:
            {
               switch(ptr->opr.optr){
                  case ';':
                     {  
                        clsDataInitialize(objindex, clsindex, ptr->opr.operands[0]);
                        class_Tab[clsindex].obj[objindex].data[ptr->opr.operands[1]->var.index].value = executeTheNode(ptr->opr.operands[2]); 
                        return;
                     }
               }
            }

   }
}

/*OUTPUT THE LIST OF EXPRESSIONS RECURSIVELY BY EVALUATING THE NODES*/
void printTheList(parseNode *ptr){
   if(!ptr)return;
   switch(ptr->type){
      case oprType:
         switch(ptr->opr.optr){
            case ';':
               {  
                  printTheList(ptr->opr.operands[0]);
                  if((ptr->opr.operands[1])->type == constringType){
                     printf("%s ",(ptr->opr.operands[1])->constString.svalue);
                  }else{
                     double num = executeTheNode(ptr->opr.operands[1]);
                     int num1 = (int)num;
                     double num2 = num1;
                     double zer = 0;
                     if(num2-num == zer){
                        printf("%d ", num1); 
                     }else{
                        printf("%lf ", num); 
                     }
                  }

               }
         }
   }
   
}

/*CLEAR THE SPACE OF THE NODE AFTER IT'S EXECUTION IS DONE*/
void cleanSpace(parseNode *ptr) { 
   if (!ptr) return;

   if (ptr->type == oprType) { 
      for (int i = 0; i < ptr->opr.nops; i++) 
         cleanSpace(ptr->opr.operands[i]); 
      free(ptr->opr.operands); 
   }

   free(ptr); 
}

/*EXECUTE THE NODES STARTING FROM ROOT OF THE INPUT MAIN FUNCTION CODE RECURSIVELY*/
double executeTheNode(parseNode *ptr) { 
   if (!ptr) return 0;

   switch(ptr->type) { 

      //IF IT IS A 'CONSTANT NODE' THEN RETURN IT'S VALUE.
      case connumType:  return ptr->constNum.value;

      //IF IT IS A 'VARIABLE NODE' THEN RETURN THE VALUE OF IT STORED IN SYMBOL TABLE.
      case varType:     return sym_Tab[symTabList_index][ptr->var.index].value; 

      //IF IT IS A 'OPERATOR NODE' THEN CHECK THE OPERATOR TYPE.
      case oprType: 
      
         switch(ptr->opr.optr) { 

            //WHILE LOOP IMPLEMENTATION.
            case UNTIL: 
               {
                  //EXECUTE OPERAND-2 UNTIL OPERAND-1 IS EVALUATED TO TRUE.
                  while(executeTheNode(ptr->opr.operands[0])) executeTheNode(ptr->opr.operands[1]);
                  return 0;
               }
               
            //FOR LOOP IMPLEMENTATION.
            case LOOP:
               {
                  executeTheNode(ptr->opr.operands[0]);           //DECLARATION OF LOOP VARIABLE. 
                  while(executeTheNode(ptr->opr.operands[2])){    //USING WHILE LOOP TO EXECUTE FOR LOOP.
                     executeTheNode(ptr->opr.operands[3]);        //FOR LOOP'S BODY.
                     executeTheNode(ptr->opr.operands[1]);        //UPDATION OF LOOP VARIABLE.
                  };
                  return 0;
               }

            //IF AND IF-ELSE IMPLEMENTATION.
            case CHECK: 
               {
                  if (executeTheNode(ptr->opr.operands[0])) 
                     executeTheNode(ptr->opr.operands[1]); 
                  else if (ptr->opr.nops > 2) 
                     executeTheNode(ptr->opr.operands[2]);
                  return 0;  
               }
               
            //WRITE FUNCTION: TO PRINT ANY INDIVIDUAL VARIABLES.
            case WRITE:
               {
                  switch(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type){
                     case intType:
                        {
                           int num = (int)sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value;
                           printf("%d\n",num);
                           break;
                        }
                     case doubleType:
                        {
                           printf("%f\n",sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
                           break;
                        }
                  }
                  return 0;
               }

            //OUTPUT FUNCTION: TO PRINT LIST OF EXPRESSIONS.
            case PRINT: 

               {
                  printTheList(ptr->opr.operands[0]);
                  printf("\n");
                  return 0;
               }
            
            //OUTPUT FUNCTION TO PRINT A STRING AND AN EXPRESSION.
            case PRINTF: 
               {
                  double num = executeTheNode(ptr->opr.operands[1]);
                  int num1 = (int)num;
                  double num2 = num1;
                  double zer = 0;
                  if(num2-num == zer){
                     printf("%s %d\n", ptr->opr.operands[0]->constString.svalue, num1);
                  }else{
                     printf("%s %lf\n", ptr->opr.operands[0]->constString.svalue, num);
                  }
                  return 0;
               }
               
            //SEGREGATE THE STATEMENTS IN THE STATEMENT LIST.
            case ';': 
               executeTheNode(ptr->opr.operands[0]); return executeTheNode(ptr->opr.operands[1]); 

            //ASSIGNMENT OPERATION.
            case '=': 
               {  
                  if(ptr->opr.nops == 1){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type = (ptr->opr.type == 0)?intType:doubleType;
                  }else if(ptr->opr.nops == 2){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type = (ptr->opr.type == 0)?intType:doubleType;
                     if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[1]);
                     }else{
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)executeTheNode(ptr->opr.operands[1]);
                     }
                     return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value); 
                  }else{
                     if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[1]);
                     }else{
                        sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)executeTheNode(ptr->opr.operands[1]);
                     }
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                     return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value); 
                  }
               }

            //ADD AND ASSIGN '+=' OPERATION.
            case EP:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value + executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value + executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //SUBTRACT AND ASSIGN '-=' OPERATION.
            case EM:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value - executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value - executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //MULTIPLY AND ASSIGN '*=' OPERATION.
            case EMUL:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value * executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value * executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }
            
            //DIVIDE AND ASSIGN '/=' OPERATION.
            case EDIV:
               {
                  if(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].type == doubleType){
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value / executeTheNode(ptr->opr.operands[1]);
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = (int)(sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value / executeTheNode(ptr->opr.operands[1]));
                  }
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value);
               }

            //RECOGNIZE (NEGATIVE NUMBERS WITHOUT ANY LEFT OPERAND) AND RETURN IT.
            case UMINUS: 
               return -executeTheNode(ptr->opr.operands[0]); 

            //ADDITION OPERATION.
            case '+': 
               return executeTheNode(ptr->opr.operands[0]) + executeTheNode(ptr->opr.operands[1]); 

            //SUBTRACTION OPERATION.
            case '-': 
               return executeTheNode(ptr->opr.operands[0]) - executeTheNode(ptr->opr.operands[1]);

            //MULTIPLICATION OPERATION.
            case '*': 
               return executeTheNode(ptr->opr.operands[0]) * executeTheNode(ptr->opr.operands[1]); 
            
            //DIVISION OPERATION.
            //IF OPERAND-2 IS EVALUATED TO 0, PRINT ERROR.
            case '/': 
               {
                  double op2 = executeTheNode(ptr->opr.operands[1]);
                  if( op2 == 0){
                     yyerror("Divide by zero error."); 
                     return 0;
                  }else{
                     return executeTheNode(ptr->opr.operands[0]) / op2; 
                  }
               }
            
            //BOOLEAN OPERATION = '<'.
            case '<': 
               return executeTheNode(ptr->opr.operands[0]) < executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '>'.
            case '>': 
               return executeTheNode(ptr->opr.operands[0]) > executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '>='.
            case GE: 
               return executeTheNode(ptr->opr.operands[0]) >= executeTheNode(ptr->opr.operands[1]);
               
            //BOOLEAN OPERATION = '<='.
            case LE: 
               return executeTheNode(ptr->opr.operands[0]) <= executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '!='.
            case NE: 
               return executeTheNode(ptr->opr.operands[0]) != executeTheNode(ptr->opr.operands[1]); 

            //BOOLEAN OPERATION = '=='.
            case EQ: 
               return executeTheNode(ptr->opr.operands[0]) == executeTheNode(ptr->opr.operands[1]); 
            
            //AND OPEERATION.
            case AND: 
               return (int)executeTheNode(ptr->opr.operands[0]) & (int)executeTheNode(ptr->opr.operands[1]); 
            
            //OR OPERATION.
            case OR: 
               return (int)executeTheNode(ptr->opr.operands[0]) | (int)executeTheNode(ptr->opr.operands[1]);
             
            //UNARY INCREMENT OPERATION.
            case UP : 
               {
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[0])+1); 
               }

            //UNARY DECREMENT OPERATION.
            case UM : 
               {
                  sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].used = 1;
                  return (sym_Tab[symTabList_index][ptr->opr.operands[0]->var.index].value = executeTheNode(ptr->opr.operands[0])-1);
               }
            
            //EXECUTE THE EXPRESSION AND RETURN IT.
            case RETURN: 
               return executeTheNode(ptr->opr.operands[0]); 
            
            //FUNCTION IS CALLED, EXECUTE THE PARSE TREE OF THE FUCNTION(EXECUTE THE FUNCTION).
            case FUNCALL:
               {
                  int funcindex = ptr->opr.operands[0]->var.index;

                  //TAKE THE FUNCTION CALL ARGUMENTS AND STORE IN TEMPORARY ARGUMENT LIST.
                  tal_index=0;
                  getArguments(ptr->opr.operands[1]);

                  //NEXT LEVEL SYMBOL TABLE == THIS FUNCTION LEVEL SYMBOL TABLE. 
                  symTabList_index++;

                  //ADDING ARGUMENTS OF THE FUNCTION CALL INTO THE SYMBOL TABLE.
                  for(int i =0; i <func_Table[funcindex].numPara ; i++){
                     sym_Tab[symTabList_index][func_Table[funcindex].para[i].var.index].type = (func_Table[funcindex].para[i].type == conintTyp)?intType:doubleType;
                     sym_Tab[symTabList_index][func_Table[funcindex].para[i].var.index].value = tempArgList[i];
                  }
                  tal_index=0;

                  //EXECUTE THE FUNCTION USING IT'S ROOT WHICH WAS STORED IN FUNCTION TABLE.
                  double res= executeTheNode(func_Table[funcindex].start);

                  //BACK TO PREVIOUS LEVEL SYMBOL TABLE.
                  if(symTabList_index >= 1) symTabList_index--;

                  // RETURN THE RETURN VALUE OF THE FUNCTION'S RETURN EXPRESSION.
                  return res;
               }
            
            //ACCESS CLASS MEMBER VARIABLES.
            case CLSDATA:
               {
                  return class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value;
               }

            //ASSIGN CLASS MEMBER VARIABLES THE EVALUATED EXPRESSION.
            case CLSDATAINI:
               {
                  
                  if(class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].type == intType){
                     class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value = (int)executeTheNode(ptr->opr.operands[3]);
                  }else{
                     class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value = executeTheNode(ptr->opr.operands[3]);
                  }
                  return class_Tab[ptr->opr.operands[0]->var.index].obj[ptr->opr.operands[1]->var.index].data[ptr->opr.operands[2]->var.index].value;
               }

            //MEMBER METHOD OF OBJECT IS CALLED, EXECUTE THE PARSE TREE OF THAT METHOD(EXECUTE THE FUNCTION).
            case OBJFUNCALL:
               {
                  int clsindex = ptr->opr.operands[0]->var.index;
                  int objindex = ptr->opr.operands[1]->var.index;
                  int methindex = ptr->opr.operands[2]->var.index;

                  //TAKE THE FUNCTION CALL ARGUMENTS AND STORE IN TEMPORARY ARGUMENT LIST.
                  getArguments(ptr->opr.operands[3]);

                  //NEXT LEVEL SYMBOL TABLE == THIS FUNCTION LEVEL SYMBOL TABLE. 
                  symTabList_index++;

                  //TAKE THE MEMBER VARIABLES OF THE CLASS INTO CURRENT LEVEL SYMBOL TABLE.
                  for(int i =0; i< 1000; i++){
                     sym_Tab[symTabList_index][i] = class_Tab[clsindex].obj[objindex].data[i];
                  }
                  
                  //ADDING ARGUMENTS OF THE FUNCTION CALL INTO THE SYMBOL TABLE.
                  for(int i =0; i <class_Tab[clsindex].obj[objindex].methTable[methindex].numPara ; i++){
                     sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].var.index].type = (class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].type == conintTyp)?intType:doubleType;
                     sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].methTable[methindex].para[i].var.index].value = tempArgList[i];
                  }
                  tal_index=0;

                  //EXECUTE THE FUNCTION USING IT'S ROOT WHICH WAS STORED IN FUNCTION TABLE.
                  double res= executeTheNode(class_Tab[clsindex].obj[objindex].methTable[methindex].start);

                  //UPDATE THE MEMBER VARIABLES OF THE CLASS.
                  for(int i =0; i < class_Tab[clsindex].obj[objindex].nodp ; i++){
                     if(sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].inUse[i]].used == 1){
                           for(int j = 0; j<100; j++){
                              class_Tab[clsindex].obj[j].data[class_Tab[clsindex].obj[objindex].inUse[i]].value = sym_Tab[symTabList_index][class_Tab[clsindex].obj[objindex].inUse[i]].value;
                           }
                     }
                  }

                  //BACK TO PREVIOUS LEVEL SYMBOL TABLE.
                  if(symTabList_index >= 1) symTabList_index--;

                  // RETURN THE RETURN VALUE OF THE FUNCTION'S RETURN EXPRESSION.
                  return res;

               }

            //INITIALIZE THE CLASS MEMBER VARIABLES WHILE CREATING OBJECTS = CONSTRUCTOR IMPLEMENTATION.
            case CLSCONSTR:
               {
                  int i = ptr->opr.operands[0]->var.index;
                  int j = ptr->opr.operands[1]->var.index;
                  clsDataInitialize(i, j, ptr->opr.operands[2]);
                  return 0;
               }
            
            //TAKE INPUT: ANY # OF INPUTS IN ONE LINE.
            case INPUT:
               {  
                  executeTheNode(ptr->opr.operands[0]);
                  double inp;
                  scanf("%lf", &inp);
                  if(sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].type == intType){
                     sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].value = (int)inp;
                  }else{
                     sym_Tab[symTabList_index][ptr->opr.operands[1]->var.index].value = inp;
                  }
               }
         } 
   } 
   return 0; 
} 


/*PRINTING ERROR MESSAGE*/
void yyerror(char *s) { 
   fprintf(stdout, "%s\n", s); 
}

/*MAIN FUNCTION : TAKES INPUT OF INPUTFILE & CALLS THE PARSER USING 'YYPARSE()'*/
int main(void) {
   char* s;
   scanf("%s", s);
   extern FILE* yyin;
   FILE* f = fopen(s,"r"); 
   yyin = f;
   yyparse(); 
   return 0; 
}