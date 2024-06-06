// Clean code: Fehlerfreier Syntax, ausgiebig getestet, gut dokumentiert, hoher Quellcodeportabilitaet, einfach zu aendern und erweitern, gut lesbar 
// Aussagekraeftige Namen fuer Variablen, Desinformation vermeiden, klare Unterscheidungen
// Parameter -Wall, -Wextra und -Wpedantic verwenden

#include <iostream>   // nur wichtigsten Libraries verwenden
using namespace std;

//Starttext fuer das Programm
void displayInfo() { // Namen der Funktion verbessert, generell auf camelCase umgeaendert
    cout << "Programm 'Umgekehrter Text':\nGeben Sie einen Text (auch Zahlen) ein. Spezielle Buchstaben koennen Probleme bereiten!\nMit dem Wort 'exit()' wird das Programm beendet! " << endl;
}

// Funktion die jedes Wort in einem String umdreht und auf Gross/Kleinschreibung achtet
string reverseString(string strText) { // -> aussagekraeftiger Name, Verb klein geschrieben
    string result;
    strText.insert(0, " ");
    unsigned breakpoint = 0; // unsigned anstelle int
 
    for (unsigned letter = 0; letter <= strText.length(); letter++) { // Verbesserte Lesbarkeit, unnoetige leere Zeilen entfernen
        char character = strText[letter];
        
        if (character == ' ' || character == '\0') { 
            for (int k = letter - 1; k > breakpoint; k--) {
                char j = strText[k];
                if (k == letter - 1) {
                    result += toupper(j);
                } else {
                    result += tolower(j);
                }
            };
            breakpoint = letter;
            result += " ";
        };
    };
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
        string userInput = getUserInput(); // bessere Bezeichnung des Breaks
        if (userInput == "exit()") {
            break; // bessere Lesbarkeit des Breaks
        }
        cout << reverseString(userInput) << endl;
    }
    return 0;
}
