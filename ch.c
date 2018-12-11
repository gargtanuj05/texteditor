/**
 * ch.c -- для обмена содержимого текущей строки до и после курсора
 *
 * Copyright (c) 2018, Mihailov Igor <mihailov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

static void change(int index, char *contents, int cursor, void *data);

void ch(text txt) {
  /* Применяем функцию change к каждой строке текста */
  process_forward(txt, change, txt);
}

static void change(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  if (cursor >= 0 && cursor != (int)strlen(contents)) {

    char begin[MAXLINE];
    char after[MAXLINE];

    /* Копируем части строки до и после курсора */
    strncpy(begin, contents, cursor);
    begin[cursor] = '\0';

    strncpy(after, contents + cursor, strlen(contents) - cursor - 1);
    after[strlen(contents) - cursor - 1] = '\0';

    /* Меняем местами строки до и после курсора */
    strncpy(contents, after, strlen(after));
    strncpy(contents + strlen(after), begin, strlen(contents));

    /*Ставим курсор в новую позицию*/
    mwcrsr(data, index + 1, strlen(after) + 1);

    /*Добавляем перевод на следуюющую строку в конце строки*/
    contents[strlen(contents)] = '\n';
    contents[strlen(contents) + 1] = '\0';
  }
}
