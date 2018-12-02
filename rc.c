/**
* rc.c -- функция удаления первой пустой строки из файла
*
* Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void remove_line(int index, char *contents, int cursor, void *data);

/**
* Удаляет текущую строку
*/
void remove_current_line(text txt){
  process_forward(txt, remove_line, txt);
}

static void remove_line(int index, char *contents, int cursor, void *data)
{
  /* Функция обработчик всегда получает существующую строку */
  assert(contents != NULL);

  if (cursor > 0){
    delete_line(data, index + 1);
    mwcrsr(data, index, cursor + 1);
  }
}
