/**
* mnwbf.c -- перемещения курсора в начало следующего слова, если это возможно
*
* Copyright (c) 2018, Dmitriy Kustov <kustov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void mnwbf_line(int index, char *contents, int cursor, void *data);

/**
* Перемещает курсор в начало следующего слова
*/
void mnwbf(text txt)
{
  process_forward(txt, mnwbf_line, NULL);
}
static void mnwbf_line(int index, char *contents, int cursor, void *data)
{
  assert(contents != NULL);

  UNUSED(data);

  int length = strlen(contents);

  if (cursor != -1) {
    for (int i = 1; i < length; i++) {
      if (isspace(contents[cursor+i]) && !isspace(contents[cursor+i+1])) {
        cursor += i;
        break;
      }
    }
  }
  mwcrsr(txt, index + 1, cursor);
}
