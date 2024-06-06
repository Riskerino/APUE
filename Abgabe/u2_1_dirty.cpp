#include <iostream>
using namespace std;

void Box(){    //Starttext fuer das Programm
    cout << "Program 'Umgekehrter Text':" << endl;
    cout << "Geben Sie einen Text (auch Zahlen) ein. Spezielle Buchstaben koennen Probleme bereiten!" << endl;
    cout << "Mit dem Wort 'exit()' wird das Programm beendet!" << endl;
}

string Text(string s) {

    string result;
    s.insert(0, " ");
    int breakpoint = 0;
 
     for (int i = 0; i <= s.length(); i++) {
        char c = s[i];
        
        if (c == ' ' || c == '\0') { 
           
            for (int k=i-1; k>breakpoint; k--){
                char j = s[k];
                if (k == i-1) {result += toupper(j);}
               
                else {result += tolower(j);};
                
        };
        
        breakpoint = i;
        result += " ";
     };

     };
  
   
    return result;
}

string Input() {

    cout << "\nGeben Sie einen neuen Text ein:" << endl;
    string String;
    if (getline(cin, String)) {
        return(String);
    } else {
        cout << "Ein unbekannter Fehler trat auf. Das Programm wird beendet...";
        return (0);}
    return(0);
}

int main() {

    Box();
    while(1){
        string NewInputStr = Input();
        if (NewInputStr == "exit()") {break;};
        cout << Text(NewInputStr) << endl;

    }
}