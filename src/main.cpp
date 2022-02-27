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
        cout << input << endl;

        intent_processor.intent_preproccessing(input);

        if(input == "X"){
            break;
        }else{
            Intent * i = new Intent(input);
        //TODO
        }
    }    
} 