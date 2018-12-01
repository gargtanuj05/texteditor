/**
 * Перемещает курсор на заданную позицию
 */

#include "common.h"
#include "text/text.h"

change_cursor_position(text txt, int cursor, int line);


void mwcrsr(text txt, int cursor, int line)
{
    change_cursor_position(txt, cursor, line);
}
