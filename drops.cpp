#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
#include "drops.hpp"

using namespace std;

int main() {
    cout<<"Welcome to the Draw for the JB13 Vol.1 Shoes! For access to the draw, please enter the password (Ja'Corey).\n";
    
    enterportal();

//Amount of shoes that will be sold. This can be changed depending on how many shoes you want to sell for the demonstration.
    int shoecount = 12;
// This can be changed if you would like a more specific number for the first drop.
    int first_drop = shoecount / 3;
    
    std::string names;
        
//Queue for the people's names to be entered into and stored in.
    queue<string> line;
    
    
    while(names != "Q" && names != "q"){
    cout << "Please enter your first name to be entered into the draw. Enter Q when you are finished entering names.";
    cin >> names;
//Conditional statement allows for the Q to not be added to the line queue and have the names stored into line queue.
    if(names != "Q" && names != "q"){
        line.push(names);
    }
        
}

// If statement creates a conditional for the instance that not enough participants were entered into the sneaker release.
    if (line.size() < shoecount) {
    int currentline = line.size();
    cout << "Congratulations! Because there wasn't enough names entered into the raffle, everyone who entered will receive a pair of the shoes! Thank you!\n";
        //iterates through the queue.
        for (int l = 0; l <= currentline; l++) {
        cout << line.front() << "\n";
        line.pop();
        shoecount--;
    }
    exit(EXIT_SUCCESS);
    }
    

    cout << "\n" << "Thank you for entering the sneaker release. The people's names that will be displayed below are the people that will recieve the shoe automatically. If your name is not displayed, then your name will be entered into a randomized raffle to be chosen for the rest of the stock available.\n";

//For loop iterates throughout the first set of sneaker releases.
    for (int l = 0; l < first_drop; l++) {
        cout << line.front() << "\n";
        line.pop();
        shoecount--;
    }
    
    cout << "Congrats!\n";
    cout << "If you haven't been selected, you will now be entered into the raffle.\n" << "Entering Second phase of sneaker release\n";
    

//HashMap for the second pool of names to be entered into the raffle. This is where names will be pulled from.
    map<int, string> sec_draw ;
    int numassign = 1;
    int n = 0;

    int currentline = line.size();
    
//While loop inserts remaining names into the hasmap to be used later on.
    while ( n < currentline) {
        
        sec_draw.insert({numassign, line.front()});
        line.pop();
        numassign++;
        n++;
    }


    cout << "Selection of the names will begin...\n";

    int randonum;

    unordered_set<int> numpool;
    

/* Sets do not allow duplicate keys. 
With this while loop, the randomizer will continue to attempt to add numbers until 
the set has enough names for every shoe to be given to a person without a person getting multiple pairs. */    
    while (numpool.size() < shoecount) {
        randonum = rand() % currentline + 1;
        numpool.insert(randonum);
        
    } 
    
    cout << "These are the people who have been selected for the remaining shoes left in stock. If you're name was not displayed, you unforntunately were not selected. Please try again next time. Thank you!\n";

    
// For each loop iterates through the hashmap of the winners selected.
    for(int n: numpool) {
        std::cout << sec_draw[n] << "\n";
    }
    
    
    return 0;
}