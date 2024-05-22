
#include "phonenumber.h"

bool PhoneNumber::iswellformed( ) const 
{
    if(nr[0] != '+'){
        return false;
    }
    if(nr.length() < 10 || nr.length() > 20){
        return false;
    }
    for(int i = 1; i < nr.length(); i++){
        if(isdigit(nr[i]) ==false){
            return false;
        }
    }
    return true;
}

 
