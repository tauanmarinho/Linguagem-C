#include <stdio.h>
#include <stdlib.h>

struct rank
{
       int count;
       char nome[30];
       };
int main()
{
    int i,j;
  struct rank p[1], n[1], b[1];
  
  FILE *fp;
  
  fp=fopen("rank.txt","r++");
  if (fp==NULL) printf ("erro");

           
      fscanf(fp,"%s",p[1].nome);
      fscanf(fp,"%i",&p[1].count);
           
      
      printf("Digite o score:");
      scanf("%i",&b[1].count);
      
if(p[1].count<b[1].count)
{
                         
printf("Digite o nome:");
      gets(b[1].nome);
     

fprintf(fp,"Nome: %s\t", b[1].nome);
fprintf(fp,"Score: %i\n", b[1].count);        
}                

fclose(fp);
  system("PAUSE");	
  return 0;
}
