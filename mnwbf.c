/**
 * mnwbf.c -- для перемещения курсора в начало следующего слова, если это
 * возможно
 *
 * Copyright (c) 2018, Dmitriy Kustov <kustov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void mnwbf_line(int index, char *contents, int cursor, void *data);

void mnwbf(text txt) { process_forward(txt, mnwbf_line, txt); }

static void mnwbf_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  if (cursor >= 0) {
    int length = strlen(contents);
    for (int i = 1; i < length; i++) {
      if (isspace(contents[cursor + i]) && !isspace(contents[cursor + i + 1]) &&
          contents[cursor + i + 1] != '\0') {
        mwcrsr((text)data, index + 1, cursor + i + 2);
        break;
      }
    }
  }
}
