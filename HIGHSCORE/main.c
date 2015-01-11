#include <stdio.h>
#include <stdlib.h>

int main()
{
int x;
int count;
char n[30];
FILE *fp;
fp=fopen ("rank.txt","r+");
FILE *fpn;
 if (fp==NULL) printf ("Erro!\n");

fscanf (fp,"%i", &x);
printf ("O maior escore eh:  %i\n",x);

printf ("Digite seu score: ");
scanf ("%i",&count);

if (count>x) 
{
 fclose(fp);
 fp=fopen ("rank.txt", "w+");
 fprintf (fp,"%i",count);
 fclose (fp);
 fpn=fopen ("nome.txt","w+");
 printf("Digite seu nome:");
 scanf("%s",n);
 fflush(stdin);
fprintf (fp,"%s",n);
fclose(fpn);
}
else
{
    printf ("Voce nao conseguiu superar o maior score, tente novamente\n");
}


  system("PAUSE");	
  return 0;
}
