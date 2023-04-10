#include "Cell.h"

char Complementary(char nokleotid)
{
    if (nokleotid == 'A') { return 'T';}
    else if (nokleotid == 'T') { return 'A';}
    else if (nokleotid == 'C') { return 'G';}
    else if (nokleotid == 'G') { return 'C';}
    return ' ';
}
