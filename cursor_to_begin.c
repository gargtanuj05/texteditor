/**
* cursor_to_begin.c -- функция перевода курсора в начало текущей строки
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

static void mlb(int index, char *contents, int cursor, void *data);

/**
* Выводит содержимое указанного файла на экран
*/
void cursor_to_begin(text txt)
{
  /* Применяем функцию show_line к каждой строке текста */
  process_forward(txt, mlb, txt);
}

/**
* Выводит содержимое указанного файла на экран
*/
static void mlb(int index, char *contents, int cursor, void *data)
{
  /* Функция обработчик всегда получает существующую строку */
  assert(contents != NULL);

  /* Декларируем неиспользуемые параметры */
  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  if (cursor != -1){
    change_cursor_position(data, index, 0);
  }
}
