#include <stdio.h>
#include <string.h>

typedef struct word
{
    char string[20];
    size_t count;
} Tword;

// if new word, return 1 else 0
int found_word(char s[20], size_t unique_words, Tword *words)
{
    for (size_t i = 0; i < unique_words; i++)
    {
        if (strcmp(words[i].string, s) == 0) {
            words[i].count++;
            return 0;
        }
    }
    

    words = (int *)realloc(words, sizeof(words) + sizeof(Tword));
    words[unique_words].string = s;
    words[unique_words].count = 1;

    printf("%s\n", s);
    return 1;
}

int main()
{
    FILE *f;
    if ((f = fopen("text.txt", "r")) == NULL)
    {
        printf("input couldnt be opened");
        return 1;
    }

    Tword *words;
    size_t unique_words = 0;

    char c;
    char s[20];
    while ((c = fgetc(f)) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '.')
        {
            unique_words += found_word(s, unique_words, words);
            s[0] = '\0';
        }
        else
        {
            strncat(s, &c, 1);
        }
    }
    unique_words += found_word(s, unique_words, words);

    printf("unique_words: %d", unique_words);
    return 0;
}