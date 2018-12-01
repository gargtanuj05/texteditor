/**
 * mwbb.c -- реализует смещение позиции курсора в начало слова, если возможно
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <ctype.h>
#include <stdlib.h>

static void move_cursor_left(int index, char *contents, int cursor, void*data);


void mwbb(text txt)
{
    process_forward(txt, move_cursor_left, txt);
    getcrsr(txt);
}

static void move_cursor_left(int index, char *contents, int cursor, void*data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    if (cursor >= 0){
        printf("%d %d\n",index, cursor);
        while(cursor > 0 && !isspace(contents[cursor])){
	    cursor--;
        }
        mwcrsr(data, index, cursor);
    }
}
