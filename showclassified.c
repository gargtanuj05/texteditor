/**
 * showclassified.c -- функция замены непробельных символов на символ * звёзды
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
 * Заменяет непробельные символы на символ '*' звезды
 */
static void show_stars(int index, char *contents, int cursor, void *data);

void showclassified(text txt) {
  /*Обработка строк*/
  process_forward(txt, show_stars, NULL);
}

static void show_stars(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  int i = 0;
  while (contents[i]) {
    if (contents[i] != ' ' && contents[i] != '\n')
      printf("*");
    else
      printf("%c", contents[i]);
    i++;
  }
  if (contents[strlen(contents) - 1] != '\n')
    printf("\n");
}
