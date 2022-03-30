#include <iostream>

#include "intent.h"
#include "intent_processing.h"

using namespace std;

int main(){
    cout << "To exit, hit 'X' and then Enter." << endl;

    IntentProcessor intent_processor = IntentProcessor();

    while(true){
        cout << "Enter prompt: " ;
        string input;
        getline(cin,input);

        if(input == "X"){
            break;
        }else{
            intent_processor.intent_preproccessing(input);

            Intent * i = new Intent(input);

            string formed_intent = intent_processor.retrieve_intents(i->get_prompt());
            
            if(formed_intent == "unknown"){
                cout << "Unknown request. Please try again.\n" << endl;
                delete i;
                i = nullptr;
                
                continue;
            }

            i->set_intent(formed_intent);

            cout << i->get_intent() << endl << endl;

            delete i;
            i = nullptr;
        }
    }    
} 
