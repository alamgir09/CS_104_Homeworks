#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include "searcheng.h"

using namespace std;

// Helper function that will extract the extension of a filename
std::string extract_extension(const std::string& filename);

std::string extract_extension(const std::string& filename)
{
    size_t idx = filename.rfind(".");
    if (idx == std::string::npos) {
        return std::string();
    }
    return filename.substr(idx + 1);
}


// To be updated as needed 
SearchEng::SearchEng()
{
    map<string, WebPage*> mapFiles;
    map<string, WebPageSet> mapTerms;
}

// To be completed
SearchEng::~SearchEng()
{
    //Probably will be used to delete dynamically allocated WebPages
    for (map<string, WebPage*>::const_iterator it = mapFiles.begin(); it != mapFiles.end(); ++it)
    {
        delete it->second;
    }
}

// Complete
void SearchEng::register_parser(const std::string& extension, PageParser* parser)
{
    if (parsers_.find(extension) != parsers_.end())
    {
        throw std::invalid_argument("parser for provided extension already exists");
    }
    parsers_.insert(make_pair(extension, parser));
}

// Complete
void SearchEng::read_pages_from_index(const std::string& index_file)
{
    ifstream ifile(index_file.c_str());
    if(ifile.fail()) {
        cerr << "Unable to open index file: " << index_file << endl;
    }

    // Parse all the files
    string filename;
    while(ifile >> filename) {
#ifdef DEBUG
        cout << "Reading " << filename << endl;
#endif
        read_page(filename);
    }
    ifile.close();
}

// To be completed
void SearchEng::read_page(const string& filename)
{

    string ext = extract_extension(filename);
    // Two stringsets allow us to capture searchable terms and outgoing links the parsers will provide
    StringSet allSearchableTerms;

    StringSet outgoingLinks;

    ifstream file(filename);

    // Dynamically allocated webpage
    WebPage* webp;

    if (parsers_.find(ext) != parsers_.end())
    {
        throw std::logic_error("No parser registered for this extension");
    }
    read_pages_from_index(filename);
    if (file.fail())
    {
        throw std::invalid_argument("Filename does not exist");
    }
    if (mapFiles.find(filename) != mapFiles.end())
    {
        webp = new WebPage;
        mapFiles.insert((make_pair(filename, webp)));
    }
    else
    {
        mapFiles[filename] = webp;
    }
    
    parsers_.find(ext)->second->parse(file, allSearchableTerms, outgoingLinks);
    webp->all_terms(allSearchableTerms);
    // Need to somehow add outgoing links here
    //webp->outgoing_links()
    //webp->outgoing_links = outgoingLinks;


}

// To be completed
WebPage* SearchEng::retrieve_page(const std::string& page_name) const
{
    for (map<string, WebPage*>::const_iterator it = mapFiles.begin(); it != mapFiles.end(); ++it)
    {
        if (mapFiles.find(page_name) != mapFiles.end())
        {
            return it->second;
        }
        else
        {
            return NULL;
        }
    }
}

// To be completed
void SearchEng::display_page(std::ostream& ostr, const std::string& page_name) const
{
    string extension = extract_extension(page_name);

    if (parsers_.find(extension) != parsers_.end())
    {
        throw std::logic_error("No parser registered for this extension");
    }
    if (mapFiles.find(page_name) == mapFiles.end())
    {
        throw std::invalid_argument("Filename does not exist");
    }
    ifstream file(page_name);
    ostr << parsers_.find(extension)->second->display_text(file);
}

// To be completed
WebPageSet SearchEng::search(const std::vector<std::string>& terms, WebPageSetCombiner* combiner) const
{
    WebPageSet habibi;
    return habibi;

}

// Add private helper function implementations here

