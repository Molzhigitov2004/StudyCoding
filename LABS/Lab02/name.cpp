
#include "name.h"
#include <cctype> 

void Name::normalize( )
{
    for(int i = 0; i < n.length(); i++){
        n[i] = tolower(n[i]);
    }
    n[0] = toupper(n[0]);
}

