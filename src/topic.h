#pragma once
#include <string>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Topic{
    public:
        Topic()=default;
        Topic(string_view text);
        Topic(string_view text, string_view tag);

        string get_text();
        string get_tag();

    private:
        string text{};
        string tag{};

        inline static vector<string> accepted_tags{"City", "Country"};
};