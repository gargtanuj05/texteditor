/**
 * showalphaonly.c -- реализует команду вывода текста в прямом порядке
 * следования строк, опуская небуквенные символы
 *
 * Copyright (c) 2018, Rostislav Shamarin <shamarin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void alpha_line(int index, char *contents, int cursor, void *data);

/**
 *
 */

void showalphaonly(text txt) {
  /* Применяем функцию alpha_line к каждой строке текста */
  process_forward(txt, alpha_line, NULL);
}

static void alpha_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  char str[strlen(contents)];
  int a = 0;

  for (int i = 0; i < (int)strlen(contents); i++) {
    if (isalpha(contents[i]) || contents[i] == ' ' || contents[i] == '\n') {
      str[a] = contents[i];
      a++;
    }
  }

  str[a] = '\0';
  printf("%s", str);

  if (str[a - 1] != '\n')
    printf("\n");
}
