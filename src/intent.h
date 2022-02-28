#pragma once

#include <string>
#include <vector>

using namespace std;
class Intent{
    string prompt{};
    string intent{"Intent: Get "};

public:
    Intent(const string&);
    
    string get_intent();
    string get_prompt();

    void set_intent(const string&);
};