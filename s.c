/**
 * s.c -- функция разделения строки на две по позиции курсора
 *
 * Copyright (c) 2018, Eugene Dikov <dikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "data.h"
#include "text/text.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 * Разделяет строку на две по позиции курсора
 *
 */
static void copy(int index, char *contents, int cursor, void *data);
static void copy_back(int index, char *contents, int cursor, void *data);

void s(text txt) {

  dat *fdata = (dat *)malloc(sizeof(dat));
  fdata->line = 0;
  fdata->cursor = 0;
  fdata->txt = create_text();

  /*Обработка строк*/
  process_forward(txt, copy, fdata);

  /*Подготовка главного текста*/
  remove_all(txt);

  /*Заполнение текста содержимым*/
  process_forward(fdata->txt, copy_back, txt);

  /*Установка курсора*/
  mwcrsr(txt, fdata->line, fdata->cursor);
}

/*Заполнение текста содержимым*/
static void copy_back(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);
  text txt = data;

  append_line(txt, contents);
}

/*Разделяет строку contents на две и копирует содержимое в буфер buf_txt*/
static void copy(int index, char *contents, int cursor, void *data) {
  assert(contents != NULL);

  UNUSED(index);
  dat *fdata = data;
  char buf[MAXLINE + 1] = {'\0'};

  if (cursor < 0) {
    append_line(fdata->txt, contents);
  } else {
    /*Сохранение координат курсора*/
    fdata->line = index + 1;
    fdata->cursor = cursor + 1;

    /*Разделение строки*/
    append_line(fdata->txt, strncpy(buf, contents, cursor));
    strncpy(buf + 1, contents + cursor, MAXLINE - 1 - cursor);
    buf[0] = '\b';
    append_line(fdata->txt, buf);
  }
}
