
#include "map.h"

// Should be copied from assignment 3: 

int case_insensitive_cmp::operator( ) //completed //copied
      ( const std::string& s1, const std::string& s2 ) const
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


// Must be written:

size_t case_insensitive_hash::operator( ) ( const std::string& s ) const //completed //works
{
   size_t hashvalue = 0;
   size_t n = 1;
   for (size_t i = 0; i < s.size(); ++i) {
      char lowercase_c = std::tolower(s[i]);
      hashvalue += (lowercase_c * n);
      n *= 31;
   }
   return hashvalue;
} 

auto map::getbucket( const keytype& key ) -> buckettype& //completed //works
{
   keyhash hh;
   size_t index = hh(key) % buckets.size();
   return buckets[index];
}

auto map::getbucket( const keytype& key ) const -> const buckettype& //completed //works
{
   keyhash hh;
   size_t index = hh(key) % buckets.size();
   return buckets[index];
}

auto map::find( const keytype& key, buckettype& bk ) //completed //works
-> buckettype::iterator
{
   map::keycmp cmp;
   for (auto it = bk.begin(); it != bk.end(); ++it) {
      if (cmp(it->first, key) == 0) {
         return it;
      }
   }
   return bk.end();
}

auto map::find( const keytype& key, const buckettype& bk ) //completed //works
-> buckettype::const_iterator
{
   map::keycmp cmp;
   for (auto it = bk.begin(); it != bk.end(); ++it) {
      if (cmp(it->first, key) == 0) {
         return it;
      }
   }
   return bk.end();
}


size_t map::nrbuckets_needed(size_t sz) const { //completed //works
   size_t buckets = 3;
   while (buckets * max_load_factor < sz) {
      buckets *= 3;
   }
   return buckets;
}


void map::rehash(size_t nrbuckets) //completed //works
{
   auto oldbuckets = std::exchange(buckets, std::vector<buckettype>(nrbuckets));
   // In this way, you can use method getbucket( ) for reinserting.
   current_size = 0;
   for (size_t i = 0; i < oldbuckets.size(); ++i) {
      for (auto p = oldbuckets[i].begin(); p != oldbuckets[i].end(); ++p) {
         buckettype& newBucket = getbucket(p->first);
         newBucket.push_back(*p);
         current_size++;
      }
   }
   oldbuckets.clear();
}





bool map::contains(const keytype& key) const //completed //works
{
    const buckettype& Bucket = getbucket(key);
    return find(key, Bucket) != Bucket.end();
}



bool map::insert( const keytype& key, const valtype& val ) //completed //works
{
   buckettype& Bucket = getbucket(key);
   if(find(key, Bucket) != Bucket.end()) return false;
   if(rehash_needed(current_size+1) == true){
      size_t new_buckets = nrbuckets_needed(current_size+1);
      rehash(new_buckets);
      buckettype& newBucket = getbucket(key); 
      newBucket.push_back({key, val});        
      current_size++;
   } else {
      Bucket.push_back({key, val});
      current_size++;
   }
   return true;
}


auto map::at( const keytype& key ) const -> const valtype& //completed //works
{
   // If you want to store the bucket of key, make sure to use
   // a reference (not a copy). 
   const buckettype& Bucket = getbucket(key);
   auto it = find(key, Bucket);
   if(it == Bucket.end()){
      throw std::out_of_range("Key is not presented in map");
   } else {
      return it->second;
   }
}

auto map::at( const keytype& key ) -> valtype& //completed //works
{
   // If you want to store the bucket of key, make sure to use
   // a reference (not a copy).
   buckettype& Bucket = getbucket(key);
   auto it = find(key, Bucket);
   if(it == Bucket.end()){
      throw std::out_of_range("Key is not presented in map");
   } else {
      return it->second;
   }
}

auto map::operator[] (const keytype& key) -> valtype& //completed //works
{
   buckettype& Bucket = getbucket(key);
   auto it = find(key, Bucket);
   if (it != Bucket.end()) {
      return it->second;
   } else {
      if (rehash_needed(current_size + 1)) {
         size_t new_buckets = nrbuckets_needed(current_size + 1);
         rehash(new_buckets);
         buckettype& newBucket = getbucket(key);
         newBucket.push_back({key, valtype{}});
         current_size++;
         return newBucket.back().second;
      } else {
         Bucket.push_back({key, valtype{}});
         current_size++;
         return Bucket.back().second;
      }
   }
}



bool map::erase( const keytype& key ) //completed //works
{
   buckettype& Bucket = getbucket(key);
   auto it = find(key, Bucket);
   if(it != Bucket.end()){
      Bucket.erase(it);
      current_size --;
      return true;
   } else {
      return false;
   }
}

size_t map::size( ) const //completed //works
{
   return current_size;
}

bool map::empty( ) const //completed //works
{
   return current_size == 0;
}

void map::clear() //completed //works
{
   for (size_t i = 0; i < buckets.size(); i++) {
      buckets[i].clear();
   }
   current_size = 0;
}


void map::print( std::ostream& out ) const //completed //given
{
   out << "hashmap( max_load_factor = " << max_load_factor;
   out << ", size = " << current_size << " ):\n";

   for( size_t i = 0; i != buckets. size( ); i++ )
   {
      out << "   bucket[" << i << "]:    {";
      for( auto p = buckets[i]. begin( ); p != buckets[i]. end( ); ++ p )
      {
         if( p != buckets[i]. begin( ))
            out << ", ";
         else
            out << " ";
         out << ( p -> first ) << " : " << ( p -> second );
      }
      out << " }\n";
   }
}


