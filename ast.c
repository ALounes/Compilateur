#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "ast.h"

// Cette variable globale vaut au depart 0, et est incrementee a chaque fois
int countDigraph;

// Q1 : Ecrire la fonction qui permet d'allouer et d'initialiser un noeud
// de type numeric avec la bonne valeur reelle
nodeType *createNumericNode(float v)
{
	nodeType *p = NULL;

	p = (nodeType*)malloc(sizeof(nodeType));
	if (p == NULL){
		printf("ERREUR : echec allocation memoire ");
		exit(1);
	}	 

	p->type = typeNumeric ;
	p->digraphNode = -1; // POUR DOT ??? QUE FAIRE ?
	p->t_numeric.valeur = v ;
	
	return p;
}

// Q2 : Ecrire la fonction qui permet d'allouer et d'initialiser un
// noeud de type operator. L'argument oper definit l'operation avec
// des valeurs extraites de l'enum, nops definit le nombre d'operandes
// et ... represente la liste des noeuds fils, fils0 jusqu'a fils_nops-1
nodeType *createOperatorNode(int oper, int nops, ...) 
{
	va_list ap;
	nodeType *p;
	int i;

	// Alocation memoire pour le noeud 
	p = (nodeType*)malloc(sizeof(nodeType));
	if (p == NULL){
		printf("ERREUR : echec allocation memoire ");
		exit(1);
	}	 	
 
	// Le noeud est de type operateur 
	p->type = typeOperator ;
	p->digraphNode = -1; // POUR DOT ??? QUE FAIRE ?


	// affectation de la valeur de l'operateur 
	p->t_oper.oper = oper;
	// affectation du nombre de fils (2?)
	p->t_oper.nOperands = nops;


	// alocation memoire d'un tableau de pointeur sur des noeuds
	p->t_oper.op = (nodeType**)malloc(nops*sizeof(nodeType*));
	if (p->t_oper.op == NULL){
		printf("ERREUR : echec allocation memoire ");
		exit(1);
	}

	va_start(ap, nops);
	for(i=0; i<nops; i++)
	{
		p->t_oper.op[i] = va_arg(ap, nodeType*);
	}

	va_end(ap);

	return p;
}

// Q3 : Ecrire la fonction, recursive, qui permet de generer
// le code assembleur EVM equivalent a un AST a partir
// d'un pointeur sur la racine de celui-ci
void generateAsmRec(nodeType *n, FILE *fout)
{
   int i = 0;
	int ligne = 0;
	int nbr_instruction = 0;

	switch(n->type)
	{
		case typeNumeric :
			fprintf(fout, "\tpush %f\n", n->t_numeric.valeur);
			break;
	
		case typeOperator :
			switch(n->t_oper.oper)
			{
				case OPER_ADD:
				   for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateAsmRec(*(n->t_oper.op + i),fout);
				   }
					fprintf(fout, "\tadd\n"); 
					break;

				case OPER_SUB:
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateAsmRec(*(n->t_oper.op + i),fout);
				   } 
					fprintf(fout, "\tsub\n");
					break;

				case OPER_MULT:
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateAsmRec(*(n->t_oper.op + i),fout);
				   } 
					fprintf(fout, "\tmult\n");
					break;

				case OPER_DIV:
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateAsmRec(*(n->t_oper.op + i),fout);
				   } 
					fprintf(fout, "\tdiv\n");
					break;

				case OPER_OUTPUT:
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateAsmRec(*(n->t_oper.op + i),fout);
				   } 
					fprintf(fout, "\toutput\n");
					break;

				default :
					printf("ERREUR : operateur non reconnu ");
					exit(1);
					break;
			}
			break;

		default :
			printf("\n ERREUR , noeud Non reconnu .... \n");
			exit(1);
			break;
	}
}

// Q4 ; Ecrire la fonction, non recursive, qui va permettre
// de generer un fichier assembleur correct a partir de l'AST.
// La fonction devra inserer a la fichier du fichier assembleur
// l'instruction halt, pour arreter l'execution de la machine virtuelle
// et la pseudo-instruction end qui arretera l'assemblage
void generateAsm(nodeType *n, char *filename)
{
   FILE *fout = fopen(filename, "w");

   fprintf(fout, "debut :\n");
   generateAsmRec(n, fout);
   fprintf(fout, "\thalt\n");
   fprintf(fout, "\tend\n");
   fclose(fout);
}

// Q5 : Ecrire la fonction, recursive, qui permet de generer
// la partie "liste des noeuds" d'un digraph dot a partir
// d'un pointeur sur la racine de l'AST. L'ecriture se
// fera dans le fichier pointe par fout. Cette fonction
// doit parcourir l'AST et affecter le champs digraphNode 
// avec un entier definissant le nom du noeud. Ce champs
// sera utilise par la fonction recursive suivante permettant
// de generer les arcs du graphe.
void generateDigraphNameNode(nodeType *n,FILE *fout)
{
   int i = 0;
   switch(n->type)
	{
		case typeNumeric : {
		   n->digraphNode = countDigraph;
			fprintf(fout, "\tN%d [label=%f]\n",countDigraph, n->t_numeric.valeur);
			++countDigraph;
			break;
		}
	
		case typeOperator : {
			switch(n->t_oper.oper)
			{
				case OPER_ADD: {
				    
					n->digraphNode = countDigraph;
					fprintf(fout, "\tN%d [label=\"+\"]\n",countDigraph);
					++countDigraph;
				   for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateDigraphNameNode(*(n->t_oper.op + i),fout);
				   }
					
					break;
				}

				case OPER_SUB: {
				   n->digraphNode = countDigraph;
					fprintf(fout, "\tN%d [label=\"-\"]\n",countDigraph);
					++countDigraph;
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateDigraphNameNode(*(n->t_oper.op + i),fout);
				   } 
					
					break;
				}

				case OPER_MULT: {
				   n->digraphNode = countDigraph;
					fprintf(fout, "\tN%d [label=\"*\"]\n",countDigraph);
					++countDigraph;
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateDigraphNameNode(*(n->t_oper.op + i),fout);
				   } 
					
					break;
            }
            
				case OPER_DIV:
				   n->digraphNode = countDigraph;
					fprintf(fout, "\tN%d [label=\"/\"]\n",countDigraph);
					++countDigraph;
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateDigraphNameNode(*(n->t_oper.op + i),fout);
				   } 
					
					break;

				case OPER_OUTPUT: {
				   n->digraphNode = countDigraph;
					fprintf(fout, "\tN%d [label=\"output\"]\n",countDigraph);
					++countDigraph;
					for (i = 0; i < n->t_oper.nOperands; ++i)
				   {
				      generateDigraphNameNode(*(n->t_oper.op + i),fout);
				   } 
					
					break;
				}

				default :
					printf("ERREUR : operateur non reconnu ");
					exit(1);
					break;
			}
		break;
      }
		default :
			printf("\n ERREUR , noeud Non reconnu .... \n");
			exit(1);
			break;
	}
}

// Q6 : Ecrire la fonction, recursive, qui permet de generer
// la partie "liste des arcs" d'un digraph dot a partir
// d'un pointeur sur la racine de l'AST. L'ecriture se
// fera dans le fichier pointe par fout. La fonction utilise la numerotation
// faite par la fonction recursive precedente 
void generateDigraphEdges(nodeType *n,FILE *fout)
{
   int i = 0;

   switch(n->type)
	{
		case typeNumeric :
			// Ne rien faire
			break;
	
		case typeOperator :
			
		   for (i = 0; i < n->t_oper.nOperands; ++i)
		   {
		      fprintf(fout, "\tN%d -> N%d\n",n->digraphNode,(*(n->t_oper.op + i))->digraphNode);
		      generateDigraphEdges(*(n->t_oper.op + i),fout);
		   }

			break;

		default :
			printf("\n ERREUR , noeud Non reconnu .... \n");
			exit(1);
			break;
	}

}

// Q7 : Ecrire la fonction, non recursive, permettant de
// generer un fichier res.dot contenant toutes les infos
// permettant un affichage graphique plaisant. On pourra
// utiliser l'appel syeme "system" pour lancer automatiquement
// la conversion res.dot en res.png
void generateDigraph(nodeType *n)
{
   FILE *fout = fopen("res.dot", "w");
/*\nnode [label=\"\N\"]\");\ngraph [bb=\"0,0,286,252\"];*/
   fprintf(fout, "digraph {\n");
   generateDigraphNameNode(n,fout);
   generateDigraphEdges(n,fout);
   fprintf(fout, "}\n");
   fclose(fout);
}

// La encore cadeau...
int main(int argc, char **argv)
{
	nodeType *n0=createNumericNode(1.23);
	nodeType *n1=createNumericNode(4.56);
	nodeType *n2=createNumericNode(7.89);
	nodeType *n3=createOperatorNode(OPER_ADD,2,n0,n1);
	nodeType *n4=createOperatorNode(OPER_ADD,2,n3,n2);
	nodeType *n5=createOperatorNode(OPER_OUTPUT,1,n4);
	generateAsm(n5,"res.asm");
	countDigraph = 0;
	generateDigraph(n5);

	return 0;
}
