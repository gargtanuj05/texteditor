/**
 * showunderscores.c -- функция замены пробелов на символ _ подчеркивания
 *
 * Copyright (c) 2018, Klim Basargin <basargin@petrsu.ru>
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
 * Заменяет пробелы на символ '_' подчеркивания
 */
static void show_underscores(int index, char *contents, int cursor, void *data);

void showunderscores(text txt) {
  /*Обработка строк*/
  process_forward(txt, show_underscores, NULL);
}

static void show_underscores(int index, char *contents, int cursor,
                             void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(data);

  char line[MAXLINE];
  char output_line[MAXLINE];
  strcpy(line, contents);

  int i;
  if (cursor >= 0) {
    i = 0;
    strncpy(output_line, line, cursor);
    output_line[cursor] = '|';
    strcpy(output_line + cursor + 1, line + cursor);
    while (output_line[i]) {
      if (output_line[i] == ' ')
        printf("_");
      else
        printf("%c", output_line[i]);
      i++;
    }
    if (output_line[strlen(output_line) - 1] != '\n')
      printf("\n");
  } else {
    i = 0;
    while (line[i]) {
      if (line[i] == ' ')
        printf("_");
      else
        printf("%c", line[i]);
      i++;
    }
  }
}
