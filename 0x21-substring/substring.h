#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int match(char const *s, char const **words, int nb_words, int word_length);
int is_not_in(int *arr, int length, int k);
int string_match(char const *str, char const *word);

#endif