/**
 * restore.c -- реализует удаление курсора из строки
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "data.h"
#include "text/text.h"

static void remove_cursor_line(int index, char *contents, int cursor, void *data);

void remove_cursor(text txt, int cursor, int line)
{
	dat d;
	d.cursor = cursor;
	d.line = line;
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, remove_cursor_line, &d);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void remove_cursor_line(int index, char *contents, int cursor, void *data)
{
	/* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
	
	/* Декларируем неиспользуемые параметры */
	UNUSED(index);
	UNUSED(cursor);
	
	dat* d = (dat*)data;
	size_t m = (size_t)d->cursor - 1;
	int line = d->line - 1;
    
	if (line == index)
		memmove(&contents[m], &contents[m + 1], strlen(contents) - m);
}
