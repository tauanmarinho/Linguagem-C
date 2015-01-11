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
  struct rank p[5], n[1], b[1];
  FILE *fp;
  
  fp=fopen("rank.txt","w+");
  if (fp==NULL) printf ("erro");
  
  for(i=0;i<5;i++)
  {
  fscanf(fp,"%s",p[i].nome);
  fscanf(fp,"%i",&p[i].count);  
  }
  for (i=0; i<5; i=i+1)
{
    for(j=0; j<4; j=j+1) 
    {
             if (p[j].count < p[j+1].count)
             {
             n[1] = p[j];
             p[j] = p[j+1];
             p[j+1]= n[1];
             }
    }
}
  
  for (i=0;i<1;i++)
  {
      printf("Digite o nome:");
      //fflush(stdin);
      gets(b[1].nome);
      printf("Digite o score:");
      //fflush(stdin);
      scanf("%i",&b[1].count);
      
      }
  for (i=4; i>=0; i--)
{
   if(b[1].count>p[j].count)
   {
             n[1] = p[j];
             p[j] = b[1];
             b[1] = n[1];
             i=0;
    }
}
  
for(i=0;i<5;i++)
{
        fprintf(fp,"Nome: %s\t", p[i].nome);
        fprintf(fp,"Score: %i\n", p[i].count);        
                
                }
fclose(fp);
  system("PAUSE");	
  return 0;
}
