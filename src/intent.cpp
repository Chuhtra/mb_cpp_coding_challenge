#include "intent.h"
#include <string_view>

Intent::Intent(const string& prompt){
    this->prompt=prompt;
}

string Intent::get_intent(){                 
    return this->intent; 
}
string Intent::get_prompt(){ 
    return this->prompt;
}
void Intent::set_intent(const string& text){
    this->intent += text;
}