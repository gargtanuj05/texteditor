/**
 * digitlines.c -- реализует команду вывода строк в которых встречаются цифры
 *
 * Copyright (c) 2018, Mihailov Igor <mihailov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void digit_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит строки с цифрами на экран
 */

void showlineswithdigits(text txt)
{
    /* Применяем функцию digit_line к каждой строке текста */
    process_forward(txt, digit_line, NULL);
}

/**
 * Выводит строки с цифрами на экран
 */

static void digit_line(int index, char *contents, int cursor, void *data)
{
    int mark = 0;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    for(int i = 0; i<strlen(contents); i++) {
	if (isdigit(contents[i])){
	    mark = 1;
	    break;
	}	
    }
    
    /* Выводим строку, если присутствуют цифры */
    if (mark == 1)
	printf("%s", contents);
}
