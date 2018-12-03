/**
 * showupper.c -- функция вывода текста из файла прописными буквами
 *
 * Copyright (c) 2018, Hristoforov Egor <hristofo@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

void toup(char *s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        s[i] = toupper(s[i]);
    }
}

static void showupper_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит текст в верхнем регистре
 */
void showupper(text txt)
{
    /* Применяем функцию showupper_line к каждой строке текста */
    process_forward(txt, showupper_line, NULL);
    printf("\n");
}

static void showupper_line(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(data);

    /* Капитализация символов */
    char line[MAXLINE];
    char output_line[MAXLINE];
    strcpy(line, contents);

    if (cursor >= 0){
        strncpy(output_line, line, cursor);
        output_line[cursor] = '|';
        strcpy(output_line+cursor+1, line+cursor);
        toup(output_line);
        printf("%s", output_line);
    } else {
        toup(line);
        printf("%s", line);
    }
}