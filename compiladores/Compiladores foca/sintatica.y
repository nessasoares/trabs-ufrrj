%{
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>
#include <boost/algorithm/string/replace.hpp>

#define YYSTYPE atributos

using namespace std;


int i = 0;
int lbl = 0;
string swVar = "";

struct atributos
{
	string label; //nome
	string traducao;
	string tipo;
	string valor;
	int booleano;
	string operacao;
	int tamanho;
};

struct contexto{
	map<string,atributos> varMap;
	string labelInicio, labelFim;
};

struct funcao{
	string conteudo;
	string label;
	vector<string>tipos; 
	vector<atributos>parametros; 
};

struct dim{
	map<string, vector<string> > dim;
};

map<string,atributos> varInfo;
vector<funcao> stackFunction;
vector<contexto> varContext;
map<string,atributos>::iterator varInfoIt;
vector<string> variaveis;
vector<string> variaveisGlobais;
vector<string> tempGlobal;
vector <string> mensagens;
map<string,int> strTemp;
vector<dim> matContext;
vector<string> matTemp;
vector<atributos> varStack;
map<string, vector<atributos> > funcParam;
vector<atributos> temparam;
vector<string> setMeFree;
string retorno = "";

void yyerror(string);
int yylex(void);
string itos(int);
string typeCompare(string,string);
void addVar(string,string, string);
atributos getVar(string);
int checkVar(string label);
atributos operacoes(struct atributos, struct atributos,string, struct atributos);
void checkRelacionalType(string t1, string t2);
void checkBooleanType(string t1, string t2);
void checkNegacaoBool(string t1);
void declaraVariaveis();
void declaraVariaveisGlobais();
void checkDeclar(string label);
void getErrors();
void pushContext();
void popContext();
int verificaVariavel(string label, string tipo);
int getTamanho(string tipo);
void addGlobalVar(string,string, string);
void atribuiTempsGlobais();
contexto returnContexto();
void defineLabel(string, string);
string getLabel();
string getContinue();
string getBreak();
void pushFunction(string, string); //empilhar as funções
void popFunction(); 
void declaraFunctions();
void pushParameters(string);
string popParameters();
int checkVariableValue(string label);
void freeAll();

%}

%token TK_IF TK_ELSE TK_WHILE TK_LOOP TK_WRITE TK_READ TK_FOR TK_SWITCH TK_CASE TK_DEFAULT TK_CONTINUE TK_BREAK TK_LEN TK_COMENTARIO TK_COMENTARIOS
%token TK_NUM TK_BOOLEANO TK_CHAR TK_REAL TK_RELACIONAL TK_IGUALDADE TK_LOGICO TK_NEGACAO TK_STRING
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_BOOL TK_TIPO_STRING TK_GLOBAL TK_RETURN
%token TK_BOOL_TRUE TK_BOOL_FALSE
%token TK_FIM TK_ERROR

%start T

%left '{' '}'
%left '~' "&&" "||"
%left '=' '>' '<' "<=" ">=" "==" "!="
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

T 			: PUSH_CONTEXT S POP_CONTEXT
			{

				$$.traducao = $2.traducao;
			}

S 			:  COMANDOS
			{
				//yyerror("");
				getErrors();
				cout << "/*Compilador PACMAN*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n"<<endl;
				//adicionando o contexto global 
				declaraVariaveisGlobais();
				declaraVariaveis();
				cout<<"int main(void)\n{\n"<<endl;
				cout <<"goto init;\n\n"<<endl;
				declaraFunctions();
				cout <<"init: \n "<<endl;
				atribuiTempsGlobais();
				cout << $1.traducao<<endl;
				freeAll();
				cout<<"\treturn 0;\n}" << endl;

			}
			;

BLOCO		: PUSH_CONTEXT '{' COMANDOS '}' POP_CONTEXT
			{
				$$.traducao = $3.traducao;
			}
			| COMANDO
			{
				$$.traducao = $1.traducao;
			}
			;

PUSH_CONTEXT:
			{
				pushContext();
				$$.traducao = "";
		  		$$.label = "";
			}
			;

POP_CONTEXT:
			{
				popContext();
				$$.traducao = "";
			  	$$.label = "";
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| DECLAR ';'
			| IF
			| WRITE ';'
			| READ ';'
			| WHILE
			| FOR
			| SWITCH
			| JUMP
			| FUNCTION
			| RETURN
			| COMENTARIO
			| COMENTARIOS
			;

FUNCTION    : TK_TIPO_INT TK_ID '('PARAMETERS')' BLOCO 
			{
				
				$$.traducao = "";
				string conteudo = "\t\n" + $4.traducao + $6.traducao + "\t goto " + $2.label+"Fim;\n "  ;
				pushFunction($2.label, conteudo);
				
			}
			|TK_TIPO_CHAR TK_ID '('PARAMETERS')' BLOCO 
			{
				
				$$.traducao = "";
				string conteudo = "\t\n" +popParameters() + $6.traducao + "\tgoto " + $2.label+"Fim;\n "  ;
				pushFunction($2.label, conteudo);
			}
			|TK_TIPO_STRING TK_ID '('PARAMETERS')' BLOCO 
			{
				
				$$.traducao = "";
				string conteudo = "\t\n" +popParameters() + $6.traducao + "\tgoto " + $2.label+"Fim;\n "  ;
				pushFunction($2.label, conteudo);
			}
			|TK_TIPO_FLOAT TK_ID '('PARAMETERS')' BLOCO 
			{
				
				$$.traducao = "";
				string conteudo = "\t\n" +popParameters() + $6.traducao + "\tgoto " + $2.label+"Fim;\n "  ;
				pushFunction($2.label, conteudo);
			}
			;

RETURN      :TK_RETURN TK_ID ';'
			{
				$$.label = "TMP"+itos(i++);
				$$.traducao = "\n\t" +$$.label + " = " +getVar($2.label).valor + "\n";
				retorno = $$.label;

			}
			|
			{
				$$.traducao = "";
			} 	
			;
PARAMETERS  : TK_TIPO_INT TK_ID ';' PARAMETERS
			{
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				$$.label = "TMP"+itos(i++);
				$$.traducao = $4.traducao + "\tint " +$2.label + " = " + $$.label + ";\n";
				atributos a;
				a.tipo = "int";
				a.label = $$.label;
				temparam.push_back(a);
				addVar($2.label, a.label, a.tipo);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
			| TK_TIPO_FLOAT TK_ID ';' PARAMETERS
			{
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				$$.label = "TMP"+itos(i++);
				$$.traducao = $4.traducao + "\tfloat " +$2.label + " = " + $$.label + ";\n";
				atributos a;
				a.tipo = "float";
				a.label = $$.label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
			| TK_TIPO_CHAR TK_ID ';' PARAMETERS
			{
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				$$.label = "TMP"+itos(i++);
				$$.traducao = $4.traducao + "\tchar " +$2.label + " = " + $$.label + ";\n";
				atributos a;
				a.tipo = "char";
				a.label = $$.label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);

			}
			|TK_TIPO_STRING TK_ID ';' PARAMETERS
			{
				//$$.traducao = $1.label + " "+$2.traducao;
				//pushParameters($2.label);
				$$.label = "TMP"+itos(i++);
				$$.traducao = $4.traducao + "\tchar* " +$2.label + " = " + $$.label + ";\n";
				atributos a;
				a.tipo = "char*";
				a.label = $$.label;
				temparam.push_back(a);
				variaveis.push_back("\t" + a.tipo+ " "+a.label);
			}
			|
			{
				$$.traducao = "";
			}							
			;
			
CHAMAPARAM  : E ';' CHAMAPARAM
			{
				$$.traducao = $1.traducao + $3.traducao;
				atributos a;
				a.tipo = $1.tipo;
				a.label = $$.label;
				temparam.push_back(a);
			}
			|
			{
				$$.traducao = "";
			}
			;

JUMP		: BREAK
			| CONTINUE
			;

WRITE		: TK_WRITE W_OBJ
			{
				$$.traducao = $2.traducao + "\tcout << " + $2.valor + " << endl;\n";
			}
			;

W_OBJ		: TK_STRING
			{
				$$.valor = $1.valor;
				$$.traducao = "";
			}
			| '(' W_LINE ')'
			{
				$$.traducao = $2.traducao;
				$$.valor = $2.valor;
			}
			| E
			{
				$$.traducao = $1.traducao;
				$$.valor = $1.label;
			}
			;

W_LINE		: W_LINE ',' W_LINE
			{
				$$.valor = $1.valor + " << " + $3.valor;
				$$.traducao = $1.traducao + $3.traducao;
			}
			| TK_STRING
			{
				$$.traducao = "";
				$$.valor = $1.valor;
			}
			| E
			{
				$$.traducao = $1.traducao;
				$$.valor = $1.label;
			}
			|
			;

READ		: TK_READ R_OBJ
			{
				$$.traducao = "\tcin >> " + $2.traducao + ";\n";
			}
			;

R_OBJ		: TK_ID
			{
				if(getVar($1.label).tipo == "bool"){
					mensagens.push_back("Ler Booleano? Ficou biruta?");
				}
				$$.traducao = $1.label;
			}
			| '(' R_LINE ')'
			{
				$$.traducao = $2.traducao;
			}
			;

R_LINE		: TK_ID
			{
				if(getVar($1.label).tipo == "bool"){
					mensagens.push_back("Ler Booleano? Ficou biruta?");
				}
				$$.traducao = $1.label;
			}
			| R_LINE ',' R_LINE
			{
				$$.traducao = $1.traducao + " >> " + $3.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;
			
LEN			: TK_LEN '(' TK_STRING ')'
			{
				$$.tipo = "int";
				$$.traducao = "\tstrlen("+ $3.valor + ");\n";
			}
			| TK_LEN TK_STRING
			{
				$$.tipo = "int";
				$$.traducao = "\tstrlen("+ $2.valor + ");\n";
			}
			| TK_LEN '(' TK_ID ')'
			{
				$$.tipo = "int";
				if(getVar($3.label).tipo == "string"){
					$$.traducao = "\tstrlen("+ $3.label + ");\n";
				}else{
					mensagens.push_back("Sem paciência para iniciantes... Len é pra string... Apenas.");
				}
			}
			| TK_LEN TK_ID
			{
				$$.tipo = "int";
				if(getVar($2.label).tipo == "string"){
					$$.traducao = "\tstrlen("+ $2.label + ");\n";
				}else{
					mensagens.push_back("Sem paciência para iniciantes... Len é pra string... Apenas.");
				}
			}
			;

IF			: TK_IF '(' EXPRESSION ')' BLOCO ELSE
			{
				string fim = getLabel();
				string aux = "TMP"+itos(i++);
				variaveis.push_back("\tint "+aux);
				$$.traducao = $3.traducao + "\t"+ aux + " = !" + $3.label + "\n\tif("+aux+">=1)\n\t\tgoto "+$6.label+";\n" + $5.traducao + "\tgoto "+fim+";\n\t"+ $6.label +":\n" + $6.traducao + "\t" + fim +":\n";
			
			}
			;

ELSE		: TK_ELSE BLOCO
			{
				$$.label = getLabel();
				$$.traducao = $2.traducao;

			}
			|
			{
				$$.label = getLabel();
				$$.traducao = "";
			}
			;

WHILE		: TK_WHILE '(' EXPRESSION ')'  BLOCO 
			{
				$$.label = getLabel();
				string fim = getLabel();
				string aux = "TMP"+itos(i++);
				$$.traducao = "\t" + $$.label + ":\n" + $3.traducao + "\t" + aux + " = !" + $3.label + "\n\tif(" + aux + ">=1)\n\t\t goto "+fim+";\n" + $5.traducao + "\tgoto " + $$.label +";\n\t"+fim +":\n";
			}
			| TK_LOOP BLOCO TK_WHILE '(' EXPRESSION ')' ';'
			{
				$$.label = getLabel();
				$$.traducao = "\t" + $$.label + ": \n" + $2.traducao + $5.traducao + "\tif("+$5.label+">=1)\n\t\t goto " + $$.label + ";\n";
			}
			;

FOR			: TK_FOR '(' DECLAR ';' EXPRESSION ';' DECLAR ')' BLOCO
			{
				$$.label = getLabel();
				string fim = getLabel();
				string aux = "TMP" + itos(i++);
				$$.traducao = $3.traducao + "\t" + $$.label + ":\n" + $5.traducao + "\t" + aux + " = !" + $5.label + "\n\tif("+aux+">=1)\n\t\t goto "+fim+";\n" + $9.traducao + $7.traducao + "\tgoto " + $$.label + ";\n\t"+fim +":\n";
			}
			;

SWITCH		: TK_SWITCH '(' TK_ID ')' '{' CASES '}'
			{
				string fim = getLabel();
				boost::replace_all($6.traducao, "??" , $3.label);
				boost::replace_all($6.traducao, "!!" , fim);
				$$.traducao = $6.traducao + "\t" + fim + ":\n";
			}
			;

CASES		: TK_CASE E ':' BLOCO CASES
			{
				string fim = getLabel();
				$$.traducao = $2.traducao + "\tif(?? != " + $2.label + ")\n\t\tgoto " + fim + ";\n" + $4.traducao + "\tgoto !!;\n\t" + fim + ":\n" + $5.traducao;
			}
			| TK_CASE E ':' BLOCO DEFAULT
			{
				string fim = getLabel();
				$$.traducao = $2.traducao + "\tif(?? != " + $2.label + ")\n\t\tgoto " + fim + ";\n" + $4.traducao + "\tgoto !!\n\t" + fim + ":\n" + $5.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

DEFAULT		: TK_DEFAULT ':' BLOCO
			{
				$$.traducao = $3.traducao;
			}
			;

BREAK		: TK_BREAK ';'
			{
				
				$$.traducao = "\tgoto "+ getBreak() + ";\n";
			}
			;

CONTINUE	: TK_CONTINUE ';'
			{
				$$.traducao = "\tgoto "+ getContinue() + ";\n";
			}
			;

E 			: E '+' E
			{
				if($1.tipo == "string" && $3.tipo == "string"){
					$$.tipo = "string";
					$$.label = "TMP" + itos(i++);
					int tam1, tam2;
					if(strTemp.count($1.label)){
						tam1 = strTemp[$1.label];
					}else{
						tam1 = getVar($1.label).tamanho;
					}
					if(strTemp.count($3.label)){
						tam2 = strTemp[$3.label];
					}else{
						tam2 = getVar($3.label).tamanho;
					}
					variaveis.push_back("\tchar "+$$.label+"["+itos(tam1+tam2+1)+"]");
					strTemp[$$.label] = tam1+tam2;
					$$.traducao = $1.traducao + $3.traducao + "\tstrcat("+$$.label+", "+$1.label+");\n\tstrcat("+$$.label+", "+$3.label+");\n";
				}else{
					$$ = operacoes($$,$1,"+",$3);
				}
			}
			| E '-' E
			{
				$$ = operacoes($$,$1,"-",$3);
			}
			|E '*' E
			{
				$$ = operacoes($$,$1,"*",$3);

			}
			|E '/' E
			{
				$$ = operacoes($$,$1,"/",$3);

			}
			| TK_NUM
			{
				$$.label = "TMP" + itos(i++);
				//$$.traducao = "\tint " + $$.label + " = " + $1.traducao + ";\n";
				$$.traducao = "\t"+$$.label + " = " + $1.traducao + ";\n";
				variaveis.push_back("\tint "+$$.label);
				$$.tipo = "int";
			}
			| TK_REAL
			{
				$$.label = "TMP" + itos(i++);
				//$$.traducao = "\tfloat " + $$.label + " = " + $1.traducao + ";\n";
				$$.traducao = "\t"+$$.label + " = " + $1.traducao + ";\n";
				variaveis.push_back("\tfloat "+$$.label);
				$$.tipo = "float";
			}
			| TK_CHAR
			{
				$$.label = "TMP" + itos(i++);
			//	$$.traducao = "\tchar " + $$.label + " = " + $1.traducao + ";\n";
				$$.traducao = "\t"+$$.label + " = " + $1.traducao + ";\n";
				variaveis.push_back("\tchar "+$$.label);
				$$.tipo = "char";
			}
			|TK_BOOL_TRUE
			{
				$$.label = "TMP" + itos(i++);
				$1.traducao = "true";
				//$$.traducao = "\tint " + $$.label + " = 1;\n";
				$$.traducao = "\t" + $$.label + " = 1;\n";
				$$.tipo = "bool";
				variaveis.push_back("\tint "+$$.label);
				$$.booleano = 1; // usa essa bagaça aqui p comparar
			}
			|TK_BOOL_FALSE
			{
				$$.label = "TMP" + itos(i++);
				$1.traducao = "false";
				//$$.traducao = "\tint " + $$.label + " = 0;\n";
				$$.traducao = "\t" + $$.label + " = 0;\n";
				$$.tipo = "bool";
				variaveis.push_back("\tint "+$$.label);
				$$.booleano = 0; // usa essa bagaça aqui o comparar
			}
			| TK_ID
			{
					if(checkVar($1.label)){
					  $$.valor = getVar($1.label).valor;
					  $$.tipo = getVar($1.label).tipo;
					  $$.label = "TMP" + itos(i++);
					//$$.traducao = "\t"+ $$.tipo + " " + $$.label + " = " + $1.label + ";\n";
					if($$.tipo == "string"){
						variaveis.push_back("\tchar "+$$.label + "[" + itos(varContext[varContext.size()-1].varMap[$1.label].tamanho+1) + "]");
						strTemp[$$.label] = varContext[varContext.size()-1].varMap[$1.label].tamanho;
						$$.traducao = "\tstrcpy(" + $$.label + ", " + $1.label + ");\n"; 
					}else{
						variaveis.push_back("\t"+$$.tipo+ " " +$$.label);
						$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
					}
					}
			}
			| TK_STRING
			{
				$$.label = "TMP" + itos(i++);
				strTemp[$$.label] = $1.valor.length()-2;
				variaveis.push_back("\tchar* "+$$.label);
				$$.traducao = "\t"+$$.label+" = "+$1.valor+";\n";
				$$.tipo = "string";
			}
			| '(' TK_TIPO_INT ')' E
			{
				if($4.tipo == "bool"){
					//yyerror("Cast de BOOL pra INT aqui não!");
					mensagens.push_back("Cast de BOOL pra INT aqui não!");
				}
				if($4.tipo == "string"){
					//yyerror("Cast de BOOL pra INT aqui não!");
					mensagens.push_back("Cast de STRING pra INT aqui não!");
				}
				$$.label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tint " + $$.label + " = (int) " + $4.label + ";\n";
				$$.traducao = $4.traducao + "\t" + $$.label + " = (int) " + $4.label + ";\n";
				$$.tipo = "int";
				variaveis.push_back("\t"+$$.tipo+" "+$$.label);
			}
			| '(' TK_TIPO_FLOAT ')' E
			{
				if($4.tipo == "bool"){
				//	yyerror("Cast de BOOL pra FLOAT aqui não!");
					mensagens.push_back("Cast de BOOL pra FLOAT aqui não!");
				}
				if($4.tipo == "string"){
				//	yyerror("Cast de BOOL pra FLOAT aqui não!");
					mensagens.push_back("Cast de STRING pra FLOAT aqui não!");
				}
				$$.label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tfloat " + $$.label + " = (float) " + $4.label + ";\n";
				$$.traducao = $4.traducao + "\t " + $$.label + " = (float) " + $4.label + ";\n";
				$$.tipo = "float";
				variaveis.push_back("\t"+$$.tipo+" "+$$.label);

			}
			| '(' TK_TIPO_CHAR ')' E
			{
				if($4.tipo == "bool"){
				//	yyerror("Cast de BOOL pra CHAR aqui não!");
					mensagens.push_back("Cast de BOOL pra CHAR aqui não!");

				}
				if($4.tipo == "string"){
				//	yyerror("Cast de BOOL pra CHAR aqui não!");
					mensagens.push_back("Cast de STRING pra CHAR aqui não!");
				}
				$$.label = "TMP" + itos(i++);
				//$$.traducao = $4.traducao + "\tchar " + $$.label + " = (char) " + $4.label + ";\n";
				$$.traducao = $4.traducao + "\t" + $$.label + " = (char) " + $4.label + ";\n";
				$$.tipo = "char";
				variaveis.push_back("\t"+$$.tipo+" "+$$.label);

			}
			| '(' TK_TIPO_STRING ')' E
			{
				$$.tipo = "string";
				$$.label = "TMP" + itos(i++);
				if($4.tipo == "char"){
					variaveis.push_back("\tchar "+$$.label+"[2]");
					$$.traducao = $4.traducao + "\t" + $$.label + "[0] = " + $4.label + ";\n";
					strTemp[$$.label] = 1;
				}else if($4.tipo == "string"){
					$$.traducao = $4.traducao;
					$$.label = $4.label;
				}else if($4.tipo == "int"){
					variaveis.push_back("\tchar "+$$.label+"[12]");
					$$.traducao = $4.traducao + "\tsprintf(" + $$.label + ", \"%d\", " + $4.label + ");\n";
					strTemp[$$.label] = 11;
				}else if($4.tipo == "float"){
					variaveis.push_back("\tchar "+$$.label+"[16]");
					$$.traducao = $4.traducao + "\tsprintf(" + $$.label + ", \"%f\", " + $4.label + ");\n";
					strTemp[$$.label] = 15;
				}else{
					mensagens.push_back("OPA, conversão de boolean pra string é forçar a barra né!");
				}
				string temp = "TMP" + itos(i++);
				variaveis.push_back("\tchar* "+temp);
				$$.traducao = $$.traducao + "\t" + temp + " = " + $$.label;
				$$.label = temp;
			}
			| '(' E ')'
			{
				$$.traducao = $2.traducao;
				$$.label = $2.label;
				$$.tipo = $2.tipo;
				variaveis.push_back("\t"+$$.tipo+" "+$$.label);

			}
			| LEN
			{
				$$.label = "TMP" + itos(i++);
				variaveis.push_back("\tint "+$$.label);
				$$.traducao = "\t"+ $$.label + " = " + $1.traducao;
			}
			| '+''+' TK_ID
			{
				if(getVar($3.label).tipo == "int" || getVar($3.label).tipo == "float"){
					$$.traducao = "\t" + $3.label + " = " + $3.label + " + " +  itos(1) + ";\n";
					$$.tipo = getVar($3.label).tipo;
					$$.label = $3.label;
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar ++ nisso aí que tu botou...");
				}
			}
			| '-''-' TK_ID
			{
				if(getVar($3.label).tipo == "int" || getVar($3.label).tipo == "float"){
					$$.traducao = "\t" + $3.label + " = " + $3.label + " - " +  itos(1) + ";\n";
					$$.tipo = getVar($3.label).tipo;
					$$.label = $3.label;
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar -- nisso aí que tu botou...");
				}
			}
			| TK_ID '+''+'
			{
				if(getVar($3.label).tipo == "int" || getVar($3.label).tipo == "float"){
					$$.label = "TMP"+itos(i++);
					$$.tipo = getVar($3.label).tipo;
					variaveis.push_back("\t"+getVar($3.label).tipo + " " + $$.label);
					$$.traducao = "\t" + $$.label + " = " + $3.label + ";\n\t" + $3.label + " = " + $3.label + " + 1;\n";
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar ++ nisso aí que tu botou...");
				}
			}
			| TK_ID '-''-'
			{
				if(getVar($3.label).tipo == "int" || getVar($3.label).tipo == "float"){
					$$.label = "TMP"+itos(i++);
					$$.tipo = getVar($3.label).tipo;
					variaveis.push_back("\t"+getVar($3.label).tipo + " " + $$.label);
					$$.traducao = "\t" + $$.label + " = " + $3.label + ";\n\t" + $3.label + " = " + $3.label + " - 1;\n";
				}else{
					mensagens.push_back("Coitado de você que acha que dá pra usar -- nisso aí que tu botou...");
				}
			}
			| TK_ID DIM '[' E ']'
			{
				$$.tipo = getVar($1.label).tipo;
				$$.label = "TMP"+itos(i++);
				string tipo;
				if($$.tipo == "int*" || $$.tipo == "bool*"){
					variaveis.push_back("\tint "+$$.label);
					tipo = "int";
				}
				else if($$.tipo == "float*"){
					variaveis.push_back("\tfloat "+$$.label);
					tipo = "int";
				}
				else if($$.tipo == "char*"){
					variaveis.push_back("\tchar "+$$.label);
					tipo = "int";
				}
				else{
					variaveis.push_back("\tchar* "+$$.label);
					tipo = "int";
				}
				matTemp.push_back($4.label);
				if(matTemp.size() == matContext[varContext.size()-1].dim[$1.label].size()){
					string multiplier = "1";
					string index = "0";
					int j;
					$$.traducao = "";
					string aux1, aux2, aux3, aux4;
					for(j=0; j<matContext[varContext.size()-1].dim[$1.label].size(); j++){
						aux1 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux1);
						$$.traducao += "\t" + aux1 + " = " + multiplier + ";\n";
						aux2 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux2);
						$$.traducao += "\t" + aux2 + " = " + aux1 + " * " + matTemp[j] + ";\n";
						aux3 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux3);
						$$.traducao += "\t" + aux3 + " = " + index + ";\n";
						aux4 = "TMP"+itos(i++);
						variaveis.push_back("\t"+tipo+" "+aux4);
						$$.traducao += "\t" + aux4 + " = " + aux3 + " + " + aux2 + ";\n";
						index = aux4;
						multiplier = aux1 + " + " + matContext[varContext.size()-1].dim[$1.label][j];
					}
					$$.traducao = $2.traducao + $4.traducao + $$.traducao + "\t" + $$.label + " = " + $1.label + "["+index+"];\n";
				}else{
					mensagens.push_back("Dimensão paralela da matriz: "+$1.label);
				}
				matTemp.clear();
			}
			| TK_ID '('CHAMAPARAM')'
			{
				string declaratudo = "";
				int i;
				for(i = 0; i < funcParam[$1.label].size(); i++){
					if(temparam[i].tipo == funcParam[$1.label][i].tipo){
						declaratudo += "\t" + funcParam[$1.label][i].label + " = " + temparam[i].label + ";\n";
					}else{
						mensagens.push_back("Não deu match nos parâmetros");
					}
				}
				string retorno_funcao = "TMP" + itos(i++);
				$$.traducao = $3.traducao + declaratudo + "\tgoto " + $1.label + ";\n\t"+ $1.label+"Fim" +": \n\t"+ retorno_funcao +" = "+ retorno +"\n";
				retorno = "";
			}	
			;
COMENTARIO  : TK_COMENTARIO
			{
				$$.traducao = "";
			}
			;
			
COMENTARIOS  : TK_COMENTARIOS
			{
				$$.traducao = "";
			}
			;

DECLAR      : TK_TIPO_INT TK_ID
			{
				//checkDeclar($2.label);
				$$.traducao = "\tint " + $2.label + ";\n";
				$$.tipo = "int";
				addVar($2.label, "", $$.tipo);


			}
			| TK_TIPO_INT TK_ID '=' E

			{
				if($4.tipo == "string" || $4.tipo == "string*"){
					mensagens.push_back("STRING pra INT? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				$$.tipo = "int";
				if($4.tipo != "int" && $4.tipo != "int*"){
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tint "+ $2.label + " = (int) " + $4.label + ";\n";
				}else{
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tint "+ $2.label + " = " + $4.label + ";\n";
				}
				addVar($2.label,  $4.label, $$.tipo);
			}
			| TK_TIPO_FLOAT TK_ID
			{
				//checkDeclar($2.label);
				$$.traducao = "\tfloat " + $2.label + ";\n";
				$$.tipo = "float";
				addVar($2.label, "", $$.tipo); //coloquei o valor como "" pq é só a declaração, mas depois tem que ver isso

			}
			| TK_TIPO_FLOAT TK_ID '=' E
			{
				if($4.tipo == "string" || $4.tipo == "string*"){
					mensagens.push_back("STRING pra FLOAT? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				if($4.tipo != "float" && $4.tipo != "float*"){
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tfloat "+ $2.label + " = (float) " + $4.label + ";\n";
				}else{
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tfloat "+ $2.label + " = " + $4.label + ";\n";
				}
				$$.tipo = "float";
				addVar($2.label, $4.label, $$.tipo);

			}
			| TK_TIPO_CHAR TK_ID
			{
				//checkDeclar($2.label);
				$$.traducao = "\tchar " + $2.label + ";\n";
				$$.tipo = "char";
				addVar($2.label, "", $$.tipo);
			}
			| TK_TIPO_CHAR TK_ID '=' E
			{
				if($4.tipo == "string" || $4.tipo == "string*"){
					mensagens.push_back("STRING pra CHAR? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				if($4.tipo != "char" && $4.tipo != "char*"){
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tchar "+ $2.label + " = (char) " + $4.label + ";\n";
				}else{
					$$.traducao = $4.traducao;
					//$$.traducao = $4.traducao + "\tchar "+ $2.label + " = " + $4.label + ";\n";
				}
				$$.tipo = "char";
				addVar($2.label, $4.label, $$.tipo);

			}
			| TK_TIPO_BOOL TK_ID
			{
				//checkDeclar($2.label);
			    $$.traducao = "\tint " + $2.label + ";\n";
				$$.tipo = "bool";
				addVar($2.label, "", $$.tipo);

			}
			| TK_TIPO_BOOL TK_ID '=' EXPRESSION
			{
				//checkDeclar($2.label);
				$$.traducao = $4.traducao;
			   // $$.traducao = $4.traducao + "\tint " + $2.label + " = " + $4.label + ";\n";
			    $$.tipo = "bool";
			    addVar($2.label, $4.label, $$.tipo);
			}
			| TK_TIPO_INT TK_ID '=' EXPRESSION
			{
				//checkDeclar($2.label);
				$$.label = "TMP" + itos(i++);
				$$.traducao = $4.traducao;
				//$$.traducao = $4.traducao + "\tint"+" " + $2.label + " = " + $4.label + ";\n";
				addVar($2.label, $4.label, $$.tipo);

			}
			| TK_ID '=' E
			{
				$$.tipo = getVar($1.label).tipo;
				//cout << $$.tipo << endl;
				if(($$.tipo == "bool" || $$.tipo == "bool*") && ($3.tipo != "bool" && $3.tipo != "bool*")){
					//yyerror("Conversão inválida de "+$3.tipo+" para bool");
					mensagens.push_back("Conversão inválida de "+$3.tipo+" para bool");
				}
				if($3.tipo == "string"  || $3.tipo == "string*"){
					if(getVar($1.label).tipo == "string"){
						if(strTemp.count($3.label)>0){
							varContext[varContext.size()-1].varMap[$1.label].tamanho = strTemp[$3.label];
							$$.traducao = $3.traducao + "\t"+$1.label+" = "+$3.label+";\n";
						}else{
							varContext[varContext.size()-1].varMap[$1.label].tamanho = varContext[varContext.size()-1].varMap[$3.label].tamanho;
							$$.traducao = $3.traducao + "\t"+$1.label+" = "+$3.label+";\n";
						}
					}else{
						mensagens.push_back("Conversão inválida de string para "+getVar($3.label).tipo);
					}
				}else if((getVar($1.label).tipo == "string" || getVar($1.label).tipo == "string*")){
					mensagens.push_back("Conversão inválida de "+getVar($3.label).tipo+" para string");
				}else{
					$$.traducao = $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
				}
			}
			|	TK_TIPO_STRING TK_ID
			{
				$$.label = $2.label;
				$$.traducao = "\tchar* " + $$.label + " = (char*) malloc(200 * sizeof(char));\n";
				$$.tipo = "string";
				addVar($$.label, "", $$.tipo);
			}
			|	TK_TIPO_STRING TK_ID '=' E
			{
				$$.label = $2.label;
				$$.tipo = "string";
				addVar($$.label, "", $$.tipo);
				if($4.tipo == "string" || $4.tipo == "string*"){
					if(strTemp[$4.label] > 0){ 
						$$.traducao = $4.traducao;
						//$$.traducao = $4.traducao + "\tchar* " + $$.label + " = "+$4.label+";\n";
						varContext[varContext.size()-1].varMap[$$.label].tamanho = strTemp[$4.label];
					}else{
						$$.traducao = $4.traducao;
						//$$.traducao = $4.traducao + "\tchar* " + $$.label + " = "+$4.label+";\n";
						varContext[varContext.size()-1].varMap[$$.label].tamanho = varContext[varContext.size()-1].varMap[$4.label].tamanho;
					}
				}else{
					mensagens.push_back("Não tem conversão implícita pra string não, querido, usa (string) aí.");
				}
			}
			| GLOBAL
			| TK_ID '+''=' E
			{
				string tipo = varContext[varContext.size()-1].varMap [$1.label].tipo;
				string temp = "TMP"+itos(i++);
				if(tipo == "string"){
					if($4.tipo == "string"){
						if(strTemp.count($4.label)){
							variaveis.push_back("\tchar "+temp+"["+itos(getVar($1.label).tamanho+strTemp[$4.label]+1)+"]");
							strTemp[temp] = getVar($1.label).tamanho+strTemp[$4.label];
						}else{
							variaveis.push_back("\tchar "+temp+"["+itos(getVar($1.label).tamanho+getVar($4.label).tamanho+1)+"]");
							strTemp[temp] = getVar($1.label).tamanho+getVar($4.label).tamanho;
						}
						$$.traducao = $4.traducao + "\t strcpy("+temp+", "+$1.label+");\n\tstrcat("+temp+", "+$4.label+");\n";
						$$.label = temp;
					}else{
						mensagens.push_back("Operações de strings somente com strings!");
					}
				}else{
					if($4.tipo == "string" || $4.tipo == "bool" || tipo == "bool"){
						mensagens.push_back("operação matemática com bool ou string aqui não!");
					}else{
						if(tipo == "int"){
							if($4.tipo == "int"){
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " + " + $4.label + ";\n";
							}else{
								variaveis.push_back("\tint "+temp);
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + temp + " = (int) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " + " + temp + ";\n";
							}
						}else if(tipo == "float"){
							if($4.tipo == "float"){
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " + " + $4.label + ";\n";
							}else{
								variaveis.push_back("\tfloat "+temp);
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + temp + " = (float) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " + " + temp + ";\n";
							}
						}else if(tipo == "char"){
							if($4.tipo == "char"){
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " + " + $4.label + ";\n";
							}else{
								variaveis.push_back("\tchar "+temp);
								$$.label = $1.label;
								$$.traducao = $4.traducao + "\t" + temp + " = (char) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " + " + temp + ";\n";
							}
						}
					}
				}
			}
			| TK_ID '-''=' E
			{
				string tipo = varContext[varContext.size()-1].varMap [$1.label].tipo;
				string temp = "TMP"+itos(i++);
				if($4.tipo == "string" || $4.tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if($4.tipo == "int"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " - " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (int) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " - " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if($4.tipo == "float"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " - " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (float) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " - " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if($4.tipo == "char"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " - " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (char) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " - " + temp + ";\n";
						}
					}
				}
			}
			| TK_ID '*''=' E
			{
				string tipo = varContext[varContext.size()-1].varMap [$1.label].tipo;
				string temp = "TMP"+itos(i++);
				if($4.tipo == "string" || $4.tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if($4.tipo == "int"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " * " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (int) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " * " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if($4.tipo == "float"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " * " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (float) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " * " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if($4.tipo == "char"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " * " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (char) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " * " + temp + ";\n";
						}
					}
				}
			}
			| TK_ID '/''=' E
			{
				string tipo = varContext[varContext.size()-1].varMap [$1.label].tipo;
				string temp = "TMP"+itos(i++);
				if($4.tipo == "string" || $4.tipo == "bool" || tipo == "bool" || tipo == "string"){
					mensagens.push_back("operação matemática com bool ou string aqui não!");
				}else{
					if(tipo == "int"){
						if($4.tipo == "int"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " / " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tint "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (int) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " / " + temp + ";\n";
						}
					}else if(tipo == "float"){
						if($4.tipo == "float"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " / " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tfloat "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (float) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " / " + temp + ";\n";
						}
					}else if(tipo == "char"){
						if($4.tipo == "char"){
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + $$.label + " = " + $1.label + " / " + $4.label + ";\n";
						}else{
							variaveis.push_back("\tchar "+temp);
							$$.label = $1.label;
							$$.traducao = $4.traducao + "\t" + temp + " = (char) " + $4.label + ";\n\t" + $$.label + " = " + $1.label + " / " + temp + ";\n";
						}
					}
				}
			}
			| MATRIX
			;

MATRIX		: TK_TIPO_INT TK_ID DIM '[' E ']'
			{
				if($5.tipo == "int"){
					$$.label = $2.label;
					$$.tipo = "int*";
					addVar($$.label, "", $$.tipo);
					matContext[varContext.size()-1].dim[$$.label].insert(matContext[varContext.size()-1].dim[$$.label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[$$.label].push_back($5.label);
					int j = 0;
					string size = "1";
					$$.traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[$$.label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						$$.traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[$$.label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					$$.traducao += "\t" + aux2 + " = " + aux + " * sizeof(int);\n";
					$$.traducao = $3.traducao + $5.traducao + $$.traducao + "\t" + "int* " + $$.label +" = (int*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back($2.label);
			}
			| TK_TIPO_CHAR TK_ID DIM '[' E ']'
			{
				if($5.tipo == "int"){
					$$.label = $2.label;
					$$.tipo = "char*";
					addVar($$.label, "", $$.tipo);
					matContext[varContext.size()-1].dim[$$.label].insert(matContext[varContext.size()-1].dim[$$.label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[$$.label].push_back($5.label);
					int j = 0;
					string size = "1";
					$$.traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[$$.label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						$$.traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[$$.label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					$$.traducao += "\t" + aux2 + " = " + aux + " * sizeof(char);\n";
					$$.traducao = $3.traducao + $5.traducao + $$.traducao + "\t" + "char* " + $$.label +" = (char*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back($2.label);
			}
			| TK_TIPO_FLOAT TK_ID DIM '[' E ']'
			{
				if($5.tipo == "int"){
					$$.label = $2.label;
					$$.tipo = "float*";
					addVar($$.label, "", $$.tipo);
					matContext[varContext.size()-1].dim[$$.label].insert(matContext[varContext.size()-1].dim[$$.label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[$$.label].push_back($5.label);
					int j = 0;
					string size = "1";
					$$.traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[$$.label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						$$.traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[$$.label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					$$.traducao += "\t" + aux2 + " = " + aux + " * sizeof(float);\n";
					$$.traducao = $3.traducao + $5.traducao + $$.traducao + "\t" + "float* " + $$.label +" = (float*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back($2.label);
			}
			| TK_TIPO_BOOL TK_ID DIM '[' E ']'
			{
				if($5.tipo == "int"){
					$$.label = $2.label;
					$$.tipo = "bool*";
					addVar($$.label, "", $$.tipo);
					matContext[varContext.size()-1].dim[$$.label].insert(matContext[varContext.size()-1].dim[$$.label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[$$.label].push_back($5.label);
					int j = 0;
					string size = "1";
					$$.traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[$$.label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						$$.traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[$$.label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					$$.traducao += "\t" + aux2 + " = " + aux + " * sizeof(int);\n";
					$$.traducao = $3.traducao + $5.traducao + $$.traducao + "\t" + "int* " + $$.label +" = (int*) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back($2.label);
			}
			| TK_TIPO_STRING TK_ID DIM '[' E ']'
			{
				if($5.tipo == "int"){
					$$.label = $2.label;
					$$.tipo = "string*";
					addVar($$.label, "", $$.tipo);
					matContext[varContext.size()-1].dim[$$.label].insert(matContext[varContext.size()-1].dim[$$.label].end(), matTemp.begin(), matTemp.end());
					matTemp.clear();
					matContext[varContext.size()-1].dim[$$.label].push_back($5.label);
					int j = 0;
					string size = "1";
					$$.traducao = "";
					string aux;
					for(j=0; j<matContext[varContext.size()-1].dim[$$.label].size(); j++){
						aux = "TMP"+itos(i++);
						variaveis.push_back("\tint "+aux);
						$$.traducao += "\t" + aux + " = " + size + " * " + matContext[varContext.size()-1].dim[$$.label][j] + ";\n";
						size = aux;
					}
					string aux2 = "TMP"+itos(i++);
					variaveis.push_back("\tint "+aux2);
					$$.traducao += "\t" + aux2 + " = " + aux + " * sizeof(char*);\n";
					$$.traducao = $3.traducao + $5.traducao + $$.traducao + "\t" + "char** " + $$.label +" = (char**) malloc("+aux2+");\n";
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
				setMeFree.push_back($2.label);
			}
			| TK_ID DIM '[' E ']' '=' E
			{
				if($4.tipo == "int"){
					$$.label = $1.label;
					$$.tipo = $7.tipo;
					string tipo = "int";
					matTemp.push_back($4.label);
					if(matTemp.size() == matContext[varContext.size()-1].dim[$1.label].size()){
						string multiplier = "1";
						string index = "0";
						int j;
						string aux1, aux2, aux3, aux4;
						for(j=0; j<matContext[varContext.size()-1].dim[$1.label].size(); j++){
							aux1 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux1);
							$$.traducao += "\t" + aux1 + " = " + multiplier + ";\n";
							aux2 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux2);
							$$.traducao += "\t" + aux2 + " = " + aux1 + " * " + matTemp[j] + ";\n";
							aux3 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux3);
							$$.traducao += "\t" + aux3 + " = " + index + ";\n";
							aux4 = "TMP"+itos(i++);
							variaveis.push_back("\t"+tipo+" "+aux4);
							$$.traducao += "\t" + aux4 + " = " + aux3 + " + " + aux2 + ";\n";
							index = aux4;
							multiplier = aux1 + " + " + matContext[varContext.size()-1].dim[$1.label][j];
						}
						$$.traducao = $7.traducao + $2.traducao + $4.traducao + $$.traducao + "\t" + $1.label + "["+index+"] = " + $7.label + ";\n";
					}else{
						mensagens.push_back("Dimensão paralela da matriz: "+$1.label);
					}
					matTemp.clear();
				}else{
					mensagens.push_back("quase na hora de apresentar e não to mais com criatividade pra mensagem de erro");
				}
			}
			;
			
DIM			: DIM '[' E ']'
			{
				if($3.tipo == "int"){
					$$.traducao = $1.traducao + $3.traducao;
					matTemp.push_back($3.label);
				}else{
					mensagens.push_back("Olha esse tamanho de matriz aí que tá estranho...");
				}
			}
			|
			{
				$$.traducao = "";
			}
			;

GLOBAL : 	TK_GLOBAL TK_TIPO_INT TK_ID
			{
				//checkDeclar($2.label);
				$$.traducao = "";
				$$.tipo = "int";
				addGlobalVar($3.label, "", $$.tipo);
			}
			| TK_GLOBAL TK_TIPO_INT TK_ID '=' E

			{
				if($5.tipo == "string"){
					mensagens.push_back("STRING pra INT? Vou nem comentar...");
				}
				$$.tipo = "int";
				$$.traducao = "";
				addGlobalVar($3.label, $5.traducao , $$.tipo);
			}
			| TK_GLOBAL TK_TIPO_FLOAT TK_ID
			{
				$$.traducao = "";
				$$.tipo = "float";
				addGlobalVar($3.label, "", $$.tipo); //coloquei o valor como "" pq é só a declaração, mas depois tem que ver isso

			}
			| TK_GLOBAL TK_TIPO_FLOAT TK_ID '=' E
			{
				if($4.tipo == "string"){
					mensagens.push_back("STRING pra FLOAT? Vou nem comentar...");
				}
				$$.traducao = "";
				$$.tipo = "float";
				addGlobalVar($3.label, $5.traducao, $$.tipo);

			}
			| TK_GLOBAL TK_TIPO_CHAR TK_ID
			{
				$$.traducao = "";
				$$.tipo = "char";
				addGlobalVar($3.label, "", $$.tipo);
			}
			| TK_GLOBAL TK_TIPO_CHAR TK_ID '=' E
			{
			if($5.tipo == "string"){
					mensagens.push_back("STRING pra CHAR? Vou nem comentar...");
				}
				//checkDeclar($2.label);
				$$.traducao="";
				$$.tipo = "char";
				addGlobalVar($3.label, $5.traducao, $$.tipo);

			}
			| TK_GLOBAL TK_TIPO_BOOL TK_ID
			{
				$$.traducao = "";
				$$.tipo = "bool";
				addGlobalVar($3.label, "", $$.tipo);

			}
			| TK_GLOBAL TK_TIPO_BOOL TK_ID '=' EXPRESSION
			{
				$$.traducao = "";
			    $$.tipo = "bool";
			    addGlobalVar($3.label, $5.traducao, $$.tipo);
			}
			| TK_GLOBAL TK_TIPO_INT TK_ID '=' EXPRESSION
			{
				//checkDeclar($2.label);
				$$.label = "TMP" + itos(i++);
				$$.traducao = "";
				addGlobalVar($3.label, $5.traducao, $$.tipo);

			}
			|	TK_GLOBAL TK_TIPO_STRING TK_ID
			{
				$$.label = $3.label;
				$$.traducao = "";
				$$.tipo = "string";
				addGlobalVar($$.label, "", $$.tipo);
			}
			|	TK_GLOBAL TK_TIPO_STRING TK_ID '=' E
			{
				$$.label = $3.label;
				$$.tipo = "string";
				$$.traducao = "";
				addGlobalVar($$.label, $5.traducao, $$.tipo);
				if($5.tipo == "string"){
					if(strTemp[$5.label] > 0){ 
						varContext[varContext.size()-1].varMap[$$.label].tamanho = strTemp[$4.label];
					}else{
						varContext[varContext.size()-1].varMap[$$.label].tamanho = varContext[varContext.size()-1].varMap[$4.label].tamanho;
					}
				}else{
					mensagens.push_back("Não tem conversão implícita pra string não, querido, usa (string) aí.");
				}
			}
			|TK_GLOBAL TK_ID
			{
				if(!checkVar($1.label)){
					mensagens.push_back("Então... a variável é global mas precisa de um tipo né?! Troca lá a '" + $2.label +"' por favor. :) ");
				}
			}
			;	

EXPRESSION  : EXPRESSION TK_RELACIONAL EXPRESSION
			{
				checkRelacionalType($1.tipo, $3.tipo); //se forem tipos diferentes, daqui ele n passa e estoura o erro
				$$.label = "TMP" + itos(i++);
				$$.traducao = $$.traducao + $3.traducao + "\t"+ $$.label + " = " + $1.label + $2.operacao +$3.label + ";\n";
				$$.tipo = "bool";
				variaveis.push_back("\tint " + $$.label);


			}
			| EXPRESSION TK_IGUALDADE EXPRESSION
			{
				$$.label = "TMP" + itos(i++);
				$$.tipo = "bool";
				$$.traducao = $$.traducao + $3.traducao + "\t"+$$.label + " = " + $1.label + $2.operacao +$3.label + ";\n";
				variaveis.push_back("\tint " + $$.label);
			}
			| EXPRESSION TK_LOGICO EXPRESSION
			{
				checkBooleanType($1.tipo, $3.tipo);
				$$.label = "TMP" + itos(i++);
				$$.tipo = "bool";
				$$.traducao = $1.traducao + $3.traducao + "\t"+ $$.label + " = " + $1.label + $2.operacao +$3.label + ";\n";
				variaveis.push_back("\tint " + $$.label);
			}
			| TK_NEGACAO EXPRESSION
			{
				checkNegacaoBool($2.tipo);
				$$.label = "TMP" + itos(i++);
				$$.tipo = "bool";
				$$.traducao = $2.traducao + "\t"+ $$.label + " = " + $1.operacao + $2.label + ";\n";
				variaveis.push_back("\tint " + $$.label);
			}
			| E
			;


%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

void yyerror(string msg)
{
/*	if(mensagens.size() > 0){
		for(vector<string>::iterator it = mensagens.begin(); it != mensagens.end(); ++it){
			cout<<*it<<endl;
		}*/
		//cout << ""<<msg << endl;
		exit (0);
	//}
}

void getErrors()
{
	if(mensagens.size() > 0){
		for(vector<string>::iterator it = mensagens.begin(); it != mensagens.end(); ++it){
			cout<<*it<<endl;
		}
		//cout << ""<<msg << endl;
		exit (0);
	}
}


string typeCompare(string t1, string t2){
	if(t1 == "int" && t2 == "int"){
		return "int";
	}else if(t1 == "float" && t2 == "float"){
		return "float";
	}else if(t1 == "float" && t2 == "int" || t1 == "int" && t2 == "float"){
		return "float";
	}else if((t1 == "char" && t2 == "int") || (t1 == "int" && t2 == "char")){
		return "int";
	}else if((t1 == "char" && t2 == "float") || (t1 == "float" && t2 == "char")){
		return "float";
	}else if(t1 == "char" && t2 == "char"){
		return "int";
	}
}

void addGlobalVar(string label, string valor, string tipo){
  varInfoIt = varInfo.find(label);
  //cout << label << " "<< valor <<" "<< tipo <<endl;

  //if(varInfoIt != varInfo.end()){ // Var||Const was declared previously
  //  atributos var = varInfoIt->second;
	//}
	//variaveisGlobais.push_back(" " + tipo + " " +label);
	string novoValor = valor.substr(0, valor.size()-1);
  	tempGlobal.push_back(novoValor);
  	//string inicializaGlobal  = "\t" + label +" = " +novoValor.substr(1, 5) + ";";
  	//tempGlobal.push_back(inicializaGlobal);
  	if(verificaVariavel(label,tipo) == 0){

		atributos v;
		v.label = label;
		v.valor = valor;
		//v.tipo = tipo;
		if(tipo == "string"){
			v.tamanho = 199;
		}else{
			v.tamanho = getTamanho(tipo);
		}
		varInfo[label] = v;
		if(tipo == "bool"){
			v.booleano = 1;
			v.tipo = "int";
		}else{
			v.booleano = 0;
			v.tipo = tipo;
		}
		varContext[0].varMap[label] = v;

	}

}


void addVar(string label, string valor, string tipo){
  varInfoIt = varInfo.find(label);
 	if(verificaVariavel(label, tipo) == 0){

		atributos v;
		v.label = label;
		v.valor = valor;
		//v.tipo = tipo;
		if(tipo == "string"){
			v.tamanho = 199;
		}else{
			v.tamanho = getTamanho(tipo);
		}
		varInfo[label] = v;
		if(tipo == "bool"){
			v.booleano = 1;
			v.tipo = "bool";
		}else{
			v.booleano = 0;
			v.tipo = tipo;
		}
		varContext[0].varMap[label] = v;

	}

}

int getTamanho(string tipo){

	if(tipo == "int"){
		return 4;
	}else if (tipo == "float"){
		return 4;
	}else if (tipo == "char"){
		return 1;
	}
	return 0;
}

atributos operacoes(struct atributos $$, struct atributos $1, string op, struct atributos $3){
	
	if($1.tipo == "string" || $3.tipo == "string"){
		mensagens.push_back("Operação inválida com STRING.");
	}
	
	$$.label = "TMP" + itos(i++);
	$$.tipo = typeCompare($1.tipo, $3.tipo); // int + float = float
	variaveis.push_back("\t" + $$.tipo + " " +$$.label);
	if($1.tipo == "int" && $$.tipo == "float"){
	   string aux = "TMP"+itos(i++); // aux = TMP30
	   //$$.traducao = $$.traducao + "\tfloat " + aux + " = " + $1.label+";\n"; // float TMP30 = TMP0
	   $$.traducao = $$.traducao + "\t" + aux + " = (float) " + $1.label+";\n"; // float TMP30 = TMP0
	   $1.label = aux; // TMP0 -> TMP30
	   $$.traducao = $$.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$1.label);

	}else if($3.tipo == "int" && $$.tipo == "float"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = "\tfloat " + aux + " = " + $3.label+";\n" + $$.traducao; // float TMP30 = TMP0
	  $$.traducao = "\t" + aux + " = (float) " + $3.label+";\n" + $$.traducao;
	  $3.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($$.tipo == "float" && $1.tipo == "char"){
		string aux = "TMP"+itos(i++); // aux = TMP30
        //$$.traducao = $$.traducao + "\tfloat " + aux + " = " + $1.label+";\n"; // float TMP30 = TMP0
        $$.traducao = $$.traducao + "\t " + aux + " = (float) " + $1.label+";\n";
	    $1.label = aux; // TMP0 -> TMP30
	    $$.traducao = $$.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
			variaveis.push_back("\t" + $$.tipo + " " +$1.label);

	}else if($$.tipo == "float" && $3.tipo == "char"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = "\tfloat " + aux + " = " + $3.label+";\n" + $$.traducao; // float TMP30 = TMP0
	  $$.traducao = "\t" + aux + " = (float) " + $3.label+";\n" + $$.traducao;
	  $3.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "char" && $3.tipo == "char"){
		string aux = "TMP"+itos(i++);
		$$.traducao = $1.traducao + $3.traducao;
	//	$$.traducao = $$.traducao + "\tint " + aux + " = " + $1.label + ";\n";
		$$.traducao = $$.traducao + "\t " + aux + " = (int) " + $1.label + ";\n";
		$1.label = aux;
		aux = "TMP"+itos(i++);
		$$.traducao = $$.traducao + "\tint " + aux + " = (int) " + $3.label + ";\n";
		$3.label = aux;
		$$.traducao = $$.traducao + "\tint " + $$.label + " = " + $1.label + op + $3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "char" && $3.tipo == "int"){
      string aux = "TMP"+itos(i++); // aux = TMP30
	  //$$.traducao = $$.traducao + "\tint " + aux + " = (int) " + $1.label+";\n"; // float TMP30 = TMP0
	  $$.traducao = $$.traducao + "\t" + aux + " = " + $1.label+";\n";
	  $1.label = aux; // TMP0 -> TMP30
	  $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
		variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else if($1.tipo == "int" && $3.tipo == "char"){
	  string aux = "TMP"+itos(i++); // aux = TMP30
	  $$.traducao = $$.traducao +"\tint " + aux + " = (int) " + $3.label+";\n"; // float TMP30 = TMP0
	  $3.label = aux; // TMP0 -> TMP30
	 // $$.traducao = $3.traducao + $$.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
     $$.traducao = $3.traducao + $$.traducao + "\t"+ $$.label + " = " + $1.label + op +$3.label + ";\n";
		 variaveis.push_back("\t" + $$.tipo + " " +$3.label);

	}else{
	  //$$.traducao = $1.traducao + $3.traducao + "\t"+$$.tipo+" " + $$.label + " = " + $1.label + op +$3.label + ";\n";
  	  $$.traducao = $1.traducao + $3.traducao + "\t"+ $$.label + " = " + $1.label + op +$3.label + ";\n";

	}
	return $$;
}

atributos getVar(string label){
	for(int i = varContext.size() - 1; i>=0; i--){
		if(varContext[i].varMap.count(label)){
			return varContext[i].varMap[label];
		}
	}
}

//verifica se a variável ja foi criada antes
int checkVar(string label){
	for(int i = varContext.size() - 1; i>= 0; i--){
		if(varContext[i].varMap.count(label)){
			return 1;
		}
	}
	mensagens.push_back("XIIIIII! Dá uma olhada, porque acho que a variável '"+ label + "' não foi declarada! ");
	return 0;
	
}

void checkRelacionalType(string t1, string t2){
	if((t1 == "int" && t2 == "int") || (t1 == "float" && t2 == "float")){
		return;
	} else if ((t1 == "float" && t2 == "int") || (t1 == "int" && t2 == "float")){
		return;
	}else{
		//yyerror("Não dá pra comparar esses tipos que você colocou não. Troca lá");
		mensagens.push_back("Não dá pra comparar esses tipos que você colocou não. Troca lá");

	}
}

void checkBooleanType(string t1, string t2){
	if(t1 != "bool" || t2 != "bool"){
		//yyerror("Não dá para comparar, pois não é tipo booleano.");
		mensagens.push_back("Não dá para comparar, pois não é tipo booleano.");
	}else{
		return;
	}
}

void checkNegacaoBool(string t){
	if(t != "bool"){
		//yyerror("Não dá para fazer negação, pois a variável não é booleana");
		mensagens.push_back("Não dá para fazer negação, pois a variável não é booleana");
	}else{
		return;
	}
}

void declaraVariaveis(){
	for(std::vector<string>::iterator it = variaveis.begin(); it != variaveis.end(); ++it) {
    	cout<< *it << ";"<<endl;
	}
	cout << "" <<endl;

}

void declaraFunctions(){
	for(int i = stackFunction.size()-1; i>= 0; i--){
		cout << stackFunction[i].label  << ":"<< endl;
		cout << stackFunction[i].conteudo << endl;
	
	}
}

void declaraVariaveisGlobais(){
	for(std::vector<string>::iterator it = variaveisGlobais.begin(); it != variaveisGlobais.end(); ++it) {
    	cout<< *it << ";"<<endl;
	}
	cout << "" <<endl;

}

void atribuiTempsGlobais(){
	for(std::vector<string>::iterator it = tempGlobal.begin(); it != tempGlobal.end(); ++it) {
    	cout<< *it << ""<<endl;
	}
}

void pushContext(){


	contexto newContext;
	varContext.push_back(newContext);
	dim newc;
	matContext.push_back(newc);

}

void popContext(){
	varContext.pop_back();
}

int verificaVariavel(string label, string tipo){
	int i = varContext.size() - 1;
	
	if (varContext[i].varMap.count(label)) {
  		mensagens.push_back("Ih. Dá uma olhadinha lá, porque acho que a variável '"+label + "' já foi declarada antes.");
		return 1;
	}

	return 0;
}

contexto returnContexto(){
	cout<<"RETURN CONTEXTO" << endl;
	for(int i = varContext.size()-1; i>= 0; i--){
		//if(varContext[i].labelInicio != ""){
		//	return varContext[i];
		//}
	}
}

void defineLabel(string inicio, string fim){
	varContext[varContext.size()-1].labelInicio = inicio;
	varContext[varContext.size()-1].labelFim = fim;

}

string getLabel(){
	lbl++;	
	return "LBL" + itos(lbl);
} 

string getContinue(){
	return "LBL" + itos(lbl+1);
}

string getBreak(){
	int temp = lbl+2; 
	return "LBL" + itos(temp);
}

//empilha função
void pushFunction(string label, string content){
	funcao newfunction;
	newfunction.label = label;
	newfunction.conteudo = content;
	funcParam[label] = temparam;
	stackFunction.push_back(newfunction);
	temparam.clear();
}

//desempilha função
void popFunction(){
	stackFunction.pop_back();
}

//empilha parametros da função
void pushParameters(string label){
	if(!checkVar(label)){
		mensagens.push_back("Pelamor né. Essa variável aí da função veio de onde? Troca lá");
	}else{
		atributos var = getVar(label);	
		varStack.push_back(var);

	}
}

string popParameters(){
	string result = ""; 
	for(int i = varStack.size()-1; i>= 0; i--){
	//	if(checkVariableValue(varStack[i].label)){
			result += "\t " + varStack[i].label + " = " + varStack[i].valor + ";\n"; 
	//	}		
	}
	varStack.clear();
	return result;
}

int checkVariableValue(string label){
	atributos var = getVar(label);
	if(var.valor == ""){
		mensagens.push_back("EU VOU EXPOR ELA! Tu esqueceu de inicializar a variável '"+ label +"' ali ó. ");
		return 0;
	}
	return 1;
}

void freeAll(){
	int i;
	for(i=0; i<setMeFree.size(); i++){
		cout << "\tfree("+setMeFree[i]+");" << endl;
	}
}

