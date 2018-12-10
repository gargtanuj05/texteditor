/**
 * rp.c -- удаляет строку перед текущей.
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

static void rp_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void rp(text txt) { process_forward(txt, rp_line, NULL); }

/**
 * Выводит содержимое указанного файла на экран
 */
static void rp_line(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(data);

  if (cursor > 0) {
    delete_line(data, index);
  }
}
