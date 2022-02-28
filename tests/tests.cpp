#include <gtest/gtest.h>
#include <string>
using namespace std;
#include "../src/intent_processing.h"

TEST(IntentProcessor, PromptPreprocessing) {
    IntentProcessor intent_processor = IntentProcessor();
    string processed_string = "TEst String?..";
    intent_processor.intent_preproccessing(processed_string);
    string test_string = "test string";
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}

TEST(IntentProcessor, IntentRetrieval_Known) {
    IntentProcessor intent_processor = IntentProcessor();
    string processed_string = "What is the weather like in Paris today?";
    intent_processor.intent_preproccessing(processed_string);

    processed_string = intent_processor.retrieve_intents(processed_string);
    string test_string = "Weather City.";
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}

TEST(IntentProcessor, IntentRetrieval_Unknown) {
    IntentProcessor intent_processor = IntentProcessor();
    string processed_string = "asdfghjkl";
    intent_processor.intent_preproccessing(processed_string);
    
    processed_string = intent_processor.retrieve_intents(processed_string);
    string test_string = "unknown";
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}

TEST(IntentProcessor, String_Splitter) {
    vector<string> processed_string = IntentProcessor::split_string("One Two Three");
    vector<string> test_string {"One", "Two", "Three"};
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}


