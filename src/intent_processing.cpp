#include "intent_processing.h"

void IntentProcessor::intent_preproccessing(string& text){
    transform(text.begin(), text.end(), text.begin(), ::tolower);;
}