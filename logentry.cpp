/**
 * @file logentry.hpp
 *
 * @version 1.0
 * @date
 * @author
 *
 * Implementation for a log entry.
 *
 */

#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

/**
 * @pre
 * @post
 */
log_entry::log_entry(const String & s) {
    // ...
    std::vector<String> vec = s.split(' ');
    
}

/**
 * @pre
 * @post
 */
std::vector<log_entry> parse(std::istream & in) {
    std::vector<log_entry> result;

    return result;
}

/**
 * @pre
 * @post
 */
void output_all(std::ostream & out, const std::vector<log_entry> &) {
    
}

/**
 * @pre
 * @post
 */
void by_host(std::ostream & out, const std::vector<log_entry> &) {

}

////////////////////////////////////////////////////////// 
/**
 * @pre
 * @post
 */
int byte_count(const std::vector<log_entry> &) {
    
    return 0;
}

