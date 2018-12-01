/**
 * shownonempty.c -- реализует команду вывода содержимого непустых строк
 *
 * Copyright (c) 2018, Egor Ignatov <ignatov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "_text.h"
#include "text.h"
#include <stdlib.h>
#include <ctype.h>

void change_cursor_position(text txt, int new_position, int new_line)
{
    node *p;
    p = txt->begin;
    for (int i = 0; i < new_line; i++){
        p = p->next;
    }
    txt->cursor->position = new_position;
    txt->cursor->line = p;
}
