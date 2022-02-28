#pragma once
#include <vector>
#include <string>
#include<sstream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
class IntentProcessor{
    public:
        IntentProcessor() = default;

        void intent_preproccessing(string& text);
        string retrieve_intents(const string& text);

    private:
        map<string, string> topics_of_interest {{"weather", "-"}, 
                                                {"price", "-"}, 
                                                {"fact", "-"},
                                                {"paris", "City"},
                                                {"berlin", "City"}
                                                };
};