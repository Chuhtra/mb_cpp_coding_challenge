#include "topic.h"

Topic::Topic(string_view text): Topic(text, "") {}

Topic::Topic(string_view text, string_view tag){
    this->text = text;
    if(tag != "" && find(this->accepted_tags.begin(), this->accepted_tags.end(), tag) != this->accepted_tags.end() ){
        this->tag = tag;
    }
}


string Topic::get_text(){
    return this->text;
}
string Topic::get_tag(){
    return this->tag;
}