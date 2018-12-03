/**
* remove_first_entry_line.c -- функция удаления первой пустой строки из файла
*
* Copyright (c) 2018, Hristoforov Egor <hristofo@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void remove_line(int index, char *contents, int cursor, void *data);

/**
* Удаляет первую пустую строку
*/
static int flag = 0;
void remove_first_entry_line(text txt){
  process_forward(txt, remove_line, txt);
  flag = 0;
}

/* Проверяет что строка состоит только из пробелов. */
int isos(char *str){
  int len = strlen(str);
  for (int i = 0; i < len; i++){
    if (!isspace(str[i])){
      return 0;
    }
  }
  return 1;
}

static void remove_line(int index, char *contents, int cursor, void *data)
{
  assert(contents != NULL);

  UNUSED(index);
  UNUSED(cursor);

  if((contents[0] == '\n' || isos(contents) == 1 ) && contents[0] != '\0' && !flag){
    delete_line(data, index + 1);
    flag = 1;
  }
}