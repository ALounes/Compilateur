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
			case OP_ADD: 
			{
				printf("ADD\n");
				pile[sp-1]=pile[sp-1]+pile[sp]; 
				sp-- ; pc++ ;
				break;
			}

         case OP_SUB: 
			{
				printf("SUB\n");
            pile[sp-1]=pile[sp-1]-pile[sp]; 
				sp--; pc++; 
				break;
			}
			
			case OP_MULT:	
			{
				printf("MULT\n");
		      pile[sp-1]=pile[sp-1]*pile[sp]; 
				sp-- ; pc++ ; 
				break;
			}
				
		   case OP_DIV:	
			{
				printf("DIV\n");
		      if (pile[sp] == 0)
		      {
		         printf("Erreur : Division par 0\n");
		         exit(1);
		      }
		      
		      pile[sp-1]=pile[sp-1]/pile[sp]; 
				sp-- ; pc++ ; 
				break;
			}	
			
			case OP_NEG:	
			{
				printf("NEG\n");
		      pile[sp] = -pile[sp]; 
				pc++; 
				break;
			}
			
			case OP_AND:	
			{
				printf("AND\n");
		      pile[sp-1] = pile[sp]&&pile[sp-1]; 
		      sp--; pc++; 
				break;
			}

			case OP_OR:	
			{
				printf("AND\n");
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp--; pc++; 
				break;
			}

			case OP_NOT:	
			{
				printf("NOT\n");
		      pile[sp] = !(pile[sp]);
				pc++; 
				break;
			}

			case OP_EQ:	
			{
				printf("EQ\n");
		      pile[sp-1]= (pile[sp] == pile[sp-1]); 
		      sp--; pc++; 
				break;
			}

			case OP_LS:
			{
				printf("LS\n");
		      pile[sp-1]= (pile[sp]>pile[sp-1]); 
		      sp--; pc++; 
				break;
			}

			case OP_GT:	
			{
				printf("GT\n");
		      pile[sp-1]=(pile[sp]<pile[sp-1]); 
		      sp--; pc++; 
				break;
			}

			case OP_INC:	
			{
				printf("INC\n");
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp += codeSegment[pc+1];
				pc += 2; 
				break;
			}

			case OP_DEC:	
			{
				printf("INC\n");
		      pile[sp-1]=pile[sp]||pile[sp-1]; 
		      sp -= codeSegment[pc+1];
				pc += 2; 
				break;
			}
			
			case OP_PUSH:	
			{
				printf("PUSH\n");
		      pile[sp+1]=codeSegment[pc+1]; 
				sp++ ; pc += 2; 
				break;
			}
			
			case OP_PUSHR:	
			{			
				printf("PUSHR\n");
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
				break;
			}

			case OP_LIBP:	
			{
				printf("LIBP\n");
		      pile[sp+1] = bp + codeSegment[pc+1];   
				sp++ ; pc += 2; 
				break;
			}
			
			case OP_DUPL:	
			{
				printf("DUPL\n");
		      pile[sp+1] = pile[sp];   
				sp++; pc++; 
				break;
			}
			case OP_CONT:	
			{
				printf("CONT\n");
			   i = pile[sp];
				if ((i <= -1) || (i > sp))
				{
					printf("ERREUR: le sommet de la pile doit contenir l'adresse d'une cellule memoire\n");
					exit(1);
				}
		      pile[sp] = pile[i];
		      pc++; 
				break;
			}

			case OP_MOVE:	
			{
				printf("MOVE\n");
			   addr = pile[sp-codeSegment[pc+1]-1];
			   
			   for (i = 0; i < codeSegment[pc+1]; i++)
			   {
			      pile[addr-i] = pile[sp-i] ; 
			   }

				sp -= (codeSegment[pc+1] + 1) ; 
				pc += 2; 
				break;
			}

			case OP_COPY:	
			{
				printf("COPY\n");
			   addr = pile[sp];
			   
			   for (i = 0; i < codeSegment[pc+1]; i++)
			   { 
			      pile[sp + i] = pile[addr - codeSegment[pc+1] + 1 + i] ; 
			   }
			   
				sp += (codeSegment[pc+1] - 1) ; 
				pc += 2; 
				break;
			}

			case OP_JP:	
			{
				printf("JP\n"); 
				pc = codeSegment[pc+1]; 
				break;
			}

			case OP_JF:	
			{
				printf("JF\n"); 
			   if (pile[sp] == 0)
			   {
			      pc = codeSegment[pc+1];
			   }
				else 
				{
				   pc += 2;
				}
				sp--; 
				break;
			}

			case OP_JL:	
			{
				printf("JL\n"); 
			   if (pile[sp] > pile[sp-1])
			   {
			      pc = codeSegment[pc+1];
			   }
				else 
				{
				   pc += 2;
				}
				sp -= 2; 
				break;
			}
			
			case OP_JG:	
			{
				printf("JG\n"); 
			   if (pile[sp] < pile[sp-1])
			   {
			      pc = codeSegment[pc+1];
			   }
				else {
				   pc += 2;
				}
				sp -= 2; 
				break;
			}
			
			case OP_CALL:	
			{ 
				printf("CALL\n");
			   pile[sp+1] = pc+2;
			   pc = codeSegment[pc+1];
				sp++; 
				break;
			}
			
			case OP_RET:	
			{
				printf("RET\n"); 
			   pc = pile[sp];
				sp--; 
				break;
			}
		
		   // INSTRUCTIONS E-S
			
			case OP_INPUT:	
			{
				printf("INPUT : ");
				i = pile[sp];
			   scanf("%f",&pile[i]);
				sp--; pc++ ; 
				break;
			}
			
			case OP_OUTPUT:	
			{
			   printf("Output : %3.2f\n",pile[sp]);
				sp--; pc++ ; 
				break;
			}
			
			case OP_OUTCHAR:	
			{			
				printf("OUTCHAR\n");
			   i = 0;
				while (codeSegment[pc+i+1] != 0)
				{
				   printf("%c",codeSegment[pc+i+1]);
				   i++;
				}
	
				pc += i + 2;
				break;
			}
			
			case OP_SAVEBP:	
			{
				printf("SAVEBP\n"); 
			   pile[sp+1] = bp;
				sp++; 
				pc++;				break;
			}
			case OP_RSTRBP:	
			{
				printf("RSTRBP\n"); 
			   bp = pile[sp];
				sp--; 
				pc++;
				break;
			}
   
			default:
				printf("Instruction non reconnue\n");
				exit(1);
		}
		//printExecStack();
		//printPile();
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
