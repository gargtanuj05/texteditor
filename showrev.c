/**
 * showrev.c -- реализует команду вывода содержимого текста в обратном порядке
 * следования строк
 *
 * Copyright (c) 2018, Kirill Logvinov <logvinov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void showrev_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое в обратном порядке
 */
void showrev(text txt) { process_backward(txt, showrev_line, NULL); }

static void showrev_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(data);
  UNUSED(index);

  char line[MAXLINE];
  char output_line[MAXLINE];
  strcpy(line, contents);

  if (cursor >= 0) {
    strncpy(output_line, line, cursor);
    output_line[cursor] = '|';
    strcpy(output_line + cursor + 1, line + cursor);
    printf("%s", output_line);
    if (output_line[strlen(output_line) - 1] != '\n')
      printf("\n");
  } else {
    printf("%s", line);
    if (line[strlen(line) - 1] != '\n')
      printf("\n");
  }
}
