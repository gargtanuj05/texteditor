/**
* Перемещает курсор на заданную позицию
*/

#include "common.h"
#include "text/text.h"

change_cursor_position(text txt, int line, int cursor);


void mwcrsr(text txt, int line, int cursor)
{
  change_cursor_position(txt, line, cursor);
  getcrsr(txt);
}
