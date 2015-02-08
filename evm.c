#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vm_codops.h"

#define MAX_CODESEGMENT_SIZE 1000

#define MAX_STACK_SIZE 100

// Q1 : Les registres de la machine virtuelle
int pc, sp, bp;
// Q2 : Declaration du segment de code
int codeSegment[MAX_CODESEGMENT_SIZE];
// Q3 : Declaration de la pile d'execution (tableau de float)
float pile[MAX_STACK_SIZE];



// Q4 : Fonction de lecture d'un fichier langage machine
//      ouvert et dont le pointeur de fichier est fin

void readAssembly(FILE *fin)
{
   int prov,taille,i;
   fscanf(fin, "%d\n", &taille);

   for (i = 0; i < taille; i++)
   {
      fscanf(fin, "%d:%d\n", &prov,&codeSegment[i]);
   }
   //printf("SP : %d",sp);

}

// Q5 : Fonction de debug qui affiche la pile jusqu'a son sommet 

void printPile()
{
   int i;
   printf("\n(Début de pile)\n");
   
   for (i = sp; i > bp; i--)
   {
      printf("%.2f \n", pile[i]);
   }
   printf("(Fin de pile,SP = % d)\n",sp);

}

// Q6 : Boucle principale d'exécution de la machine virtuelle 
//      On sort de cette fonction si l'instruction pointee
//      par pc est OP_HALT. On traitera les erreurs et on
//	pensera a ajouter des traces et des moyens de mise
//	au point

void run()
{
	float fv;
	int vm1,v;
   int i,depile,n,orig,dest;
	char strReal[256];
	int strRealLength,pos;
   int addr;

	//printExecStack();
	while (codeSegment[pc]!= OP_HALT)
	{
		//printf("%d: ",pc);
		//printf("%d ",codeSegment[pc]);
		switch (codeSegment[pc])
		{
			case OP_ADD: {
				pile[sp-1]=pile[sp-1]+pile[sp]; 
				sp-- ; pc++ ; 
				printf("ADD\n");
				printf("Instruction suivante : %d",codeSegment[pc]);
				break;
			}

         case OP_SUB: {
            pile[sp-1]=pile[sp-1]-pile[sp]; 
				sp-- ; pc++ ; break;
			}
			
			case OP_MULT:	{
		      pile[sp-1]=pile[sp-1]*pile[sp]; 
				sp-- ; pc++ ; 
				printf("MULT\n");
				break;
			}
				
		   case OP_DIV:	{
		      if (pile[sp] == 0)
		      {
		         printf("Erreur : Division par 0\n");
		         exit(1);
		      }
		      
		      pile[sp-1]=pile[sp-1]/pile[sp]; 
				sp-- ; pc++ ; 
				
				break;
			}	
			
			case OP_NEG:	{
		      pile[sp]=-pile[sp]; 
				pc++; 
				printf("NEG\n");
				break;
			}
			
			case OP_AND:	{
		      pile[sp-1] = pile[sp]&&pile[sp-1]; 
		      sp--;
				pc++; 
				printf("AND\n");
				break;
			}
			case OP_OR:	{
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp--;
				pc++; 
				printf("AND\n");
				break;
			}
			case OP_NOT:	{
		      pile[sp] = !(pile[sp]) ;
		      // pile[sp] = 
				pc++; 
				printf("NOT\n");
				break;
			}
			case OP_EQ:	{
		      pile[sp-1]= (pile[sp] == pile[sp-1]); 
		      sp--;
				pc++; 
				printf("EQ\n");
				break;
			}
			case OP_LS:	{
		      pile[sp-1]= (pile[sp]>pile[sp-1]); 
		      sp--;
				pc++; 
				printf("LS\n");
				break;
			}
			case OP_GT:	{
		      pile[sp-1]=(pile[sp]<pile[sp-1]); 
		      sp--;
				pc++; 
				printf("GT\n");
				break;
			}
			case OP_INC:	{
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp += codeSegment[pc+1];
				pc += 2; 
				printf("INC\n");
				break;
			}
			case OP_DEC:	{
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp -= codeSegment[pc+1];
				pc += 2; 
				printf("INC\n");
				break;
			}
			
			case OP_PUSH:	{
		      pile[sp+1]=codeSegment[pc+1]; 
				sp++ ; pc += 2; 
				printf("PUSH\n");
				break;
			}
			
			case OP_PUSHR:	{
			
				i = 0;
				while (codeSegment[pc+1+i] != 0)
				{
				   strReal[i] = codeSegment[pc+1+i];
				   i++;
				}
				strReal[i] = '\0';
				pile[sp+1] = strtof(strReal,NULL);
				
				sp++;
				pc += i + 2;
				
				printf("PUSHR\n");
				break;
			}
			case OP_LIBP:	{
		      pile[sp+1] = bp + codeSegment[pc+1];   
				sp++ ; pc += 2; 
				printf("LIBP\n");
				break;
			}
			
			case OP_DUPL:	{
		      pile[sp+1] = pile[sp];   
				sp++ ; 
				pc++; 
				printf("DUPL\n");
				break;
			}
			case OP_CONT:	{
			   i = pile[sp];
		      pile[sp] = pile[i];
		      pc++; 
				printf("CONT\n");
				break;
			}
			case OP_MOVE:	{
			   addr = pile[sp-codeSegment[pc+1]-1];
			   
			   for (i = 0; i < codeSegment[pc+1]; i++)
			   {
			      pile[addr-i] = pile[sp-i] ; 
			   }
				sp -= (codeSegment[pc+1] + 1) ; pc += 2; 
				printf("MOVE\n");
				break;
			}
			case OP_COPY:	{
			   addr = pile[sp];
			   
			   for (i = 0; i < codeSegment[pc+1]; i++)
			   { 
			      pile[sp + i] = pile[addr - codeSegment[pc+1] + 1 + i] ; 
			   }
			   
				sp += (codeSegment[pc+1] - 1) ; pc += 2; 
				printf("COPY\n");
				break;
			}
			case OP_JP:	{ 
				pc = codeSegment[pc+1]; 
				printf("JP\n");
				break;
			}
			case OP_JF:	{ 
			   if (pile[sp] == 0)
			   {
			      pc = codeSegment[pc+1];
			   }
				else {
				   pc += 2;
				}
				sp--; 
				printf("JF\n");
				break;
			}
			case OP_JL:	{ 
			   if (pile[sp] > pile[sp-1])
			   {
			      pc = codeSegment[pc+1];
			   }
				else {
				   pc += 2;
				}
				sp -= 2; 
				printf("JL\n");
				break;
			}
			
			case OP_JG:	{ 
			   if (pile[sp] < pile[sp-1])
			   {
			      pc = codeSegment[pc+1];
			   }
				else {
				   pc += 2;
				}
				sp -= 2; 
				printf("JG\n");
				break;
			}
			
			case OP_CALL:	{ 
			   pile[sp+1] = pc+2;
			   pc = codeSegment[pc+1];
				sp++; 
				printf("CALL\n");
				break;
			}
			
			case OP_RET:	{ 
			   pc = pile[sp];
				sp--; 
				printf("RET\n");
				break;
			}
		
		   // INSTRUCTIONS E-S
			
			case OP_INPUT:	{
				printf("INPUT : ");
				i = pile[sp];
			   scanf("%f",&pile[i]);
				sp-- ; pc++ ; 

				break;
			}
			
			case OP_OUTPUT:	{
			   printf("Output : %3.2f\n",pile[sp]);
				sp-- ; pc++ ; 
				break;
			}
			
			case OP_OUTCHAR:	{
			
			   i = 0;
				while (codeSegment[pc+1+i] != 0)
				{
				   printf("%c",codeSegment[pc+1+i]);
				   i++;
				}

				
				pc += i + 2;
				printf("\nOUTCHAR, PC : %d\n",strtof(strReal,NULL),pc);
			
			
			   //printf("Outchar : %3.2f\n",pile[sp]);
				//sp-- ; pc++ ; 
				//printf("Instruction suivante : %d",codeSegment[pc]);
				break;
			}
			
			case OP_SAVEBP:	{ 
			   pile[sp+1] = bp;
				sp++; 
				pc++;
				printf("SAVEBP\n");
				break;
			}
			case OP_RSTRBP:	{ 
			   bp = pile[sp];
				sp--; 
				pc++;
				printf("RSTRBP\n");
				break;
			}
			
			// add code here
   
			default:
				printf("Instruction non reconnue\n");
				exit(1);
		}
		//printExecStack();
		printPile();
	}
}

// Q7 : Programme principal. Apres les tests de nombre et de qualite
//	des arguments, ouvrir le fichier langage machine, appeler
//	la fonction readAssembly, et fermer le fichier ouvert. Ensuite
//	initialiser pc a 0, sp et bp a -1. Enfin, lancer la machine
//	virtuelle avec la fonction run().

int main(int argc, char **argv)
{
	if (argc!=2)
	{
		printf("Usage : vm infile.bin\n");
	}
	FILE *fin=fopen(argv[1],"r");
	if (fin==NULL)
	{
		printf("Error opening read file %s\n",argv[1]);
		
		exit(1);
	}
   readAssembly(fin);
   fclose(fin);
   pc = 0;
   sp = -1;
   bp = -1;
   run();

	// add code here

   
	return 0;
}
