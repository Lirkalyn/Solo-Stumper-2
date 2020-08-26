/*
** EPITECH PROJECT, 2020
** rostring
** File description:
** rotate-string-desu
*/

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int nb_word_finder(char *str)
{
    int nb_word = 0;
    int bool = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && bool == 0) {
            nb_word += 1;
            bool = 1;
        }
        else if (str[i] == ' ' || str[i] == '\t')
            bool = 0;
    }
    return nb_word;
}

int *word_pos_finder(char *str, int nb_word)
{
    int *pos;
    int bool = 0;
    int j = 0;

    pos = (int *)malloc(nb_word * sizeof(int));
    if (pos == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && bool == 0) {
            pos[j++] = i;
            bool = 1;
        }
        else if (str[i] == ' ' || str[i] == '\t')
        bool = 0;
    }
    return pos;
}

int *word_lenght_finder(char *str, int nb_word, int *pos)
{
    int tmp_len = 0;
    int *lenght;
    int bool = 0;

    lenght = (int *)malloc(nb_word * sizeof(int));
    if (lenght == NULL)
        return NULL;
    for (int i = 0; i < nb_word; i++) {
        for (int j = pos[i]; (str[j] != ' ' &&
            str[j] != '\t' && str[j] != '\0'); j++) {
            tmp_len += 1;
        }
        lenght[i] = tmp_len;
        tmp_len = 0;
    }
    return lenght;
}

char *str_maker(char *str, int nb_word, int *pos, int *lenght)
{
    char *rsl;
    int f_len = 0;
    int k = 0;

    for (int i = 0; i < nb_word; i++)
        f_len += lenght[i];
    f_len += nb_word;
    rsl = (char *)malloc (f_len * sizeof(char));
    if (rsl == NULL)
        return NULL;
    rsl[f_len - 1] = '\0';
    for (int i = 1; i < nb_word; i++) {
        for (int j = pos[i]; (str[j] != ' ' &&
            str[j] != '\t' && str[j] != '\0'); j++)
            rsl[k++] = str[j];
        rsl[k++] = ' ';
    }
    for (int i = pos[0]; str[i] != ' ' && str[i] != '\t' && str[i] != '\0'; i++)
        rsl[k++] = str[i];
    return rsl;
}

int main(int argc, char *argv[])
{
    char *rsl;
    int *pos;
    int *lenght;
    int nb_word = 0;

    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }
    nb_word = nb_word_finder(argv[1]);
    pos = word_pos_finder(argv[1], nb_word);
    lenght = word_lenght_finder(argv[1], nb_word, pos);
    rsl = str_maker(argv[1], nb_word, pos, lenght);
    if (pos == NULL || lenght == NULL || rsl == NULL)
        return 84;
    for (int i = 0; rsl[i] != '\0'; i++)
        write(1, &rsl[i], 1);
    write(1, "\n", 1);
    return 0;
}
