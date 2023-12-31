#ifndef WORDLE_H
#define WORDLE_H

#include <set>
#include <string>
#include <vector>

/**
 * @brief Returns the list of all legal words in the provided dictionary
 *        that meet the criteria provided in the `in` and `floating`
 *        inputs.
 * 
 * @param [in] in - string of fixed, correct characters and `-`s to indicate
 *                  the length of string and locations that must be filled in
 * @param [in] floating  - Characters that must be used somewhere in the word
 * @param [in] dict - Dictionary of strings of legal words
 * @return std::set<std::string> - Set of all words that meet the criteria
 */
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict);

// Helper Functions below

//void traversal(std::vector<char> floatVec, const std::set<std::string>& dict, std::set<std::string> &generated, long unsigned int index, std::string combination, std::string& letters, long unsigned int& dashes);
// int inWord(std::string& combination, const std::string& floating);
//long unsigned int dashesPresent(std::string& combination);

#endif