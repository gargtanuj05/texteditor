/**
 * c1n.c -- для перемещения первой строки в конец текста
 *
 * Copyright (c) 2018, Mihailov Igor <mihailov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

/* Считывает первую строку */
static void read_first(int index, char *contents, int cursor, void *data);

static char first_line[MAXLINE];
void c1n(text txt) {
  /*Применяем функцию read_first к каждой строке текста */
  process_forward(txt, read_first, NULL);

  /*Удаляем первую строку */
  delete_line(txt, 1);

  /*Записываем первую строку в конец текста*/
  append_line(txt, first_line);
}

static void read_first(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(cursor);
  UNUSED(data);

  /* Считываем первую строку */
  if (index == 0) {
    strncpy(first_line, contents, strlen(contents));
    first_line[strlen(contents)] = '\0';
  }
}
