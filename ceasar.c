#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int key_check(char* key);
char rotate(char c, int n);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("modo de uso: ./caesar chave\n");
        return 1;
    }
    else
    {
        int verificador = key_check(argv[1]);
        if(verificador == 1)
        {
            printf("modo de uso: ./caesar chave\n");
            return 1;
        }
    }
    
    // forçar getline a usar malloc
    char* text = NULL;
    // contar tamanho do buffer alocado sem exceder UINT_MAX
    size_t len = 0;
    // signed integer para contar char lido porcausa de casos de EOF ou erro 
    ssize_t read;
    printf("Texto para criptografar:\n");
    while((read = getline(&text, &len, stdin)) != -1)
    {
        int key = atoi(argv[1]);
        for(int i = 0; i < read; i++)
        {
            text[i] = rotate(text[i], key);
        }
    }
    printf("Texto criptografado: %s\n", text);
    free(text);
    return 0;
}

int key_check(char* key)
{
    int len = strlen(key);
    for(int i = 0; i < len; i++)
    {
        if(!isdigit(key[i]))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

char rotate(char c, int n)
{
    if(islower(c))
    {
        // valor ascii para a = 97, A = 65, 26 letras no alfabeto 
        c = (((c - 'a') + n) % 26) + 'a';
    }
    else if(isupper(c))
    {
        c = (((c - 'A') + n) % 26) + 'A';
    }
    return c;
}
