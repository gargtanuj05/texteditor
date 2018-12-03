/**
* digitlines.c -- реализует команду вывода строк в которых встречаются цифры
*
* Copyright (c) 2018, Mihailov Igor <mihailov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void digit_line(int index, char *contents, int cursor, void *data);

/**
* Выводит строки с цифрами на экран
*/
void showlineswithdigits(text txt)
{
  /* Применяем функцию digit_line к каждой строке текста */
  process_forward(txt, digit_line, NULL);
}

static void digit_line(int index, char *contents, int cursor, void *data)
{
  int mark = 0;
  
  assert(contents != NULL);
  
  UNUSED(index);
  UNUSED(cursor);
  UNUSED(data);
  
  char output_line[MAXLINE];
  
  for(int i = 0; i<(int)strlen(contents); i++) {
    if (isdigit(contents[i])){
      mark = 1;
      break;
    }
  }
  
  /* Выводим строку с цифрами на экран */
  if (mark == 1)
  {
    if (cursor >= 0){
      strncpy(output_line, contents, cursor);
      output_line[cursor] = '|';
      strcpy(output_line+cursor+1, contents+cursor);
      printf("%s", output_line);
    } else {
      printf("%s", contents);
    }
  }
}