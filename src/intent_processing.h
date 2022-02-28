#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
class IntentProcessor{
    // Class to include input and intent processing functions, as well as needed information stores.
    public:
        IntentProcessor() = default;

        void intent_preproccessing(string& text);
        string retrieve_intents(const string& text);
        static vector<string> split_string(const string& text);

    private:
        string tag_simple_topic = "-";
        string tag_city = "City";
        map<string, string> topics_of_interest {{"weather", tag_simple_topic}, 
                                                {"price", tag_simple_topic}, 
                                                {"fact", tag_simple_topic},
                                                {"paris", tag_city},
                                                {"berlin", tag_city}
                                                };
};