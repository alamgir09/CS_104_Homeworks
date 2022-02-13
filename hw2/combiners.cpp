#include "searcheng.h"
#include "combiners.h"

// Complete the necessary code
using namespace std;

WebPageSet AndWebPageSetCombiner::combine(const WebPageSet& setA, const WebPageSet& setB)
{
    // This is the set that we're going to input the AND results in and return
    WebPageSet setC;
    // Accounts for if either set given to us are empty, resulting in an empty set being returned
    if (setA.empty() || setB.empty())
    {
        setC.clear();
        return setC;
    }
    //StringSet terms_setA = setA.all_terms();
    for (WebPageSet::iterator it = setA.begin(); it != setA.end(); ++it)
    {
        // Compares terms, if does exist in setB then adds to setC
        if (setB.find(*it) != setB.end())
        {
            setC.insert(*it);
        }
    }
    return setC;
}

WebPageSet OrWebPageSetCombiner::combine(const WebPageSet& setA, const WebPageSet& setB)
{
    WebPageSet setC;
    // Iterates through all terms in setA then setB and adds both, since set already accounts for duplicates I don't need to do anything else
    for (WebPageSet::iterator it = setA.begin(); it != setA.end(); ++it)
    {
        setC.insert(*it);
    }
    for (WebPageSet::iterator it = setB.begin(); it != setB.end(); ++it)
    {
        setC.insert(*it);
    }
    return setC;
}

WebPageSet DiffWebPageSetCombiner::combine(const WebPageSet& setA, const WebPageSet& setB)
{
    WebPageSet setC;
    // Iterates through setA and adds any term not in setB to setC
    for (WebPageSet::iterator it = setA.begin(); it != setA.end(); ++it)
    {
        if (setB.find(*it) == setB.end())
        {
            setC.insert(*it);
        }
    }
    return setC;
}