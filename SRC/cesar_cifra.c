#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef WIN32
#include <conio.h>

#else
#define getch(a) getchar(a); fflush(stdin)
#endif




enum booleano
{
    true = 1, false = 0
};
typedef enum booleano BOOL;
/*--------------------------------------*/


// limpa ecran
void limpar()
{
    system ("clear || cls");
}



/*Funcao que faz substituicao de cada letra no texto de acordo com a chave numerica informada*/
char cifraCesar(char *texto, int chave, int tipo) // tipo = 0 -> Encriptar mensagem | tipo = 1 -> decifrar mensagem
{
    /*-----VARIAVEIS PRINCIPAIS--------*/
    int tam=strlen(texto);
    int i=0;
    int cont=0;
    char letra;
    char saida[100];
    /*----------------------------------*/


    /*----------LOOP PARA SUBSTITUIÇÃO---------*/
    for (letra='a'; letra<='z'; letra++)
    {
        while(i<=tam)
        {
            if(texto[i] == letra)
            {
                if(tipo == 0)
                    texto[i] = letra+chave;

                else

                if (tipo == 1)
                    texto[i] = letra-chave;

                i++;
                cont ++;
                letra='a';

            }

            else if(texto[i] == ' ')
            {
                i++;
                cont ++;
                letra='a';
            }

            else if(texto[i] == toupper(letra))
            {

                if(tipo == 0)
                    texto[i] = toupper(letra+chave);
                else if (tipo == 1)
                    texto[i] = toupper(letra-chave);

                i++;
                cont ++;
                letra='a';
            }

            else
                letra++;

            if(cont == tam)
                break;

        }
    }


    if(tipo == 0)
        return printf("Codigo gerado: %s\n",texto);
    else
        return printf("Mensagem decifrada: %s\n",texto);
}



int main()
{
    /*-----VARIAVEIS PRINCIPAIS--------*/
    int op=3;
    int chave;
    char *mensagem;
    const int tamanho = 100;
    BOOL confirma=false;
    /*----------------------------------*/

    //Alocar  memoria para receber mensagem (texto pleno) e cifrado (texto criptografado)
    mensagem = (char *)malloc(tamanho);
    /*-----------------------------------------------------------------------------------*/

    printf ("\n--------------------------------------------\n");
    printf ("\n          -- Cifra de César --\n");
    printf ("\n--------------------------------------------\n");

    while (op!=0)
    {

        printf ("\t\t Escolha uma Opcao: \n\n");

        printf ("1-) Encriptar mensagem \n");
        printf ("2-) Decifrar mensagem  \n");
        printf ("0-) Sair \n");
        scanf  ("%d",&op);

        if (op ==  1)
        {

            printf("Chave de Deslocamento: ");
            scanf ("%d",&chave);

            printf ("Mensagem: \n");
            fflush(stdin);
            gets(mensagem);

            cifraCesar(mensagem,chave,0);

            getch();

            confirma=true;
            limpar();
        }

        else if (op == 2)
        {

            if (confirma == false)
            {

                printf("Chave de Deslocamento: ");
                scanf ("%d",&chave);

                printf ("Mensagem: \n");
                fflush(stdin);
                gets(mensagem);

                cifraCesar(mensagem,chave,1);
                getch();

                limpar();
            }

            else if(confirma == true)
            {

                cifraCesar(mensagem,chave,1);
                getch();

                limpar();
                op=0;
            }
        }
        else if (op == 0)
        {
            free(mensagem);
            break;
        }

        else
        {

            printf("\n\t Confirme a Opcao escolhida!\n");
            getch();

            limpar();
            break;
        }


    }

}