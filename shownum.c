/**
* show.c -- реализует команду вывода содержимого текста с нумерацией строк
*
* Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <stdlib.h>

#define MAGENTA "\x1b[35m"
#define RESET "\033[0m"

static void shownum_line(int index, char *contents, int cursor, void *data);

/**
* Выводит содержимое с нумерацией строк
*/
void shownum(text txt)
{
  process_forward(txt, shownum_line, NULL);
}

/**
* Выводит содержимое с нумерацией строк
*/
static void shownum_line(int index, char *contents, int cursor, void *data)
{
  /* Функция обработчик всегда получает существующую строку */
  assert(contents != NULL);

  /* Декларируем неиспользуемые параметры */
  UNUSED(cursor);
  UNUSED(data);
  UNUSED(index);

  /* Выводим строку и ее номер на экран */
  if (contents[0] != '\0') {
    printf(MAGENTA "%d" RESET " %s", index + 1, contents);
  }
}
