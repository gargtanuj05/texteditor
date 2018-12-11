/**
 * cursor_to_begin.c -- функция перевода курсора в начало текущей строки
 *
 * Copyright (c) 2018, Hristoforov Egor <hristofo@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void mlb(int index, char *contents, int cursor, void *data);

/**
 * Переводит курсор в начало текущей строки
 */
void cursor_to_begin(text txt) {
  /* Применяем функцию mlb к каждой строке текста */
  process_forward(txt, mlb, txt);
}

static void mlb(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);

  if (cursor != -1) {
    mwcrsr((text)data, index + 1, 1);
  }
}
