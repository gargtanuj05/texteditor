/**
* showclassified.c -- функция замены непробельных символов на символ * звёзды
*
* Copyright (c) 2018, Eugene Dikov <dikov@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <stdlib.h>

/**
 * 
 * Заменяет непробельные символы на символ '*' звезды
 *
 */
 
static void show_stars(int index, char *contents, int cursor, void *data);

void showclassified(text txt){
	/*Обработка строк*/
    process_forward(txt, show_stars, NULL);
    /*Вывод текста*/
    show(txt);
}

static void show_stars(int index, char *contents, int cursor, void *data){
    assert(contents != NULL);
	
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    int i = 0;
    while(contents[i]){
        if(contents[i] != ' ' && contents[i] != '\n')
            printf("*");
        else
            printf("%c", contents[i]);
        i++;
    }
}
