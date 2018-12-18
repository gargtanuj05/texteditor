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

#include "common.h"
#include "text/text.h"

#define MAXLINE 255

int main() {
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
    
    /* Выводим текст с капитализацией символов, которым предшествует пробел */
    if (strcmp(cmd, "showupfirst") == 0) {
      showupfirst(txt);
      continue;
    }

    /* Перемещаем курсор в конец строки */
    if (strcmp(cmd, "mle") == 0) {
      mle(txt);
      continue;	
    }

    /* Удаляем первую непустую строку  */
    if (strcmp(cmd, "r1ne") == 0) {
      r1ne(txt);
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

    /* Заменяет непробельные символы на символ '*' звезды */
    if (strcmp(cmd, "showclassified") == 0) {
      showclassified(txt);
      continue;
    }

    /* Выводим содержимое непустых строк */
    if (strcmp(cmd, "shownonempty") == 0) {
      shownonempty(txt);
      continue;
    }

    /* Меняем позицию курсора на заданную */
    if (strcmp(cmd, "mwcrsr") == 0) {
      char *line = strtok(NULL, " \n"), *position = strtok(NULL, " \n");
      if (line && position)
        mwcrsr(txt, atoi(line), atoi(position));
      else
        printf("Usage: mwcrsr line position\n");
      continue;
    }

    if (strcmp(cmd, "getcrsr") == 0) {
      getcrsr(txt);
      continue;
    }
    /* Перемещаем курсор в нчало слова */
    if (strcmp(cmd, "mwbb") == 0) {
      mwbb(txt);
      continue;
    }

    /* Удаляем текущую строку */
    if (strcmp(cmd, "rc") == 0) {
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

    /* Перемещаем курсор в начало строки */
    if (strcmp(cmd, "mlb") == 0) {
      cursor_to_begin(txt);
      continue;
    }

    /* Выводим часть строки от начала до курсора */
    if (strcmp(cmd, "plb") == 0) {
      plb(txt);
      continue;
    }

    /* Разделяет строку на две по позиции курсора */
    if (strcmp(cmd, "s") == 0) {
      s(txt);
      continue;
    }

    /* Выводим столбец длин строк текста */
    if (strcmp(cmd, "showlengths") == 0) {
      showlengths(txt);
      continue;
    }

    /* Перемещаем курсор в начало следующего слова, если это возможно  */
    if (strcmp(cmd, "mnwbf") == 0) {
      mnwbf(txt);
      continue;
    }

    /* Удаляем строку перед текущей */
    if (strcmp(cmd, "rp") == 0) {
      rp(txt);
      continue;
    }

    /* Обмен содержимого текущей строки до и после курсора */
    if (strcmp(cmd, "ch") == 0) {
      ch(txt);
      continue;
    }

    /* Перемещаем курсор на один символ вправо, если это возможно */
    if (strcmp(cmd, "mcf") == 0) {
      mcf(txt);
      continue;
    }

    /* Удаляем первую строку */
    if (strcmp(cmd, "rh") == 0) {
      rh(txt);
      continue;
    }

    /* Удаляем строку после текущей */
    if (strcmp(cmd, "rn") == 0) {
      rn(txt);
      continue;
    }

    /* Заменяем пробелы символом подчеркивания */
    if (strcmp(cmd, "showunderscores") == 0) {
      showunderscores(txt);
      continue;
    }

    /* Перемещаем курсор в конец предыдущего слова, если это возможно */
    if (strcmp(cmd, "mpweb") == 0) {
      mpweb(txt);
      continue;
    }

    /* Выводим содержимое в обратном порядке */
    if (strcmp(cmd, "showrev") == 0) {
      showrev(txt);
      continue;
    }

    /* Выводим часть строки от курсора до конца строки */
    if (strcmp(cmd, "ple") == 0) {
      ple(txt);
      continue;
    }

    /* Выводим часть строки от курсора до конца строки */
    if (strcmp(cmd, "ple") == 0) {
      ple(txt);
      continue;
    }

    /* Выводим текст, опуская небуквенные символы */
    if (strcmp(cmd, "showalphaonly") == 0) {
      showalphaonly(txt);
      continue;
    }

    /* Если команда не известна */
    fprintf(stderr, "Unknown command: %s\n", cmd);
  }

  return 0;
}
