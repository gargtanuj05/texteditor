/**
* get_cursor_position -- реализует получение координат курсора
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
#include <setjmp.h>
#include "data.h"

static jmp_buf s_jumpBuffer;
static void get_cursor_position(int index, char* contents, int cursor, void* data);

dat getcrsr(text txt)
{
  int val;
  val = setjmp(s_jumpBuffer);
  if (val){
      dat data;
      data.cursor = val & 65535;
      val /= 65536;
      data.line = val;
      return data;
  }
  process_forward(txt, get_cursor_position, NULL);
}

static void get_cursor_position(int index, char* contents, int cursor, void* data)
{
  assert(contents != NULL);
  UNUSED(data);
  if (cursor >= 0){
    printf("cursor line - %d\ncursor position -  %d\n", index + 1, cursor + 1);
    int val = index;
    val *= 65536;
    val += cursor;
    longjmp(s_jumpBuffer, val);
  }
}
