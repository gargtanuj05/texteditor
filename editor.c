/**
* editor.c -- строковый текстовый редактор
*
* Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
  char cmdline[MAXLINE + 1];
  char *cmd;
  char *arg;

  /* Создаем объект для представления текста */
  text txt = create_text();

  /* Цикл обработки команд */
  while (1) {
    printf("ed > ");

    /* Получаем команду */
    fgets(cmdline, MAXLINE, stdin);

    /* Извлекаем имя команды */
    if ((cmd = strtok(cmdline, " \n")) == NULL) {
      continue;
    }
    /* Распознаем поддерживаемую команду */

    /* Завершаем работу редактора */
    if (strcmp(cmd, "quit") == 0) {
      fprintf(stderr, "Bye!\n");
      break;
    }

    /* Загружаем содержимое файла, заданного параметром */
    if (strcmp(cmd, "load") == 0) {
      if ((arg = strtok(NULL, " \n")) == NULL) {
        fprintf(stderr, "Usage: load filename\n");
      } else
      load(txt, arg);
      continue;
    }

    /* Сохраняем текст в указанный файл */
    if (strcmp(cmd, "save") == 0) {
      if ((arg = strtok(NULL, " \n")) == NULL) {
        fprintf(stderr, "Usage: save filename\n");
      } else {
        save(txt, arg);
      }
      continue;
    }

    /* Выводим текст */
    if (strcmp(cmd, "show") == 0) {
      show(txt);
      continue;
    }

    /* Переводим в верхний регистр */
    if (strcmp(cmd, "showupper") == 0) {
      showupper(txt);
      continue;
    }

    /* Удаляем первую пустую строку */
    if (strcmp(cmd, "r1e") == 0) {
      remove_first_entry_line(txt);
      continue;
    }

    /* Выводим содержимое с нумерацией строк */
    if (strcmp(cmd, "shownum") == 0) {
      shownum(txt);
      continue;
    }

    /* Выводим строки, в которых встречаются цифры */
    if (strcmp(cmd, "showlineswithdigits") == 0) {
      showlineswithdigits(txt);
      continue;
    }

    /* Выводим содержимое непустых строк */
    if (strcmp(cmd, "shownonempty") == 0) {
      shownonempty(txt);
      continue;
    }

    /* Меняем позицию курсора на заданную */
    if (strcmp(cmd, "mwcrsr") == 0){
      char* position = strtok(NULL, " \n"), *line = strtok(NULL, " \n");
      mwcrsr(txt, atoi(position), atoi(line));
      continue;
    }

    /* Выводим координаты курсора */
    if (strcmp(cmd, "getcrsr") == 0){
      getcrsr(txt);
      continue;
    }

    /* Перемещаем курсор в начало слова, если возможно*/
    if (strcmp(cmd, "mwbb") == 0){
      mwbb(txt);
      continue;
    }

    /* Удаляем текущую строку */
    if (strcmp(cmd, "rc") == 0){
      remove_current_line(txt);
      continue;
    }

    /* Выводим первое слово из каждой строки */
    if (strcmp(cmd, "showfirstwords") == 0) {
      showfirstwords(txt);
      continue;
    }

    /* Перемещаем первую строку в конец текста */
    if (strcmp(cmd, "c1n") == 0) {
      c1n(txt);
      continue;
    }

    if (strcmp(cmd, "printpos") == 0) {
      printpos(getcrsr(txt));
      continue;
    }

    /* Перемещаем курсор в начало строки */
    if (strcmp(cmd, "mlb") == 0) {
      cursor_to_begin(txt);
      continue;
    }

    /* Если команда не известна */
    fprintf(stderr, "Unknown command: %s\n", cmd);
  }

  return 0;
}