#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cctype>
#include "md_parser.h"
#include "util.h"

using namespace std;

typedef enum { NORMALTEXT, LINKTEXT, ISLINK, LINKURL } PARSE_STATE_T;

// COMPLETED, DOES NOT NEED TO BE MODIFIED
void MDParser::parse(std::istream& istr, std::set<std::string>& allSearchableTerms, std::set<std::string>& allOutgoingLinks)
{

    // Remove any contents of the sets before starting to parse.
    allSearchableTerms.clear();
    allOutgoingLinks.clear();

    // Complete your code below 

    // Some initial code is referenced from txt_parser.cpp file

    // Initialize the current term and link as empty strings.
    string term = "";

    // Get the first character from the file.
    char c = istr.get();

    PARSE_STATE_T state = NORMALTEXT;

    // Continue reading from the file until input fails 
    
    while( !istr.fail())
    {
    // Checks if special character, else simply adds character to term and moves to next
        if (!isalnum(c))
        {
            // Only one conditional work at a time, depending on state
            if (state == NORMALTEXT)
            {
                if(term != "")
                {
                    term = conv_to_lower(term);
                    allSearchableTerms.insert(term);
                }
                term = "";
                if (c == '[')
                {
                    state = LINKTEXT;
                }
            }
            else if (state == LINKTEXT)
            {
                if (c == ']')
                {
                    state = ISLINK;
                }
                if(term != "")
                {
                    term = conv_to_lower(term);
                    // cout << "Terms " << term << endl;
                    allSearchableTerms.insert(term);
                }
                term = "";
            }
            // Will check if conditions of link are satisfied, else will revert back to LinkText or NormalText depending on character
            else if (state == ISLINK)
            {
                if (c == '[')
                {
                    state = LINKTEXT;
                }
                else if (c == '(')
                {
                    state = LINKURL;
                }
                else
                {
                    state = NORMALTEXT;
                }
                
            }
            else if (state == LINKURL)
            {
                if (c == ')')
                {
                    if (term != "")
                    {
                    term = conv_to_lower(term);
                    // cout << term  << " Links" << endl;
                    allOutgoingLinks.insert(term);
                    }
                    state = NORMALTEXT;
                    term = "";
                }
                // To account for special characters in link_url, we will add the special character to term if link hasn't ended
                else 
                {
                    term += c;
                }
            }
            c = istr.get();
        }
        else
        {
            term += c;
            c = istr.get();
        }
    
    }
    
    if(term != "")
    {
        term = conv_to_lower(term);
        // cout << term << endl;
        allSearchableTerms.insert(term);
    }
    //std::string habibi = MDParser::display_text(istr);
    //cout << "Return Val is " << habibi << endl;
}

// To be completed
std::string MDParser::display_text(std::istream& istr)
{
    // Referenced from txt_parser.cpp file

    string retval; 

    // string term = "";

    char c = istr.get();
    PARSE_STATE_T state = NORMALTEXT;

    while(!istr.fail())
    {
        // Checks if special character, else simply adds character to term and moves to next
        if (!isalnum(c))
        {
            // Only one conditional work at a time, depending on state
            if (state == NORMALTEXT)
            {
                if (c == '[')
                {
                    state = LINKTEXT;
                }
                retval += c;
            }
            else if (state == LINKTEXT)
            {
                if (c == ']')
                {
                    state = ISLINK;
                }
                retval += c;
            }
            // Will check if conditions of link are satisfied, else will revert back to LinkText or NormalText depending on character
            else if (state == ISLINK)
            {
                if (c == '[')
                {
                    state = LINKTEXT;
                    retval += c;
                }
                else if (c == '(')
                {
                    state = LINKURL;
                }
                else
                {
                    state = NORMALTEXT;
                    retval += c;
                }
                
            }
            else if (state == LINKURL)
            {
                if (c == ')')
                {
                    state = NORMALTEXT;
                }
            }
            c = istr.get();
        }
        else
        {
            if (state == LINKURL)
            {
                continue;
            }
            else
            {
            retval += c;
            c = istr.get();
            }
        }
    }
    cout << "Return Val is " << retval << endl;
    return retval;
}


