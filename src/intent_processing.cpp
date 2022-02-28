#include "intent_processing.h"

void IntentProcessor::intent_preproccessing(string& text){
    // to lowercase
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    // remove punctuation
    text.erase(remove_if(text.begin (), text.end (), ::ispunct), text.end ());
}

vector<string> IntentProcessor::split_string(const string& text){
    istringstream iss(text);
    vector<string> tokens {istream_iterator<string>{iss},
                    istream_iterator<string>{}};
    return tokens;
}

string IntentProcessor::retrieve_intents(const string& text){
    string result{};
    bool unknown_intent{true};
    vector<string> tokens = split_string(text);

    for(string token : tokens){
        string tag = topics_of_interest[token];
        if(tag != ""){
            if(tag == "-"){
                tag = token;
            }
            tag[0] = toupper( tag[0] );
            result += tag + " ";
            if(unknown_intent) unknown_intent = false;
        }
    }
    if(unknown_intent){ 
        return "unknown";
    }else{
        result.back() = '.';
        return result;
    }
}