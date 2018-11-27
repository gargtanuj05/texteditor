/**
 * data.c -- реализует проверку ввода для функций, работающих с курсором
 *
 * Copyright (c) 2018, Darya Madrakhimova <madrahim@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */
 
#include <stdio.h>
#include "data.h"

void iscorrect(dat data)
{
	if (data.line <= 0 || data.cursor <= 0) {
		fprintf(stderr, "Incorrect data entered!\n");
		return;
	}
}
