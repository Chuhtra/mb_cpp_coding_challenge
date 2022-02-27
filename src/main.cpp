#include <iostream>


using namespace std;

int main(){
    cout << "To exit, hit 'X' and then Enter." << endl;
    while(true){
        cout << "Enter prompt: " ;
        string input;
        getline(cin,input);
        cout << input << endl;

        if(input == "X"){
            break;
        }else{
        //TODO
        }
    }    
} 