
#include "set.h"


int case_insensitive_cmp::operator( ) ( const std::string& s1, const std::string& s2 ) const
{
   size_t i = 0;
   while (i < s1.length() && i < s2.length()) {
      char c1 = std::tolower(s1[i]);
      char c2 = std::tolower(s2[i]);
      if (c1 != c2) {
         return c1 - c2;
      }
      i++;
   }
   return s1.length() - s2.length();
}


const treenode* find( const treenode* n, const treenode::valtype& val ) //completed //works
{
   treenode::valcmp cmp;
   // case_insensitive_cmp cmp;
   while(n != nullptr){
      int comparison = cmp(n->val, val);
      if(comparison < 0){
         n = n->right;
      } else if (comparison > 0){
         n = n->left;
      } else {
         return n;
      }
   }
   return nullptr;
}

treenode** find( treenode** n, const treenode::valtype& val ) //completed //works
{
   treenode::valcmp cmp;
   // case_insensitive_cmp cmp;
    while (*n != nullptr) {
      int comparison = cmp((*n)->val, val);
      if (comparison < 0) {
         n = &((*n)->right);
      } else if (comparison > 0) {
         n = &((*n)->left);
      } else {
         return n;
      }
   }
   return n;
}

size_t size( const treenode* n ) //completed //works
{
   if (n == nullptr) {
      return 0;
   }
   return 1 + size(n->left) + size(n->right);   
}

size_t height( const treenode* n ) //completed //works
{
   if(n == nullptr){
      return 0;
   }
   size_t left_height = height(n->left);
   size_t right_height = height(n->right);
   if (left_height > right_height) {
      return 1 + left_height;
   } else {
      return 1 + right_height;
   }
}

void deallocate( treenode* n ) //completed //works
{
   if(n == nullptr){
      return;
   }
   deallocate(n->right);
   deallocate(n->left);

   delete n;
}


treenode* makecopy( const treenode* n ) //completed //works
{
   if (n == nullptr) {
      return nullptr;
   }

   treenode* newNode = new treenode(n->val);

   newNode->left = makecopy(n->left);
   newNode->right = makecopy(n->right);

   return newNode;
}


// Step to the right as long as possible. When we get
// stuck, we are in the rightmost node. Remove it, and
// return it. (Don't delete it.)
// *from cannot be the empty tree.

treenode* extractrightmost( treenode** from ) //completed //given
{
   while( (*from) -> right )
      from = & (*from) -> right;

   treenode* n = *from;
   *from = (*from) -> left;
   return n;
}

void print( std::ostream& out, const treenode* n, unsigned int indent ) //completed //given
{

   for( unsigned int i = 0; i != indent; ++ i )
      out << "|  "; 
   if(n)
   {
      out << ( n -> val ) << "\n";
      print( out, n -> left, indent + 1 );
      print( out, n -> right, indent + 1 ); 
   }
   else
      out << "#\n"; 
}


// Both the upperbound and the lowerbound are strict.
// We use pointers, so that they can be absent. 
// Of course, this is a tasteless way of dealing with partiality.

void checkbetween( const treenode* n, //completed //given
                   const treenode::valtype* lowerbound, 
                   const treenode::valtype* upperbound ) 
{
   treenode::valcmp cmp;

   while(n) 
   {
      if( lowerbound && cmp( *lowerbound, n -> val ) >= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << " is not above lower bound " << *lowerbound << "\n";
         throw std::runtime_error( "tree not correct" ); 
      }

      if( upperbound && cmp( *upperbound, n -> val ) <= 0 ) 
      {
         std::cout << "value " << ( n -> val );
         std::cout << "is not below upperbound " << *upperbound << "\n";
         throw std::runtime_error( "tree not correct" );  
      }

      checkbetween( n -> left, lowerbound, &( n -> val ));
      lowerbound = & ( n -> val );
      n = n -> right;
   }
} 


unsigned int log_base2( size_t s ) //completed //works
{
   if(s == 1|| s == 0) return 0;
   unsigned int result = 0;
   unsigned int power = 1;

   while (power<= s) {
      power *= 2;
      result++;
   }

   return result - 1;
}

bool set::contains( const valtype& val ) const //completed //works
{ 
   const treenode* toFind = find(tr, val);
   return toFind != nullptr;
}

 
bool set::insert( const valtype& val ) //completed //works
{
   treenode** toInsert = find(&tr, val);
   if(*toInsert == nullptr){
      *toInsert = new treenode(val, nullptr, nullptr);
      return true;
   } else {
      return false;
   }
}


bool set::remove( const valtype& val ) //completed //works
{
   treenode** toRemove = find(&tr, val);

   if(*toRemove == nullptr){
      return false;
   }

   if((*toRemove)->left == nullptr && (*toRemove)->right == nullptr){
      delete *toRemove;
      *toRemove = nullptr;
   } else if((*toRemove)->left == nullptr){
      treenode* temp = *toRemove;
      *toRemove = (*toRemove)->right;
      delete temp;
   } else if ((*toRemove)->right == nullptr){
      treenode* temp = *toRemove;
      *toRemove = (*toRemove)->left;
      delete temp;
   } else {
      treenode* temp = extractrightmost(&((*toRemove)->left));
      (*toRemove)->val = temp->val;
      delete temp;
   }

   return true;
}


size_t set::size( ) const //completed //works
{
   return ::size( tr );
}

size_t set::height( ) const //completed //works
{
   return ::height( tr );
}

bool set::empty( ) const //completed //works
{
   return tr == nullptr;
}

set:: ~set( ) //completed //works
{
   clear();
}

void set::clear( ) //completed //works
{
   deallocate(tr);
   tr = nullptr;
}

set::set( const set& other ) //completed //works
{ 
   tr = makecopy(other.tr);
}


set& set::operator = ( const set& other ) //completed //works
{
   if(this == &other){
      return *this;
   } else {
      deallocate(tr);
      tr = makecopy (other.tr);
      return *this;
   }
}



void set::checksorted( ) const //completed //given
{
   ::checkbetween( tr, nullptr, nullptr );
}


void set::print( std::ostream& out, unsigned int indent ) const //completed //works
{
   ::print( out, tr, indent );
}