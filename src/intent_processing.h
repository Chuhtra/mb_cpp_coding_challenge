#pragma once
#include <vector>
#include <string>
#include <algorithm>

#include "topic.h"

using namespace std;
class IntentProcessor{
    public:
        IntentProcessor() = default;

        void intent_preproccessing(string& text);

    private:
        vector<Topic> topic_of_interest {
                Topic("weather"), 
                Topic("price"), 
                Topic("fact"),
                Topic("Paris", "City"),
                Topic("Berlin", "City")
                };
};