#include <iostream>
#include <fstream>
#include "searcheng.h"
#include "searchui.h"
#include "md_parser.h"
#include "txt_parser.h"
#include "cmdhandler.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Must provide an index file" << endl;
        return 1;
    }
    // Only for testing display_text in MDP
    /*
    MDParser mdP;
    ifstream f(argv[1]);
    cout << "Display_text is " << mdP.display_text(f) << endl;
    */
    // return 0;
    // Declare the search engine
    SearchEng seng;

    // ---------------------- [TO BE COMPLETED] -------------------------------
    // Create and register appropriate parsers for .md and .txt files
    MDParser mdP;
    seng.register_parser("md", &mdP);
    TXTParser txT; 
    seng.register_parser("txt", &txT);

    // Create the SearchUI object
    SearchUI ui(&seng);

    // Create and add appropriate Command Handlers to the SearchUI
    ui.add_handler(new QuitHandler);
    ui.add_handler(new PrintHandler);



    // ------------------------------------------------------------------------

    try {
        seng.read_pages_from_index(argv[1]);
    }
    catch (std::exception& e) {
        cout << e.what() << endl;
        return 1;
    }

    if (argc == 2)
    {
        ui.run(cin, cout);

    }
    else if (argc == 3) {
        ifstream in_file(argv[2]);
        ui.run(in_file, cout);
    }
    else  {
        ifstream in_file(argv[2]);
        ofstream out_file(argv[3]);
        ui.run(in_file, out_file);
    }
    // You may add cleanup code here though you likely do not
    // need to.

    return 0;
}
