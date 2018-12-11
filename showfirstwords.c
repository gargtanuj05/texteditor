/**
 * showfirstwords.c -- программа организует вывод первого слова из строки
 *
 * Copyright (c) 2018, Maksim Zdorovennov <zdoroven@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void showfirstwords_line(int index, char *contents, int cursor,
                                void *data);

void showfirstwords(text txt) {
  process_forward(txt, showfirstwords_line, NULL);
}

static void showfirstwords_line(int index, char *contents, int cursor,
                                void *data) {

  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  int i = 0;

  while (!isspace(contents[i]) && i < (int)strlen(contents)) {
    printf("%c", contents[i]);
    i++;
  }
  if (contents[i - 1] != '\n')
    printf("\n");
}
