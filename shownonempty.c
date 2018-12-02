/**
* shownonempty.c -- реализует команду вывода содержимого непустых строк
*
* Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <stdlib.h>
#include <ctype.h>

#define RESET "\033[0m"

static void shownonempty_line(int index, char* contents, int cursor, void* data);

void shownonempty(text txt)
{
  process_forward(txt, shownonempty_line, NULL);
}

static void shownonempty_line(int index, char* contents, int cursor, void* data)
{
  /* Функция обработчик всегда получает существующую строку*/
  assert(contents != NULL);

  /* Декларируем неиспользуемые параметры*/
  UNUSED(cursor);
  UNUSED(data);
  UNUSED(index);

  /* Вывод непустых строк*/
  if (contents[0] != '\0'){
    int i = 1;
    while(contents[i] != '\0'){
      /* Проверям является ли текущий символ пробелом(пробел,
      * табуляция, etc)*/
      if (isspace(contents[i])){
        i++;
        continue;
      }

      /* Если нашли непробельный символ, то выводим строку*/
      printf(RESET"%s", contents);
      break;
    }
  }
}
