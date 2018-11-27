/**
 * restore.c -- реализует резервное копирование текста
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void restore_line(int index, char *contents, int cursor, void *data);

void restore(text txt, text tmp)
{
	remove_all(txt);
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(tmp, restore_line, txt);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void restore_line(int index, char *contents, int cursor, void *data)
{
	text txt = (text)data;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    append_line(txt, contents);
}
