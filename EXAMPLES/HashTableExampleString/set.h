#ifndef SET_H_
#define SET_H_
#include <ostream>
#include <list>
#include <cstdlib>
#include <math.h>

//Case insensitive string equality
bool equal(const std::string& s1, const std::string& s2);
// {
//     std::string lower_s1 = s1;
//     std::string lower_s2 = s2;
//     std::transform(lower_s1.begin(), lower_s1.end(), lower_s1.begin(), ::tolower);
//     std::transform(lower_s2.begin(), lower_s2.end(), lower_s2.begin(), ::tolower);
    
//     return lower_s1 == lower_s2;
// }

//Hash function for strings
size_t hash(const std::string& s1);
// {
//     // Basic hash function for strings
//     size_t hash = 0;
//     for (char c : s1) {
//         hash = (hash * 31) + c;
//     }
//     return hash;
// }

class set{
    std::list<std::string>* bucket_array;

    size_t bucket_array_size;

    size_t set_size;

    const double max_load_number = 3.0;
    
    public:

        //Creates empty set
        set() :
            bucket_array(new std::list<std::string>[4]),
            bucket_array_size(4),
            set_size(0)
            {}

        //Copy constructor
        set(const set& s);

//         set::set(const set& s) :
//     bucket_array(new std::list<std::string>[s.bucket_array_size]),
//     bucket_array_size(s.bucket_array_size),
//     set_size(s.set_size),
//     max_load_number(s.max_load_number) {
//     // Copy elements from the source set to the new set
//     for (size_t i = 0; i < bucket_array_size; ++i) {
//         bucket_array[i] = s.bucket_array[i];
//     }
// }

        //Initializer list constructor
        set(std::initializer_list<std::string> ilist);

// set::set(std::initializer_list<std::string> ilist) :
//     set() { // Delegate to default constructor to initialize
//     // Insert elements from the initializer list
//     for (const auto& val : ilist) {
//         insert(val);
//     }
// }

        // Copy assignment
        set& operator=(const set& s);

// set& set::operator=(const set& s) {
//     if (this != &s) { // Check for self-assignment
//         // Delete existing data
//         clear();
//         // Copy data from the source set
//         bucket_array_size = s.bucket_array_size;
//         set_size = s.set_size;
//         max_load_number = s.max_load_number;
//         bucket_array = new std::list<std::string>[bucket_array_size];
//         for (size_t i = 0; i < bucket_array_size; ++i) {
//             bucket_array[i] = s.bucket_array[i];
//         }
//     }
//     return *this;
// }

        //Insert the given value into the set, if it is not already there
        //Returns true if and only if the value is not already there
        bool insert(std::string val);

// bool set::insert(std::string val) {
//     size_t index = hash(val) % bucket_array_size;
//     for (const auto& elem : bucket_array[index]) {
//         if (equal(elem, val)) {
//             return false; // Value already exists
//         }
//     }
//     bucket_array[index].push_back(val);
//     ++set_size;
//     if (loadfactor() > max_load_number) {
//         // Rehash if load factor exceeds threshold
//         // Implement rehashing logic here
//     }
//     return true;
// }

        //Returns true if and only if value is in the set
        bool contains(std::string val) const;

// bool set::contains(std::string val) const {
//     size_t index = hash(val) % bucket_array_size;
//     for (const auto& elem : bucket_array[index]) {
//         if (equal(elem, val)) {
//             return true; // Value found
//         }
//     }
//     return false; // Value not found
// }

        //Removes the given value from the set, if it is currently there
        //Returns true if and only if the value was there to be removed
        bool remove(std::string val);

// bool set::remove(std::string val) {
//     size_t index = hash(val) % bucket_array_size;
//     auto& bucket = bucket_array[index];
//     for (auto it = bucket.begin(); it != bucket.end(); ++it) {
//         if (equal(*it, val)) {
//             bucket.erase(it);
//             --set_size;
//             return true; // Value removed
//         }
//     }
//     return false; // Value not found
// }

        //Removes everything from the set
        void clear();

// void set::clear() {
//     delete[] bucket_array;
//     bucket_array = new std::list<std::string>[4];
//     bucket_array_size = 4;
//     set_size = 0;
// }

        //Returns the current load factor of the underlying hash table
        double loadfactor() const{
            return (int)set_size/bucket_array_size;
        }

        //Returns the standard deviation of the number of items in the buckets
        double standarddec() const {
            double sum = 0.0;
            double lf - loadfactor();


            for(size_t i = 0; i < bucket_array_size;i++){
                double dif = bucket_array[i].size() - lf;
                sum += dif * dif;

            }

            return sqrt(sum/bucket_array_size);
        }

        void print(std::ostream& out) const {
            for(size_t i = 0; i < bucket_array_size; i++){
                std::list<std::string> bucket = bucket_array[i];

                out <<"bucket[" << i << "] = {";
                    bool first = true;
                    
                    for(std::string val : bucket){
                        if(first) {
                            out << val;
                            first = false;
                        } else {
                            out << "," << val;
                        }
                    }
                out << "}" << val;
            }
        }

        // Destructor
        ~set();
// set::~set() {
//     delete[] bucket_array;
// }
};

inline std::ostream& operator<<(std::ostream& out, const set& s) {
    s.print(out);
    return out;
}



#endif /* SET_H_ */