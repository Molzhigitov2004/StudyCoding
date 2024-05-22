
#include "phonebook.h"

void PhoneEntry::print(std::ostream& out) const {
    out << firstname << " " << secondname << " " << number << "\n";
}

void PhoneEntry::read(std::istream& in) {
    in >> firstname >> secondname >> number;
}


void PhoneBook::read( std::istream& in ) 
{
    while (in){
    PhoneEntry entry;
    entry.read(in);
    if(in){
    entries.push_back(entry);
    }
    }
} 


void PhoneBook::print( std::ostream& out ) const 
{
    for( int i = 0; i < entries.size(); i++){
        entries[i].print(out);
    }
}


void PhoneBook::checkandnormalize( std::ostream& err )
{ 
    for( int i = 0; i < entries.size(); i++){
        entries[i].firstname.normalize();
        entries[i].secondname.normalize();


        if (!entries[i].number.iswellformed()) {
            err << "Warning: Not well formed phone number in entry " << i + 1 << ": ";
            entries[i].number.print(err);
            err << "\n";
        }
    }
}


