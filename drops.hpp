#include <iostream>


using namespace std;

void enterportal() {
    //This function is used in order to create a password wall.
        string password = "Ja'Corey";
    
    string entry;
    
    cin >> entry;
    
    
    if (entry != password) {
        while (entry != password){ 
            cout << "Incorrect password, please try again.\n";
            cin >> entry;
            
        }
        
        cout << "You have entered the portal\n";
    }
    else {
        cout << "You have entered the portal\n";
    }
    
}


 