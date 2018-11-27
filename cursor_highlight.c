/**
 * cursor_highlight.c -- реализует подстветку курсора
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include "data.h"
#include <stdlib.h>
#include <string.h>

void cursor_highlight_line(int index, char *contents, int cursor, void *data);

void cursor_highlight(text txt, int cursor, int line)
{
	dat d;
	d.cursor = cursor;
	d.line = line;
	iscorrect(d);
	process_forward(txt, cursor_highlight_line, &d);
}

/**
 * Подсветка курсора
 */
void cursor_highlight_line(int index, char *contents, int cursor, void *data)
{
	UNUSED(index);
	UNUSED(cursor);
	dat* d = (dat*)data;
	size_t m = (size_t)d->cursor - 1;
	int line = d->line - 1;
	
	char buffer[strlen(contents) + 1];
	strcpy(buffer, contents);
	if (index == line && m < strlen(contents)) {
		for (size_t i = m; i <= strlen(contents); i++) {
			if (i > m)
				buffer[i] = contents[i - 1];
			else
				buffer[i] = '|';	
		}
		buffer[strlen(contents) + 1] = '\0';
	}
	strcpy(contents, buffer);
}
		