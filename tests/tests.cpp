#include <gtest/gtest.h>
#include <string>
using namespace std;
#include "../src/intent_processing.h"

// Test input preprocessing.
TEST(IntentProcessor, PromptPreprocessing) {
    IntentProcessor intent_processor = IntentProcessor();
    string processed_string = "TEst String?..";
    intent_processor.intent_preproccessing(processed_string);
    string test_string = "test string";
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}

// Test intent retrieval on target cases.
TEST(IntentProcessor, IntentRetrieval_Known) {
    IntentProcessor intent_processor = IntentProcessor();
    vector<string> target_input {
        "What is the weather like today?",
        "What is the weather like in Paris today?",
        "Tell me an interesting fact."
    };
    vector<string> target_output {
        "Weather.", "Weather City.", "Fact."
    };

    for(size_t i{}; i <target_input.size(); ++i){
        string processed_string = target_input[i];
        intent_processor.intent_preproccessing(processed_string);

        processed_string = intent_processor.retrieve_intents(processed_string);
        string test_string = target_output[i];
        // Expect equality.
        EXPECT_TRUE(processed_string == test_string);
    }
}

// Test intent retrival on unknown cases.
TEST(IntentProcessor, IntentRetrieval_Unknown) {
    IntentProcessor intent_processor = IntentProcessor();
    string processed_string = "asdfghjkl";
    intent_processor.intent_preproccessing(processed_string);
    
    processed_string = intent_processor.retrieve_intents(processed_string);
    string test_string = "unknown";
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}

// Test input splitting.
TEST(IntentProcessor, String_Splitter) {
    vector<string> processed_string = IntentProcessor::split_string("One Two Three");
    vector<string> test_string {"One", "Two", "Three"};
    // Expect equality.
    EXPECT_TRUE(processed_string == test_string);
}


