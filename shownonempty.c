/**
 * shownonempty.c -- реализует команду вывода содержимого непустых строк
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void shownonempty_line(int index, char *contents, int cursor,
                              void *data);

void shownonempty(text txt) { process_forward(txt, shownonempty_line, NULL); }

static void shownonempty_line(int index, char *contents, int cursor,
                              void *data) {
  assert(contents != NULL);

  UNUSED(cursor);
  UNUSED(data);
  UNUSED(index);

  /* Вывод непустых строк*/
  int i = 0;
  while (contents[i] != '\0') {
    /* Проверям является ли текущий символ пробельным */
    if (isspace(contents[i])) {
      i++;
      continue;
    }

    /* Если нашли непробельный символ, то выводим строку*/
    if (cursor >= 0) {
      /* Есил в строке есть курсор выводим вместе с ним */
      for (int j = 0; j < (int)strlen(contents) + 1; j++) {
        if (j == cursor) {
          printf("|");
        }
        printf("%c", contents[j]);
      }
    } else
      printf("%s", contents);
    break;
  }
  if (contents[strlen(contents) - 1] != '\n')
    printf("\n");
}
