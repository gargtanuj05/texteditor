/**
* ch.c -- для обмена содержимого текущей строки до и после курсора
*
* Copyright (c) 2018, Mihailov Igor <mihailov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void change(int index, char *contents, int cursor, void *data);

void ch(text txt)
{
  /* Применяем функцию first_to_end к каждой строке текста */
  process_forward(txt, change, NULL);
}


static void change(int index, char *contents, int cursor, void *data)
{
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(data);

  if (cursor != -1)
  {
    char begin[MAXLINE];
    char after[MAXLINE];

    /* Копируем части строки до и после курсора */
    strncpy(begin, contents, cursor);
    begin[cursor] = '\0';

    strncpy(after, contents + cursor, strlen(contents));
    after[strlen(contents) - cursor] = '\0';

    /* Меняем местами строки до и после курсора */
    strncpy(contents, after, cursor);
    strncpy(contents + cursor, begin, strlen(contents));

    contents[strlen(contents)] = '\0';
  }
}
