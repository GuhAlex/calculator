#include <stdio.h>
#include <stdlib.h>

void show(void);
void adi(void);
void sub(void);
void mult(void);
void divi(void);
void back(void);
void clearbuffer(void);

int main()

{
  int choice;

  system("clear || cls");
  show();
  scanf(" %i", &choice);

  switch (choice)   
  {

    case 1:
     
      system("clear || cls");
      adi();

      break;

   case 2:

      system("clear || cls");
      sub();
    
      break;

   case 3:

      system("clear || cls");
      mult();
      
      break;
 
   case 4:

      system("clear || cls");
      divi();
      
      break;
   
   case 5:

      system("clear || cls");
      exit (0);
      
      break;
  }

  clearbuffer();
  back();

  return 0;
}

void show(void)

{
  printf("\t\t\tEscolha a operação matemática que deseja:\n");
  printf("\t\t\t[1]Para Adição[+]\n");
  printf("\t\t\t[2]Para Subtração[-]\n");
  printf("\t\t\t[3]Para Multiplicação[x]\n");
  printf("\t\t\t[4]Para Divisão[:]\n");
  printf("\t\t\t[5]Para Sair\n\t\t\t");

}

void adi(void)

{
      int num;
      int soma = 0;
      int i = 0; 
      int j = 0;
      int buffer[100];// Buffer para amarzenar os valores a serem somados

      printf("Digite '=' para somar os valores:\n");

      while(scanf(" %d", &num) != 0)  // scanf retorna zero para valores que não conseguir assimilar. 
      {
        buffer[i] = num;              // enquanto o retorno do scanf for diferente de zero, armazene no buffer.
        ++i;
      }
 
      for(j = 0; j < i; j++) // Para acessar os valores do buffer
      {
          soma += buffer[j]; // Somando os valores do buffer
      }

      printf(" %d\n", soma);
}

void sub(void)

{
      int num;
      int sub = 0;
      int i = 0;
      int j;
      // Armazena apenas dois valores no buffer para a operação matemática, pois a subtração não possui as
      // mesmas propriedades associativas e comutativas como na soma e multiplicação.
      int buffer[2]; 

      printf("Digite '=' para subtrair os valores\n");

      while(scanf("%d", &num) != 0)
      {  
        buffer[i] = num;              
        i++;
        
        if (i > 2)
        {
          printf("Informe apenas dois valores para a subtração\n\n");
          clearbuffer();
          back();
        }
      }
      
         sub = buffer[0] - buffer[1];
      
         printf("%d\n", sub);
}

void mult(void)

{
  int num;
  int mult = 1; // atribui 1 á variável, pois todo valor multiplicado por 0 resultará 0
  int i = 0; 
  int j = 0;
  int buffer[100];

  printf("Digite '=' para multiplicar os valores:\n");
  
  while(scanf(" %d", &num) != 0)
  {
    buffer[i] = num;
    ++i;
  }
  
  for(j = 0; j < i; j++)
  {
      mult *= buffer[j];
  }


  printf(" %d\n", mult);
}

void divi(void)

{
    int num;
    int div = 0;
    int resto;
    int i = 0; 
    int j = 0;
    // Armazena apenas dois valores no buffer para a operação matemática, pois a divisão não possui as
    // mesmas propriedades associativas e comutativas como na soma e multiplicação.
    int buffer[2];

    printf("Digite '=' para divisão dos valores:\n");

    while(scanf(" %d", &num) != 0)
    {
      buffer[i] = num;
      ++i;
        if (i > 2)
        {
          printf("Informe apenas dois valores para a divisão\n\n");
          clearbuffer();
          back();
        }
     }

     div = buffer[0]/buffer[1];
     resto = buffer[0]%buffer[1];
   
     printf(" %d,%d\n", div, resto);
}

void back(void)

{
      char choice;
      printf("Deseja Voltar?\n");
      printf("[1]Para Sim\n");
      printf("[2]Para Não\n");
      scanf("%c", &choice);
      if (choice == '1'){
        main();
        clearbuffer();
      }
      else
        exit(0);
}


void clearbuffer(void) // Função para limpar qualquer conteúdo acumulado no stdin incluindo o caractere de nova linha
{
  char c;
  while((c = getchar()) != '\n' && c != EOF);
}
