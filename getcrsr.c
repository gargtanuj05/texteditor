/**
* change_cursor_position -- реализует перемещение курсора
*
* Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include "text/text.h"
#include "common.h"
#include <stdlib.h>
#include <ctype.h>


static void get_cursor_position(int index, char* contents, int cursor, void* data);

void getcrsr(text txt)
{
  process_forward(txt, get_cursor_position, NULL);
}

static void get_cursor_position(int index, char* contents, int cursor, void* data)
{
  assert(contents != NULL);

  UNUSED(data);
  if (cursor >= 0){
    printf("cursor line - %d\ncursor position -  %d\n", index + 1, cursor + 1);
  }
}
