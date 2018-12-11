/**
 * plb.c -- функция вывода строки от начала до позиции курсора
 *
 * Copyright (c) 2018, Eugene Dikov <dikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Выводит строку от начала до позиции курсора
 */
static void get_plb(int index, char *contents, int cursor, void *data);

void plb(text txt) {
  /*Обработка строк*/
  process_forward(txt, get_plb, txt);
}

static void get_plb(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(data);

  /*Вывод строки от начала до курсора*/
  if (cursor >= 0) {
    for (int i = 0; i < cursor; i++) {
      printf("%c", contents[i]);
    }
  }
  if (contents[cursor - 1] != '\0')
    printf("\n");
}
