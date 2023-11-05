#include "memberType.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void displayAllMembers(const vector<memberType>& members) {
    for(const memberType& member : members) {
        member.displayMemberInfo();
        cout << endl;
    }
}


void readData(ifstream& inData, vector<memberType>& members) {
  int i = 0;
  string name;
  int id = 0;
  int booksBought = 0;
  double amountSpent = 0.00;
  inData >> i;
  // vector<memberType> members; 
  
  for(int j = 0; j < i; j++) {
    inData >>  id >> name >> booksBought >> amountSpent;
    memberType member(name, id, booksBought, amountSpent);
    members.push_back(member); 
  }
}

int main() {
    ifstream inData;
    inData.open("memberData.txt");

    if(inData.is_open()) {
        vector<memberType> members;
        readData(inData, members);
        displayAllMembers(members);

        inData.close();
        cout << "Member Information:" << endl;
    } else {
        cout << "Failed to open file." << endl;
    }

    return 0;
}