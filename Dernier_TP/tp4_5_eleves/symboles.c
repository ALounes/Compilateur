#include "symboles.h" 

int currentFunction;
type_variable table_ident_fonctions[NBRE_FONCTIONS_MAX][NBRE_IDENT_MAX];
int table_nbre_variables[NBRE_FONCTIONS_MAX];
int table_fonctions[NBRE_FONCTIONS_MAX];
int table_nbre_variables_globales[NBRE_FONCTIONS_MAX];
int table_nbre_variables_locales[NBRE_FONCTIONS_MAX];
int table_nbre_formels[NBRE_FONCTIONS_MAX];

void reset_index_table_nbre_variables(int func)
{
	table_nbre_variables[func]=0;
}

void init_table_symboles()
{
	// Question 1) Ajouter le code necessaire pour initialiser la table des symboles
  int i;
  for(i = 0; i < NBRE_FONCTIONS_MAX; i++){
    reset_index_table_nbre_variables(i);
  }
  
}

int est_deja_declare(int func, char *ident)
{
  int i;
  for(i = 0; i < table_nbre_variables[func]; i++){
    if(strcmp(ident, table_ident_fonctions[func][i].ident) == 0){
      return i;
    }
  }
  return -1;
}

void print_current_table_symb()
{
	print_table_symb(currentFunction);
}

void print_table_symb(int func)
{
  int i;
  
  printf("------ DEBUT ------- %d\n",func);
  for (i=0;i<table_nbre_variables[func];i++)
    printf("%d: %s %d %d\n", i, table_ident_fonctions[func][i].ident,
	   table_ident_fonctions[func][i].typv, table_ident_fonctions[func][i].funcNum);
  printf("nbLocales=%d\n",table_nbre_variables_locales[func]);
  printf("nbFormels=%d\n",table_nbre_formels[func]);
  printf("------ FIN ---------\n");
}

void print_table_fonctions()
{
	int i;

	for (i=0;i<=currentFunction;i++)
		printf("%d: %d\n",i,table_fonctions[i]);
}

void ajouter_variable(int func, char *ident, int typv)
{
  
// Question 3) Ajouter le code necessaire
	if (typv == TYPE_VARIABLE_GLOBALE)
	{
	table_nbre_variables_globales[func]++;
	}
	if (typv == TYPE_VARIABLE_LOCALE)
	{
	table_nbre_variables_locales[func]++;
	}
	if (typv == TYPE_PARAMETRE)
	{
	table_nbre_formels[func]++;
	}
	table_ident_fonctions[func][table_nbre_variables[func]].funcNum = -1;
	table_ident_fonctions[func][table_nbre_variables[func]].ident = strdup(ident);
	table_ident_fonctions[func][table_nbre_variables[func]].typv = typv;
	table_nbre_variables[func]++;
}

void ajouter_table_fonctions(int index,int funcNum)
{
	table_fonctions[currentFunction]=index;
	table_ident_fonctions[0][index].funcNum=funcNum;
}

void declarer_variable(int func, char *ident, int typv)
{
	if (est_deja_declare(func,ident)!=-1)
	{
		printf("identificateur %s deja declare\n",ident);
		exit(1);
	}
	ajouter_variable(func, ident, typv);
}

void increment_current_function()
{
	currentFunction++;
}

int getFunctionNum()
{
	return currentFunction;
}
