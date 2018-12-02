/**
* Перемещает курсор на заданную позицию
*/

#include "common.h"
#include "text/text.h"

void change_cursor_position(text txt, int line, int cursor);


void mwcrsr(text txt, int line, int cursor)
{
  change_cursor_position(txt, line, cursor);
  getcrsr(txt);
}
