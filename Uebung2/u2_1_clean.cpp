#include <iostream>
using namespace std;

//Starttext fuer das Programm
void displayInfo() { // Namen der Funktion verbessert, generell auf CamelCase umgeaendert
    cout << "Program 'Umgekehrter Text':" << endl;
    cout << "Geben Sie einen Text (auch Zahlen) ein. Spezielle Buchstaben koennen Probleme bereiten!" << endl;
    cout << "Mit dem Wort 'exit()' wird das Programm beendet!" << endl;
}

// Function to reverse each word in a string while preserving capitalization
string reverseString(string s) {
    string result;
    int breakpoint = 0;
 
    for (int i = 0; i <= s.length(); i++) { // Verbesserte Lesbarkeit, unnoetige leere Zeilen entfernen
        char c = s[i];
        
        if (c == ' ' || c == '\0') { 
            for (int k = i - 1; k >= breakpoint; k--) {
                char j = s[k];
                if (k == i - 1) {
                    result += toupper(j);
                } else {
                    result += tolower(j);
                }
            }
            breakpoint = i + 1;
            result += " ";
        }
    }
    return result;
}

// Funktion, die den Input des Benutzers erfragt
string getUserInput() { // eindeutigere Bezeichnung
    cout << "\nGebe hier einen neuen Text ein:" << endl;
    string newString;
    if (getline(cin, newString)) {
        return newString;
    } else {
        cout << "Ein unbekannter Fehler trat auf. Das Programm wird beendet...";
        exit(1); // Exit mit Error code 1 Ausgabe
    }
}

int main() {
    displayInfo();
    while (true) { // bool anstatt von 1
        string userInput = getUserInput();
        if (userInput == "exit()") {
            break; // bessere Lesbarkeit des Breaks
        }
        cout << reverseString(userInput) << endl;
    }
    return 0;
}
