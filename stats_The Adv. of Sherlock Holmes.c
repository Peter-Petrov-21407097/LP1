#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
 
#define MAX_PALAVRA_LEN 50
#define MAX_palavras 25000
 
 
void bubblesort(int v[], int tam, int (*compara)()){
        int i=0, j, t, trocou;
        do {
                trocou = 0;
                for(j=0; j<tam-1-i; j++)        /* Percorre vetor */
                        if( (*compara)(v[j], v[j+1]) ) {
                                t = v[j];
                                v[j] = v[j+1];
                                v[j+1] = t;
                                trocou = 1;
                        }
                i++;
        } while(trocou==1);
}
 
int eparagrafo(char linha[]);
int obterpalavras(char linha[]);
 
int main(int argc, char const *argv[])
{
        FILE *fp;
 
        int paragrafos = 1, linhas = 0, isinparagrafo = 0, conta = 0, idx = 0;
        int paragrafos2 = 0, paragrafos3 = 0;
        int vogais = 0, consoantes = 0;
        int palavras = 0;
 
        char linha[1000];
        char prevlinha[1000];
 
 
 
        //char *fileName=argv[1];
        char *nomeficheiro = "stats_The Adv. of Sherlock Holmes.txt";
       
        //CENAS
       
       
       
        char palavras1[MAX_palavras][MAX_PALAVRA_LEN];
    int  conta1[MAX_palavras] = { 0 };
    int w = 0;
    char palavra1[MAX_PALAVRA_LEN];
    int c1,j;
    int l = 0;
 
       
       
       
        //CENAS 2
                fp = fopen(nomeficheiro, "rt");
 
        if (fp == NULL)
        {
                printf("erro ao ler %s\n", nomeficheiro);
        }
        else
        {
        while ((c1 = fgetc(fp)) != EOF)
    {
        c1= tolower(c1);
        if (isalpha(c1))
        {
            if (l < MAX_PALAVRA_LEN - 1)
               palavra1[l++] = c1;
            else
            {
                fprintf(stderr, "Palavra bastante grande: %*s%c...\n", l, palavra1, c1);
                break;
            }
        }
        else if (l > 0)
        {
            palavra1[l] = '\0';
            
            assert(strlen(palavra1) < MAX_PALAVRA_LEN);
            int encontra = 0;
            for ( j = 0; j < w; j++)
            {
                if (strcmp(palavra1, palavras1[j]) == 0)
                {
                    conta1[j]++;
                    encontra = 1;
                    break;
                }
            }
            if (!encontra)
            {
                if (w >= MAX_palavras)
                {
                    fprintf(stderr, "Palavras bastante semelhantes (%s)\n", palavra1);
                    break;
                }
                strcpy(palavras1[w], palavra1);
                conta1[w++] = 1;
            }
            l = 0;
        }
    }
palavra1[l] = '\0';
            //printf("Encontra a palavra <<%s>>\n", palavra1);
            assert(strlen(palavra1) < MAX_PALAVRA_LEN);
            int encontra = 0;
            for ( j = 0; j < w; j++)
            {
                if (strcmp(palavra1, palavras1[j]) == 0)
                {
                    conta1[j]++;
                    encontra = 1;
                    break;
                }
            }
            if (!encontra)
            {
                if (w >= MAX_palavras)
                {
                    fprintf(stderr, "Palavras bastante semelhantes (%s)\n", palavra1);
                }
                strcpy(palavras1[w], palavra1);
                conta1[w++] = 1;
            }
            l = 0;
       
 
    for (j = 0; j < w; j++) {
                printf("%3d: %s\n", conta1[j], palavras1[j]);
        }
        printf("palavrasU: %d\n", j);
}
        fclose(fp);
 
        fp = fopen(nomeficheiro, "r");
 
        if (fp == NULL)
        {
                printf("Erro ao ler %s\n", nomeficheiro);
        }
        else
        {
                int c;
                while ((c = getc(fp)) != EOF) {
                        tolower(c);
                        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                                vogais++;
                        }
                        if (c == 'b' || c == 'c' || c == 'd' || c == 'f'
                                || c == 'g' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'm'
                                || c == 'n' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't'
                                || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z') {
                                consoantes++;
                        }
                }
               
                fclose(fp);
               
               
                fp = fopen(nomeficheiro, "r");
       
                while (fgets(linha, 1000, fp))
                {
                        linhas++;
                        if (eparagrafo(linha) == 1 && isinparagrafo == 0)
                        {
                                paragrafos++;
                                isinparagrafo = 1;
 
                                if (prevlinha[strlen(prevlinha) - 2] != '.')
                                        paragrafos2++;
 
                                if (linha[0] >= 97 && linha[0] <= 122 ) {
                                        paragrafos3++;
                        }
                        }
 
                        if (eparagrafo(linha) == 0)
                        {
                                isinparagrafo = 0;
 
                                palavras += obtempalavras(linha);
                        }
 
                        strcpy(prevlinha, linha);
 
                }
 
                if (prevlinha[strlen(prevlinha) - 1] != '.')
                        paragrafos2++;
        }
        fclose(fp);
 
 
        printf("linhas: %d\n", linhas);
        printf("paragrafos: %d\n", paragrafos);
        printf("paragrafos2: %d\n", paragrafos2);
        printf("paragrafos3: %d\n", paragrafos3);
        printf("palavras: %d\n", palavras);
        printf("vogais: %d\n", vogais);
        printf("consoantes: %d\n", consoantes);
 
       
        system("PAUSE");
        return 0;
}
 
int eparagrafo(char linha[])
{
        if (linha[0] == '\n')
                return 1;
 
        return 0;
}
 
int obtempalavras(char linha[])
{
        int palavras = 0;
        int i;
 
        for (i = 1; i < strlen(linha) - 1; i++)
        {
                if (linha[i] == ' ')
                {
                        if (linha[i - 1] != ' ' && linha[i + 1] != ' ')
                                palavras++;
                }
        }
 
        palavras++;
 
        return palavras;
}
