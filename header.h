//TYPES OF NODES IN PARSETREE NODES.
typedef enum { connumType, constringType, varType, oprType, conintTyp, condoubleTyp } T; 
//TYPES OF VALUES IN SYMBOL TABLE NODES.
typedef enum { intType, doubleType, stringType } T1; 



//CONSTANT NUMBER NODE: NODE USED IN PARSE NODE TO STORE THE CONSTANT VALUE.
typedef struct { 
    double value; 
} connumNode;

//STRING NODE: NODE USED IN PARSE NODE TO STORE THE STRING.
typedef struct { 
    char* svalue; 
} constringNode; 

//VARIABLE NODE: NODE USED IN PARSE NODE TO STORE VARIABLE INDEX.
typedef struct { 
    int index;
} varNode; 

//OPERATOR NODE: NODE USED IN PARSE NODE TO STORE OPERATION RELATED STUFF.
typedef struct { 
    int optr;                           //OPERATOR TYPE
    int nops;                           //# OF OPERANDS
    int type;                           
    struct node **operands;             //THE OPERANDS IN THE OPERATION.
} operationNode; 



//PARSE NODE: THESE NODES ARE USED IN THE PARSE TREE FORMATION OF THE INPUT CODE AND THEN EXECUTED.
typedef struct node { 
    T type;                             //TYPE OF THE NODE IN THE PARSE TREE.
    union {                             //IT CAN HAVE ONE OF THESE STRUCTURES.
        connumNode constNum;            
        constringNode constString; 
        varNode var; 
        operationNode opr;
    }; 
}parseNode; 



/*FUNCTION NODE: USED TO STORE A FUNCTION'S ROOT NODE(ROOT NODE OF THE PARSE TREE OF THE FUNCTION CODE), 
  # OF PARAMETERS & THE PARAMETERS*/
typedef struct {
    int numPara;                        //# OF PARAMETERS.
    parseNode para[10];                 //PARAMETER LIST OF THE FUNCTION.
    parseNode *start;                   //ROOT NODE OF THE PARSE TREE OF THE FUNCTION CODE.
}funcNode;



//TABLE NODE: USED IN SYMBOL TABLE, OBJECTS TO STORE THE CONSTANTS.
typedef struct {
    int used;                           
    T1 type;                            //CONSTANT'S TYPE.
    double value;                       //VALUE OF CONSTANT.
} tabNode;



//OBJECT NODE: EACH OBJECT HOLDS THE MEMBER VARIABLES, MEMBER METHODS AND METHOD PARAMETERS.
typedef struct {
    int nodp;                           //# OF MEMBER VARIABLES.
    int inUse[10];                      //INDEXES OF THE MEMBER VARIABLES.
    tabNode data[1000];                 //MEMBER VARIABLES.
    funcNode methTable[100];            //MEMBER METHODS.
} objNode;



//CLASS NODE: EACH CLASS HOLDS SEVERAL OBJECTS.
typedef struct {
    objNode obj[100];                   //OBJECTS OF THE CLASS.
}classNode;