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

void printpos(dat val)
{
    printf("%d %d\n", val.line, val.cursor);
}
