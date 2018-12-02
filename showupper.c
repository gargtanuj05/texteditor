/**
* showupper.c -- функция вывода текста из файла прописными буквами
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

static void show_line(int index, char *contents, int cursor, void *data);

/**
* Выводит содержимое указанного файла на экран
*/
void showupper(text txt)
{
  /* Применяем функцию show_line к каждой строке текста */
  process_forward(txt, show_line, NULL);
}

/**
* Выводит содержимое указанного файла на экран
*/
static void show_line(int index, char *contents, int cursor, void *data)
{
  /* Функция обработчик всегда получает существующую строку */
  assert(contents != NULL);

  /* Декларируем неиспользуемые параметры */
  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  /* Капитализация символов */

  int len = strlen(contents);
  char line[MAXLINE];
  strcpy(line, contents);

  for (int i = 0; i < len; i++){
    line[i] = toupper(line[i]);
  }

  /* Выводим строку на экран */
  printf("%s", line);
}
