/**
 * r1ne.c -- функция удаления первой непустой строки из файла
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

static void r1nee(int index, char *contents, int cursor, void *data);

/**
 * Удаляет первую непустую строку
 */
static int flag = 0;
void r1ne(text txt) {
    process_forward(txt, r1nee, txt);
    flag = 0;
}

/* Проверяет наличие в строке буквы или цифры */
int empty(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
	if ((isdigit(str[i])) || isalpha(str[i])) {
	    return 1;
	}
    }
    return 0;
}

static void r1nee(int index, char *contents, int cursor, void *data) {
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(cursor);

    if ((empty(contents) == 1) && strlen(contents) != '\0' &&
	!flag) {
	delete_line(data, index + 1);
	flag = 1;
   
    }
}
