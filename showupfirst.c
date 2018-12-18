/**
 * showupfirst.c -- функция перевода букв после пробела в верхний регистр
 *
 * Copyright (c) 2018, Minenko Danil <minenko@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void toupfirst(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
	if (isspace(s[i])){
	    s[i+1] = toupper(s[i+1]);
	}
    }
}

static void showupfirstt(int index, char *contents, int cursor, void *data);

/**
 * Переводит буквы после пробела в верхний регистр
 */
void showupfirst(text txt) {
    /* Применяем функцию showupfirst к каждой строке текста */
    process_forward(txt, showupfirstt, NULL);
}

static void showupfirstt(int index, char *contents, int cursor, void *data) {
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(data);

    /* Капитализация символов после пробела */
    char line[MAXLINE];
    char output_line[MAXLINE];
    strcpy(line, contents);

    if (cursor >= 0) {
	strncpy(output_line, line, cursor);
	output_line[cursor] = '|';
	strcpy(output_line + cursor + 1, line + cursor);
	toupfirst(output_line);
	printf("%s", output_line);
	if (output_line[strlen(output_line) - 1] != '\n')
	    printf("\n");
    } else {
	toupfirst(line);
	printf("%s", line);
	if (line[strlen(line) - 1] != '\n')
	    printf("\n");
    }
}
