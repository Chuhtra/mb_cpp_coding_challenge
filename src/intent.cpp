#include "intent.h"
#include <string_view>

Intent::Intent(const std::string& prompt){
    this->prompt=prompt;
}

string Intent::get_intent(){                 
    return this->intent; 
}
string Intent::get_prompt(){ 
    return this->prompt;
}
void Intent::set_intent(vector<string> const parts){
    for (const auto &piece : parts) this->intent += piece + " ";
}